#include "maintenance.h"
#include "ui_maintenance.h"

maintenance::maintenance(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::maintenance)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap pix(SETTINGSPIC);
    ui->settingsPic->setPixmap(pix.scaled(250,250, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    setWindowTitle("Let's Play NBA Basketball");
}

maintenance::~maintenance()
{
    delete ui;
}

void maintenance::on_MenuTeamButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    loadTeamData();
}

void maintenance::on_teamBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void maintenance::on_menuSouvenirButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    loadSouvenirData();
    ui->SouvenirTeamCombo->addItems(DbManager::instance().getTeams());
    ui->showTeamsCombo->addItem("Show All");
    ui->showTeamsCombo->addItems(DbManager::instance().getTeams());
}

void maintenance::on_souvenirBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->SouvenirNameLineEdit->clear();
    ui->SouvenirCostSpin->clear();
    ui->SouvenirTeamCombo->setCurrentIndex(0);
    ui->showTeamsCombo->setCurrentIndex(0);
}

void maintenance::on_pushButton_clicked()
{
    souvenir newSouvenir;
    newSouvenir.name = ui->SouvenirNameLineEdit->text();
    newSouvenir.cost = ui->SouvenirCostSpin->value();
    newSouvenir.team = ui->SouvenirTeamCombo->currentText();

   if(DbManager::instance().addSouvenir(newSouvenir))
   {
       ui->SouvenirNameLineEdit->clear();
       ui->SouvenirCostSpin->clear();
       ui->SouvenirTeamCombo->setCurrentIndex(0);
   }
   loadSouvenirData();
}

void maintenance::loadSouvenirData()
{
    if(ui->showTeamsCombo->currentText()=="Show All")
    {
        ui->SouvenirTableView->setModel(DbManager::instance().toTableSouvenir());
    }
    else
    {
         ui->SouvenirTableView->setModel(DbManager::instance().toTableSingleTeamSouvenirs(ui->showTeamsCombo->currentText()));
    }
    ui->SouvenirTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->SouvenirTableView->setAlternatingRowColors(true);
    ui->SouvenirTableView->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");

}

void maintenance::on_SouvenirTableView_doubleClicked(const QModelIndex &index)
{
    souvenir aSouvenir;
    aSouvenir.name = index.sibling(index.row(), 0).data().toString();
    aSouvenir.cost = index.sibling(index.row(), 1).data().toDouble();
    aSouvenir.team = index.sibling(index.row(), 2).data().toString();

     ui->SouvenirTableView->selectRow(index.row());

    QInputDialog inputOperation;
    QStringList operations;

    operations << "Edit Souvenir Price" << "Delete Souvenir";
    inputOperation.setComboBoxItems(operations);

    inputOperation.setWindowTitle("Select an option");
    if(inputOperation.exec())
    {
        if(inputOperation.textValue() == "Delete Souvenir")
        {
            QMessageBox::StandardButton confirm;
            confirm = QMessageBox::question(this, "Confirm Modifications", "Are you sure you want to delete this souvenir?", QMessageBox::Yes|QMessageBox::No);
            if(confirm==QMessageBox::Yes)
            {
                DbManager::instance().deleteSouvenir(aSouvenir);
                loadSouvenirData();
            }
        }
        else if(inputOperation.textValue() == "Edit Souvenir Price")
        {
            bool ok;
            double price = QInputDialog::getDouble(this, tr("Edit Option"), tr("Edit Souvenir cost: "), aSouvenir.cost, 0, 10000, 2, &ok);

            if(ok && price != 0.00)
            {
                DbManager::instance().editSouvenir(aSouvenir, price);
                loadSouvenirData();
            }
            else if(price == 0.00)
            {
                QMessageBox msgBox;
                msgBox.setText("Price cannot be 0.00");
                msgBox.setWindowTitle("Error");
                msgBox.exec();
            }
        }
    }
}

//reads excel sheet
void maintenance::on_addTeamButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), FOLDER, tr("*.xlsx"));
    if(filename.isEmpty())
    {
        return;
    }
    filename.replace('/','\\');
    QAxObject* excel = new QAxObject( "Excel.Application", 0 );
            QAxObject* workbooks = excel->querySubObject( "Workbooks" );
            QAxObject* workbook = workbooks->querySubObject( "Open(const QString&)", filename );
            QAxObject* sheets = workbook->querySubObject( "Worksheets" );
            int sheetCount = sheets->dynamicCall("Count()").toInt();        //worksheets count
            QAxObject* sheet = sheets->querySubObject( "Item( int )", sheetCount );

            // Find the cells that actually have content
            QAxObject* usedrange = sheet->querySubObject( "UsedRange");
            QAxObject * rows = usedrange->querySubObject("Rows");
            QAxObject * columns = usedrange->querySubObject("Columns");
            int intRowStart = usedrange->property("Row").toInt();
            int intColStart = usedrange->property("Column").toInt();
            int intCols = columns->property("Count").toInt();
            int intRows = rows->property("Count").toInt();

            team newTeam;
            //Row starts at 1 to remove header columns
            for (int row=intRowStart + 1 ; row < intRowStart+intRows ; row++) {
                for (int col=intColStart ; col < intColStart+intCols ; col++)
                {
                    QAxObject* cell = sheet->querySubObject( "Cells( int, int )", row, col );
                    QVariant value = cell->dynamicCall( "Value()" );
                    if (value.toString().isEmpty())
                    {
                        continue;
                    }
                    switch (col)
                    {
                        case 1: newTeam.conference=value.toString();
                            break;
                        case 2: newTeam.division=value.toString();
                            break;
                        case 3: newTeam.teamname=value.toString();
                            break;
                        case 4: newTeam.location=value.toString();
                            break;
                        case 5: newTeam.arena=value.toString();
                            break;
                        case 6: newTeam.capacity=value.toInt();
                            break;
                        case 7: newTeam.year=value.toInt();
                            break;
                        case 8: {newTeam.coach = value.toString();
                                if(DbManager::instance().addTeam(newTeam))
                                {}}
                            break;
                    }
                }
            }
            workbook->dynamicCall("Close()");
            excel->dynamicCall("Quit()");
            loadTeamData();
}

void maintenance::on_showTeamsCombo_currentIndexChanged(const QString &arg1)
{
    qDebug() << "Showing souvenirs for " << arg1 << ".";
    loadSouvenirData();
}

void maintenance::loadTeamData()
{
    ui->teamMaintenanceTableView->setModel(DbManager::instance().toTableTeam());
    ui->teamMaintenanceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->teamMaintenanceTableView->setAlternatingRowColors(true);
    ui->teamMaintenanceTableView->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
    qDebug() << "Showing teams.";
}

void maintenance::on_teamMaintenanceTableView_doubleClicked(const QModelIndex &index)
{
    team aTeam;
    aTeam.conference = index.sibling(index.row(), 0).data().toString();
    aTeam.division = index.sibling(index.row(), 1).data().toString();
    aTeam.teamname = index.sibling(index.row(), 2).data().toString();
    aTeam.location = index.sibling(index.row(), 3).data().toString();
    aTeam.arena = index.sibling(index.row(), 4).data().toString();
    aTeam.capacity = index.sibling(index.row(), 5).data().toInt();
    aTeam.year = index.sibling(index.row(), 6).data().toInt();
    aTeam.coach = index.sibling(index.row(), 7).data().toString();

    ui->teamMaintenanceTableView->selectRow(index.row());

    QInputDialog inputOperation;
    QStringList operations;

    operations << "Edit arena name" << "Edit arena capacity";
    inputOperation.setComboBoxItems(operations);

    inputOperation.setWindowTitle("Select an option");
    if(inputOperation.exec())
    {
        if(inputOperation.textValue() == "Edit arena name")
        {
            bool ok;
            QString arena = QInputDialog::getText(this, "Edit Option", "Edit arena name: ", QLineEdit::Normal, "", &ok);
            if(ok && !arena.isEmpty())
            {
                DbManager::instance().updateArena(aTeam, arena);
                loadTeamData();
            }
        }
        else if(inputOperation.textValue() == "Edit arena capacity")
        {
            bool ok;
            int capacity = QInputDialog::getInt(this, tr("Edit Option"), tr("Edit Souvenir cost: "), aTeam.capacity, 1, 1000000,1,&ok);
            if(ok && capacity!=0)
            {
                DbManager::instance().updateCapacity(aTeam, capacity);
                loadTeamData();
            }
            if(capacity == 0)
            {
                qDebug() << "Arena capacity cannot be zero.";
            }
        }
    }
}
