/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidgetRadios;
    QListWidget *listWidgetFavorites;
    QPushButton *buttonPlay;
    QPushButton *buttonStop;
    QPushButton *buttonAddToFavorites;
    QPushButton *buttonRemoveFromFavorites;
    QLineEdit *lineEditSearch;
    QPushButton *buttonSearch;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(638, 545);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidgetRadios = new QListWidget(centralwidget);
        listWidgetRadios->setObjectName(QString::fromUtf8("listWidgetRadios"));
        listWidgetRadios->setGeometry(QRect(10, 10, 300, 401));
        listWidgetFavorites = new QListWidget(centralwidget);
        listWidgetFavorites->setObjectName(QString::fromUtf8("listWidgetFavorites"));
        listWidgetFavorites->setGeometry(QRect(320, 10, 300, 400));
        listWidgetFavorites->setSelectionMode(QAbstractItemView::SingleSelection);
        buttonPlay = new QPushButton(centralwidget);
        buttonPlay->setObjectName(QString::fromUtf8("buttonPlay"));
        buttonPlay->setGeometry(QRect(10, 420, 80, 26));
        buttonStop = new QPushButton(centralwidget);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
        buttonStop->setGeometry(QRect(100, 420, 80, 26));
        buttonAddToFavorites = new QPushButton(centralwidget);
        buttonAddToFavorites->setObjectName(QString::fromUtf8("buttonAddToFavorites"));
        buttonAddToFavorites->setGeometry(QRect(320, 420, 120, 26));
        buttonRemoveFromFavorites = new QPushButton(centralwidget);
        buttonRemoveFromFavorites->setObjectName(QString::fromUtf8("buttonRemoveFromFavorites"));
        buttonRemoveFromFavorites->setGeometry(QRect(450, 420, 160, 26));
        lineEditSearch = new QLineEdit(centralwidget);
        lineEditSearch->setObjectName(QString::fromUtf8("lineEditSearch"));
        lineEditSearch->setGeometry(QRect(10, 460, 200, 26));
        buttonSearch = new QPushButton(centralwidget);
        buttonSearch->setObjectName(QString::fromUtf8("buttonSearch"));
        buttonSearch->setGeometry(QRect(220, 460, 80, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 638, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(buttonPlay, SIGNAL(clicked()), MainWindow, SLOT(on_buttonPlay_clicked()));
        QObject::connect(buttonStop, SIGNAL(clicked()), MainWindow, SLOT(on_buttonStop_clicked()));
        QObject::connect(buttonAddToFavorites, SIGNAL(clicked()), MainWindow, SLOT(on_buttonAddToFavorites_clicked()));
        QObject::connect(buttonRemoveFromFavorites, SIGNAL(clicked()), MainWindow, SLOT(on_buttonRemoveFromFavorites_clicked()));
        QObject::connect(buttonSearch, SIGNAL(clicked()), MainWindow, SLOT(on_buttonSearch_clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonPlay->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        buttonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        buttonAddToFavorites->setText(QCoreApplication::translate("MainWindow", "Add to Favorites", nullptr));
        buttonRemoveFromFavorites->setText(QCoreApplication::translate("MainWindow", "Remove from Favorites", nullptr));
        buttonSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
