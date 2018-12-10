/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *logo;
    QLabel *label_2;
    QFrame *line;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *label_4;
    QLabel *label_3;
    QCheckBox *showPassword;
    QPushButton *logOnPushButton;
    QLabel *label;
    QLabel *label_5;
    QFrame *line_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(908, 682);
        MainWindow->setStyleSheet(QLatin1String("background: #D3D3D3;\n"
"color: #D2691E ;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(-130, 80, 431, 501));
        logo->setPixmap(QPixmap(QString::fromUtf8("NBALogo.png")));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 630, 341, 20));
        label_2->setStyleSheet(QStringLiteral(""));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(360, 120, 51, 411));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        usernameLineEdit = new QLineEdit(centralWidget);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(490, 270, 391, 20));
        usernameLineEdit->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        passwordLineEdit = new QLineEdit(centralWidget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(490, 300, 391, 20));
        passwordLineEdit->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(410, 300, 61, 16));
        label_4->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(410, 270, 61, 16));
        label_3->setStyleSheet(QStringLiteral(""));
        showPassword = new QCheckBox(centralWidget);
        showPassword->setObjectName(QStringLiteral("showPassword"));
        showPassword->setGeometry(QRect(490, 330, 141, 20));
        showPassword->setStyleSheet(QLatin1String("border: #white;\n"
"color: #white;"));
        logOnPushButton = new QPushButton(centralWidget);
        logOnPushButton->setObjectName(QStringLiteral("logOnPushButton"));
        logOnPushButton->setGeometry(QRect(490, 360, 391, 41));
        logOnPushButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(640, 190, 91, 61));
        QFont font;
        label->setFont(font);
        label->setStyleSheet(QLatin1String("font-size: 35px;\n"
""));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(550, 410, 281, 20));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(620, 240, 118, 3));
        line_2->setStyleSheet(QStringLiteral("background: #D2691E ;"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        logo->raise();
        label_2->raise();
        line->raise();
        usernameLineEdit->raise();
        passwordLineEdit->raise();
        label_4->raise();
        label_3->raise();
        showPassword->raise();
        logOnPushButton->raise();
        label_5->raise();
        label->raise();
        line_2->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        logo->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Copyright \302\251 2018 NBA Properties Inc. All Rights Reserved.", nullptr));
        usernameLineEdit->setText(QString());
        passwordLineEdit->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Password:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Username:", nullptr));
        showPassword->setText(QApplication::translate("MainWindow", "Show Password", nullptr));
        logOnPushButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QApplication::translate("MainWindow", "Login", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Don't have an account?     /    Forgot Password?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
