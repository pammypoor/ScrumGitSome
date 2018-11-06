#ifndef FANPAGE_H
#define FANPAGE_H

#include <QMainWindow>

namespace Ui {
class fanpage;
}

class fanpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit fanpage(QWidget *parent = 0);
    ~fanpage();

private:
    Ui::fanpage *ui;
};

#endif // FANPAGE_H
