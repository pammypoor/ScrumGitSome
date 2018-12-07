#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "filesused.h"
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QFile>
#include <QInputDialog>
#include <vector>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QSpinBox>

struct souvenir
{
    QString name;
    double cost;
    QString team;
};

struct team
{
    QString conference;
    QString division;
    QString teamname;
    QString location;
    QString arena;
    int capacity;
    int year;
    QString coach;
};

class DbManager
{
public:
    ~DbManager();
    static DbManager& instance();
    bool isOpen() const;
    QString LoginCheck(QString username, QString password);

    bool addSouvenir(souvenir newSouvenir);
    QSqlQueryModel* toTableSouvenir();
    bool souvenirExist(souvenir aSouvenir);
    void deleteSouvenir(souvenir aSouvenir);
    void editSouvenir(souvenir aSouvenir, double newPrice);
    QSqlQueryModel* getTeamSouvenir(QString team);
    QString getArena(QString teamName);

    QStringList getTeams();
    bool addTeam(team newTeam);
    bool teamExist(team aTeam);
    QSqlQueryModel* toTableSingleTeamSouvenirs(QString team);

    QSqlQueryModel* getSingleTeam(QString teamName);
    QVector<QString> getFromTeams();
    QVector<QString> getToTeams();
    QVector<double>  getWeights();
    int              getNumOfTeams();

    void updateArena(team aTeam, QString newArena);
    void updateCapacity(team aTeam, int newCapacity);

    QSqlQueryModel* toTableTeam();
    QSqlQueryModel* toTableTeamName();
    QSqlQueryModel* toTableTeambyArena();
    QSqlQueryModel* toTableTeambyCapacity();
    QSqlQueryModel* toTableTeambyYear();

    QSqlQueryModel* getDivision(QString division, QString sort);
    QSqlQueryModel* getConference(QString conference, QString sort);

    QSqlQueryModel* toTableDistances();
    bool addDistance(QString bTeam, QString bArena, QString eTeam, double distance);

private:
    QSqlDatabase database;
    DbManager();
    DbManager(const DbManager& database);
};

#endif // DBMANAGER_H
