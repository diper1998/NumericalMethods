/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_2;
    QCustomPlot *graph;
    QGroupBox *groupBox_3;
    QLabel *label;
    QLineEdit *lineEdit_Splitting;
    QGroupBox *groupBox_4;
    QLabel *label_2;
    QLabel *label_Accuracy;
    QLabel *label_3;
    QLabel *label_X;
    QPushButton *pushButton_Task1;
    QPushButton *pushButton_Task2;
    QPushButton *pushButton_Task3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(759, 634);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(270, 10, 461, 241));
        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 441, 211));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 290, 721, 291));
        graph = new QCustomPlot(groupBox_2);
        graph->setObjectName(QStringLiteral("graph"));
        graph->setGeometry(QRect(20, 20, 681, 261));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 120, 80));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 91, 16));
        lineEdit_Splitting = new QLineEdit(groupBox_3);
        lineEdit_Splitting->setObjectName(QStringLiteral("lineEdit_Splitting"));
        lineEdit_Splitting->setGeometry(QRect(10, 40, 101, 20));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 100, 241, 171));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 161, 16));
        label_Accuracy = new QLabel(groupBox_4);
        label_Accuracy->setObjectName(QStringLiteral("label_Accuracy"));
        label_Accuracy->setGeometry(QRect(10, 40, 221, 16));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 47, 13));
        label_X = new QLabel(groupBox_4);
        label_X->setObjectName(QStringLiteral("label_X"));
        label_X->setGeometry(QRect(60, 60, 171, 16));
        pushButton_Task1 = new QPushButton(centralWidget);
        pushButton_Task1->setObjectName(QStringLiteral("pushButton_Task1"));
        pushButton_Task1->setGeometry(QRect(270, 260, 121, 23));
        pushButton_Task2 = new QPushButton(centralWidget);
        pushButton_Task2->setObjectName(QStringLiteral("pushButton_Task2"));
        pushButton_Task2->setGeometry(QRect(400, 260, 121, 23));
        pushButton_Task3 = new QPushButton(centralWidget);
        pushButton_Task3->setObjectName(QStringLiteral("pushButton_Task3"));
        pushButton_Task3->setGeometry(QRect(530, 260, 111, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 759, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Xi", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Vi", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Ui", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "|Vi-Ui|", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \321\200\320\260\320\267\320\261\320\270\320\265\320\275\320\270\320\271", nullptr));
        lineEdit_Splitting->setText(QApplication::translate("MainWindow", "500", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\321\214:", nullptr));
        label_Accuracy->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270 x =", nullptr));
        label_X->setText(QString());
        pushButton_Task1->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260 \342\204\2261", nullptr));
        pushButton_Task2->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\260\320\262\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260 \342\204\2262", nullptr));
        pushButton_Task3->setText(QApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
