#ifndef ROUTEMAP_H
#define ROUTEMAP_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>

class RouteMap : public QMainWindow
{
    Q_OBJECT
public:
    explicit RouteMap(QWidget *parent = nullptr);

    RouteMap*routeMap=nullptr;
    mutable double scale;
    void zoomInButtonClicked();
    void zoomOutButtonClicked();
    QLabel *MainBackground;
    QImage originalMap;
    QScrollArea *scrollArea;


signals:

};

#endif // ROUTEMAP_H
