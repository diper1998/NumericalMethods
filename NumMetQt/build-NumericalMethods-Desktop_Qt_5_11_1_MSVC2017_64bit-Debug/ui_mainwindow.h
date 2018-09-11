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
#include <QtWidgets/QGridLayout>
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

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLineEdit *lineEdit_X;
    QLineEdit *lineEdit_U;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *lineEdit_a1;
    QLabel *label_6;
    QLineEdit *lineEdit_a2;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEdit_m;
    QLineEdit *lineEdit_h;
    QLineEdit *lineEdit_N;
    QPushButton *pushButton_Enter;
    QLabel *label;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(732, 588);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        lineEdit_X = new QLineEdit(groupBox);
        lineEdit_X->setObjectName(QStringLiteral("lineEdit_X"));

        gridLayout->addWidget(lineEdit_X, 1, 2, 1, 1);

        lineEdit_U = new QLineEdit(groupBox);
        lineEdit_U->setObjectName(QStringLiteral("lineEdit_U"));

        gridLayout->addWidget(lineEdit_U, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        lineEdit_a1 = new QLineEdit(groupBox);
        lineEdit_a1->setObjectName(QStringLiteral("lineEdit_a1"));

        gridLayout->addWidget(lineEdit_a1, 2, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        lineEdit_a2 = new QLineEdit(groupBox);
        lineEdit_a2->setObjectName(QStringLiteral("lineEdit_a2"));

        gridLayout->addWidget(lineEdit_a2, 3, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        lineEdit_m = new QLineEdit(groupBox);
        lineEdit_m->setObjectName(QStringLiteral("lineEdit_m"));
        lineEdit_m->setEnabled(true);
        lineEdit_m->setAutoFillBackground(false);

        gridLayout->addWidget(lineEdit_m, 5, 2, 1, 1);

        lineEdit_h = new QLineEdit(groupBox);
        lineEdit_h->setObjectName(QStringLiteral("lineEdit_h"));

        gridLayout->addWidget(lineEdit_h, 6, 2, 1, 1);

        lineEdit_N = new QLineEdit(groupBox);
        lineEdit_N->setObjectName(QStringLiteral("lineEdit_N"));

        gridLayout->addWidget(lineEdit_N, 7, 2, 1, 1);

        pushButton_Enter = new QPushButton(groupBox);
        pushButton_Enter->setObjectName(QStringLiteral("pushButton_Enter"));

        gridLayout->addWidget(pushButton_Enter, 9, 2, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 2, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableWidget = new QTableWidget(groupBox_2);
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
        tableWidget->setAutoScroll(true);

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 2, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 732, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit_U, lineEdit_X);
        QWidget::setTabOrder(lineEdit_X, lineEdit_a1);
        QWidget::setTabOrder(lineEdit_a1, lineEdit_a2);
        QWidget::setTabOrder(lineEdit_a2, lineEdit_m);
        QWidget::setTabOrder(lineEdit_m, lineEdit_h);
        QWidget::setTabOrder(lineEdit_h, lineEdit_N);
        QWidget::setTabOrder(lineEdit_N, pushButton_Enter);
        QWidget::setTabOrder(pushButton_Enter, tableWidget);
        QWidget::setTabOrder(tableWidget, pushButton);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\260\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260(X)", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "U(0)", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 a1", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 a2", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201. \320\272\320\276\320\273-\320\262\320\276 \321\210\320\260\320\263\320\276\320\262(N)", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263(h)", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\201\320\260(m)", nullptr));
        pushButton_Enter->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Vi", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "^Vi", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "U", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
