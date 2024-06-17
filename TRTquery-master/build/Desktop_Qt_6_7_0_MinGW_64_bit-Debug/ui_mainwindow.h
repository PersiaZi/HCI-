/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushEnter;
    QPushButton *pushQuit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(782, 610);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushEnter = new QPushButton(centralwidget);
        pushEnter->setObjectName("pushEnter");
        pushEnter->setGeometry(QRect(180, 410, 131, 71));
        pushEnter->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/resource/Enter.png);\n"
"border-image: url(:/new/prefix1/resource/Enter.png);"));
        pushQuit = new QPushButton(centralwidget);
        pushQuit->setObjectName("pushQuit");
        pushQuit->setGeometry(QRect(480, 410, 131, 71));
        pushQuit->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/resource/Quit.png);\n"
"border-image: url(:/new/prefix1/resource/Quit.png);"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushEnter->setText(QString());
        pushQuit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
