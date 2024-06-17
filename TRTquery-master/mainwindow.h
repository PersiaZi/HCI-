#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "functionpage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //画背景图
    void paintEvent(QPaintEvent*);

    //点击“进入”，进入线路图
    FunctionPage*functionPage=nullptr;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
