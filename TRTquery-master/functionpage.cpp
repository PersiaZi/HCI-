#include "functionpage.h"
#include "routemap.h"
#include "stationlist.h"
#include "routeplan.h"//包含3个子窗口的头文件
#include <QToolBar>
#include <QStackedWidget>
#include <QPixmap>

FunctionPage::FunctionPage(QWidget *parent)
    : QMainWindow{parent}
{
    this->setWindowTitle("欢迎使用上海地铁线路查询系统！");
    this->setWindowIcon(QPixmap(":/new/prefix1/resource/logo.png"));
    this->setFixedSize(1200,800);

    //设置工具栏
    QToolBar *toolbar = new QToolBar(this);
    this->addToolBar(Qt::LeftToolBarArea,toolbar);
    toolbar->setMovable(false);
    QAction *action1 = new QAction("线路图", this);
    QAction *action2 = new QAction("车站列表", this);
    QAction *action3 = new QAction("方案规划", this);
    toolbar->addAction(action1);
    toolbar->addAction(action2);
    toolbar->addAction(action3);

    //利用QStackedWidget类创建3个子窗口
    QStackedWidget*stack = new QStackedWidget(this);
    RouteMap*routeMap = new RouteMap;
    StationList*stationList = new StationList;
    RoutePlan*routePlan = new RoutePlan;
    stack->move(71,0);//-71为大概位置，后期再作调整
    QPixmap pixmap1(":/new/prefix1/resource/RouteMap.png");
    stack->resize(pixmap1.size());
    stack->addWidget(routeMap);
    stack->addWidget(stationList);
    stack->addWidget(routePlan);

    //点击导航栏的各个项目时，弹到对应的子窗口
    QObject::connect(action1, &QAction::triggered,this, [=](){//pay attention
        stack->setCurrentIndex(0);
    });
    QObject::connect(action2, &QAction::triggered,this, [=](){//pay attention
        stack->setCurrentIndex(1);
    });
    QObject::connect(action3, &QAction::triggered,this, [=](){//pay attention
        stack->setCurrentIndex(2);
    });
}
