#include <QApplication>
//#include "myribbonwindow.h"
#include "switch.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Switch w;
    w.setWindowTitle("Update Wizard");
    w.setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/res/UpdateWIZARD.ico"));
    w.show();
    return app.exec();
}
