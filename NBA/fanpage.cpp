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
    loadAllTeams();
}

void fanpage::on_mainViewArenasButton_clicked()
{

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
    }
    else
    {
         ui->teamTable->setModel(DbManager::instance().getSingleTeam(ui->teamNameTeamCombo->currentText()));
    }
    ui->teamTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->teamTable->setAlternatingRowColors(true);
    ui->teamTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
}

void fanpage::on_teamNameTeamCombo_currentIndexChanged(const QString &arg1)
{
    qDebug() << "Showing info for " << arg1 << ".";
    loadAllTeams();
}
