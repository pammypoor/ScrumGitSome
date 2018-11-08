/****************************************************************************
** Meta object code from reading C++ file 'fanpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fanpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fanpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_fanpage_t {
    QByteArrayData data[11];
    char stringdata0[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fanpage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fanpage_t qt_meta_stringdata_fanpage = {
    {
QT_MOC_LITERAL(0, 0, 7), // "fanpage"
QT_MOC_LITERAL(1, 8, 29), // "on_mainPlanTripButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 34), // "on_mainViewSouvenirsButton_cl..."
QT_MOC_LITERAL(4, 74, 30), // "on_mainViewTeamsButton_clicked"
QT_MOC_LITERAL(5, 105, 31), // "on_mainViewArenasButton_clicked"
QT_MOC_LITERAL(6, 137, 29), // "on_backSouvenirButton_clicked"
QT_MOC_LITERAL(7, 167, 44), // "on_teamNameSouvenirCombo_curr..."
QT_MOC_LITERAL(8, 212, 4), // "arg1"
QT_MOC_LITERAL(9, 217, 25), // "on_backTeamButton_clicked"
QT_MOC_LITERAL(10, 243, 40) // "on_teamNameTeamCombo_currentI..."

    },
    "fanpage\0on_mainPlanTripButton_clicked\0"
    "\0on_mainViewSouvenirsButton_clicked\0"
    "on_mainViewTeamsButton_clicked\0"
    "on_mainViewArenasButton_clicked\0"
    "on_backSouvenirButton_clicked\0"
    "on_teamNameSouvenirCombo_currentIndexChanged\0"
    "arg1\0on_backTeamButton_clicked\0"
    "on_teamNameTeamCombo_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fanpage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void fanpage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fanpage *_t = static_cast<fanpage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_mainPlanTripButton_clicked(); break;
        case 1: _t->on_mainViewSouvenirsButton_clicked(); break;
        case 2: _t->on_mainViewTeamsButton_clicked(); break;
        case 3: _t->on_mainViewArenasButton_clicked(); break;
        case 4: _t->on_backSouvenirButton_clicked(); break;
        case 5: _t->on_teamNameSouvenirCombo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_backTeamButton_clicked(); break;
        case 7: _t->on_teamNameTeamCombo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject fanpage::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_fanpage.data,
      qt_meta_data_fanpage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *fanpage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fanpage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_fanpage.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int fanpage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
