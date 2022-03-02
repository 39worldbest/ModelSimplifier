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
//	BT_SetDialogMessage(BTDM_INTRO1, _T("很抱歉，程序遇到了一个未知错误！"));
//	wstring errorMessage(_T("为了帮助我们修正错误，程序将试着收集相关的错误与状态信息。"));
//	errorMessage += _T("您可以选择将这些信息发送给我们，或者保存到文件。");
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
