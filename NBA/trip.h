#ifndef TRIP_H
#define TRIP_H

#include <QMainWindow>
#include "dbmanager.h"
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QSpinBox>
#include <QStyledItemDelegate>

namespace Ui {
class trip;
}

class trip : public QMainWindow
{
    Q_OBJECT
    friend class fanpage;
public:
    explicit trip(QWidget *parent = 0);
    explicit trip(QWidget *parent, QVector<QString> teams);
    explicit trip(QWidget *parent, QVector<QString> teams, QVector<QString> teamsVisited);
    void loadSouvenirs(QString team);
    void loadTotalDistance(double distance);
    void loadTeamVisited(QString team);
    void loadArenas(QString team);
    void displayBFS();
    void displayDFS();
    ~trip();

private slots:
    void on_tripButton_clicked();

    void on_souvenirsTable_doubleClicked(const QModelIndex &index);

    void displayInfo();

private:
    Ui::trip *ui;
    int teamCount;
    double totalDistance;
    QVector<QString> teams;
    QVector<QString> teamsVisited;
};

#endif // TRIP_H
