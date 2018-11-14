#ifndef FANPAGE_H
#define FANPAGE_H

#include <QMainWindow>
#include "filesused.h"
#include "dbmanager.h"
#include <QVector>
#include <algorithm>

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
    void loadCapacity(QSqlQueryModel* modal);
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

    void on_easternConferenceRadio_clicked();

    void on_showAllConferenceRadio_clicked();

    void on_westernConferenceRadio_clicked();

    void on_teamTeamSortRadio_clicked();

    void on_teamArenaSortRadio_clicked();

    void on_teamCapacitySortRadio_clicked();

    void on_teamYearSortRadio_clicked();

    void on_divisionCombo_currentIndexChanged(const QString &arg1);

    void on_backArenaButton_clicked();

    void on_mainViewArenasButton_2_clicked();

    void on_backCoachButton_clicked();

private:
    Ui::fanpage *ui;
};

#endif // FANPAGE_H
