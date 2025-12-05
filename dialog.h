#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void grid();
signals:
    void MainRequested();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_plus_clicked();

    void on_cross_clicked();

    void on_folder_clicked();

    void on_serial_number_clicked();

    void on_importButton_clicked();

    void on_checkButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
