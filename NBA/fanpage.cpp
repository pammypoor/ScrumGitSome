#include "fanpage.h"
#include "ui_fanpage.h"
#include <algorithm>
fanpage::fanpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fanpage)
{
    ui->setupUi(this);
    QPixmap pix(MAINPIC);
    ui->mainLogo->setPixmap(pix.scaled(200,200, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    ui->stackedWidget->setCurrentIndex(0);
    populateGraph();
    ui->shortestTripButton->setDisabled(true);
}

fanpage::~fanpage()
{
    delete ui;
}

void fanpage::on_mainPlanTripButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    loadPlanTeams();
    ui->planTripTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->distanceButton->setChecked(1);
    ui->selectedTeamsTable->insertColumn(0);
    ui->selectedTeamsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->selectedTeamsTable->setAlternatingRowColors(true);
    ui->selectedTeamsTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
    ui->selectedTeamsTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
    ui->selectedTeamsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void fanpage::populateGraph()
{
    typedef Graph<QString, double> Graph; //readability purposes
    typedef Graph::Link Link;         //readability purposes

    vector<Link> links;
    int sizeOfGraph = 30; // modify when adding another team or distance

    QVector<QString> fromTeams;
    QVector<QString> toTeams;
    QVector<double>  weights;

    QVector<double> insertedEdges;
    QVector<double>::iterator fIt;

    sizeOfGraph = DbManager::instance().getNumOfTeams();
    /**REMOVE -1 when updated teams table in db**/
    sizeOfGraph--;

    fromTeams = DbManager::instance().getFromTeams();
    toTeams   = DbManager::instance().getToTeams();
    weights   = DbManager::instance().getWeights();

    for(int i = 0; i < fromTeams.size(); i++)
    {
        fIt = std::find(insertedEdges.begin(), insertedEdges.end(), weights[i]);

        if(fIt == insertedEdges.end())
        {
           links.push_back(Link(make_pair(fromTeams[i], toTeams[i]), weights[i]));
           insertedEdges.push_back(weights[i]);
        }
    }

    myGraph = new Graph(links.begin(), links.end(), sizeOfGraph);
    myGraph->PrintGraph();

}

void fanpage::on_mainViewSouvenirsButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
     ui->teamNameSouvenirCombo->addItem("Show All");
     ui->teamNameSouvenirCombo->addItems(DbManager::instance().getTeams());
     ui->teamNameSouvenirCombo->setCurrentIndex(0);
     loadAllSouvenirs();
}

void fanpage::on_mainViewTeamsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->teamNameTeamCombo->addItem("Show All");
    ui->teamNameTeamCombo->addItems(DbManager::instance().getTeams());
    ui->teamNameTeamCombo->setCurrentIndex(0);

    ui->showAllConferenceRadio->setChecked(true);
    ui->teamTeamSortRadio->setChecked(true);

    loadAllTeams();
    loadCapacity(DbManager::instance().getConference("*", "capacity"));
}

void fanpage::on_backSouvenirButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void fanpage::loadAllSouvenirs()
{
    if(ui->teamNameSouvenirCombo->currentText()=="Show All")
    {
        ui->souvenirTable->setModel(DbManager::instance().toTableSouvenir());
    }
    else
    {
         ui->souvenirTable->setModel(DbManager::instance().toTableSingleTeamSouvenirs(ui->teamNameSouvenirCombo->currentText()));
    }
    ui->souvenirTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->souvenirTable->setAlternatingRowColors(true);
    ui->souvenirTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
}

void fanpage::on_teamNameSouvenirCombo_currentIndexChanged(const QString &arg1)
{
    qDebug() << "Showing souvenirs for " << arg1 << ".";
    loadAllSouvenirs();
}

void fanpage::on_backTeamButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->teamNameTeamCombo->clear();
}

void fanpage::loadAllTeams()
{
    if(ui->teamNameTeamCombo->currentText()== "Show All")
    {
        ui->teamTable->setModel(DbManager::instance().toTableTeam());
        loadCapacity(DbManager::instance().getConference("*", "capacity"));
    }
    else
    {
         ui->teamTable->setModel(DbManager::instance().getSingleTeam(ui->teamNameTeamCombo->currentText()));
         loadCapacity(DbManager::instance().getSingleTeam(ui->teamNameTeamCombo->currentText()));
    }
    ui->teamTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->teamTable->setAlternatingRowColors(true);
    ui->teamTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
}

void fanpage::loadPlanTeams()
{
    ui->planTripTable->setModel(DbManager::instance().toTableTeamName());
    ui->planTripTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->planTripTable->setAlternatingRowColors(true);
    ui->planTripTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
}

void fanpage::on_teamNameTeamCombo_currentIndexChanged(const QString &arg1)
{
    qDebug() << "Showing info for " << arg1 << ".";
    loadAllTeams();
    if(arg1!="Show All")
    {
        ui->groupBox->setEnabled(false);
    }
    else
    {
        ui->groupBox->setEnabled(true);
        ui->showAllConferenceRadio->setChecked(true);
        on_showAllConferenceRadio_clicked();
    }
}

void fanpage::on_showAllConferenceRadio_clicked()
{
    ui->divisionCombo->clear();
    ui->divisionCombo->addItem("Show All");

    if(ui->teamTeamSortRadio->isChecked())
    {
        loadAllTeams();
    }
    if(ui->teamArenaSortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("*", "arena"));
        loadCapacity(DbManager::instance().getConference("*", "capacity"));
    }
    if(ui->teamCapacitySortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("*", "capacity"));
        loadCapacity(DbManager::instance().getConference("*", "capacity"));
    }
    if(ui->teamYearSortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("*", "year"));
        loadCapacity(DbManager::instance().getConference("*", "capacity"));
    }
}

void fanpage::on_easternConferenceRadio_clicked()
{
    ui->divisionCombo->clear();
    QList<QString> list = {"Show All", "Atlantic", "Central", "Southeast"};
    ui->divisionCombo->addItems(list);

    if(ui->teamTeamSortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "team"));
        loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
    }
    if(ui->teamArenaSortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "arena"));
        loadCapacity(DbManager::instance().getConference("Eastern", "capicity"));
    }
    if(ui->teamCapacitySortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "capacity"));
        loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
    }
    if(ui->teamYearSortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "year"));
        loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
    }
}

void fanpage::on_westernConferenceRadio_clicked()
{
    ui->divisionCombo->clear();
    QList<QString> list = {"Show All", "Northwest", "Pacific", "Southwest"};
    ui->divisionCombo->addItems(list);

    if(ui->teamTeamSortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Western", "team"));
        loadCapacity(DbManager::instance().getConference("Western", "team"));
    }
    if(ui->teamArenaSortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Western", "arena"));
        loadCapacity(DbManager::instance().getConference("Western", "capacity"));
    }
    if(ui->teamCapacitySortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Western", "capacity"));
        loadCapacity(DbManager::instance().getConference("Western", "capacity"));
    }
    if(ui->teamYearSortRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Western", "year"));
        loadCapacity(DbManager::instance().getConference("Western", "capacity"));
    }
}

void fanpage::on_teamTeamSortRadio_clicked()
{
    if(ui->easternConferenceRadio->isChecked() && ui->divisionCombo->currentText() == "Show All")
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "team"));
        loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
    }
    else if(ui->westernConferenceRadio->isChecked() && ui->divisionCombo->currentText() == "Show All")
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Western", "team"));
        loadCapacity(DbManager::instance().getConference("Western", "capacity"));
    }
    else if(ui->showAllConferenceRadio->isChecked())
    {
        loadAllTeams();
    }
    else
    {
        ui->teamTable->setModel(DbManager::instance().getDivision(ui->divisionCombo->currentText(), "team"));
        loadCapacity(DbManager::instance().getDivision(ui->divisionCombo->currentText(), "capacity"));
    }
}

void fanpage::on_teamArenaSortRadio_clicked()
{
    if(ui->easternConferenceRadio->isChecked() && ui->divisionCombo->currentText() == "Show All")
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "arena"));
        loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
    }
    else if(ui->westernConferenceRadio->isChecked() && ui->divisionCombo->currentText() == "Show All")
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Western", "arena"));
        loadCapacity(DbManager::instance().getConference("Western", "capacity"));
    }
    else if(ui->showAllConferenceRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("*", "arena"));
        loadCapacity(DbManager::instance().getConference("*", "capacity"));
    }
    else
    {
        ui->teamTable->setModel(DbManager::instance().getDivision(ui->divisionCombo->currentText(), "arena"));
        loadCapacity(DbManager::instance().getDivision(ui->divisionCombo->currentText(), "capacity"));
    }
}

void fanpage::on_teamCapacitySortRadio_clicked()
{
    if(ui->easternConferenceRadio->isChecked() && ui->divisionCombo->currentText() == "Show All")
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "capacity"));
        loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
    }
    else if(ui->westernConferenceRadio->isChecked() && ui->divisionCombo->currentText() == "Show All")
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Western", "capacity"));
        loadCapacity(DbManager::instance().getConference("Western", "capacity"));
    }
    else if(ui->showAllConferenceRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("*", "capacity"));
        loadCapacity(DbManager::instance().getConference("*", "capacity"));
    }
    else
    {
        ui->teamTable->setModel(DbManager::instance().getDivision(ui->divisionCombo->currentText(), "capacity"));
        loadCapacity(DbManager::instance().getDivision(ui->divisionCombo->currentText(), "capacity"));
    }
}

void fanpage::on_teamYearSortRadio_clicked()
{
    if(ui->easternConferenceRadio->isChecked() && ui->divisionCombo->currentText() == "Show All")
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "year"));
        loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
    }
    else if(ui->westernConferenceRadio->isChecked() && ui->divisionCombo->currentText() == "Show All")
    {
        ui->teamTable->setModel(DbManager::instance().getConference("Western", "year"));
        loadCapacity(DbManager::instance().getConference("Western", "capacity"));
    }
    else if(ui->showAllConferenceRadio->isChecked())
    {
        ui->teamTable->setModel(DbManager::instance().getConference("*", "year"));
        loadCapacity(DbManager::instance().getConference("*", "capacity"));
    }
    else
    {
        ui->teamTable->setModel(DbManager::instance().getDivision(ui->divisionCombo->currentText(), "year"));
        loadCapacity(DbManager::instance().getDivision(ui->divisionCombo->currentText(), "capacity"));
    }
}

//Loads table according to options. Method runs if conference changes
void fanpage::on_divisionCombo_currentIndexChanged(const QString &arg1)
{
    if(ui->easternConferenceRadio->isChecked() && ui->divisionCombo->currentText() == "Show All")
    {
        if(ui->teamTeamSortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "team"));
            loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
        }
        if(ui->teamArenaSortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "arena"));
            loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
        }
        if(ui->teamCapacitySortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "capacity"));
            loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
        }
        if(ui->teamYearSortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getConference("Eastern", "year"));
            loadCapacity(DbManager::instance().getConference("Eastern", "capacity"));
        }
    }
    else if(ui->westernConferenceRadio->isChecked() && ui->divisionCombo->currentText() == "Show All")
    {
        if(ui->teamTeamSortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getConference("Western", "team"));
            loadCapacity(DbManager::instance().getConference("Western", "capacity"));
        }
        if(ui->teamArenaSortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getConference("Western", "arena"));
            loadCapacity(DbManager::instance().getConference("Western", "capacity"));
        }
        if(ui->teamCapacitySortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getConference("Western", "capacity"));
            loadCapacity(DbManager::instance().getConference("Western", "capacity"));
        }
        if(ui->teamYearSortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getConference("Western", "year"));
            loadCapacity(DbManager::instance().getConference("Western", "capacity"));
        }
    }
    else
    {
        if(ui->teamTeamSortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getDivision(arg1, "team"));
            loadCapacity(DbManager::instance().getDivision(arg1, "capacity"));
        }
        if(ui->teamArenaSortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getDivision(arg1, "arena"));
            loadCapacity(DbManager::instance().getDivision(arg1, "capacity"));
        }
        if(ui->teamCapacitySortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getDivision(arg1, "capacity"));
            loadCapacity(DbManager::instance().getDivision(arg1, "capacity"));
        }
        if(ui->teamYearSortRadio->isChecked())
        {
            ui->teamTable->setModel(DbManager::instance().getDivision(arg1, "year"));
            loadCapacity(DbManager::instance().getDivision(arg1, "capacity"));
        }
    }
}

void fanpage::loadCapacity(QSqlQueryModel* modal)
{
    int sum = 0;
    for(int i = 0; i < modal->rowCount(); i++)
    {
        sum +=modal->record(i).value(5).toInt();
    }
    ui->capacityLabel->setText(QString::number(sum));
}


void fanpage::on_backTripButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    tripTeams.clear();
    ui->selectedTeamsTable->setRowCount(0);
}

void fanpage::on_planTripTable_activated(const QModelIndex &index)
{
    bool isFound = false;
    int count;
    int foundAt = 0;
    for(count = 0; count < tripTeams.size(); count++)
    {
        if(tripTeams.at(count) == index.sibling(index.row(), 0).data().toString())
        {
            isFound = true;
            foundAt = count;
        }
    }
    if(!isFound)
    {
        tripTeams.push_back(index.sibling(index.row(), 0).data().toString());
        ui->selectedTeamsTable->insertRow(ui->selectedTeamsTable->rowCount());
        ui->selectedTeamsTable->setItem( ui->selectedTeamsTable->rowCount()-1, 0,  new QTableWidgetItem(index.sibling(index.row(), 0).data().toString()));
        ui->teamCombo->addItem(index.sibling(index.row(), 0).data().toString());
    }
    else
    {
        tripTeams.remove(foundAt);
        ui->selectedTeamsTable->removeRow(foundAt);
        ui->teamCombo->removeItem(foundAt);
        //Check if theres 2 teams in selected table if true activate button for shortest distance
        on_selectedTeamsTable_cellChanged(0, 0);
    }
}


void fanpage::on_tripButton_clicked()
{

    if(ui->distanceButton->isChecked())
    {
        if(ui->teamCombo->currentText() != tripTeams.begin())
        {
            for(int count = 0; count < tripTeams.size(); count++)
            {
                if(tripTeams.at(count) == ui->teamCombo->currentText())
                {
                    tripTeams.removeAt(count);
                }
            }
            tripTeams.insert(0, ui->teamCombo->currentText());
        }
        tripTeams = shortestTrip(tripTeams);


        tripPage = new trip(this, tripTeams);
        tripPage->show();
        tripPage->loadTotalDistance(getDistanceTrip(tripTeams));

    }
    else if(ui->orderButton->isChecked())
    {
        if(ui->teamCombo->currentText() != tripTeams.begin())
        {
            for(int count = 0; count < tripTeams.size(); count++)
            {
                if(tripTeams.at(count) == ui->teamCombo->currentText())
                {
                    tripTeams.removeAt(count);
                }
            }
            tripTeams.insert(0, ui->teamCombo->currentText());
        }

        // This statement works but does the same thing recursively
        // It returns a vector containing the path of the trip that will be taken.
//        QVector<QString> test = getTripInFanOrder();


        tripPage = new trip(this, tripTeams);
        tripPage->show();
        tripPage->loadTotalDistance(getDistanceTrip(tripTeams));
    }
}

//ShortestTripButtonClicked - activated when there are two teams selected
//                            calculates dijkstra on the starting and ending team
//                            and brings up trip UI, displays the total distance
//                            and allows user to purchase souvenirs
void fanpage::on_shortestTripButton_clicked()
{
    bool validNumOfTeams = false;
    QVector<QString> shortestPath;
    int cost;
    QString starting;
    QString ending;

    if(ui->selectedTeamsTable->rowCount() == 2)
    {
        //Valid number of teams a starting team and an ending team to generate
        //Dijkstra's shortest path
        validNumOfTeams = true;

        if(ui->teamCombo->currentText() == tripTeams[0])
        {
            starting = tripTeams[0];
            ending   = tripTeams[1];
        }
        else
        {
            starting = tripTeams[1];
            ending   = tripTeams[0];
        }

        shortestPath = myGraph->Dijkstra(starting, ending, cost);
        //we have a vector with the path and cost with the cost


        //I tried to fix it idk if this should affect the implementation in trip.cpp
        // i commented what u had, feel free to delete this if its wrong
//        tripPage = new trip(this, shortestPath, QVector<QString> {starting, ending});
        tripPage = new trip(this, shortestPath, shortestPath);

        tripPage->show();
        tripPage->loadTotalDistance(cost);
//        tripPage->loadTeamVisited(starting);
//        tripPage->loadTeamVisited(ending);

        for(int i = 0; i < shortestPath.size(); i++)
        {
            tripPage->loadTeamVisited(shortestPath[i]);
        }
    }
}

//SelectedTeamsTableChanged - activates button only when there are two teams selected
//                            otherwise dont activate it
void fanpage::on_selectedTeamsTable_cellChanged(int row, int column)
{
    if(ui->selectedTeamsTable->rowCount() == 2)
    {
        ui->shortestTripButton->setEnabled(true);
    }
    else
    {
        ui->shortestTripButton->setDisabled(true);
    }
}


void fanpage::on_minimumSpanTreeButton_clicked()
{
    qDebug() << myGraph->Kruskal();

    tripPage = new trip(this, tripTeams);
    tripPage->show();
    tripPage->displayInfo();

}

double fanpage::getDistanceTrip(QVector<QString> teams)
{
    int sum = 0;
    int cost =0;
    QString starting;
    QString ending;
        for(int count = 0; count < teams.size()-1; count++)
        {
           starting = teams.at(count);
           ending = teams.at(count+1);
           QVector<QString> shortestPath = myGraph->Dijkstra(starting, ending, cost);
           tripPage->loadTeamVisited(starting);
           tripPage->loadArenas(starting);
           sum += cost;
        }
        tripPage->loadTeamVisited(ending);
        tripPage->loadArenas(ending);
        return sum;
}

void fanpage::on_bfsButton_clicked()
{
    myGraph->bfs("Los Angeles Lakers");

    tripPage = new trip(this, tripTeams);
    tripPage->show();
    tripPage->displayBFS();
}

void fanpage::on_dfsButton_clicked()
{
    myGraph->dfs("Denver Nuggets");

    tripPage = new trip(this, tripTeams);
    tripPage->show();
    tripPage->displayDFS();
}

QVector<QString> fanpage::getTripInFanOrder()
{
    QVector<QString> pathForTrip;
    int totalCost = 0;
    grandTotalForUserSpecificPath = 0;

    if(tripTeams.size() > 1)
    {
        ShortestPath(0, 1, tripTeams.size() - 1, pathForTrip, totalCost);

        qDebug() << "After recursion this list will be passed in the Trip UI";
        for(QVector<QString>::iterator it = pathForTrip.begin();
            it != pathForTrip.end(); it++)
        {
            qDebug() << *it;

        }
        qDebug() << grandTotalForUserSpecificPath;
        qDebug() << endl;
    }
    else
    {
        qDebug() << "Could not calculate recursive on 1 element only";
    }

    return pathForTrip;
}

//recursive call to obtain the shortest trip
void fanpage::ShortestPath(int start, int end, int finish, QVector<QString>& path, int& totalCost)
{
    if(tripTeams[end] == tripTeams[finish])
    {
        QVector<QString> temp;
        temp = myGraph->Dijkstra(tripTeams[start], tripTeams[finish], totalCost);
        grandTotalForUserSpecificPath = grandTotalForUserSpecificPath + totalCost;
        QVector<QString>::iterator itEnd = temp.end();
        QVector<QString>::iterator itBegin = temp.begin();
        for(; itBegin != itEnd; itBegin++)
        {
            path.push_back(*itBegin);
        }

    }
    else
    {
        QVector<QString> temp;
        temp = myGraph->Dijkstra(tripTeams[start], tripTeams[end], totalCost);
        grandTotalForUserSpecificPath = grandTotalForUserSpecificPath + totalCost;
        QVector<QString>::iterator itEnd = temp.end();
        itEnd--;
        QVector<QString>::iterator itBegin = temp.begin();

        for(; itBegin != itEnd; itBegin++)
        {
            path.push_back(*itBegin);
        }

        ShortestPath(start + 1, end + 1, finish, path, totalCost);
    }
}

QVector<QString> fanpage::shortestTrip(QVector<QString> teams)
{
    QVector<QString> toReturn;
    toReturn.push_back(teams.at(0));
    teams.remove(0);
    int cost = 0;
    int smallestCost = 10000000000000;
    int smallestCostAt=0;

    for(int count = 0; count < teams.size(); count++)
    {
        for(int i = 0; i < teams.size(); i++)
        {

            QVector<QString> temp = myGraph->Dijkstra(toReturn.at(count), teams.at(i), cost);
            if(cost < smallestCost)
            {
                smallestCostAt = i;
                smallestCost = cost;
            }
            qDebug() << toReturn.at(count) << teams.at(i) << cost << smallestCost;
        }
        toReturn.push_back(teams.at(smallestCostAt));
        teams.remove(smallestCostAt);
        smallestCost = 100000000000000;
    }
    toReturn.push_back(teams.at(0));
    return toReturn;
}
