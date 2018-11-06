#include "dbmanager.h"

DbManager::DbManager()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(Path_to_DB);
    database.setConnectOptions(Path_to_DB);

    if(QFile::exists(Path_to_DB))
    {
        if(!database.open())
        {
            qDebug() << "Error: Connection Failed.";
        }
        else
        {
            qDebug() << "Database connection successful.";
        }
    }
}

DbManager::~DbManager()
{
    if(database.isOpen())
        database.close();
}

bool DbManager::isOpen() const
{
    return database.isOpen();
}

QString DbManager::LoginCheck(QString username, QString password)
{
    QSqlQuery query;
    query.prepare("SELECT username, password, type FROM login WHERE username = (:username)");
    query.bindValue(":username", username);

    if(query.exec())
        {
            int passID = query.record().indexOf("password");
            int typeID = query.record().indexOf("type");

            if(query.next())
            {
                if(query.value(passID).toString() == password)
                {
                     return query.value(typeID).toString();
                }
                else
                {
                   qDebug() << "Password is wrong.";
                   return NULL;
                }
            }
        }
    else
    {
        qDebug() << "Username does not exist.";
    }
    return NULL;
}

DbManager& DbManager::instance()
{
    static DbManager dmInstance;
    return dmInstance;
}

bool DbManager::addSouvenir(souvenir newSouvenir)
{
    if(newSouvenir.name.isEmpty() || newSouvenir.cost == 0.00 || newSouvenir.team.isEmpty())
    {
        qDebug() << "Cannot create a client record if any of their information is not filled";
        return false;
    }

    if(souvenirExist(newSouvenir))
    {
        qDebug() << "Souvenir Exists";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO souvenirs(name, cost, team) VALUES(:name, :cost, :team)");
    query.bindValue(":name", newSouvenir.name);
    query.bindValue(":cost", newSouvenir.cost);
    query.bindValue(":team", newSouvenir.team);

    if(query.exec())
    {
        qDebug() << "Souvenir added.";
        return true;
    }
    else
    {
        qDebug() << "Add souvenir failed.";
        return false;
    }
}

QSqlQueryModel* DbManager::toTableSouvenir()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery("SELECT name, cost, team FROM souvenirs ORDER BY team ASC;");
    return modal;
}

bool DbManager::souvenirExist(souvenir aSouvenir)
{
    bool exists = false;
    QSqlQuery query;
    QString name = aSouvenir.name;
    QString team = aSouvenir.team;

    query.prepare("SELECT name FROM souvenirs WHERE name=:name AND team=:team;");
    query.bindValue(":name", name);
    query.bindValue(":team", team);

    if(query.exec())
    {
        if(query.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Souvenir already exists.";
    }
    return exists;
}

void DbManager::deleteSouvenir(souvenir aSouvenir)
{
    QSqlQuery query;

    if(souvenirExist(aSouvenir))
    {
        query.prepare("DELETE FROM souvenirs WHERE name = (:name) AND team = (:team);");
        query.bindValue(":name", aSouvenir.name);
        query.bindValue(":team", aSouvenir.team);

        if( query.exec() )
        {
            qDebug() << "Souvenir deleted!";
        }
        else
        {
            qDebug() << "Delete Souvenir failed";
        }
    }
}

void DbManager::editSouvenir(souvenir aSouvenir, double newPrice)
{
    QSqlQuery query;
    query.prepare("UPDATE souvenirs SET cost=:cost WHERE name=:name AND team=:team;");
    query.bindValue(":cost", newPrice);
    query.bindValue(":name", aSouvenir.name);
    query.bindValue(":team", aSouvenir.team);
\
    if(query.exec())
    {
        qDebug() << "Souvenir edited.";
    }
    else
    {
        qDebug() << "Souvenir does not exist";
    }
}

QStringList DbManager::getTeams()
{
    QSqlQuery query;
    QStringList lst;
    query.prepare("SELECT team FROM teams ORDER BY team ASC;");
    if(query.exec())
    {
        qDebug() << "Teams successfully added to combo box.";
    }
    while(query.next())
    {
        lst << query.value(0).toString();
    }
    return lst;
}

bool DbManager::addTeam(team newTeam)
{
    if(teamExist(newTeam))
    {
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO teams(conference, division, team, location, arena, capacity, year, coach) VALUES(:conference, :division, :team, :location, :arena, :capacity, :year, :coach)");
    query.bindValue(":conference", newTeam.conference);
    query.bindValue(":division", newTeam.division);
    query.bindValue(":team", newTeam.teamname);
    query.bindValue(":location", newTeam.location);
    query.bindValue(":arena", newTeam.arena);
    query.bindValue(":capacity", newTeam.capacity);
    query.bindValue(":year", newTeam.year);
    query.bindValue(":coach", newTeam.coach);

    if(query.exec())
    {
        qDebug() << "Team added.";
    }
    else
    {
        qDebug() << "Add team failed.";
        return false;
    }

    souvenir newBasketball;
    newBasketball.name = "Autographed Basketball";
    newBasketball.cost = 49.89;
    newBasketball.team = newTeam.teamname;

    souvenir newPennant;
    newPennant.name = "Team Pennant";
    newPennant.cost = 17.99;
    newPennant.team = newTeam.teamname;

    souvenir newPicture;
    newPicture.name = "Team Picture";
    newPicture.cost = 29.99;
    newPicture.team = newTeam.teamname;

    souvenir newJersey;
    newJersey.name = "Team Jersey";
    newJersey.cost = 179.99;
    newJersey.team = newTeam.teamname;

    DbManager::instance().addSouvenir(newBasketball);
    DbManager::instance().addSouvenir(newPennant);
    DbManager::instance().addSouvenir(newPicture);
    DbManager::instance().addSouvenir(newJersey);
}

bool DbManager::teamExist(team aTeam)
{
    bool exists = false;
    QSqlQuery query;
    QString name = aTeam.teamname;

    query.prepare("SELECT team FROM teams WHERE team=:name;");
    query.bindValue(":name", name);

    if(query.exec())
    {
        if(query.next())
        {
            exists = true;
        }
    }
    return exists;
}

QSqlQueryModel* DbManager::toTableSingleTeamSouvenirs(QString team)
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QString queryString = "SELECT * FROM souvenirs WHERE team = '" + team + "' ORDER BY name ASC;";
    modal->setQuery(queryString);
    return modal;
}

QSqlQueryModel* DbManager::toTableTeam()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery("SELECT * FROM teams ORDER BY team ASC;");
    return modal;
}

void DbManager::updateArena(team aTeam, QString newArena)
{
    QSqlQuery query;
    query.prepare("UPDATE teams SET arena=:arena WHERE team=:team");
    query.bindValue(":team", aTeam.teamname);
    query.bindValue(":arena", newArena);
    if(query.exec())
    {
        qDebug() << "Arena name updated.";
    }
    else
    {
        qDebug() << "Update arena failed.";
    }
}

void DbManager::updateCapacity(team aTeam, int newCapacity)
{
    QSqlQuery query;
    query.prepare("UPDATE teams SET capacity=:capacity WHERE team=:team");
    query.bindValue(":team", aTeam.teamname);
    query.bindValue(":capacity", newCapacity);
    if(query.exec())
    {
        qDebug() << "Arena capacity updated.";
    }
    else
    {
        qDebug() << "Update capacity failed.";
    }
}
