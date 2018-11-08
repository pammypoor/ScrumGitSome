/********************************************************************************
** Form generated from reading UI file 'maintenance.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTENANCE_H
#define UI_MAINTENANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_maintenance
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *settingsPic;
    QLabel *label;
    QPushButton *menuSouvenirButton;
    QPushButton *MenuTeamButton;
    QWidget *page_2;
    QPushButton *teamBackButton;
    QPushButton *addTeamButton;
    QTableView *teamMaintenanceTableView;
    QWidget *page_3;
    QGroupBox *groupBox_2;
    QLabel *SouvenirLabelName;
    QLabel *label_2;
    QLineEdit *SouvenirNameLineEdit;
    QLabel *label_3;
    QDoubleSpinBox *SouvenirCostSpin;
    QComboBox *SouvenirTeamCombo;
    QPushButton *pushButton;
    QPushButton *souvenirBackButton;
    QTableView *SouvenirTableView;
    QLabel *label_4;
    QComboBox *showTeamsCombo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *maintenance)
    {
        if (maintenance->objectName().isEmpty())
            maintenance->setObjectName(QStringLiteral("maintenance"));
        maintenance->resize(800, 600);
        centralwidget = new QWidget(maintenance);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 801, 581));
        stackedWidget->setStyleSheet(QStringLiteral("background: #003366;"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        settingsPic = new QLabel(page);
        settingsPic->setObjectName(QStringLiteral("settingsPic"));
        settingsPic->setGeometry(QRect(260, 120, 281, 221));
        settingsPic->setPixmap(QPixmap(QString::fromUtf8("settings.png")));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 60, 201, 41));
        label->setStyleSheet(QLatin1String("color: white;\n"
"font-size: 35px;"));
        menuSouvenirButton = new QPushButton(page);
        menuSouvenirButton->setObjectName(QStringLiteral("menuSouvenirButton"));
        menuSouvenirButton->setGeometry(QRect(410, 380, 171, 121));
        menuSouvenirButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background:DarkGrey ;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background: Gray;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}"));
        MenuTeamButton = new QPushButton(page);
        MenuTeamButton->setObjectName(QStringLiteral("MenuTeamButton"));
        MenuTeamButton->setGeometry(QRect(200, 380, 171, 121));
        MenuTeamButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background:DarkGrey ;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background: gray;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        teamBackButton = new QPushButton(page_2);
        teamBackButton->setObjectName(QStringLiteral("teamBackButton"));
        teamBackButton->setGeometry(QRect(700, 540, 80, 22));
        teamBackButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        addTeamButton = new QPushButton(page_2);
        addTeamButton->setObjectName(QStringLiteral("addTeamButton"));
        addTeamButton->setGeometry(QRect(290, 510, 201, 22));
        addTeamButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        teamMaintenanceTableView = new QTableView(page_2);
        teamMaintenanceTableView->setObjectName(QStringLiteral("teamMaintenanceTableView"));
        teamMaintenanceTableView->setGeometry(QRect(5, 11, 781, 481));
        teamMaintenanceTableView->setStyleSheet(QLatin1String("QScrollBar{\n"
"	border: 1px solid #999999;\n"
"	background: white;\n"
"	width: 10px;\n"
"	margin: 0px 0px 0px 0px;\n"
"}\n"
"QScrollBar::handle:vertical{\n"
"	background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(32, 47, 130), stop: 0.5 rgb(32, 47, 130), stop:1 rgb(32, 47, 130));\n"
"	min-height: 0px;\n"
"}\n"
""));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        groupBox_2 = new QGroupBox(page_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 400, 421, 161));
        groupBox_2->setStyleSheet(QStringLiteral("color: white;"));
        SouvenirLabelName = new QLabel(groupBox_2);
        SouvenirLabelName->setObjectName(QStringLiteral("SouvenirLabelName"));
        SouvenirLabelName->setGeometry(QRect(20, 40, 81, 16));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 71, 16));
        SouvenirNameLineEdit = new QLineEdit(groupBox_2);
        SouvenirNameLineEdit->setObjectName(QStringLiteral("SouvenirNameLineEdit"));
        SouvenirNameLineEdit->setGeometry(QRect(110, 40, 271, 21));
        SouvenirNameLineEdit->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 100, 81, 16));
        SouvenirCostSpin = new QDoubleSpinBox(groupBox_2);
        SouvenirCostSpin->setObjectName(QStringLiteral("SouvenirCostSpin"));
        SouvenirCostSpin->setGeometry(QRect(110, 70, 271, 21));
        SouvenirCostSpin->setStyleSheet(QStringLiteral(""));
        SouvenirTeamCombo = new QComboBox(groupBox_2);
        SouvenirTeamCombo->setObjectName(QStringLiteral("SouvenirTeamCombo"));
        SouvenirTeamCombo->setGeometry(QRect(110, 100, 271, 22));
        SouvenirTeamCombo->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 130, 80, 22));
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        souvenirBackButton = new QPushButton(page_3);
        souvenirBackButton->setObjectName(QStringLiteral("souvenirBackButton"));
        souvenirBackButton->setGeometry(QRect(700, 540, 80, 22));
        souvenirBackButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background:DarkGrey ;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background: Gray;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}"));
        SouvenirTableView = new QTableView(page_3);
        SouvenirTableView->setObjectName(QStringLiteral("SouvenirTableView"));
        SouvenirTableView->setGeometry(QRect(15, 11, 771, 381));
        SouvenirTableView->setStyleSheet(QStringLiteral(""));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(510, 430, 47, 14));
        label_4->setStyleSheet(QStringLiteral("color: white;"));
        showTeamsCombo = new QComboBox(page_3);
        showTeamsCombo->setObjectName(QStringLiteral("showTeamsCombo"));
        showTeamsCombo->setGeometry(QRect(550, 421, 231, 31));
        showTeamsCombo->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        stackedWidget->addWidget(page_3);
        maintenance->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(maintenance);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        maintenance->setStatusBar(statusbar);

        retranslateUi(maintenance);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(maintenance);
    } // setupUi

    void retranslateUi(QMainWindow *maintenance)
    {
        maintenance->setWindowTitle(QApplication::translate("maintenance", "MainWindow", nullptr));
        settingsPic->setText(QString());
        label->setText(QApplication::translate("maintenance", "Maintenance", nullptr));
        menuSouvenirButton->setText(QApplication::translate("maintenance", "Modify Souvenirs", nullptr));
        MenuTeamButton->setText(QApplication::translate("maintenance", "Modify Teams", nullptr));
        teamBackButton->setText(QApplication::translate("maintenance", "Back", nullptr));
        addTeamButton->setText(QApplication::translate("maintenance", "Add Team File", nullptr));
        groupBox_2->setTitle(QApplication::translate("maintenance", "Add Souvenir", nullptr));
        SouvenirLabelName->setText(QApplication::translate("maintenance", "Product name:", nullptr));
        label_2->setText(QApplication::translate("maintenance", "Product Cost:", nullptr));
        label_3->setText(QApplication::translate("maintenance", "Product Team:", nullptr));
        pushButton->setText(QApplication::translate("maintenance", "Add", nullptr));
        souvenirBackButton->setText(QApplication::translate("maintenance", "Back", nullptr));
        label_4->setText(QApplication::translate("maintenance", "Show:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class maintenance: public Ui_maintenance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTENANCE_H
