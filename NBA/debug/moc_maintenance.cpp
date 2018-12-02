/****************************************************************************
** Meta object code from reading C++ file 'maintenance.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../maintenance.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maintenance.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_maintenance_t {
    QByteArrayData data[17];
    char stringdata0[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_maintenance_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_maintenance_t qt_meta_stringdata_maintenance = {
    {
QT_MOC_LITERAL(0, 0, 11), // "maintenance"
QT_MOC_LITERAL(1, 12, 25), // "on_MenuTeamButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 25), // "on_teamBackButton_clicked"
QT_MOC_LITERAL(4, 65, 29), // "on_menuSouvenirButton_clicked"
QT_MOC_LITERAL(5, 95, 29), // "on_souvenirBackButton_clicked"
QT_MOC_LITERAL(6, 125, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 147, 34), // "on_SouvenirTableView_doubleCl..."
QT_MOC_LITERAL(8, 182, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 194, 5), // "index"
QT_MOC_LITERAL(10, 200, 24), // "on_addTeamButton_clicked"
QT_MOC_LITERAL(11, 225, 37), // "on_showTeamsCombo_currentInde..."
QT_MOC_LITERAL(12, 263, 4), // "arg1"
QT_MOC_LITERAL(13, 268, 41), // "on_teamMaintenanceTableView_d..."
QT_MOC_LITERAL(14, 310, 29), // "on_distanceBackButton_clicked"
QT_MOC_LITERAL(15, 340, 29), // "on_menuDistanceButton_clicked"
QT_MOC_LITERAL(16, 370, 29) // "on_addDistancesButton_clicked"

    },
    "maintenance\0on_MenuTeamButton_clicked\0"
    "\0on_teamBackButton_clicked\0"
    "on_menuSouvenirButton_clicked\0"
    "on_souvenirBackButton_clicked\0"
    "on_pushButton_clicked\0"
    "on_SouvenirTableView_doubleClicked\0"
    "QModelIndex\0index\0on_addTeamButton_clicked\0"
    "on_showTeamsCombo_currentIndexChanged\0"
    "arg1\0on_teamMaintenanceTableView_doubleClicked\0"
    "on_distanceBackButton_clicked\0"
    "on_menuDistanceButton_clicked\0"
    "on_addDistancesButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_maintenance[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    1,   79,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      13,    1,   86,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void maintenance::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        maintenance *_t = static_cast<maintenance *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_MenuTeamButton_clicked(); break;
        case 1: _t->on_teamBackButton_clicked(); break;
        case 2: _t->on_menuSouvenirButton_clicked(); break;
        case 3: _t->on_souvenirBackButton_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_SouvenirTableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_addTeamButton_clicked(); break;
        case 7: _t->on_showTeamsCombo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_teamMaintenanceTableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_distanceBackButton_clicked(); break;
        case 10: _t->on_menuDistanceButton_clicked(); break;
        case 11: _t->on_addDistancesButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject maintenance::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_maintenance.data,
      qt_meta_data_maintenance,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *maintenance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *maintenance::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_maintenance.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int maintenance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
