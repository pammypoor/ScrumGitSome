#include "fanpage.h"
#include "ui_fanpage.h"

fanpage::fanpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fanpage)
{
    ui->setupUi(this);
}

fanpage::~fanpage()
{
    delete ui;
}
