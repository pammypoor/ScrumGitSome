#include "fanpage.h"
#include "ui_fanpage.h"

fanpage::fanpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fanpage)
{
    ui->setupUi(this);
    QPixmap pix(MAINPIC);
    ui->mainLogo->setPixmap(pix.scaled(200,200, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    ui->stackedWidget->setCurrentIndex(0);
}

fanpage::~fanpage()
{
    delete ui;
}

void fanpage::on_mainPlanTripButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

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

void fanpage::on_mainViewArenasButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
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

//Brings back to main page
void fanpage::on_backArenaButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Brings to page to view arenas
void fanpage::on_mainViewArenasButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

//Brings back to main page
void fanpage::on_backCoachButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//If duplicate arena, counts smallest capacity for arena [PLEASE CHECK WITH PROF]
void fanpage::loadCapacity(QSqlQueryModel* modal)
{
    int sum = 0;
    QSet<QString> teamList;
    for(int i = 0; i < modal->rowCount(); i++)
    {
        QString toFind = modal->record(i).value(4).toString();
        if(teamList.find(toFind) == teamList.end())
        {
            sum +=modal->record(i).value(5).toInt();
            teamList.insert(toFind);
        }
    }
    ui->capacityLabel->setText(QString::number(sum));
}

