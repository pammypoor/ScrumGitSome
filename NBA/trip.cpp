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
}

void trip::loadSouvenirs(QString team)
{
    SpinBoxDelegate spin;
    ui->souvenirsTable->setModel(DbManager::instance().getTeamSouvenir(team));
    //ui->souvenirsTable->setItemDelegateForColumn(0, spin);
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
    teamCount++;
    if(teamCount < teams.size())
    {
        loadSouvenirs(teams.at(teamCount));
        ui->tripTeamName->setText(teams.at(teamCount));
    }
    else    //done with shopping
    {

    }
}
