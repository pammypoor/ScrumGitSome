#ifndef FANPAGE_H
#define FANPAGE_H

#include <QMainWindow>
#include "filesused.h"
#include "dbmanager.h"

namespace Ui {
class fanpage;
}

class fanpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit fanpage(QWidget *parent = 0);
    void loadAllSouvenirs();
    void loadAllTeams();
    ~fanpage();

private slots:

    void on_mainPlanTripButton_clicked();

    void on_mainViewSouvenirsButton_clicked();

    void on_mainViewTeamsButton_clicked();

    void on_mainViewArenasButton_clicked();

    void on_backSouvenirButton_clicked();

    void on_teamNameSouvenirCombo_currentIndexChanged(const QString &arg1);

    void on_backTeamButton_clicked();

    void on_teamNameTeamCombo_currentIndexChanged(const QString &arg1);

private:
    Ui::fanpage *ui;
};

#endif // FANPAGE_H
