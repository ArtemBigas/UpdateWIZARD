#include "myribbonwindow.h"
#include <QApplication>
#include <QScreen>
#include <QPushButton>
#include <QMessageBox>
#include <QStandardItemModel>

MyRibbonWindow::MyRibbonWindow(QWidget *parent)
    : Qtitan::RibbonMainWindow(parent)
{
    ui.setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect geom = screen->availableGeometry();
        resize(2 * geom.width() / 3, 2 * geom.height() / 3);
    }

    Refresh = new QPushButton("Обновить\nинформацию");
    Refresh->setFont(QFont("Arial", 14, QFont::Bold));
    Refresh->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/res/Update.svg"));
    Refresh->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui.Data->addWidget(Refresh);
    Download = new QPushButton("Скачать");
    Download->setFont(QFont("Arial", 14, QFont::Bold));
    Download->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/res/FileDownloading.svg"));
    ui.Data->addWidget(Download);
    Setting = new QPushButton("Настройки");
    Setting->setFont(QFont("Arial", 14, QFont::Bold));
    Setting->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/res/Settings.svg"));
    ui.Setting->addWidget(Setting);
    ListToDo = new QPushButton("Список\nзадач");
    ListToDo->setFont(QFont("Arial", 14, QFont::Bold));
    ListToDo->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/res/TaskList.svg"));
    ListToDo->setCheckable(true);
    ui.View->addWidget(ListToDo);
    WorkList = new QPushButton("Протокол\nработы");
    WorkList->setFont(QFont("Arial", 14, QFont::Bold));
    WorkList->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/res/Log.svg"));
    WorkList->setCheckable(true);
    ui.View->addWidget(WorkList);

    connect(Refresh, &QPushButton::clicked,this,&MyRibbonWindow::on_Refresh_clicked);
    connect(Download, &QPushButton::clicked,this,&MyRibbonWindow::on_Download_clicked);
    connect(Setting, &QPushButton::clicked,this,&MyRibbonWindow::on_Setting_clicked);
    connect(ListToDo, &QPushButton::clicked,this,&MyRibbonWindow::on_ListToDo_clicked);
    connect(WorkList, &QPushButton::clicked,this,&MyRibbonWindow::on_WorkList_clicked);
    // содержимое рабочей области
    database_widget=new Database(this);
    if (ui.tab_1->layout() == nullptr) {

        QVBoxLayout *layout = new QVBoxLayout();
        ui.tab_1->setLayout(layout);}
        ui.tab_1->layout()->addWidget(database_widget);
        database_widget->setFocus();

        product_widget=new Product(this);
        if (ui.tab_2->layout() == nullptr) {

            QVBoxLayout *layout = new QVBoxLayout();
            ui.tab_2->setLayout(layout);}
        ui.tab_2->layout()->addWidget(product_widget);
        product_widget->setFocus();


        setupDocking();
}


MyRibbonWindow::~MyRibbonWindow() {    delete dockManager;
}

void MyRibbonWindow::on_Setting_clicked()
{
    emit SettingRequested();

}
void MyRibbonWindow::on_Refresh_clicked()
{
QMessageBox::warning(this, tr("Warning"), tr("Не реализовано"));
}
void MyRibbonWindow::on_Download_clicked()
{
QMessageBox::warning(this, tr("Warning"), tr("Не реализовано"));
}

void MyRibbonWindow::on_ListToDo_clicked(){

    // Получаем tab‑виджет внутри panel:
    QTabWidget *tab = qobject_cast<QTabWidget*>( panel->widget() );

    int idxTask = -1, idxLog = -1;
    for (int i = 0; i < tab->count(); ++i) {
        QString t = tab->tabText(i);
        if (t == QStringLiteral("Список задач")) idxTask = i;
        else if (t == QStringLiteral("Протокол работы")) idxLog = i;
    }

    if (idxTask == -1 && idxLog == -1) {
        // Ни одной вкладки нет — создаём "Список задач" и показываем панель
        tab->addTab(new QWidget, QStringLiteral("Список задач"));
        panel->setWidget(tab);
        dockManager->showDockPanel(panel);
    }
    else if (idxTask >= 0 && idxLog >= 0) {
        // Есть обе вкладки — удаляем "Список задач"
        QWidget *w = tab->widget(idxTask);
        tab->removeTab(idxTask);
        delete w;
    }
    else if (idxTask >= 0 && idxLog < 0) {
        // Только "Список задач" — закрываем/скрываем панель
        QWidget *w = tab->widget(idxTask);
        tab->removeTab(idxTask);
        delete w;
        panel->closePanel();
    }
    else if (idxTask < 0 && idxLog >= 0) {
        // Есть только "Протокол работы" — добавляем "Список задач"
        tab->addTab(new QWidget, QStringLiteral("Список задач"));
    }
}

void MyRibbonWindow::on_WorkList_clicked(){
    // Получаем tab‑виджет внутри panel:
    QTabWidget *tab = qobject_cast<QTabWidget*>( panel->widget() );

    int idxTask = -1, idxLog = -1;
    for (int i = 0; i < tab->count(); ++i) {
        QString t = tab->tabText(i);
        if (t == QStringLiteral("Список задач")) idxTask = i;
        else if (t == QStringLiteral("Протокол работы")) idxLog = i;
    }
    if (idxTask == -1 && idxLog == -1) {
        tab->addTab(new QWidget, QStringLiteral("Протокол работы"));
        panel->setWidget(tab);
        dockManager->showDockPanel(panel);
    }
    else if (idxTask >= 0 && idxLog >= 0) {

        QWidget *w = tab->widget(idxLog);
        tab->removeTab(idxLog);
        delete w;
    }
    else if (idxLog >= 0 && idxTask < 0) {

        QWidget *w = tab->widget(idxLog);
        tab->removeTab(idxLog);
        delete w;
        panel->closePanel();
    }
    else if (idxLog < 0 && idxTask >= 0) {

        tab->addTab(new QWidget, QStringLiteral("Протокол работы"));
    }
}

void MyRibbonWindow::setupDocking(){
    dockManager = new Qtitan::DockPanelManager(this);

    //Док панель снизу
    dockManager->options().setDockPanelTransparentWhileDragging(true);
    dockManager->options().setArrowMarkersShown(true);
    dockManager->options().setDockPanelFullContentsWhileDraggingShown(true);

    dockManager->setCentralWidget( ui.centralwidget );
    panel = dockManager->addDockPanel(QStringLiteral("Panel 1"), Qtitan::BottomDockPanelArea);


    QTabWidget* tab = new QTabWidget;
    //tab->addTab(new QWidget, "Список задач");
    //tab->addTab(new QWidget, "Протокол работы");
    panel->setWidget(tab);
    panel->closePanel();
}
