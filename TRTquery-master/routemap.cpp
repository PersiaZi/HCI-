#include "routemap.h"
#include <QLabel>
#include <QScrollArea>
#include <QImage>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

RouteMap::RouteMap(QWidget *parent)
    : QMainWindow{parent}
{
    this->setWindowTitle("欢迎使用上海地铁线路查询系统！");
    this->setWindowIcon(QPixmap(":/new/prefix1/resource/logo.png"));
    this->resize(1200,800);

    //插入线路图，使用QScrollArea滚动区域
    MainBackground = new QLabel;
    originalMap.load(":/new/prefix1/resource/RouteMap.png");
    //设置图片缩放基本信息
    double scale=0.25;
    QImage scaledMap = originalMap.scaled(originalMap.size()*scale,Qt::KeepAspectRatio,Qt::SmoothTransformation);//等比例放缩
    MainBackground->setPixmap(QPixmap::fromImage(scaledMap));
    scrollArea = new QScrollArea(this);
    scrollArea->move(0,0);
    scrollArea->setFixedSize(this->width()-71,this->height());//-71为大概尺寸，后期再作调整
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(scrollArea);
    scrollArea->setWidget(MainBackground);
    scrollArea->setWidgetResizable(true);


    //设置按钮实现图片缩放
    QPushButton *zoomInButton = new QPushButton("放大",this);
    QPushButton *zoomOutButton = new QPushButton("缩小",this);
    zoomInButton->move(875,50);
    zoomOutButton->move(875+zoomInButton->width(),50);
    zoomInButton->setIcon(QPixmap(":/new/prefix1/resource/magnify.png"));
    zoomOutButton->setIcon(QPixmap(":/new/prefix1/resource/reduce.png"));
    zoomInButton->setStyleSheet("QPushButton { background-color: #18ff08; }");
    zoomOutButton->setStyleSheet("QPushButton { background-color: #ff0000; }");
    connect(zoomInButton,&QPushButton::clicked,this,&RouteMap::zoomInButtonClicked);
    connect(zoomOutButton,&QPushButton::clicked,this,&RouteMap::zoomOutButtonClicked);
}

void RouteMap::zoomInButtonClicked(){
    if(scale<=0.25){
        scale=0.25;
    }
    if(scale<=1&&scale>=0){
        scale+=0.1;
    }
    QImage scaledMap = originalMap.scaled(originalMap.size()*scale,Qt::KeepAspectRatio,Qt::SmoothTransformation);//等比例放缩
    MainBackground->setPixmap(QPixmap::fromImage(scaledMap));
}//放大图像函数

void RouteMap::zoomOutButtonClicked(){
    if(scale<=0.25){
        scale=0.25;
    }
    if(scale<=1&&scale>=0){
        scale-=0.1;
    }
    QImage scaledMap = originalMap.scaled(originalMap.size()*scale,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    MainBackground->setPixmap(QPixmap::fromImage(scaledMap));
}//缩小图像函数
