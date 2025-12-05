#include "switch.h"
#include "ui_switch.h"

Switch::Switch(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Switch)
{
    ui->setupUi(this);
    connect(ui->main, &MyRibbonWindow::SettingRequested,this, &Switch::setDialog);
    QObject::connect(ui->setting, &Dialog::MainRequested,this, &Switch::setMyRibbonWindow);

}

Switch::~Switch()
{
    delete ui;
}
void Switch::setMyRibbonWindow()

{
    QWidget* widget = findChild<QWidget*>("main");
    ui->stackedWidget->setCurrentWidget(widget);
}

void Switch::setDialog()

{
    QWidget* widget = findChild<QWidget*>("setting");
    ui->stackedWidget->setCurrentWidget(widget);
}
