/****************************************************************************
** Meta object code from reading C++ file 'notepad.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../notepad.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notepad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_notepad_t {
    QByteArrayData data[12];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_notepad_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_notepad_t qt_meta_stringdata_notepad = {
    {
QT_MOC_LITERAL(0, 0, 7), // "notepad"
QT_MOC_LITERAL(1, 8, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "on_actionopen_triggered"
QT_MOC_LITERAL(4, 56, 23), // "on_actionsave_triggered"
QT_MOC_LITERAL(5, 80, 26), // "on_actionSave_AS_triggered"
QT_MOC_LITERAL(6, 107, 22), // "on_actioncut_triggered"
QT_MOC_LITERAL(7, 130, 23), // "on_actionCopy_triggered"
QT_MOC_LITERAL(8, 154, 24), // "on_actionPaste_triggered"
QT_MOC_LITERAL(9, 179, 23), // "on_actionRedo_triggered"
QT_MOC_LITERAL(10, 203, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(11, 227, 32) // "on_actionabout_notepad_triggered"

    },
    "notepad\0on_actionNew_triggered\0\0"
    "on_actionopen_triggered\0on_actionsave_triggered\0"
    "on_actionSave_AS_triggered\0"
    "on_actioncut_triggered\0on_actionCopy_triggered\0"
    "on_actionPaste_triggered\0"
    "on_actionRedo_triggered\0on_actionUndo_triggered\0"
    "on_actionabout_notepad_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_notepad[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void notepad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        notepad *_t = static_cast<notepad *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionNew_triggered(); break;
        case 1: _t->on_actionopen_triggered(); break;
        case 2: _t->on_actionsave_triggered(); break;
        case 3: _t->on_actionSave_AS_triggered(); break;
        case 4: _t->on_actioncut_triggered(); break;
        case 5: _t->on_actionCopy_triggered(); break;
        case 6: _t->on_actionPaste_triggered(); break;
        case 7: _t->on_actionRedo_triggered(); break;
        case 8: _t->on_actionUndo_triggered(); break;
        case 9: _t->on_actionabout_notepad_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject notepad::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_notepad.data,
      qt_meta_data_notepad,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *notepad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *notepad::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_notepad.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int notepad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
