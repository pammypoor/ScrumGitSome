/********************************************************************************
** Form generated from reading UI file 'fanpage.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FANPAGE_H
#define UI_FANPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fanpage
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frame;
    QPushButton *mainPlanTripButton;
    QPushButton *mainViewSouvenirsButton;
    QPushButton *mainViewTeamsButton;
    QLabel *mainLogo;
    QLabel *label;
    QWidget *page_2;
    QPushButton *backTripButton;
    QGroupBox *groupBox_3;
    QRadioButton *distanceButton;
    QRadioButton *orderButton;
    QComboBox *teamCombo;
    QLabel *label_9;
    QCheckBox *checkBox;
    QTableView *planTripTable;
    QLabel *label_11;
    QLabel *label_13;
    QTableWidget *selectedTeamsTable;
    QPushButton *tripButton;
    QPushButton *shortestTripButton;
    QPushButton *minimumSpanTreeButton;
    QPushButton *dfsButton;
    QPushButton *bfsButton;
    QWidget *page_3;
    QTableView *souvenirTable;
    QPushButton *backSouvenirButton;
    QComboBox *teamNameSouvenirCombo;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *page_4;
    QPushButton *backTeamButton;
    QLabel *label_4;
    QTableView *teamTable;
    QGroupBox *groupBox;
    QRadioButton *teamTeamSortRadio;
    QRadioButton *teamArenaSortRadio;
    QLabel *label_6;
    QRadioButton *teamCapacitySortRadio;
    QRadioButton *teamYearSortRadio;
    QLabel *label_7;
    QComboBox *divisionCombo;
    QRadioButton *easternConferenceRadio;
    QLabel *label_8;
    QRadioButton *showAllConferenceRadio;
    QRadioButton *westernConferenceRadio;
    QLabel *label_5;
    QComboBox *teamNameTeamCombo;
    QGroupBox *groupBox_2;
    QLabel *label_10;
    QLabel *capacityLabel;
    QLabel *label_12;
    QFrame *line;
    QStatusBar *statusbar;
    QButtonGroup *sortTripGroup;
    QButtonGroup *sortByGroup;
    QButtonGroup *conferenceGroup;

    void setupUi(QMainWindow *fanpage)
    {
        if (fanpage->objectName().isEmpty())
            fanpage->setObjectName(QStringLiteral("fanpage"));
        fanpage->resize(1052, 629);
        centralwidget = new QWidget(fanpage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-20, 0, 1081, 661));
        stackedWidget->setStyleSheet(QStringLiteral("background: #003366;"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        frame = new QFrame(page);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(280, 400, 561, 191));
        frame->setStyleSheet(QLatin1String("background: Gainsboro;\n"
"border-radius: 25px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        mainPlanTripButton = new QPushButton(frame);
        mainPlanTripButton->setObjectName(QStringLiteral("mainPlanTripButton"));
        mainPlanTripButton->setGeometry(QRect(20, 30, 161, 131));
        mainPlanTripButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background: #003366;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background: #17408B ;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}"));
        mainViewSouvenirsButton = new QPushButton(frame);
        mainViewSouvenirsButton->setObjectName(QStringLiteral("mainViewSouvenirsButton"));
        mainViewSouvenirsButton->setGeometry(QRect(200, 30, 161, 131));
        mainViewSouvenirsButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background: #003366;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background: #17408B;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}"));
        mainViewTeamsButton = new QPushButton(frame);
        mainViewTeamsButton->setObjectName(QStringLiteral("mainViewTeamsButton"));
        mainViewTeamsButton->setGeometry(QRect(380, 30, 161, 131));
        mainViewTeamsButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background: #003366;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background: #17408B;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}"));
        mainLogo = new QLabel(page);
        mainLogo->setObjectName(QStringLiteral("mainLogo"));
        mainLogo->setGeometry(QRect(440, 50, 241, 241));
        mainLogo->setPixmap(QPixmap(QString::fromUtf8("mainmenu.png")));
        mainLogo->setScaledContents(false);
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 310, 181, 51));
        label->setStyleSheet(QLatin1String("font-size: 35px;\n"
"color: white;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        backTripButton = new QPushButton(page_2);
        backTripButton->setObjectName(QStringLiteral("backTripButton"));
        backTripButton->setGeometry(QRect(980, 570, 80, 22));
        backTripButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        groupBox_3 = new QGroupBox(page_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 490, 581, 61));
        groupBox_3->setStyleSheet(QStringLiteral("color: white;"));
        distanceButton = new QRadioButton(groupBox_3);
        sortTripGroup = new QButtonGroup(fanpage);
        sortTripGroup->setObjectName(QStringLiteral("sortTripGroup"));
        sortTripGroup->addButton(distanceButton);
        distanceButton->setObjectName(QStringLiteral("distanceButton"));
        distanceButton->setGeometry(QRect(10, 30, 121, 20));
        orderButton = new QRadioButton(groupBox_3);
        sortTripGroup->addButton(orderButton);
        orderButton->setObjectName(QStringLiteral("orderButton"));
        orderButton->setGeometry(QRect(120, 30, 91, 20));
        teamCombo = new QComboBox(groupBox_3);
        teamCombo->setObjectName(QStringLiteral("teamCombo"));
        teamCombo->setGeometry(QRect(280, 30, 201, 21));
        teamCombo->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(220, 30, 51, 21));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(490, 30, 72, 20));
        planTripTable = new QTableView(page_2);
        planTripTable->setObjectName(QStringLiteral("planTripTable"));
        planTripTable->setGeometry(QRect(40, 41, 661, 431));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(310, 10, 91, 20));
        label_11->setStyleSheet(QLatin1String("color: white;\n"
"font-size: 25px;"));
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(800, 10, 211, 20));
        label_13->setStyleSheet(QLatin1String("color: white;\n"
"font-size: 25px;"));
        selectedTeamsTable = new QTableWidget(page_2);
        selectedTeamsTable->setObjectName(QStringLiteral("selectedTeamsTable"));
        selectedTeamsTable->setGeometry(QRect(730, 40, 321, 431));
        tripButton = new QPushButton(page_2);
        tripButton->setObjectName(QStringLiteral("tripButton"));
        tripButton->setGeometry(QRect(120, 560, 181, 22));
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
        shortestTripButton = new QPushButton(page_2);
        shortestTripButton->setObjectName(QStringLiteral("shortestTripButton"));
        shortestTripButton->setGeometry(QRect(340, 560, 181, 22));
        shortestTripButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        minimumSpanTreeButton = new QPushButton(page_2);
        minimumSpanTreeButton->setObjectName(QStringLiteral("minimumSpanTreeButton"));
        minimumSpanTreeButton->setGeometry(QRect(680, 500, 181, 22));
        minimumSpanTreeButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        dfsButton = new QPushButton(page_2);
        dfsButton->setObjectName(QStringLiteral("dfsButton"));
        dfsButton->setGeometry(QRect(680, 530, 181, 22));
        dfsButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        bfsButton = new QPushButton(page_2);
        bfsButton->setObjectName(QStringLiteral("bfsButton"));
        bfsButton->setGeometry(QRect(680, 560, 181, 22));
        bfsButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        souvenirTable = new QTableView(page_3);
        souvenirTable->setObjectName(QStringLiteral("souvenirTable"));
        souvenirTable->setGeometry(QRect(35, 61, 1031, 511));
        backSouvenirButton = new QPushButton(page_3);
        backSouvenirButton->setObjectName(QStringLiteral("backSouvenirButton"));
        backSouvenirButton->setGeometry(QRect(980, 580, 80, 22));
        backSouvenirButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        teamNameSouvenirCombo = new QComboBox(page_3);
        teamNameSouvenirCombo->setObjectName(QStringLiteral("teamNameSouvenirCombo"));
        teamNameSouvenirCombo->setGeometry(QRect(740, 30, 281, 22));
        teamNameSouvenirCombo->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(680, 30, 47, 14));
        label_2->setStyleSheet(QStringLiteral("color: white;"));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(420, 30, 191, 20));
        label_3->setStyleSheet(QLatin1String("color: white;\n"
"font-size: 25px;"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        backTeamButton = new QPushButton(page_4);
        backTeamButton->setObjectName(QStringLiteral("backTeamButton"));
        backTeamButton->setGeometry(QRect(950, 570, 111, 22));
        backTeamButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        label_4 = new QLabel(page_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(460, 20, 141, 31));
        label_4->setStyleSheet(QLatin1String("color: white;\n"
"font-size: 25px;"));
        teamTable = new QTableView(page_4);
        teamTable->setObjectName(QStringLiteral("teamTable"));
        teamTable->setGeometry(QRect(35, 61, 1031, 391));
        groupBox = new QGroupBox(page_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 460, 561, 141));
        groupBox->setStyleSheet(QStringLiteral("color: white;"));
        teamTeamSortRadio = new QRadioButton(groupBox);
        sortByGroup = new QButtonGroup(fanpage);
        sortByGroup->setObjectName(QStringLiteral("sortByGroup"));
        sortByGroup->addButton(teamTeamSortRadio);
        teamTeamSortRadio->setObjectName(QStringLiteral("teamTeamSortRadio"));
        teamTeamSortRadio->setGeometry(QRect(20, 110, 85, 20));
        teamArenaSortRadio = new QRadioButton(groupBox);
        sortByGroup->addButton(teamArenaSortRadio);
        teamArenaSortRadio->setObjectName(QStringLiteral("teamArenaSortRadio"));
        teamArenaSortRadio->setGeometry(QRect(120, 110, 85, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 30, 61, 16));
        teamCapacitySortRadio = new QRadioButton(groupBox);
        sortByGroup->addButton(teamCapacitySortRadio);
        teamCapacitySortRadio->setObjectName(QStringLiteral("teamCapacitySortRadio"));
        teamCapacitySortRadio->setGeometry(QRect(220, 110, 111, 20));
        teamYearSortRadio = new QRadioButton(groupBox);
        sortByGroup->addButton(teamYearSortRadio);
        teamYearSortRadio->setObjectName(QStringLiteral("teamYearSortRadio"));
        teamYearSortRadio->setGeometry(QRect(340, 110, 85, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 80, 61, 16));
        divisionCombo = new QComboBox(groupBox);
        divisionCombo->setObjectName(QStringLiteral("divisionCombo"));
        divisionCombo->setGeometry(QRect(380, 50, 161, 22));
        divisionCombo->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        divisionCombo->setInsertPolicy(QComboBox::InsertAtBottom);
        easternConferenceRadio = new QRadioButton(groupBox);
        conferenceGroup = new QButtonGroup(fanpage);
        conferenceGroup->setObjectName(QStringLiteral("conferenceGroup"));
        conferenceGroup->addButton(easternConferenceRadio);
        easternConferenceRadio->setObjectName(QStringLiteral("easternConferenceRadio"));
        easternConferenceRadio->setGeometry(QRect(120, 50, 121, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(330, 50, 47, 21));
        showAllConferenceRadio = new QRadioButton(groupBox);
        conferenceGroup->addButton(showAllConferenceRadio);
        showAllConferenceRadio->setObjectName(QStringLiteral("showAllConferenceRadio"));
        showAllConferenceRadio->setGeometry(QRect(20, 50, 85, 20));
        westernConferenceRadio = new QRadioButton(groupBox);
        conferenceGroup->addButton(westernConferenceRadio);
        westernConferenceRadio->setObjectName(QStringLiteral("westernConferenceRadio"));
        westernConferenceRadio->setGeometry(QRect(220, 50, 85, 20));
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(646, 30, 71, 20));
        label_5->setStyleSheet(QStringLiteral("color: white;"));
        teamNameTeamCombo = new QComboBox(page_4);
        teamNameTeamCombo->setObjectName(QStringLiteral("teamNameTeamCombo"));
        teamNameTeamCombo->setGeometry(QRect(730, 30, 281, 22));
        teamNameTeamCombo->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        groupBox_2 = new QGroupBox(page_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(600, 460, 241, 141));
        groupBox_2->setStyleSheet(QStringLiteral("color: white;"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 30, 201, 16));
        capacityLabel = new QLabel(groupBox_2);
        capacityLabel->setObjectName(QStringLiteral("capacityLabel"));
        capacityLabel->setGeometry(QRect(70, 60, 61, 51));
        capacityLabel->setStyleSheet(QStringLiteral("font-size: 15px;"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(130, 80, 47, 14));
        line = new QFrame(page_4);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(470, 50, 118, 3));
        line->setStyleSheet(QStringLiteral("background: white;"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        stackedWidget->addWidget(page_4);
        fanpage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(fanpage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        fanpage->setStatusBar(statusbar);

        retranslateUi(fanpage);

        stackedWidget->setCurrentIndex(1);
        divisionCombo->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(fanpage);
    } // setupUi

    void retranslateUi(QMainWindow *fanpage)
    {
        fanpage->setWindowTitle(QApplication::translate("fanpage", "MainWindow", nullptr));
        mainPlanTripButton->setText(QApplication::translate("fanpage", "Plan Trip", nullptr));
        mainViewSouvenirsButton->setText(QApplication::translate("fanpage", "View Souvenirs", nullptr));
        mainViewTeamsButton->setText(QApplication::translate("fanpage", "View Teams", nullptr));
        mainLogo->setText(QString());
        label->setText(QApplication::translate("fanpage", "Main Menu", nullptr));
        backTripButton->setText(QApplication::translate("fanpage", "Back", nullptr));
        groupBox_3->setTitle(QApplication::translate("fanpage", "Trip Options", nullptr));
        distanceButton->setText(QApplication::translate("fanpage", "shortest distance", nullptr));
        orderButton->setText(QApplication::translate("fanpage", "order specified", nullptr));
        label_9->setText(QApplication::translate("fanpage", "Starting at", nullptr));
        checkBox->setText(QApplication::translate("fanpage", "all", nullptr));
        label_11->setText(QApplication::translate("fanpage", "Teams", nullptr));
        label_13->setText(QApplication::translate("fanpage", "Teams selected:", nullptr));
        tripButton->setText(QApplication::translate("fanpage", "Plan Trip", nullptr));
        shortestTripButton->setText(QApplication::translate("fanpage", "Travel Shortest Distance", nullptr));
        minimumSpanTreeButton->setText(QApplication::translate("fanpage", "Minimum Spanning Tree", nullptr));
        dfsButton->setText(QApplication::translate("fanpage", "Depth First Search", nullptr));
        bfsButton->setText(QApplication::translate("fanpage", "Breadth First Search", nullptr));
        backSouvenirButton->setText(QApplication::translate("fanpage", "Back", nullptr));
        label_2->setText(QApplication::translate("fanpage", "Show by:", nullptr));
        label_3->setText(QApplication::translate("fanpage", "View Souvenirs", nullptr));
        backTeamButton->setText(QApplication::translate("fanpage", "Back", nullptr));
        label_4->setText(QApplication::translate("fanpage", "View Teams", nullptr));
        groupBox->setTitle(QApplication::translate("fanpage", "Options:", nullptr));
        teamTeamSortRadio->setText(QApplication::translate("fanpage", "Team Name", nullptr));
        teamArenaSortRadio->setText(QApplication::translate("fanpage", "Arena Name", nullptr));
        label_6->setText(QApplication::translate("fanpage", "Conference:", nullptr));
        teamCapacitySortRadio->setText(QApplication::translate("fanpage", "Seating Capacity", nullptr));
        teamYearSortRadio->setText(QApplication::translate("fanpage", "Year Joined", nullptr));
        label_7->setText(QApplication::translate("fanpage", "Sort By:", nullptr));
        easternConferenceRadio->setText(QApplication::translate("fanpage", "Eastern", nullptr));
        label_8->setText(QApplication::translate("fanpage", "Division:", nullptr));
        showAllConferenceRadio->setText(QApplication::translate("fanpage", "Show All", nullptr));
        westernConferenceRadio->setText(QApplication::translate("fanpage", "Western", nullptr));
        label_5->setText(QApplication::translate("fanpage", "Select Team:", nullptr));
        groupBox_2->setTitle(QApplication::translate("fanpage", "Total Capacity", nullptr));
        label_10->setText(QApplication::translate("fanpage", "Total Capacity for teams shown:", nullptr));
        capacityLabel->setText(QApplication::translate("fanpage", "capacity", nullptr));
        label_12->setText(QApplication::translate("fanpage", "seats", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fanpage: public Ui_fanpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FANPAGE_H
