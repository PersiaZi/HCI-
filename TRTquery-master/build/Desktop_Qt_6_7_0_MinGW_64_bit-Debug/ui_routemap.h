/********************************************************************************
** Form generated from reading UI file 'routemap.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTEMAP_H
#define UI_ROUTEMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RouteMap
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *RouteMap)
    {
        if (RouteMap->objectName().isEmpty())
            RouteMap->setObjectName("RouteMap");
        RouteMap->resize(800, 600);
        centralwidget = new QWidget(RouteMap);
        centralwidget->setObjectName("centralwidget");
        RouteMap->setCentralWidget(centralwidget);

        retranslateUi(RouteMap);

        QMetaObject::connectSlotsByName(RouteMap);
    } // setupUi

    void retranslateUi(QMainWindow *RouteMap)
    {
        RouteMap->setWindowTitle(QCoreApplication::translate("RouteMap", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RouteMap: public Ui_RouteMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTEMAP_H
