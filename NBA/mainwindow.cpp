#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(LOGOPIC);
    ui->logo->setPixmap(pix.scaled(650,500, Qt::IgnoreAspectRatio, Qt::FastTransformation));
    setWindowTitle("Let's Play NBA Basketball");
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logOnPushButton_clicked()
{
    if(ui->usernameLineEdit->text().isEmpty() || ui->passwordLineEdit->text().isEmpty())
    {
        qDebug() << "Nothing entered.";
    }
    QString usertype = DbManager::instance().LoginCheck(ui->usernameLineEdit->text(), ui->passwordLineEdit->text());

    if(usertype == "fan")
    {
        //open fan page
        close();
        fanPage = new fanpage;
        fanPage->show();
        qDebug() << "Fan page opened.";
    }
    else if(usertype == "admin")
    {
        //open maintenance page
        close();
        adminPage = new maintenance;
        adminPage->show();
        qDebug() <<"Maintanence page opened.";
    }
    else
    {
        QMessageBox::information(this, "Login", "Invalid Login. Try Again.");
    }
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}

//Allows user to hide or show password when logging in
void MainWindow::on_showPassword_stateChanged(int arg1)
{
    ui->passwordLineEdit->setEchoMode(ui->showPassword->checkState()== Qt::Checked ? QLineEdit::Normal: QLineEdit::Password);
}

void MainWindow::on_passwordLineEdit_returnPressed()
{
    on_logOnPushButton_clicked();
}
