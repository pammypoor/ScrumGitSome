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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fanpage
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *fanpage)
    {
        if (fanpage->objectName().isEmpty())
            fanpage->setObjectName(QStringLiteral("fanpage"));
        fanpage->resize(829, 619);
        centralwidget = new QWidget(fanpage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(9, -1, 821, 591));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        fanpage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(fanpage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        fanpage->setStatusBar(statusbar);

        retranslateUi(fanpage);

        QMetaObject::connectSlotsByName(fanpage);
    } // setupUi

    void retranslateUi(QMainWindow *fanpage)
    {
        fanpage->setWindowTitle(QApplication::translate("fanpage", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fanpage: public Ui_fanpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FANPAGE_H
