#pragma once
#include "StdAfx.h"
#include "GeneratedFiles/ui_AboutForm.h"

class CAboutForm : public QDialog
{
Q_OBJECT

public:
	CAboutForm(QWidget *parent = 0,Qt::WFlags flags = 0);
private:
	Ui::CAboutForm ui;

public slots:
		void on_okButton_clicked();
};
