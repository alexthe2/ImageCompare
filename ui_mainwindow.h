/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Window;
    QAction *actionLoad_Pictures;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *mainLayout;
    QGraphicsView *item_0_0;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuPictures;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 1018);
        actionLoad_Window = new QAction(MainWindow);
        actionLoad_Window->setObjectName(QStringLiteral("actionLoad_Window"));
        actionLoad_Pictures = new QAction(MainWindow);
        actionLoad_Pictures->setObjectName(QStringLiteral("actionLoad_Pictures"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 1001, 981));
        mainLayout = new QGridLayout(gridLayoutWidget);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        mainLayout->setContentsMargins(10, 10, 10, 10);
        item_0_0 = new QGraphicsView(gridLayoutWidget);
        item_0_0->setObjectName(QStringLiteral("item_0_0"));

        mainLayout->addWidget(item_0_0, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuPictures = new QMenu(menubar);
        menuPictures->setObjectName(QStringLiteral("menuPictures"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuPictures->menuAction());
        menuFile->addAction(actionLoad_Window);
        menuPictures->addAction(actionLoad_Pictures);

        retranslateUi(MainWindow);
        QObject::connect(actionLoad_Window, SIGNAL(triggered()), MainWindow, SLOT(SetWindow()));
        QObject::connect(actionLoad_Pictures, SIGNAL(triggered()), MainWindow, SLOT(LoadImages()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionLoad_Window->setText(QApplication::translate("MainWindow", "Load Window", Q_NULLPTR));
        actionLoad_Pictures->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuPictures->setTitle(QApplication::translate("MainWindow", "Pictures", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
