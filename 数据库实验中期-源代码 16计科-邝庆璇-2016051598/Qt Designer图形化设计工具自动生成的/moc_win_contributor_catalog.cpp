/****************************************************************************
** Meta object code from reading C++ file 'win_contributor_catalog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../win_contributor_catalog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'win_contributor_catalog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WinContributorCatalog_t {
    QByteArrayData data[20];
    char stringdata0[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WinContributorCatalog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WinContributorCatalog_t qt_meta_stringdata_WinContributorCatalog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "WinContributorCatalog"
QT_MOC_LITERAL(1, 22, 12), // "paperClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 2), // "id"
QT_MOC_LITERAL(4, 39, 8), // "tabIndex"
QT_MOC_LITERAL(5, 48, 10), // "onBtnPaper"
QT_MOC_LITERAL(6, 59, 10), // "onDlgPaper"
QT_MOC_LITERAL(7, 70, 11), // "onShowStaff"
QT_MOC_LITERAL(8, 82, 10), // "onBtnPrint"
QT_MOC_LITERAL(9, 93, 19), // "onBtnAddContributor"
QT_MOC_LITERAL(10, 113, 19), // "onBtnDelContributor"
QT_MOC_LITERAL(11, 133, 16), // "onBtnContributor"
QT_MOC_LITERAL(12, 150, 12), // "onBtnAddUnit"
QT_MOC_LITERAL(13, 163, 12), // "onBtnDelUnit"
QT_MOC_LITERAL(14, 176, 9), // "onBtnUnit"
QT_MOC_LITERAL(15, 186, 11), // "onBtnSearch"
QT_MOC_LITERAL(16, 198, 9), // "onBtnShow"
QT_MOC_LITERAL(17, 208, 23), // "onContributorSelChanged"
QT_MOC_LITERAL(18, 232, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(19, 249, 34) // "onContributorItemSelcectionCh..."

    },
    "WinContributorCatalog\0paperClicked\0\0"
    "id\0tabIndex\0onBtnPaper\0onDlgPaper\0"
    "onShowStaff\0onBtnPrint\0onBtnAddContributor\0"
    "onBtnDelContributor\0onBtnContributor\0"
    "onBtnAddUnit\0onBtnDelUnit\0onBtnUnit\0"
    "onBtnSearch\0onBtnShow\0onContributorSelChanged\0"
    "QTreeWidgetItem*\0onContributorItemSelcectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WinContributorCatalog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   94,    2, 0x08 /* Private */,
       6,    2,   95,    2, 0x08 /* Private */,
       7,    1,  100,    2, 0x08 /* Private */,
       8,    0,  103,    2, 0x08 /* Private */,
       9,    0,  104,    2, 0x08 /* Private */,
      10,    0,  105,    2, 0x08 /* Private */,
      11,    0,  106,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    2,  112,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18, QMetaType::Int,    2,    2,
    QMetaType::Void,

       0        // eod
};

void WinContributorCatalog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WinContributorCatalog *_t = static_cast<WinContributorCatalog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paperClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->onBtnPaper(); break;
        case 2: _t->onDlgPaper((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->onShowStaff((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onBtnPrint(); break;
        case 5: _t->onBtnAddContributor(); break;
        case 6: _t->onBtnDelContributor(); break;
        case 7: _t->onBtnContributor(); break;
        case 8: _t->onBtnAddUnit(); break;
        case 9: _t->onBtnDelUnit(); break;
        case 10: _t->onBtnUnit(); break;
        case 11: _t->onBtnSearch(); break;
        case 12: _t->onBtnShow(); break;
        case 13: _t->onContributorSelChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->onContributorItemSelcectionChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WinContributorCatalog::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WinContributorCatalog::paperClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WinContributorCatalog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WinContributorCatalog.data,
      qt_meta_data_WinContributorCatalog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WinContributorCatalog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WinContributorCatalog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WinContributorCatalog.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WinContributorCatalog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void WinContributorCatalog::paperClicked(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
