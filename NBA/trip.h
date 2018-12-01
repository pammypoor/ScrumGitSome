#ifndef TRIP_H
#define TRIP_H

#include <QMainWindow>
#include "dbmanager.h"
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QSpinBox>
#include <QStyledItemDelegate>

class SpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    SpinBoxDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};



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
    void loadSouvenirs(QString team);
    void loadTotalDistance(int distance);
    ~trip();

private slots:
    void on_tripButton_clicked();

private:
    Ui::trip *ui;
    int teamCount;
    int totalDistance;
    QVector<QString> teams;
};

#endif // TRIP_H
