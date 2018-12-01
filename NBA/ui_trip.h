/********************************************************************************
** Form generated from reading UI file 'trip.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIP_H
#define UI_TRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trip
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QPushButton *tripButton;
    QListView *listView;
    QLabel *label_2;
    QLabel *tripTeamName;
    QTableView *souvenirsTable;
    QLabel *totalDistanceLabel;
    QLabel *totalDistanceNum;
    QWidget *page_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *trip)
    {
        if (trip->objectName().isEmpty())
            trip->setObjectName(QStringLiteral("trip"));
        trip->resize(1066, 707);
        trip->setStyleSheet(QStringLiteral("background: #003366;"));
        centralwidget = new QWidget(trip);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 0, 1051, 681));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 20, 221, 31));
        label->setStyleSheet(QLatin1String("color: white;\n"
"font-size: 25px;"));
        tripButton = new QPushButton(page);
        tripButton->setObjectName(QStringLiteral("tripButton"));
        tripButton->setGeometry(QRect(250, 650, 181, 22));
        tripButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background:DarkGrey ;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background: Gray;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}color: white;"));
        listView = new QListView(page);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(730, 180, 301, 461));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(870, 150, 47, 21));
        label_2->setStyleSheet(QLatin1String("color: white;\n"
"font-size: 20px;"));
        tripTeamName = new QLabel(page);
        tripTeamName->setObjectName(QStringLiteral("tripTeamName"));
        tripTeamName->setGeometry(QRect(700, 50, 341, 51));
        tripTeamName->setStyleSheet(QLatin1String("font-size: 35px;\n"
"color: white;"));
        souvenirsTable = new QTableView(page);
        souvenirsTable->setObjectName(QStringLiteral("souvenirsTable"));
        souvenirsTable->setGeometry(QRect(5, 61, 671, 581));
        totalDistanceLabel = new QLabel(page);
        totalDistanceLabel->setObjectName(QStringLiteral("totalDistanceLabel"));
        totalDistanceLabel->setGeometry(QRect(730, 650, 91, 20));
        QFont font;
        font.setPointSize(10);
        totalDistanceLabel->setFont(font);
        totalDistanceNum = new QLabel(page);
        totalDistanceNum->setObjectName(QStringLiteral("totalDistanceNum"));
        totalDistanceNum->setGeometry(QRect(840, 650, 111, 16));
        totalDistanceNum->setFont(font);
        totalDistanceNum->setAutoFillBackground(false);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        trip->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(trip);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        trip->setStatusBar(statusbar);

        retranslateUi(trip);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(trip);
    } // setupUi

    void retranslateUi(QMainWindow *trip)
    {
        trip->setWindowTitle(QApplication::translate("trip", "MainWindow", nullptr));
        label->setText(QApplication::translate("trip", "Purchase Souvenirs", nullptr));
        tripButton->setText(QApplication::translate("trip", "Next Team", nullptr));
        label_2->setText(QApplication::translate("trip", "Cart", nullptr));
        tripTeamName->setText(QApplication::translate("trip", "TEAM NAME", nullptr));
        totalDistanceLabel->setText(QApplication::translate("trip", "Total Distance", nullptr));
        totalDistanceNum->setText(QApplication::translate("trip", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class trip: public Ui_trip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIP_H
