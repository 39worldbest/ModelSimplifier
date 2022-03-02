#pragma once
#include "StdAfx.h"

#include "GeneratedFiles/ui_MainForm.h"
#include "AboutForm.h"
#include "DrawWidget.h"

class ColorEdit;

class CMainForm : public QMainWindow
{
	Q_OBJECT
public:
	CMainForm(QWidget *parent = 0, Qt::WFlags flags = 0);
	~CMainForm();

private:
	Ui::CMainForm ui;
	ColorEdit *backgroundColorEdit;
	ColorEdit *lightAmbientColorEdit;
	ColorEdit *lightDiffuseColorEdit;
	ColorEdit *lightSpecularColorEdit;
	ColorEdit *foregroundColorEdit;
	CDrawWidget *drawWidget;
	QHBoxLayout *layoutColor;
	QHBoxLayout *layoutLight;
	QHBoxLayout *layoutFront;

	MyMesh* mesh;

private:
	void InitOptions();
	void SaveOptions();
	void InitUI();

signals:
	void chkRotationStateChanged(int);
  
public slots:
	void on_action_exit_triggered();
	void on_action_about_triggered();
	void on_action_open_triggered();
	void on_action_close_triggered();
	void on_action_save_triggered();
	void on_action_saveAs_triggered();
	void on_action_Segmentation_triggered();
	void on_action_FillHole_triggered();
	void on_action_Simplify_triggered();

	void on_radPoint_clicked();
	void on_radLine_clicked();
	void on_radFace_clicked();
	void on_radFaceLine_clicked();
	void on_chkLighting_stateChanged(int state);
	void on_chkAntiAliasing_stateChanged(int state);
	void on_chkGourand_stateChanged(int state);
	void on_chkRotation_stateChanged(int state);
	void on_chkShowBackFace_stateChanged(int state);
	
	void on_backgroundColorEdit_colorChanged(QRgb color);
	void on_lightAmbientColorEdit_colorChanged(QRgb color);
	void on_lightDiffuseColorEdit_colorChanged(QRgb color);
	void on_lightSpecularColorEdit_colorChanged(QRgb color);
	void on_foregroundColorEdit_colorChanged(QRgb color);
};

//自定义的颜色选择控件
class ColorEdit : public QWidget
{
	Q_OBJECT
public:
	ColorEdit(QRgb initialColor);
	virtual ~ColorEdit();
	QRgb color() const {return m_color;}
	virtual void emitChange() {emit colorChanged(m_color);}
signals:
	void colorChanged(QRgb color);
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	void setColor(QRgb color);
private:
	QGraphicsScene *m_dialogParentScene;
	QFrame *m_button;
	QRgb m_color;
	QHBoxLayout *layout;
};

