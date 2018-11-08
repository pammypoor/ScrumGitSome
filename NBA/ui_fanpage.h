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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
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
    QPushButton *mainViewArenasButton;
    QLabel *mainLogo;
    QLabel *label;
    QWidget *page_2;
    QWidget *page_3;
    QTableView *souvenirTable;
    QPushButton *backSouvenirButton;
    QComboBox *teamNameSouvenirCombo;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *page_4;
    QPushButton *backTeamButton;
    QLabel *label_4;
    QComboBox *teamNameTeamCombo;
    QLabel *label_5;
    QTableView *teamTable;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *fanpage)
    {
        if (fanpage->objectName().isEmpty())
            fanpage->setObjectName(QStringLiteral("fanpage"));
        fanpage->resize(1011, 629);
        centralwidget = new QWidget(fanpage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-20, 0, 1031, 661));
        stackedWidget->setStyleSheet(QStringLiteral("background: #003366;"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        frame = new QFrame(page);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(110, 390, 851, 191));
        frame->setStyleSheet(QLatin1String("background: Gainsboro;\n"
"border-radius: 25px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        mainPlanTripButton = new QPushButton(frame);
        mainPlanTripButton->setObjectName(QStringLiteral("mainPlanTripButton"));
        mainPlanTripButton->setGeometry(QRect(40, 30, 161, 131));
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
        mainViewSouvenirsButton->setGeometry(QRect(240, 30, 161, 131));
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
        mainViewTeamsButton->setGeometry(QRect(440, 30, 161, 131));
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
        mainViewArenasButton = new QPushButton(frame);
        mainViewArenasButton->setObjectName(QStringLiteral("mainViewArenasButton"));
        mainViewArenasButton->setGeometry(QRect(640, 30, 161, 131));
        mainViewArenasButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        souvenirTable = new QTableView(page_3);
        souvenirTable->setObjectName(QStringLiteral("souvenirTable"));
        souvenirTable->setGeometry(QRect(35, 61, 981, 511));
        backSouvenirButton = new QPushButton(page_3);
        backSouvenirButton->setObjectName(QStringLiteral("backSouvenirButton"));
        backSouvenirButton->setGeometry(QRect(940, 580, 80, 22));
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
        backTeamButton->setGeometry(QRect(940, 580, 80, 22));
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
        label_4->setGeometry(QRect(440, 30, 191, 20));
        label_4->setStyleSheet(QLatin1String("color: white;\n"
"font-size: 25px;"));
        teamNameTeamCombo = new QComboBox(page_4);
        teamNameTeamCombo->setObjectName(QStringLiteral("teamNameTeamCombo"));
        teamNameTeamCombo->setGeometry(QRect(730, 30, 281, 22));
        teamNameTeamCombo->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(670, 30, 47, 14));
        label_5->setStyleSheet(QStringLiteral("color: white;"));
        teamTable = new QTableView(page_4);
        teamTable->setObjectName(QStringLiteral("teamTable"));
        teamTable->setGeometry(QRect(35, 61, 981, 511));
        stackedWidget->addWidget(page_4);
        fanpage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(fanpage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        fanpage->setStatusBar(statusbar);

        retranslateUi(fanpage);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(fanpage);
    } // setupUi

    void retranslateUi(QMainWindow *fanpage)
    {
        fanpage->setWindowTitle(QApplication::translate("fanpage", "MainWindow", nullptr));
        mainPlanTripButton->setText(QApplication::translate("fanpage", "Plan Custom Trip", nullptr));
        mainViewSouvenirsButton->setText(QApplication::translate("fanpage", "View Souvenirs", nullptr));
        mainViewTeamsButton->setText(QApplication::translate("fanpage", "View Teams", nullptr));
        mainViewArenasButton->setText(QApplication::translate("fanpage", "View Arenas", nullptr));
        mainLogo->setText(QString());
        label->setText(QApplication::translate("fanpage", "Main Menu", nullptr));
        backSouvenirButton->setText(QApplication::translate("fanpage", "Back", nullptr));
        label_2->setText(QApplication::translate("fanpage", "Show by:", nullptr));
        label_3->setText(QApplication::translate("fanpage", "View Souvenirs", nullptr));
        backTeamButton->setText(QApplication::translate("fanpage", "Back", nullptr));
        label_4->setText(QApplication::translate("fanpage", "View Teams", nullptr));
        label_5->setText(QApplication::translate("fanpage", "Show by:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fanpage: public Ui_fanpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FANPAGE_H
