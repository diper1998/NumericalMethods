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
#include <QtWidgets/QCheckBox>
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
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label_maxe1;
    QLabel *label_mine1;
    QLabel *label_maxe2;
    QLabel *label_mine2;
    QLabel *label_maxS;
    QLabel *label_minS;
    QLabel *label_mulh;
    QLabel *label_divh;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_V1;
    QLabel *label_2;
    QLineEdit *lineEdit_V2;
    QLabel *label_6;
    QLineEdit *lineEdit_h;
    QLabel *label_7;
    QLineEdit *lineEdit_N;
    QLabel *label_3;
    QLineEdit *lineEdit_m;
    QLabel *label_8;
    QLineEdit *lineEdit_c;
    QLabel *label_4;
    QLineEdit *lineEdit_k;
    QLabel *label_9;
    QLineEdit *lineEdit_d;
    QLabel *label_5;
    QLineEdit *lineEdit_f;
    QLabel *label_10;
    QLineEdit *lineEdit_M;
    QGroupBox *groupBox_3;
    QTableWidget *tableWidget;
    QPushButton *pushButton_Enter;
    QCustomPlot *graph;
    QCustomPlot *graphPortret;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Portret;
    QCheckBox *checkBox_Control;
    QCheckBox *checkBox_End;
    QLineEdit *lineEdit_X;
    QLineEdit *lineEdit_Eb;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1177, 723);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(230, 10, 251, 221));
        label_maxe1 = new QLabel(groupBox);
        label_maxe1->setObjectName(QStringLiteral("label_maxe1"));
        label_maxe1->setGeometry(QRect(10, 30, 311, 16));
        label_mine1 = new QLabel(groupBox);
        label_mine1->setObjectName(QStringLiteral("label_mine1"));
        label_mine1->setGeometry(QRect(10, 50, 311, 16));
        label_maxe2 = new QLabel(groupBox);
        label_maxe2->setObjectName(QStringLiteral("label_maxe2"));
        label_maxe2->setGeometry(QRect(10, 70, 311, 16));
        label_mine2 = new QLabel(groupBox);
        label_mine2->setObjectName(QStringLiteral("label_mine2"));
        label_mine2->setGeometry(QRect(10, 90, 311, 16));
        label_maxS = new QLabel(groupBox);
        label_maxS->setObjectName(QStringLiteral("label_maxS"));
        label_maxS->setGeometry(QRect(10, 120, 301, 16));
        label_minS = new QLabel(groupBox);
        label_minS->setObjectName(QStringLiteral("label_minS"));
        label_minS->setGeometry(QRect(10, 140, 311, 16));
        label_mulh = new QLabel(groupBox);
        label_mulh->setObjectName(QStringLiteral("label_mulh"));
        label_mulh->setGeometry(QRect(10, 170, 121, 16));
        label_divh = new QLabel(groupBox);
        label_divh->setObjectName(QStringLiteral("label_divh"));
        label_divh->setGeometry(QRect(10, 190, 101, 16));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 201, 209));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_V1 = new QLineEdit(groupBox_2);
        lineEdit_V1->setObjectName(QStringLiteral("lineEdit_V1"));

        gridLayout->addWidget(lineEdit_V1, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_V2 = new QLineEdit(groupBox_2);
        lineEdit_V2->setObjectName(QStringLiteral("lineEdit_V2"));

        gridLayout->addWidget(lineEdit_V2, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        lineEdit_h = new QLineEdit(groupBox_2);
        lineEdit_h->setObjectName(QStringLiteral("lineEdit_h"));

        gridLayout->addWidget(lineEdit_h, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        lineEdit_N = new QLineEdit(groupBox_2);
        lineEdit_N->setObjectName(QStringLiteral("lineEdit_N"));

        gridLayout->addWidget(lineEdit_N, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        lineEdit_m = new QLineEdit(groupBox_2);
        lineEdit_m->setObjectName(QStringLiteral("lineEdit_m"));

        gridLayout->addWidget(lineEdit_m, 4, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setEnabled(false);

        gridLayout->addWidget(label_8, 4, 2, 1, 1);

        lineEdit_c = new QLineEdit(groupBox_2);
        lineEdit_c->setObjectName(QStringLiteral("lineEdit_c"));
        lineEdit_c->setEnabled(false);

        gridLayout->addWidget(lineEdit_c, 4, 3, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        lineEdit_k = new QLineEdit(groupBox_2);
        lineEdit_k->setObjectName(QStringLiteral("lineEdit_k"));

        gridLayout->addWidget(lineEdit_k, 5, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setEnabled(false);

        gridLayout->addWidget(label_9, 5, 2, 1, 1);

        lineEdit_d = new QLineEdit(groupBox_2);
        lineEdit_d->setObjectName(QStringLiteral("lineEdit_d"));
        lineEdit_d->setEnabled(false);

        gridLayout->addWidget(lineEdit_d, 5, 3, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        lineEdit_f = new QLineEdit(groupBox_2);
        lineEdit_f->setObjectName(QStringLiteral("lineEdit_f"));

        gridLayout->addWidget(lineEdit_f, 6, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setEnabled(false);

        gridLayout->addWidget(label_10, 6, 2, 1, 1);

        lineEdit_M = new QLineEdit(groupBox_2);
        lineEdit_M->setObjectName(QStringLiteral("lineEdit_M"));
        lineEdit_M->setEnabled(false);

        gridLayout->addWidget(lineEdit_M, 6, 3, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 240, 471, 421));
        tableWidget = new QTableWidget(groupBox_3);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 441, 391));
        pushButton_Enter = new QPushButton(centralWidget);
        pushButton_Enter->setObjectName(QStringLiteral("pushButton_Enter"));
        pushButton_Enter->setGeometry(QRect(490, 170, 81, 23));
        graph = new QCustomPlot(centralWidget);
        graph->setObjectName(QStringLiteral("graph"));
        graph->setGeometry(QRect(580, 10, 561, 221));
        graphPortret = new QCustomPlot(centralWidget);
        graphPortret->setObjectName(QStringLiteral("graphPortret"));
        graphPortret->setGeometry(QRect(580, 250, 561, 411));
        pushButton_Clear = new QPushButton(centralWidget);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(490, 140, 81, 21));
        pushButton_Portret = new QPushButton(centralWidget);
        pushButton_Portret->setObjectName(QStringLiteral("pushButton_Portret"));
        pushButton_Portret->setGeometry(QRect(490, 250, 81, 31));
        checkBox_Control = new QCheckBox(centralWidget);
        checkBox_Control->setObjectName(QStringLiteral("checkBox_Control"));
        checkBox_Control->setGeometry(QRect(490, 20, 81, 17));
        checkBox_End = new QCheckBox(centralWidget);
        checkBox_End->setObjectName(QStringLiteral("checkBox_End"));
        checkBox_End->setGeometry(QRect(490, 80, 70, 17));
        lineEdit_X = new QLineEdit(centralWidget);
        lineEdit_X->setObjectName(QStringLiteral("lineEdit_X"));
        lineEdit_X->setGeometry(QRect(490, 110, 81, 20));
        lineEdit_Eb = new QLineEdit(centralWidget);
        lineEdit_Eb->setObjectName(QStringLiteral("lineEdit_Eb"));
        lineEdit_Eb->setGeometry(QRect(490, 45, 81, 20));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1177, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        label_maxe1->setText(QApplication::translate("MainWindow", "Max( e1 ) = ", nullptr));
        label_mine1->setText(QApplication::translate("MainWindow", "Min( e1 ) =", nullptr));
        label_maxe2->setText(QApplication::translate("MainWindow", "Max( e2 ) = ", nullptr));
        label_mine2->setText(QApplication::translate("MainWindow", "Min( e2 ) =", nullptr));
        label_maxS->setText(QApplication::translate("MainWindow", "Max(S) =", nullptr));
        label_minS->setText(QApplication::translate("MainWindow", "Min(S) =", nullptr));
        label_mulh->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\262\320\276\320\265\320\275\320\270\320\265 h:", nullptr));
        label_divh->setText(QApplication::translate("MainWindow", "\320\224\320\265\320\273\320\265\320\275\320\270\320\265 h:", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        label->setText(QApplication::translate("MainWindow", " U(0)", nullptr));
        lineEdit_V1->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_2->setText(QApplication::translate("MainWindow", " U'(0) ", nullptr));
        lineEdit_V2->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "h", nullptr));
        lineEdit_h->setText(QApplication::translate("MainWindow", "0.01", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "N", nullptr));
        lineEdit_N->setText(QApplication::translate("MainWindow", "1000", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "a", nullptr));
        lineEdit_m->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "c", nullptr));
        lineEdit_c->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "b", nullptr));
        lineEdit_k->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "d", nullptr));
        lineEdit_d->setText(QApplication::translate("MainWindow", "2", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\321\201", nullptr));
        lineEdit_f->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "M", nullptr));
        lineEdit_M->setText(QApplication::translate("MainWindow", "1", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "h", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "V1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "V2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "^V1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "^V2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "e1", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "e2", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "S", nullptr));
        pushButton_Enter->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        pushButton_Clear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton_Portret->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\267 \320\277\320\276\321\200\321\202\321\200\320\265\321\202", nullptr));
        checkBox_Control->setText(QApplication::translate("MainWindow", "  \320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214", nullptr));
        checkBox_End->setText(QApplication::translate("MainWindow", " \320\223\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        lineEdit_X->setText(QApplication::translate("MainWindow", "1", nullptr));
        lineEdit_Eb->setText(QApplication::translate("MainWindow", "1e-4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
