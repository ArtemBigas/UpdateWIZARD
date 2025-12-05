#include "database.h"
#include "ui_database.h"
#include <QStandardItemModel>
#include <QStandardItem>

Database::Database(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Database)
{
    ui->setupUi(this);
    treegrid();
}

Database::~Database()
{
    delete ui;
}

void Database::treegrid()
{
    ui->treeGrid->setViewType(Qtitan::TreeGrid::TreeView);


    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(4);


    model->setHeaderData(0, Qt::Horizontal, QStringLiteral("Наименование базы"));
    model->setHeaderData(1, Qt::Horizontal, QStringLiteral("Регион"));
    model->setHeaderData(2, Qt::Horizontal, QStringLiteral("Дата обновления"));
    model->setHeaderData(3, Qt::Horizontal, QStringLiteral("Регион"));


    QStandardItem *rootItem = new QStandardItem(QStringLiteral("SmetaWIZARD4"));

    for (int col = 1; col < 4; ++col)
        rootItem->setChild(0, col, new QStandardItem(QString()));
//пустышки для корня. Без них проблема с отображением
    model->appendRow({ rootItem,
                      new QStandardItem(),
                      new QStandardItem(),
                      new QStandardItem() });


    QStandardItem *child_1 = new QStandardItem(QStringLiteral("государственные"));
    QList<QStandardItem*> child1Row;
    child1Row << child_1;
    for (int i = 1; i < model->columnCount(); ++i) {
        child1Row << new QStandardItem();
    }
    rootItem->appendRow(child1Row);

    QStandardItem *child_1_1_col1 = new QStandardItem(QStringLiteral("1984 прейскуранты v4.0"));
    QStandardItem *child_1_1_col2 = new QStandardItem(QStringLiteral("#"));
    QStandardItem *child_1_1_col3 = new QStandardItem(QStringLiteral("15.08.2022"));
     QStandardItem *child_1_1_col4 = new QStandardItem(QStringLiteral("#"));
    // для остальных колонок — пустышки
    QList<QStandardItem*> child11Row;
    child11Row << child_1_1_col1 << child_1_1_col2<< child_1_1_col3<< child_1_1_col4;

    child_1->appendRow(child11Row);

    QStandardItem *child_1_2_col1 = new QStandardItem(QStringLiteral("1984 доп. к ерер, вып. 1, 2, 3"));
    QStandardItem *child_1_2_col2 = new QStandardItem(QStringLiteral("Ленинград"));
    QStandardItem *child_1_2_col3 = new QStandardItem(QStringLiteral("30.01.2022"));
    QStandardItem *child_1_2_col4 = new QStandardItem(QStringLiteral("#"));
    // для остальных колонок — пустышки
    QList<QStandardItem*> child12Row;
    child12Row << child_1_2_col1 << child_1_2_col2<< child_1_2_col3<< child_1_2_col4;

    child_1->appendRow(child12Row);


    Qtitan::GridTreeView *view = ui->treeGrid->view<Qtitan::GridTreeView>();
    view->setModel(model);
    view->expandToLevel(1);
}
