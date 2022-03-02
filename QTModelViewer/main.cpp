#include "stdafx.h"
#include "MainForm.h"
#include <QtGui/QApplication>
#include <tchar.h>
//#include <BugTrap.h>

//#pragma comment(lib, "BugTrapU.lib")  // Link to Unicode DLL

//void SetupExceptionHandler()
//{
//	BT_InstallSehFilter();
//	BT_SetFlags(BTF_DETAILEDMODE | BTF_EDITMAIL |BTF_ATTACHREPORT 
//		| BTF_SCREENCAPTURE | BTF_LISTPROCESSES);
//	BT_SetDialogMessage(BTDM_INTRO1, _T("�ܱ�Ǹ������������һ��δ֪����"));
//	wstring errorMessage(_T("Ϊ�˰��������������󣬳��������ռ���صĴ�����״̬��Ϣ��"));
//	errorMessage += _T("������ѡ����Щ��Ϣ���͸����ǣ����߱��浽�ļ���");
//	BT_SetDialogMessage(BTDM_INTRO2, errorMessage.c_str());
//}

int main(int argc, char *argv[])
{
	//SetupExceptionHandler();

	QApplication a(argc, argv);

	QString sPath = a.applicationDirPath();
	sPath += QString("/plugins");
	a.addLibraryPath(sPath);

	QTextCodec *codec = QTextCodec::codecForName("gb2312");
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);

	CMainForm w;
  w.move((QApplication::desktop()->width() - w.width())/2,
		(QApplication::desktop()->height() - w.height())/2);
	//w.show();
	w.showMaximized();
	return a.exec();
}
