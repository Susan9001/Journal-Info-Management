/****************************************************************************
** Meta object code from reading C++ file 'win_journal_catalog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../win_journal_catalog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'win_journal_catalog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WinJournalCatalog_t {
    QByteArrayData data[18];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WinJournalCatalog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WinJournalCatalog_t qt_meta_stringdata_WinJournalCatalog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "WinJournalCatalog"
QT_MOC_LITERAL(1, 18, 12), // "paperClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 2), // "id"
QT_MOC_LITERAL(4, 35, 8), // "tabIndex"
QT_MOC_LITERAL(5, 44, 20), // "editorJournalClicked"
QT_MOC_LITERAL(6, 65, 10), // "onBtnPaper"
QT_MOC_LITERAL(7, 76, 10), // "onDlgPaper"
QT_MOC_LITERAL(8, 87, 10), // "onBtnPrint"
QT_MOC_LITERAL(9, 98, 16), // "onBtnJournalInfo"
QT_MOC_LITERAL(10, 115, 8), // "onBtnAdd"
QT_MOC_LITERAL(11, 124, 11), // "onBtnDelete"
QT_MOC_LITERAL(12, 136, 11), // "onBtnSearch"
QT_MOC_LITERAL(13, 148, 9), // "onBtnShow"
QT_MOC_LITERAL(14, 158, 17), // "onTypeeSelChanged"
QT_MOC_LITERAL(15, 176, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(16, 193, 28), // "onTypeeItemSelcectionChanged"
QT_MOC_LITERAL(17, 222, 15) // "onToShowJournal"

    },
    "WinJournalCatalog\0paperClicked\0\0id\0"
    "tabIndex\0editorJournalClicked\0onBtnPaper\0"
    "onDlgPaper\0onBtnPrint\0onBtnJournalInfo\0"
    "onBtnAdd\0onBtnDelete\0onBtnSearch\0"
    "onBtnShow\0onTypeeSelChanged\0"
    "QTreeWidgetItem*\0onTypeeItemSelcectionChanged\0"
    "onToShowJournal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WinJournalCatalog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       5,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   85,    2, 0x08 /* Private */,
       7,    2,   86,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    2,   97,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void WinJournalCatalog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WinJournalCatalog *_t = static_cast<WinJournalCatalog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paperClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->editorJournalClicked(); break;
        case 2: _t->onBtnPaper(); break;
        case 3: _t->onDlgPaper((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->onBtnPrint(); break;
        case 5: _t->onBtnJournalInfo(); break;
        case 6: _t->onBtnAdd(); break;
        case 7: _t->onBtnDelete(); break;
        case 8: _t->onBtnSearch(); break;
        case 9: _t->onBtnShow(); break;
        case 10: _t->onTypeeSelChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->onTypeeItemSelcectionChanged(); break;
        case 12: _t->onToShowJournal((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WinJournalCatalog::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WinJournalCatalog::paperClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WinJournalCatalog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WinJournalCatalog::editorJournalClicked)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject WinJournalCatalog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WinJournalCatalog.data,
      qt_meta_data_WinJournalCatalog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WinJournalCatalog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WinJournalCatalog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WinJournalCatalog.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WinJournalCatalog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void WinJournalCatalog::paperClicked(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WinJournalCatalog::editorJournalClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
