#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QMainWindow>
#include <QFileDialog>
#include <QAxObject>
#include "filesused.h"
#include "dbmanager.h"
#include <algorithm>
#include <cctype>
#include <string>

namespace Ui {
class maintenance;
}

class maintenance : public QMainWindow
{
    Q_OBJECT

public:
    explicit maintenance(QWidget *parent = 0);
    void loadSouvenirData();
    void loadTeamData();
    ~maintenance();

private slots:
    void on_MenuTeamButton_clicked();

    void on_teamBackButton_clicked();

    void on_menuSouvenirButton_clicked();

    void on_souvenirBackButton_clicked();

    void on_pushButton_clicked();

    void on_SouvenirTableView_doubleClicked(const QModelIndex &index);

    void on_addTeamButton_clicked();

    void on_showTeamsCombo_currentIndexChanged(const QString &arg1);

    void on_teamMaintenanceTableView_doubleClicked(const QModelIndex &index);

private:
    Ui::maintenance *ui;
};

#endif // MAINTENANCE_H
