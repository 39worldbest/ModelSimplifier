#include "StdAfx.h"
#include "AboutForm.h"

CAboutForm::CAboutForm( QWidget* parent ,Qt::WFlags) : QDialog( parent )
{
	ui.setupUi(this);
}

void CAboutForm::on_okButton_clicked()
{
	this->close();
}
