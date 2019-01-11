#include "MainWin.h"
#include <QSizePolicy>

MainWin::MainWin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// 3.����ҳ����ת
	connect(ui.btn_firstEnter, SIGNAL(clicked()), this, SLOT(onClickedEnter()));

	ui.stackedWidget->setCurrentIndex(0);

	
}

void MainWin::onClickedEnter()
{
	// 1. �������ݿ�
	DB_JournalManagement = QSqlDatabase::addDatabase("QODBC");   //���ݿ���������ΪSQL Server
	qDebug() << "ODBC driver?" << DB_JournalManagement.isValid();
	QString dsn = QString::fromLocal8Bit("SQL JournalManagement");      //����Դ����
	DB_JournalManagement.setDatabaseName(dsn);                            //��������Դ����
	DB_JournalManagement.setHostName("localhost");                        //ѡ�񱾵�������127.0.1.1
	DB_JournalManagement.setUserName("sa");                               //��¼�û�
	DB_JournalManagement.setPassword("susan84253363");                           //����

	if (!DB_JournalManagement.open())                                      //�����ݿ�
	{
		qDebug() << DB_JournalManagement.lastError().text();
		QMessageBox::critical(0, QObject::tr(u8"���ݿ��ʧ�ܣ�"), DB_JournalManagement.lastError().text());
	}
	else
	{
		qDebug() << "database open success!";

		// 1.2. ��¼
		DLogin* dlgLogin = new DLogin(this);
		int ret = dlgLogin->exec();
		if (ret != QDialog::Accepted)
			return;

		// 2. ��ת���ڶ�ҳ
		ui.stackedWidget->setCurrentIndex(1);

		// 2. ��ʼ���������ڿؼ�
		// ���ڿ�Ŀ¼
		m_WinJournal = new WinJournalCatalog(this);
		QVBoxLayout* tab0_layout = new QVBoxLayout(ui.tabWidget->widget(0));
		tab0_layout->addWidget(m_WinJournal);
		ui.tabWidget->widget(0)->setLayout(tab0_layout);
		// ��Ͷ������ϢĿ¼
		m_WinContributor = new WinContributorCatalog(this);
		QVBoxLayout* tab1_layout = new QVBoxLayout(ui.tabWidget->widget(1));
		tab1_layout->addWidget(m_WinContributor);
		ui.tabWidget->widget(1)->setLayout(tab1_layout);
		// ������ҳ��
		m_WinPaper = new WinPaperCatalog(this);
		QVBoxLayout* tab2_layout = new QVBoxLayout(ui.tabWidget->widget(2));
		tab2_layout->addWidget(m_WinPaper);
		ui.tabWidget->widget(2)->setLayout(tab2_layout);
		
		// ��ת����ҳ��
		connect(m_WinContributor, SIGNAL(paperClicked(int, int)), this, SLOT(onPaperClicked(int, int)));
		connect(m_WinJournal, SIGNAL(paperClicked(int, int)), this, SLOT(onPaperClicked(int, int)));
		connect(this, SIGNAL(showPaper(int, int)), m_WinPaper, SLOT(onShowPaper(int, int)));
		// ����ҳ����ת����
		connect(m_WinPaper, SIGNAL(goBack(int)), this, SLOT(onGoBack(int)));
		// ������ҳ���Journal
		connect(m_WinPaper, SIGNAL(toEditorShowJournal(int)), m_WinJournal, SLOT(onToShowJournal(int)));
		connect(m_WinPaper, SIGNAL(toEditorShowJournal(int)), this, SLOT(onEditorJournalClicked(int)));
	}
}

void MainWin::onPaperClicked(int id, int prv_index)
{
	ui.tabWidget->setCurrentIndex(2); // paperҳ
	emit showPaper(id, prv_index);
}

void MainWin::onGoBack(int prv_index)
{
	ui.tabWidget->setCurrentIndex(prv_index);
}

void MainWin::onEditorJournalClicked(int editor_id)
{
	// ������ʾ��editor��journal����win_journal�︺�����
	onGoBack(0);
}
