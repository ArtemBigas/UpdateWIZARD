#ifndef SWITCH_H
#define SWITCH_H

#include <QDialog>

namespace Ui {
class Switch;
}

class Switch : public QDialog
{
    Q_OBJECT

public:
    explicit Switch(QWidget *parent = nullptr);
    ~Switch();
    void setMyRibbonWindow();
    void setDialog();

private:
    Ui::Switch *ui;
};

#endif // SWITCH_H
