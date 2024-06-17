#ifndef ROUTEPLAN_H
#define ROUTEPLAN_H

#include <QMainWindow>


class RoutePlan : public QMainWindow
{
    Q_OBJECT
public:
    explicit RoutePlan(QWidget *parent = nullptr);

    void onCheckBoxStateChanged(int state);

signals:
};

//extern int countTransfer;//记录换乘次数

#endif // ROUTEPLAN_H
