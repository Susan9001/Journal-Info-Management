#include "MainWin.h"
#include <QSizePolicy>

MainWin::MainWin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// 3.连接页面跳转
	connect(ui.btn_firstEnter, SIGNAL(clicked()), this, SLOT(onClickedEnter()));

	ui.stackedWidget->setCurrentIndex(0);

	
}

void MainWin::onClickedEnter()
{
	// 1. 连接数据库
	DB_JournalManagement = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
	qDebug() << "ODBC driver?" << DB_JournalManagement.isValid();
	QString dsn = QString::fromLocal8Bit("SQL JournalManagement");      //数据源名称
	DB_JournalManagement.setDatabaseName(dsn);                            //设置数据源名称
	DB_JournalManagement.setHostName("localhost");                        //选择本地主机，127.0.1.1
	DB_JournalManagement.setUserName("sa");                               //登录用户
	DB_JournalManagement.setPassword("susan84253363");                           //密码

	if (!DB_JournalManagement.open())                                      //打开数据库
	{
		qDebug() << DB_JournalManagement.lastError().text();
		QMessageBox::critical(0, QObject::tr(u8"数据库打开失败！"), DB_JournalManagement.lastError().text());
	}
	else
	{
		qDebug() << "database open success!";

		// 1.2. 登录
		DLogin* dlgLogin = new DLogin(this);
		int ret = dlgLogin->exec();
		if (ret != QDialog::Accepted)
			return;

		// 2. 跳转到第而页
		ui.stackedWidget->setCurrentIndex(1);

		// 2. 初始化几个窗口控件
		// ①期刊目录
		m_WinJournal = new WinJournalCatalog(this);
		QVBoxLayout* tab0_layout = new QVBoxLayout(ui.tabWidget->widget(0));
		tab0_layout->addWidget(m_WinJournal);
		ui.tabWidget->widget(0)->setLayout(tab0_layout);
		// ②投稿人信息目录
		m_WinContributor = new WinContributorCatalog(this);
		QVBoxLayout* tab1_layout = new QVBoxLayout(ui.tabWidget->widget(1));
		tab1_layout->addWidget(m_WinContributor);
		ui.tabWidget->widget(1)->setLayout(tab1_layout);
		// ③文章页面
		m_WinPaper = new WinPaperCatalog(this);
		QVBoxLayout* tab2_layout = new QVBoxLayout(ui.tabWidget->widget(2));
		tab2_layout->addWidget(m_WinPaper);
		ui.tabWidget->widget(2)->setLayout(tab2_layout);
		
		// 跳转文章页面
		connect(m_WinContributor, SIGNAL(paperClicked(int, int)), this, SLOT(onPaperClicked(int, int)));
		connect(m_WinJournal, SIGNAL(paperClicked(int, int)), this, SLOT(onPaperClicked(int, int)));
		connect(this, SIGNAL(showPaper(int, int)), m_WinPaper, SLOT(onShowPaper(int, int)));
		// 文章页面跳转回来
		connect(m_WinPaper, SIGNAL(goBack(int)), this, SLOT(onGoBack(int)));
		// 从文章页面回Journal
		connect(m_WinPaper, SIGNAL(toEditorShowJournal(int)), m_WinJournal, SLOT(onToShowJournal(int)));
		connect(m_WinPaper, SIGNAL(toEditorShowJournal(int)), this, SLOT(onEditorJournalClicked(int)));
	}
}

void MainWin::onPaperClicked(int id, int prv_index)
{
	ui.tabWidget->setCurrentIndex(2); // paper页
	emit showPaper(id, prv_index);
}

void MainWin::onGoBack(int prv_index)
{
	ui.tabWidget->setCurrentIndex(prv_index);
}

void MainWin::onEditorJournalClicked(int editor_id)
{
	// 具体显示该editor的journal就在win_journal里负责好了
	onGoBack(0);
}
