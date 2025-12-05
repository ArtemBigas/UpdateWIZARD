/********************************************************************************
** Form generated from reading UI file 'myribbonwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYRIBBONWINDOW_H
#define UI_MYRIBBONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "DevMachines/QtitanRibbon"

QT_BEGIN_NAMESPACE

class Ui_MyRibbonWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *tab_2;
    RibbonBar *ribbonBar;
    RibbonPage *homePage;
    RibbonGroup *Data;
    RibbonGroup *Setting;
    RibbonGroup *View;

    void setupUi(RibbonMainWindow *MyRibbonWindow)
    {
        if (MyRibbonWindow->objectName().isEmpty())
            MyRibbonWindow->setObjectName("MyRibbonWindow");
        MyRibbonWindow->resize(480, 360);
        centralwidget = new QWidget(MyRibbonWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab_1 = new QWidget();
        tab_1->setObjectName("tab");
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        MyRibbonWindow->setCentralWidget(centralwidget);
        ribbonBar = new RibbonBar(MyRibbonWindow);
        ribbonBar->setObjectName("ribbonBar");
        homePage = new RibbonPage(ribbonBar);
        homePage->setObjectName("homePage");
        homePage->setGeometry(QRect(0, 44, 480, 92));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(homePage->sizePolicy().hasHeightForWidth());
        homePage->setSizePolicy(sizePolicy);
        homePage->setMaximumSize(QSize(480, 92));
        Data = new RibbonGroup(homePage);
        Data->setObjectName("Data");
        Data->setGeometry(QRect(1, 1, 48, 90));
        sizePolicy.setHeightForWidth(Data->sizePolicy().hasHeightForWidth());
        Data->setSizePolicy(sizePolicy);
        QFont font;
        font.setKerning(true);
        Data->setFont(font);
        Data->setAcceptDrops(false);
        homePage->addGroup(Data);
        Setting = new RibbonGroup(homePage);
        Setting->setObjectName("Setting");
        Setting->setGeometry(QRect(49, 1, 44, 90));
        homePage->addGroup(Setting);
        View = new RibbonGroup(homePage);
        View->setObjectName("View");
        View->setGeometry(QRect(93, 1, 37, 90));
        homePage->addGroup(View);
        ribbonBar->addPage(homePage);
        MyRibbonWindow->setMenuBar(ribbonBar);

        retranslateUi(MyRibbonWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyRibbonWindow);
    } // setupUi

    void retranslateUi(RibbonMainWindow *MyRibbonWindow)
    {
        MyRibbonWindow->setWindowTitle(QCoreApplication::translate("MyRibbonWindow", "MyRibbonWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("MyRibbonWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MyRibbonWindow", "Tab 2", nullptr));
        homePage->setWindowTitle(QString());
        homePage->setTitle(QCoreApplication::translate("MyRibbonWindow", "&\320\223\320\273\320\260\320\262\320\275\320\260\321\217", nullptr));
        Data->setTitle(QCoreApplication::translate("MyRibbonWindow", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
        Setting->setTitle(QCoreApplication::translate("MyRibbonWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        View->setTitle(QCoreApplication::translate("MyRibbonWindow", "\320\222\320\270\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyRibbonWindow: public Ui_MyRibbonWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYRIBBONWINDOW_H
