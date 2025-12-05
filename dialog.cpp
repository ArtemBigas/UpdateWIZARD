#include "dialog.h"
#include "ui_dialog.h"
#include <QStandardItemModel>
#include <QMessageBox>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->folder->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/res/Change.svg"));
    ui->plus->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/res/Add.svg"));
    ui->cross->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/res/Remove.svg"));
    grid();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    emit MainRequested();

}


void Dialog::on_buttonBox_rejected()
{
   emit MainRequested();
}

void Dialog::grid(){
    ui->grid->setViewType(Qtitan::Grid::TableView);


    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(3);
    model->setRowCount(0);


    model->setHeaderData(0, Qt::Horizontal, QStringLiteral("Серийный номер"));
    model->setHeaderData(1, Qt::Horizontal, QStringLiteral("ID ключа"));
    model->setHeaderData(2, Qt::Horizontal, QStringLiteral("Имя ключа"));


    Qtitan::GridTableView *view = ui->grid->view<Qtitan::GridTableView>();
    view->setModel(model);
}

void Dialog::on_plus_clicked()
{
 QMessageBox::warning(this, tr("Warning"), tr("Не реализовано"));
}


void Dialog::on_cross_clicked()
{
  QMessageBox::warning(this, tr("Warning"), tr("Не реализовано"));
}


void Dialog::on_folder_clicked()
{
  QMessageBox::warning(this, tr("Warning"), tr("Не реализовано"));
}


void Dialog::on_serial_number_clicked()
{
   QMessageBox::warning(this, tr("Warning"), tr("Не реализовано"));
}


void Dialog::on_importButton_clicked()
{
  QMessageBox::warning(this, tr("Warning"), tr("Не реализовано"));
}


void Dialog::on_checkButton_clicked()
{
    QMessageBox::warning(this, tr("Warning"), tr("Не реализовано"));
}

