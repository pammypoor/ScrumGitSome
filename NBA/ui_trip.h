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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
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
    QLabel *label_2;
    QLabel *tripTeamName;
    QTableView *souvenirsTable;
    QTableWidget *cartTable;
    QWidget *page_2;
    QLabel *label_3;
    QLabel *label_4;
    QTableWidget *arenaTable;
    QLabel *label_7;
    QTableWidget *reviewSouvenirTable;
    QLabel *label_8;
    QTableWidget *reviewTeamTable;
    QGroupBox *groupBox;
    QLabel *totalDistanceNum;
    QLabel *totalDistanceLabel;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *totalSpent;
    QLabel *totalArenasVisited;
    QWidget *page_3;
    QTextBrowser *textBrowser;
    QLabel *labelName;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *trip)
    {
        if (trip->objectName().isEmpty())
            trip->setObjectName(QStringLiteral("trip"));
        trip->resize(1066, 707);
        trip->setStyleSheet(QStringLiteral("background: #D3D3D3;"));
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
        label->setStyleSheet(QLatin1String("color: #D2691E;\n"
"font-size: 25px;"));
        tripButton = new QPushButton(page);
        tripButton->setObjectName(QStringLiteral("tripButton"));
        tripButton->setGeometry(QRect(250, 650, 181, 22));
        tripButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background:#D2691E ;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background: #FF8C00;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}color: white;"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(820, 150, 151, 21));
        label_2->setStyleSheet(QLatin1String("color: #D2691E;\n"
"font-size: 20px;"));
        tripTeamName = new QLabel(page);
        tripTeamName->setObjectName(QStringLiteral("tripTeamName"));
        tripTeamName->setGeometry(QRect(630, 50, 421, 51));
        tripTeamName->setStyleSheet(QLatin1String("font-size: 35px;\n"
"color: #D2691E;"));
        souvenirsTable = new QTableView(page);
        souvenirsTable->setObjectName(QStringLiteral("souvenirsTable"));
        souvenirsTable->setGeometry(QRect(5, 61, 621, 581));
        cartTable = new QTableWidget(page);
        cartTable->setObjectName(QStringLiteral("cartTable"));
        cartTable->setGeometry(QRect(700, 180, 341, 451));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(420, 10, 191, 41));
        label_3->setStyleSheet(QLatin1String("color: #D2691E;\n"
"font-size: 35px;"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 80, 131, 31));
        label_4->setStyleSheet(QLatin1String("color: #D2691E;\n"
"font-size: 20px;"));
        arenaTable = new QTableWidget(page_2);
        arenaTable->setObjectName(QStringLiteral("arenaTable"));
        arenaTable->setGeometry(QRect(335, 120, 321, 321));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(420, 90, 171, 21));
        label_7->setStyleSheet(QLatin1String("color: #D2691E;\n"
"font-size: 20px;"));
        reviewSouvenirTable = new QTableWidget(page_2);
        reviewSouvenirTable->setObjectName(QStringLiteral("reviewSouvenirTable"));
        reviewSouvenirTable->setGeometry(QRect(685, 120, 341, 551));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(760, 90, 191, 21));
        label_8->setStyleSheet(QLatin1String("color: #D2691E;\n"
"font-size: 20px;"));
        reviewTeamTable = new QTableWidget(page_2);
        reviewTeamTable->setObjectName(QStringLiteral("reviewTeamTable"));
        reviewTeamTable->setGeometry(QRect(20, 120, 281, 541));
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(360, 480, 271, 141));
        groupBox->setStyleSheet(QStringLiteral("color: #D2691E;"));
        totalDistanceNum = new QLabel(groupBox);
        totalDistanceNum->setObjectName(QStringLiteral("totalDistanceNum"));
        totalDistanceNum->setGeometry(QRect(170, 30, 91, 21));
        QFont font;
        font.setPointSize(10);
        totalDistanceNum->setFont(font);
        totalDistanceNum->setAutoFillBackground(false);
        totalDistanceLabel = new QLabel(groupBox);
        totalDistanceLabel->setObjectName(QStringLiteral("totalDistanceLabel"));
        totalDistanceLabel->setGeometry(QRect(20, 30, 131, 20));
        totalDistanceLabel->setFont(font);
        totalDistanceLabel->setStyleSheet(QStringLiteral(""));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 60, 91, 21));
        label_5->setFont(font);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 90, 101, 16));
        label_6->setFont(font);
        totalSpent = new QLabel(groupBox);
        totalSpent->setObjectName(QStringLiteral("totalSpent"));
        totalSpent->setGeometry(QRect(170, 60, 91, 21));
        totalSpent->setFont(font);
        totalArenasVisited = new QLabel(groupBox);
        totalArenasVisited->setObjectName(QStringLiteral("totalArenasVisited"));
        totalArenasVisited->setGeometry(QRect(170, 90, 91, 16));
        totalArenasVisited->setFont(font);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        textBrowser = new QTextBrowser(page_3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(310, 120, 451, 481));
        textBrowser->setStyleSheet(QStringLiteral("color: #D2691E;"));
        labelName = new QLabel(page_3);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(420, 60, 271, 41));
        labelName->setStyleSheet(QLatin1String("color: #D2691E;\n"
"font-size: 35px;"));
        stackedWidget->addWidget(page_3);
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
        trip->setWindowTitle(QApplication::translate("trip", "Trip Review", nullptr));
        label->setText(QApplication::translate("trip", "Purchase Souvenirs", nullptr));
        tripButton->setText(QApplication::translate("trip", "Next Team", nullptr));
        label_2->setText(QApplication::translate("trip", "Shopping cart", nullptr));
        tripTeamName->setText(QApplication::translate("trip", "TEAM NAME", nullptr));
        label_3->setText(QApplication::translate("trip", "Trip Details", nullptr));
        label_4->setText(QApplication::translate("trip", "Teams visited:", nullptr));
        label_7->setText(QApplication::translate("trip", "Arenas Visited:", nullptr));
        label_8->setText(QApplication::translate("trip", "Souvenirs purchased:", nullptr));
        groupBox->setTitle(QApplication::translate("trip", "Totals", nullptr));
        totalDistanceNum->setText(QApplication::translate("trip", "TextLabel", nullptr));
        totalDistanceLabel->setText(QApplication::translate("trip", "Total Distance:", nullptr));
        label_5->setText(QApplication::translate("trip", "Total Spent:", nullptr));
        label_6->setText(QApplication::translate("trip", "Total Arenas:", nullptr));
        totalSpent->setText(QApplication::translate("trip", "TextLabel", nullptr));
        totalArenasVisited->setText(QApplication::translate("trip", "TextLabel", nullptr));
        labelName->setText(QApplication::translate("trip", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class trip: public Ui_trip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIP_H
