#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(840,630);
    this->setWindowTitle("欢迎使用上海地铁线路查询系统！");
    this->setWindowIcon(QPixmap(":/new/prefix1/resource/logo.png"));

    //设置进入按钮
    functionPage=new FunctionPage;
    connect(ui->pushEnter,&QPushButton::clicked,this,[=](){//pay sttention
        this->hide();
        functionPage->show();
    });
    connect(ui->pushQuit,&QPushButton::clicked,this,&QMainWindow::close);//设置退出按钮
}

//设置主背景
void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/prefix1/resource/Cover.png");
    painter.drawPixmap(0,0,840,630,pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
