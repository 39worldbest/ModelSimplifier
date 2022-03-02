/********************************************************************************
** Form generated from reading UI file 'AboutForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTFORM_H
#define UI_ABOUTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CAboutForm
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QPushButton *okButton;

    void setupUi(QDialog *CAboutForm)
    {
        if (CAboutForm->objectName().isEmpty())
            CAboutForm->setObjectName(QString::fromUtf8("CAboutForm"));
        CAboutForm->resize(400, 267);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CAboutForm->sizePolicy().hasHeightForWidth());
        CAboutForm->setSizePolicy(sizePolicy);
        CAboutForm->setModal(false);
        horizontalLayoutWidget = new QWidget(CAboutForm);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 371, 201));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/QtModelViewer/images/about.png")));

        horizontalLayout->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        okButton = new QPushButton(CAboutForm);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(170, 230, 75, 23));

        retranslateUi(CAboutForm);

        QMetaObject::connectSlotsByName(CAboutForm);
    } // setupUi

    void retranslateUi(QDialog *CAboutForm)
    {
        CAboutForm->setWindowTitle(QApplication::translate("CAboutForm", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label->setText(QApplication::translate("CAboutForm", "\344\270\211\347\273\264\347\275\221\347\273\234\346\250\241\345\236\213\345\271\263\345\217\260  \347\211\210\346\234\2541.0     \n"
"\347\211\210\346\235\203\346\211\200\346\234\211 (C) 2011\n"
"", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("CAboutForm", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CAboutForm: public Ui_CAboutForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTFORM_H
