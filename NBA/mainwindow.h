#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
#include "maintenance.h"
#include "fanpage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_logOnPushButton_clicked();

    void on_showPassword_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    maintenance* adminPage;
    fanpage* fanPage;
};

#endif // MAINWINDOW_H
