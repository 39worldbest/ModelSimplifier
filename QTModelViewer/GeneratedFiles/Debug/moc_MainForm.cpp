/****************************************************************************
** Meta object code from reading C++ file 'MainForm.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../MainForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CMainForm[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   10,   10,   10, 0x0a,
      67,   10,   10,   10, 0x0a,
      95,   10,   10,   10, 0x0a,
     122,   10,   10,   10, 0x0a,
     150,   10,   10,   10, 0x0a,
     177,   10,   10,   10, 0x0a,
     206,   10,   10,   10, 0x0a,
     241,   10,   10,   10, 0x0a,
     272,   10,   10,   10, 0x0a,
     303,   10,   10,   10, 0x0a,
     325,   10,   10,   10, 0x0a,
     346,   10,   10,   10, 0x0a,
     367,   10,   10,   10, 0x0a,
     398,  392,   10,   10, 0x0a,
     431,  392,   10,   10, 0x0a,
     468,  392,   10,   10, 0x0a,
     500,  392,   10,   10, 0x0a,
     533,  392,   10,   10, 0x0a,
     576,  570,   10,   10, 0x0a,
     618,  570,   10,   10, 0x0a,
     662,  570,   10,   10, 0x0a,
     706,  570,   10,   10, 0x0a,
     751,  570,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CMainForm[] = {
    "CMainForm\0\0chkRotationStateChanged(int)\0"
    "on_action_exit_triggered()\0"
    "on_action_about_triggered()\0"
    "on_action_open_triggered()\0"
    "on_action_close_triggered()\0"
    "on_action_save_triggered()\0"
    "on_action_saveAs_triggered()\0"
    "on_action_Segmentation_triggered()\0"
    "on_action_FillHole_triggered()\0"
    "on_action_Simplify_triggered()\0"
    "on_radPoint_clicked()\0on_radLine_clicked()\0"
    "on_radFace_clicked()\0on_radFaceLine_clicked()\0"
    "state\0on_chkLighting_stateChanged(int)\0"
    "on_chkAntiAliasing_stateChanged(int)\0"
    "on_chkGourand_stateChanged(int)\0"
    "on_chkRotation_stateChanged(int)\0"
    "on_chkShowBackFace_stateChanged(int)\0"
    "color\0on_backgroundColorEdit_colorChanged(QRgb)\0"
    "on_lightAmbientColorEdit_colorChanged(QRgb)\0"
    "on_lightDiffuseColorEdit_colorChanged(QRgb)\0"
    "on_lightSpecularColorEdit_colorChanged(QRgb)\0"
    "on_foregroundColorEdit_colorChanged(QRgb)\0"
};

void CMainForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CMainForm *_t = static_cast<CMainForm *>(_o);
        switch (_id) {
        case 0: _t->chkRotationStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_action_exit_triggered(); break;
        case 2: _t->on_action_about_triggered(); break;
        case 3: _t->on_action_open_triggered(); break;
        case 4: _t->on_action_close_triggered(); break;
        case 5: _t->on_action_save_triggered(); break;
        case 6: _t->on_action_saveAs_triggered(); break;
        case 7: _t->on_action_Segmentation_triggered(); break;
        case 8: _t->on_action_FillHole_triggered(); break;
        case 9: _t->on_action_Simplify_triggered(); break;
        case 10: _t->on_radPoint_clicked(); break;
        case 11: _t->on_radLine_clicked(); break;
        case 12: _t->on_radFace_clicked(); break;
        case 13: _t->on_radFaceLine_clicked(); break;
        case 14: _t->on_chkLighting_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_chkAntiAliasing_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_chkGourand_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_chkRotation_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_chkShowBackFace_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_backgroundColorEdit_colorChanged((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        case 20: _t->on_lightAmbientColorEdit_colorChanged((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        case 21: _t->on_lightDiffuseColorEdit_colorChanged((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        case 22: _t->on_lightSpecularColorEdit_colorChanged((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        case 23: _t->on_foregroundColorEdit_colorChanged((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CMainForm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CMainForm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CMainForm,
      qt_meta_data_CMainForm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CMainForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CMainForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CMainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CMainForm))
        return static_cast<void*>(const_cast< CMainForm*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CMainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void CMainForm::chkRotationStateChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_ColorEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ColorEdit[] = {
    "ColorEdit\0\0color\0colorChanged(QRgb)\0"
};

void ColorEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ColorEdit *_t = static_cast<ColorEdit *>(_o);
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ColorEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ColorEdit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ColorEdit,
      qt_meta_data_ColorEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ColorEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ColorEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ColorEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorEdit))
        return static_cast<void*>(const_cast< ColorEdit*>(this));
    return QWidget::qt_metacast(_clname);
}

int ColorEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ColorEdit::colorChanged(QRgb _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
