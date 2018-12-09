#ifndef FANPAGE_H
#define FANPAGE_H

#include <QMainWindow>
#include "filesused.h"
#include "dbmanager.h"
#include <QVector>
#include <algorithm>
#include "graph.h"
#include "trip.h"

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
    void loadPlanTeams();
    void loadCapacity(QSqlQueryModel* modal);
    QVector<QString> getTripTeams() {return tripTeams;}
    double getDistanceTrip(QVector<QString> teams);
    QVector<QString> shortestTrip(QVector<QString> teams);
    ~fanpage();

private slots:

    void on_mainPlanTripButton_clicked();
    //fills the graph in with the distances from the database
    void populateGraph();

    void on_mainViewSouvenirsButton_clicked();

    void on_mainViewTeamsButton_clicked();

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


    void on_backTripButton_clicked();

    void on_planTripTable_activated(const QModelIndex &index);

    void on_tripButton_clicked();

    void on_shortestTripButton_clicked();

    void on_selectedTeamsTable_cellChanged(int row, int column);

    void on_minimumSpanTreeButton_clicked();

    void on_bfsButton_clicked();

    void on_dfsButton_clicked();

    QVector<QString> getTripInFanOrder();

    void ShortestPath(int start, int end, int finish, QVector<QString>& path, double& totalCost);


    void on_checkBox_stateChanged(int arg1);

private:
    Ui::fanpage *ui;
    QVector<QString> tripTeams;
    QVector<souvenir> fanSouvenirs;
    Graph<QString, double> *myGraph;
    trip* tripPage;

    //For recursive user specific path
    int grandTotalForUserSpecificPath;
};

#endif // FANPAGE_H
