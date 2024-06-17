/********************************************************************************
** Form generated from reading UI file 'station.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATION_H
#define UI_STATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Station
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Station)
    {
        if (Station->objectName().isEmpty())
            Station->setObjectName("Station");
        Station->resize(800, 600);
        centralwidget = new QWidget(Station);
        centralwidget->setObjectName("centralwidget");
        Station->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Station);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        Station->setMenuBar(menubar);
        statusbar = new QStatusBar(Station);
        statusbar->setObjectName("statusbar");
        Station->setStatusBar(statusbar);

        retranslateUi(Station);

        QMetaObject::connectSlotsByName(Station);
    } // setupUi

    void retranslateUi(QMainWindow *Station)
    {
        Station->setWindowTitle(QCoreApplication::translate("Station", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Station: public Ui_Station {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATION_H
