/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
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
    QFrame *frame;
    QPushButton *logOnPushButton;
    QLabel *label;
    QCheckBox *showPassword;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *logo;
    QLabel *label_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(908, 682);
        MainWindow->setStyleSheet(QStringLiteral("background: #003366;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(180, 320, 571, 291));
        frame->setStyleSheet(QLatin1String("background: Gainsboro;\n"
"border-radius: 25px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        logOnPushButton = new QPushButton(frame);
        logOnPushButton->setObjectName(QStringLiteral("logOnPushButton"));
        logOnPushButton->setGeometry(QRect(90, 200, 411, 41));
        logOnPushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background:#17408B ;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"background: #003366;\n"
"color: white;\n"
"border-radius: 10px;\n"
"}"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 20, 131, 61));
        QFont font;
        label->setFont(font);
        label->setStyleSheet(QLatin1String("font-size: 35px;\n"
"color: #17408B;"));
        showPassword = new QCheckBox(frame);
        showPassword->setObjectName(QStringLiteral("showPassword"));
        showPassword->setGeometry(QRect(100, 170, 101, 20));
        showPassword->setStyleSheet(QLatin1String("border: #003366;\n"
"color: #003366;"));
        usernameLineEdit = new QLineEdit(frame);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(100, 100, 391, 20));
        usernameLineEdit->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        passwordLineEdit = new QLineEdit(frame);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(100, 148, 391, 20));
        passwordLineEdit->setStyleSheet(QLatin1String("background: white;\n"
"border: 1px solid Gray;\n"
"border-radius: 5px;\n"
"color: #003366;"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 80, 61, 16));
        label_3->setStyleSheet(QStringLiteral("color: #003366;"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 130, 51, 16));
        label_4->setStyleSheet(QStringLiteral("color: #003366;"));
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(330, 90, 301, 191));
        logo->setPixmap(QPixmap(QString::fromUtf8("NBALogo.png")));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 630, 291, 20));
        label_2->setStyleSheet(QStringLiteral("color: white;"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        logOnPushButton->setText(QApplication::translate("MainWindow", "Submit", nullptr));
        label->setText(QApplication::translate("MainWindow", "Log In", nullptr));
        showPassword->setText(QApplication::translate("MainWindow", "Show Password", nullptr));
        usernameLineEdit->setText(QString());
        passwordLineEdit->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Username:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Password:", nullptr));
        logo->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Copyright \302\251 2018 NBA Properties Inc. All Rights Reserved.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
