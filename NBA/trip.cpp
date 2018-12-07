#include "trip.h"
#include "ui_trip.h"

SpinBoxDelegate::SpinBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setFrame(false);
    editor->setMinimum(0);
    editor->setMaximum(100);

    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

trip::trip(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::trip)
{
    ui->setupUi(this);
    ui->tripTeamName->setAlignment(Qt::AlignCenter);
}

trip::trip(QWidget *parent, QVector<QString> teams) :
    QMainWindow(parent),
    ui(new Ui::trip)
{
    ui->setupUi(this);
        ui->tripTeamName->setAlignment(Qt::AlignCenter);
        ui->souvenirsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->souvenirsTable->setAlternatingRowColors(true);
        ui->souvenirsTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");

        teamCount = 0;
        if(teams.size() > 0)
        {
            ui->tripTeamName->setText(teams.at(0));
            loadSouvenirs(teams.at(0));
        }

        this->teams = teams;
        this->teamsVisited = teams;

        ui->cartTable->insertColumn(0); ui->cartTable->insertColumn(0); ui->cartTable->insertColumn(0); ui->cartTable->insertColumn(0);
        ui->cartTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Item Name"));
        ui->cartTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Item Cost"));
        ui->cartTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Arena Name"));
        ui->cartTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Item Amount"));

        ui->cartTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->cartTable->setAlternatingRowColors(true);
        ui->cartTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
        ui->cartTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ui->stackedWidget->setCurrentIndex(0);

        ui->reviewTeamTable->insertColumn(0);
        ui->reviewTeamTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
        ui->reviewTeamTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->reviewTeamTable->setAlternatingRowColors(true);
        ui->reviewTeamTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
        ui->reviewTeamTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ui->arenaTable->insertColumn(0);ui->arenaTable->insertColumn(0);
        ui->arenaTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Arena Name"));
        ui->arenaTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Arena Total"));
        ui->arenaTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->arenaTable->setAlternatingRowColors(true);
        ui->arenaTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
        ui->arenaTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ui->reviewSouvenirTable->insertColumn(0); ui->reviewSouvenirTable->insertColumn(0); ui->reviewSouvenirTable->insertColumn(0);
        ui->reviewSouvenirTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Item Name"));
        ui->reviewSouvenirTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Arena Name"));
        ui->reviewSouvenirTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Item Amount"));
        ui->reviewSouvenirTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->reviewSouvenirTable->setAlternatingRowColors(true);
        ui->reviewSouvenirTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
        ui->reviewSouvenirTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

trip::trip(QWidget *parent, QVector<QString> teams, QVector<QString> teamsVisited) :
    QMainWindow(parent),
    ui(new Ui::trip)
{
    ui->setupUi(this);
    QTableWidgetItem colHeader;
        ui->tripTeamName->setAlignment(Qt::AlignCenter);
        ui->souvenirsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->souvenirsTable->setAlternatingRowColors(true);
        ui->souvenirsTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
        teamCount = 0;
        if(teamsVisited.size() > 0)
        {
            ui->tripTeamName->setText(teamsVisited.at(0));
            loadSouvenirs(teamsVisited.at(0));
        }
        this->teams = teams;
        this->teamsVisited = teamsVisited;

        ui->cartTable->insertColumn(0); ui->cartTable->insertColumn(0); ui->cartTable->insertColumn(0); ui->cartTable->insertColumn(0);
        ui->cartTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Item Name"));
        ui->cartTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Item Cost"));
        ui->cartTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Arena Name"));
        ui->cartTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Item Amount"));
        ui->cartTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ui->cartTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->cartTable->setAlternatingRowColors(true);
        ui->cartTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");

        ui->stackedWidget->setCurrentIndex(0);

        ui->reviewTeamTable->insertColumn(0);
        ui->reviewTeamTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
        ui->reviewTeamTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->reviewTeamTable->setAlternatingRowColors(true);
        ui->reviewTeamTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
        ui->reviewTeamTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ui->arenaTable->insertColumn(0);ui->arenaTable->insertColumn(0);
        ui->arenaTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Arena Name"));
        ui->arenaTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Arena Total"));
        ui->arenaTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->arenaTable->setAlternatingRowColors(true);
        ui->arenaTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
        ui->arenaTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ui->reviewSouvenirTable->insertColumn(0); ui->reviewSouvenirTable->insertColumn(0); ui->reviewSouvenirTable->insertColumn(0);
        ui->reviewSouvenirTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Item Name"));
        ui->reviewSouvenirTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Arena Name"));
        ui->reviewSouvenirTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Item Amount"));
        ui->reviewSouvenirTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->reviewSouvenirTable->setAlternatingRowColors(true);
        ui->reviewSouvenirTable->setStyleSheet("alternate-background-color: #1E90FF; background-color: #4682B4;");
        ui->reviewSouvenirTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void trip::loadSouvenirs(QString team)
{
    ui->souvenirsTable->setModel(DbManager::instance().getTeamSouvenir(team));
}

void trip::loadTotalDistance(int distance)
{
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white);

    ui->totalDistanceNum->setAutoFillBackground(true);
    ui->totalDistanceNum->setPalette(palette);
    ui->totalDistanceLabel->setPalette(palette);
    ui->totalDistanceNum->setText(QString::number(distance));
}


trip::~trip()
{
    delete ui;
}

void trip::on_tripButton_clicked()
{
    double totalSpent = 0;
    teamCount++;
    if(teamCount < teamsVisited.size())
    {
        loadSouvenirs(teamsVisited.at(teamCount));
        ui->tripTeamName->setText(teamsVisited.at(teamCount));
    }
    else    //done with shopping
    {
        ui->stackedWidget->setCurrentIndex(1);
        for(int count = 0; count < ui->cartTable->rowCount(); count++)
        {
            ui->reviewSouvenirTable->insertRow(ui->reviewSouvenirTable->rowCount());
            ui->reviewSouvenirTable->setItem(ui->reviewSouvenirTable->rowCount()-1, 0, new QTableWidgetItem(ui->cartTable->item(count,0)->text()));
            ui->reviewSouvenirTable->setItem(ui->reviewSouvenirTable->rowCount()-1, 1, new QTableWidgetItem(ui->cartTable->item(count,2)->text()));
            ui->reviewSouvenirTable->setItem(ui->reviewSouvenirTable->rowCount()-1, 2, new QTableWidgetItem(ui->cartTable->item(count,3)->text()));
            totalSpent+= (ui->cartTable->item(count,1)->text().toDouble()) * (ui->cartTable->item(count,3)->text().toDouble());
        }
        ui->totalSpent->setText(QString::number(totalSpent));
        ui->totalArenasVisited->setText(QString::number(ui->arenaTable->rowCount()));
    }
}

void trip::on_souvenirsTable_doubleClicked(const QModelIndex &index)
{ 
        QString name = index.sibling(index.row(), 0).data().toString();
        QString cost = index.sibling(index.row(), 1).data().toString();
        QString team = index.sibling(index.row(), 2).data().toString();
        QString arena = DbManager::instance().getArena(team);
        bool exists = false;
        int foundAt = 0;
        int toAdd = 0;


        for(int count = 0; count < ui->cartTable->rowCount(); count++)
        {
            if(ui->cartTable->item(count,0)->text() == name && ui->cartTable->item(count,2)->text() == team)
            {
                exists = true;
                foundAt = count;
            }
        }
        if(exists)
        {
            toAdd  = ui->cartTable->item(foundAt,3)->text().toInt();
        }

        QInputDialog inputOperation;
        QStringList operations;

        operations << "Add souvenirs";
        inputOperation.setComboBoxItems(operations);

        inputOperation.setWindowTitle("Select an option");
        if(inputOperation.exec())
        {
            if(inputOperation.textValue() == "Add souvenirs")
            {
                bool ok;
                int amount = QInputDialog::getDouble(this, "Add souvenir", "Choose amount ", 0, 0, 1000, 1, &ok );
                QString am = QString::number(amount);
                if(ok && amount!= 0)
                {
                    if(!exists)
                    {
                        ui->cartTable->insertRow(ui->cartTable->rowCount());
                        ui->cartTable->setItem(ui->cartTable->rowCount()-1, 0, new QTableWidgetItem(name));
                        ui->cartTable->setItem(ui->cartTable->rowCount()-1, 1, new QTableWidgetItem(cost));
                        ui->cartTable->setItem(ui->cartTable->rowCount()-1, 2, new QTableWidgetItem(arena));
                        ui->cartTable->setItem(ui->cartTable->rowCount()-1, 3, new QTableWidgetItem(am));
                    }
                    else
                    {

                        QString am = QString::number(amount+toAdd);
                        ui->cartTable->setItem(foundAt, 3, new QTableWidgetItem(am));
                    }

                    for(int count = 0; count < ui->arenaTable->rowCount(); count++)
                    {
                        if(ui->arenaTable->item(count,0)->text() == arena)
                        {
                            double sum = 0;
                            if(ui->arenaTable->item(count,1)->text() != "zero")
                            {
                                sum = ui->arenaTable->item(count,1)->text().toDouble();
                            }
                            sum += (ui->cartTable->item(ui->cartTable->rowCount()-1,3)->text()).toDouble() * (ui->cartTable->item(ui->cartTable->rowCount()-1,1)->text()).toDouble();
                            ui->arenaTable->setItem(count, 1, new QTableWidgetItem(QString::number(sum)));
                        }
                    }
                }
            }
        }
}

void trip::loadTeamVisited(QString team)
{
    ui->reviewTeamTable->insertRow(ui->reviewTeamTable->rowCount());
    ui->reviewTeamTable->setItem(ui->reviewTeamTable->rowCount()-1, 0, new QTableWidgetItem(team));
}

void trip::displayInfo()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->labelName->setText("Showing MST");

    QFile file(MSTFILE);
    if(!file.exists())
    {
        qDebug() << "Doesnt exist";
    }
    else
    {
        qDebug() << "Opened...";
    }

    QString line;
    ui->textBrowser->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->textBrowser->setText(ui->textBrowser->toPlainText()+line+"\n");
        }
    }

    file.close();
}

void trip::displayBFS()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->labelName->setText("Showing BFS");

    QFile file(BFSFILE);
    if(!file.exists())
    {
        qDebug() << "Doesnt exist";
    }
    else
    {
        qDebug() << "Opened...";
    }

    QString line;
    ui->textBrowser->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->textBrowser->setText(ui->textBrowser->toPlainText()+line+"\n");
        }
    }

    file.close();
}

void trip::displayDFS()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->labelName->setText("Showing DFS");

    QFile file(DFSFILE);
    if(!file.exists())
    {
        qDebug() << "Doesnt exist";
    }
    else
    {
        qDebug() << "Opened...";
    }

    QString line;
    ui->textBrowser->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->textBrowser->setText(ui->textBrowser->toPlainText()+line+"\n");
        }
    }

    file.close();
}

void trip::loadArenas(QString team)
{
    QVector<QString> arenas;
    for(int count = 0; count < ui->arenaTable->rowCount(); count++)
    {
        arenas.push_back(ui->arenaTable->item(count,0)->text());
    }

    QString arena = DbManager::instance().getArena(team);

    for(int count = 0; count < arenas.size(); count++)
    {
        if(arenas.at(count) == arena)
        {
            return;
        }
    }
    ui->arenaTable->insertRow(ui->arenaTable->rowCount());
    ui->arenaTable->setItem(ui->arenaTable->rowCount()-1, 0, new QTableWidgetItem(arena));
    ui->arenaTable->setItem(ui->arenaTable->rowCount()-1, 1, new QTableWidgetItem("zero"));
}
