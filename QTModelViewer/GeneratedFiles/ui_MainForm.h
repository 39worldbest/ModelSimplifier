/********************************************************************************
** Form generated from reading UI file 'MainForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainForm
{
public:
    QAction *action_open;
    QAction *action_save;
    QAction *action_saveAs;
    QAction *action_exit;
    QAction *action_close;
    QAction *action_holeFill;
    QAction *action_about;
    QAction *action_Segmentation;
    QAction *action_FillHole;
    QAction *action_Smooth;
    QAction *action_Simplify;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *colorVLayout;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *openGLVLayout;
    QCheckBox *chkAntiAliasing;
    QCheckBox *chkGourand;
    QCheckBox *chkLighting;
    QCheckBox *chkShowBackFace;
    QRadioButton *radPoint;
    QRadioButton *radLine;
    QRadioButton *radFace;
    QRadioButton *radFaceLine;
    QVBoxLayout *drawWidgetLayout;
    QGroupBox *groupBox;
    QCheckBox *chkRotation;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainForm)
    {
        if (CMainForm->objectName().isEmpty())
            CMainForm->setObjectName(QString::fromUtf8("CMainForm"));
        CMainForm->resize(756, 619);
        action_open = new QAction(CMainForm);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QtModelViewer/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon);
        action_save = new QAction(CMainForm);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/QtModelViewer/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon1);
        action_saveAs = new QAction(CMainForm);
        action_saveAs->setObjectName(QString::fromUtf8("action_saveAs"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/QtModelViewer/images/saveAs.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_saveAs->setIcon(icon2);
        action_exit = new QAction(CMainForm);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/QtModelViewer/images/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon3);
        action_close = new QAction(CMainForm);
        action_close->setObjectName(QString::fromUtf8("action_close"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/QtModelViewer/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_close->setIcon(icon4);
        action_holeFill = new QAction(CMainForm);
        action_holeFill->setObjectName(QString::fromUtf8("action_holeFill"));
        action_about = new QAction(CMainForm);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/QtModelViewer/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_about->setIcon(icon5);
        action_Segmentation = new QAction(CMainForm);
        action_Segmentation->setObjectName(QString::fromUtf8("action_Segmentation"));
        action_FillHole = new QAction(CMainForm);
        action_FillHole->setObjectName(QString::fromUtf8("action_FillHole"));
        action_Smooth = new QAction(CMainForm);
        action_Smooth->setObjectName(QString::fromUtf8("action_Smooth"));
        action_Simplify = new QAction(CMainForm);
        action_Simplify->setObjectName(QString::fromUtf8("action_Simplify"));
        centralWidget = new QWidget(CMainForm);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(180, 150));
        groupBox_3->setMaximumSize(QSize(180, 16777215));
        verticalLayoutWidget_5 = new QWidget(groupBox_3);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(9, 19, 161, 121));
        colorVLayout = new QVBoxLayout(verticalLayoutWidget_5);
        colorVLayout->setSpacing(6);
        colorVLayout->setContentsMargins(11, 11, 11, 11);
        colorVLayout->setObjectName(QString::fromUtf8("colorVLayout"));
        colorVLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(180, 250));
        groupBox_2->setMaximumSize(QSize(180, 16777215));
        verticalLayoutWidget_4 = new QWidget(groupBox_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 19, 160, 221));
        openGLVLayout = new QVBoxLayout(verticalLayoutWidget_4);
        openGLVLayout->setSpacing(6);
        openGLVLayout->setContentsMargins(11, 11, 11, 11);
        openGLVLayout->setObjectName(QString::fromUtf8("openGLVLayout"));
        openGLVLayout->setContentsMargins(0, 0, 0, 0);
        chkAntiAliasing = new QCheckBox(verticalLayoutWidget_4);
        chkAntiAliasing->setObjectName(QString::fromUtf8("chkAntiAliasing"));

        openGLVLayout->addWidget(chkAntiAliasing);

        chkGourand = new QCheckBox(verticalLayoutWidget_4);
        chkGourand->setObjectName(QString::fromUtf8("chkGourand"));

        openGLVLayout->addWidget(chkGourand);

        chkLighting = new QCheckBox(verticalLayoutWidget_4);
        chkLighting->setObjectName(QString::fromUtf8("chkLighting"));

        openGLVLayout->addWidget(chkLighting);

        chkShowBackFace = new QCheckBox(verticalLayoutWidget_4);
        chkShowBackFace->setObjectName(QString::fromUtf8("chkShowBackFace"));

        openGLVLayout->addWidget(chkShowBackFace);

        radPoint = new QRadioButton(verticalLayoutWidget_4);
        radPoint->setObjectName(QString::fromUtf8("radPoint"));

        openGLVLayout->addWidget(radPoint);

        radLine = new QRadioButton(verticalLayoutWidget_4);
        radLine->setObjectName(QString::fromUtf8("radLine"));

        openGLVLayout->addWidget(radLine);

        radFace = new QRadioButton(verticalLayoutWidget_4);
        radFace->setObjectName(QString::fromUtf8("radFace"));

        openGLVLayout->addWidget(radFace);

        radFaceLine = new QRadioButton(verticalLayoutWidget_4);
        radFaceLine->setObjectName(QString::fromUtf8("radFaceLine"));

        openGLVLayout->addWidget(radFaceLine);


        gridLayout->addWidget(groupBox_2, 1, 0, 2, 1);

        drawWidgetLayout = new QVBoxLayout();
        drawWidgetLayout->setSpacing(6);
        drawWidgetLayout->setObjectName(QString::fromUtf8("drawWidgetLayout"));

        gridLayout->addLayout(drawWidgetLayout, 0, 1, 4, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(180, 100));
        groupBox->setMaximumSize(QSize(180, 16777215));
        chkRotation = new QCheckBox(groupBox);
        chkRotation->setObjectName(QString::fromUtf8("chkRotation"));
        chkRotation->setGeometry(QRect(10, 20, 156, 16));

        gridLayout->addWidget(groupBox, 3, 0, 1, 1);

        CMainForm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CMainForm);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 756, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        CMainForm->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMainForm);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CMainForm->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CMainForm);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CMainForm->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(action_open);
        menu->addAction(action_save);
        menu->addAction(action_saveAs);
        menu->addAction(action_close);
        menu->addSeparator();
        menu->addAction(action_exit);
        menu_2->addAction(action_Segmentation);
        menu_2->addSeparator();
        menu_2->addAction(action_FillHole);
        menu_2->addAction(action_Smooth);
        menu_2->addAction(action_Simplify);
        menu_3->addAction(action_about);
        mainToolBar->addAction(action_open);
        mainToolBar->addAction(action_save);
        mainToolBar->addAction(action_saveAs);
        mainToolBar->addAction(action_close);
        mainToolBar->addAction(action_exit);
        mainToolBar->addAction(action_about);

        retranslateUi(CMainForm);

        QMetaObject::connectSlotsByName(CMainForm);
    } // setupUi

    void retranslateUi(QMainWindow *CMainForm)
    {
        CMainForm->setWindowTitle(QApplication::translate("CMainForm", "QtModelViewer", 0, QApplication::UnicodeUTF8));
        action_open->setText(QApplication::translate("CMainForm", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        action_save->setText(QApplication::translate("CMainForm", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        action_saveAs->setText(QApplication::translate("CMainForm", "\345\217\246\345\255\230\344\270\272", 0, QApplication::UnicodeUTF8));
        action_exit->setText(QApplication::translate("CMainForm", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_exit->setToolTip(QApplication::translate("CMainForm", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_close->setText(QApplication::translate("CMainForm", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_close->setToolTip(QApplication::translate("CMainForm", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_holeFill->setText(QApplication::translate("CMainForm", "\350\241\245\346\264\236", 0, QApplication::UnicodeUTF8));
        action_about->setText(QApplication::translate("CMainForm", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
        action_Segmentation->setText(QApplication::translate("CMainForm", "\345\210\206\345\211\262", 0, QApplication::UnicodeUTF8));
        action_FillHole->setText(QApplication::translate("CMainForm", "\350\241\245\346\264\236", 0, QApplication::UnicodeUTF8));
        action_FillHole->setShortcut(QApplication::translate("CMainForm", "Ctrl+H", 0, QApplication::UnicodeUTF8));
        action_Smooth->setText(QApplication::translate("CMainForm", "\345\205\211\351\241\272", 0, QApplication::UnicodeUTF8));
        action_Simplify->setText(QApplication::translate("CMainForm", "\347\273\206\345\210\206", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CMainForm", "\351\242\234\350\211\262", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CMainForm", "OpenGL", 0, QApplication::UnicodeUTF8));
        chkAntiAliasing->setText(QApplication::translate("CMainForm", "\345\217\215\351\224\257\351\275\277", 0, QApplication::UnicodeUTF8));
        chkGourand->setText(QApplication::translate("CMainForm", "Gourand\347\235\200\350\211\262", 0, QApplication::UnicodeUTF8));
        chkLighting->setText(QApplication::translate("CMainForm", "\345\205\211\347\205\247", 0, QApplication::UnicodeUTF8));
        chkShowBackFace->setText(QApplication::translate("CMainForm", "\346\230\276\347\244\272\350\203\214\351\235\242", 0, QApplication::UnicodeUTF8));
        radPoint->setText(QApplication::translate("CMainForm", "\347\202\271", 0, QApplication::UnicodeUTF8));
        radLine->setText(QApplication::translate("CMainForm", "\347\272\277", 0, QApplication::UnicodeUTF8));
        radFace->setText(QApplication::translate("CMainForm", "\351\235\242", 0, QApplication::UnicodeUTF8));
        radFaceLine->setText(QApplication::translate("CMainForm", "\351\235\242\347\272\277\346\267\267\345\220\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CMainForm", "\345\212\250\347\224\273", 0, QApplication::UnicodeUTF8));
        chkRotation->setText(QApplication::translate("CMainForm", "\346\227\213\350\275\254", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("CMainForm", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("CMainForm", "\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("CMainForm", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMainForm: public Ui_CMainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
