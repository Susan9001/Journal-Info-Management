/****************************************************************************
** Meta object code from reading C++ file 'd_paper_info.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../d_paper_info.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'd_paper_info.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DPaperInfo_t {
    QByteArrayData data[15];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DPaperInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DPaperInfo_t qt_meta_stringdata_DPaperInfo = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DPaperInfo"
QT_MOC_LITERAL(1, 11, 16), // "toWinShowJournal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 9), // "editor_id"
QT_MOC_LITERAL(4, 39, 11), // "toShowPaper"
QT_MOC_LITERAL(5, 51, 9), // "prv_index"
QT_MOC_LITERAL(6, 61, 2), // "id"
QT_MOC_LITERAL(7, 64, 12), // "onBtnConfirm"
QT_MOC_LITERAL(8, 77, 27), // "onCurrentContributorChanged"
QT_MOC_LITERAL(9, 105, 23), // "onCurrentJournalChanged"
QT_MOC_LITERAL(10, 129, 16), // "onBtnContributor"
QT_MOC_LITERAL(11, 146, 12), // "onBtnJournal"
QT_MOC_LITERAL(12, 159, 16), // "onLineIdFinished"
QT_MOC_LITERAL(13, 176, 15), // "onToShowJournal"
QT_MOC_LITERAL(14, 192, 13) // "onToShowPaper"

    },
    "DPaperInfo\0toWinShowJournal\0\0editor_id\0"
    "toShowPaper\0prv_index\0id\0onBtnConfirm\0"
    "onCurrentContributorChanged\0"
    "onCurrentJournalChanged\0onBtnContributor\0"
    "onBtnJournal\0onLineIdFinished\0"
    "onToShowJournal\0onToShowPaper"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DPaperInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    2,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   72,    2, 0x08 /* Private */,
       8,    1,   73,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    1,   82,    2, 0x08 /* Private */,
      14,    2,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void DPaperInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DPaperInfo *_t = static_cast<DPaperInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toWinShowJournal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->toShowPaper((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->onBtnConfirm(); break;
        case 3: _t->onCurrentContributorChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onCurrentJournalChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onBtnContributor(); break;
        case 6: _t->onBtnJournal(); break;
        case 7: _t->onLineIdFinished(); break;
        case 8: _t->onToShowJournal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->onToShowPaper((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DPaperInfo::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DPaperInfo::toWinShowJournal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DPaperInfo::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DPaperInfo::toShowPaper)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DPaperInfo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DPaperInfo.data,
      qt_meta_data_DPaperInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DPaperInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DPaperInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DPaperInfo.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DPaperInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DPaperInfo::toWinShowJournal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DPaperInfo::toShowPaper(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
