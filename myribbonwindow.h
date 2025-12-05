#ifndef MYRIBBONWINDOW_H
#define MYRIBBONWINDOW_H

#include <QtnRibbonMainWindow.h>
#include <DevMachines/QtitanDocking>
#include "ui_myribbonwindow.h"
#include "database.h"
#include "product.h"


/* MyRibbonWindow */
class MyRibbonWindow : public Qtitan::RibbonMainWindow
{
    Q_OBJECT
public:
    MyRibbonWindow(QWidget *parent = Q_NULL);
    virtual ~MyRibbonWindow();
    void on_Refresh_clicked();
    void on_Download_clicked();
     void setupDocking();
    void on_ListToDo_clicked();
     void on_WorkList_clicked();
signals:
    void SettingRequested();

    private slots:
    void on_Setting_clicked();
private:
    Ui::MyRibbonWindow ui;
    QPushButton *Refresh;
    QPushButton *Download;
    QPushButton *Setting;
    QPushButton *ListToDo;
    QPushButton *WorkList;
    Database*database_widget;
    Product*product_widget;
    Qtitan::DockPanelManager *dockManager;
    Qtitan::DockWidgetPanel* panel;

};

#endif // MYRIBBONWINDOW_H
