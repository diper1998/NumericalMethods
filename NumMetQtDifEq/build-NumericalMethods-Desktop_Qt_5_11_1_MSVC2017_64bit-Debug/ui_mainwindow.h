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
#include <QtWidgets/QRadioButton>
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
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_7;
    QPushButton *pushButton_Enter;
    QLineEdit *lineEdit_h;
    QLineEdit *lineEdit_m;
    QLineEdit *lineEdit_U;
    QLineEdit *lineEdit_Eb;
    QLineEdit *lineEdit_X;
    QLabel *label_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_ContolH;
    QLabel *label_5;
    QLineEdit *lineEdit_a2;
    QLineEdit *lineEdit_N;
    QLabel *label_2;
    QLineEdit *lineEdit_a1;
    QLabel *label_6;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QCustomPlot *graph;
    QGroupBox *groupBox_3;
    QLabel *label_Doub;
    QLabel *label_Div;
    QLabel *label_maxH;
    QLabel *label_minH;
    QLabel *label_maxE;
    QLabel *label_minE;
    QLabel *label_max_e;
    QLabel *label_min_e;
    QLabel *label_Dif;
    QPushButton *pushButton_Clear;
    QGroupBox *groupBox_4;
    QRadioButton *radioButton_Test;
    QRadioButton *radioButton_Imp;
    QRadioButton *radioButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1274, 707);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(9, 9, 348, 287));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 9, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 12, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setEnabled(false);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        pushButton_Enter = new QPushButton(groupBox);
        pushButton_Enter->setObjectName(QStringLiteral("pushButton_Enter"));
        pushButton_Enter->setEnabled(true);

        gridLayout->addWidget(pushButton_Enter, 13, 2, 1, 1);

        lineEdit_h = new QLineEdit(groupBox);
        lineEdit_h->setObjectName(QStringLiteral("lineEdit_h"));

        gridLayout->addWidget(lineEdit_h, 8, 2, 1, 1);

        lineEdit_m = new QLineEdit(groupBox);
        lineEdit_m->setObjectName(QStringLiteral("lineEdit_m"));
        lineEdit_m->setEnabled(false);
        lineEdit_m->setAutoFillBackground(false);

        gridLayout->addWidget(lineEdit_m, 7, 2, 1, 1);

        lineEdit_U = new QLineEdit(groupBox);
        lineEdit_U->setObjectName(QStringLiteral("lineEdit_U"));
        lineEdit_U->setAutoFillBackground(false);

        gridLayout->addWidget(lineEdit_U, 2, 2, 1, 1);

        lineEdit_Eb = new QLineEdit(groupBox);
        lineEdit_Eb->setObjectName(QStringLiteral("lineEdit_Eb"));

        gridLayout->addWidget(lineEdit_Eb, 12, 2, 1, 1);

        lineEdit_X = new QLineEdit(groupBox);
        lineEdit_X->setObjectName(QStringLiteral("lineEdit_X"));

        gridLayout->addWidget(lineEdit_X, 1, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        checkBox_ContolH = new QCheckBox(groupBox);
        checkBox_ContolH->setObjectName(QStringLiteral("checkBox_ContolH"));

        gridLayout->addWidget(checkBox_ContolH, 11, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(false);

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        lineEdit_a2 = new QLineEdit(groupBox);
        lineEdit_a2->setObjectName(QStringLiteral("lineEdit_a2"));
        lineEdit_a2->setEnabled(false);

        gridLayout->addWidget(lineEdit_a2, 5, 2, 1, 1);

        lineEdit_N = new QLineEdit(groupBox);
        lineEdit_N->setObjectName(QStringLiteral("lineEdit_N"));

        gridLayout->addWidget(lineEdit_N, 9, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 8, 0, 1, 1);

        lineEdit_a1 = new QLineEdit(groupBox);
        lineEdit_a1->setObjectName(QStringLiteral("lineEdit_a1"));
        lineEdit_a1->setEnabled(false);

        gridLayout->addWidget(lineEdit_a1, 4, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(false);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1190, 620, 75, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(9, 299, 851, 351));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setAutoScroll(true);

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        graph = new QCustomPlot(centralWidget);
        graph->setObjectName(QStringLiteral("graph"));
        graph->setGeometry(QRect(890, 10, 371, 601));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(510, 10, 351, 271));
        label_Doub = new QLabel(groupBox_3);
        label_Doub->setObjectName(QStringLiteral("label_Doub"));
        label_Doub->setGeometry(QRect(10, 50, 221, 16));
        label_Div = new QLabel(groupBox_3);
        label_Div->setObjectName(QStringLiteral("label_Div"));
        label_Div->setGeometry(QRect(10, 70, 231, 16));
        label_maxH = new QLabel(groupBox_3);
        label_maxH->setObjectName(QStringLiteral("label_maxH"));
        label_maxH->setGeometry(QRect(10, 100, 341, 16));
        label_minH = new QLabel(groupBox_3);
        label_minH->setObjectName(QStringLiteral("label_minH"));
        label_minH->setGeometry(QRect(10, 120, 321, 16));
        label_maxE = new QLabel(groupBox_3);
        label_maxE->setObjectName(QStringLiteral("label_maxE"));
        label_maxE->setGeometry(QRect(10, 150, 371, 16));
        label_minE = new QLabel(groupBox_3);
        label_minE->setObjectName(QStringLiteral("label_minE"));
        label_minE->setGeometry(QRect(10, 170, 371, 16));
        label_max_e = new QLabel(groupBox_3);
        label_max_e->setObjectName(QStringLiteral("label_max_e"));
        label_max_e->setGeometry(QRect(10, 200, 381, 16));
        label_min_e = new QLabel(groupBox_3);
        label_min_e->setObjectName(QStringLiteral("label_min_e"));
        label_min_e->setEnabled(true);
        label_min_e->setGeometry(QRect(10, 220, 371, 16));
        label_Dif = new QLabel(groupBox_3);
        label_Dif->setObjectName(QStringLiteral("label_Dif"));
        label_Dif->setGeometry(QRect(10, 20, 371, 16));
        pushButton_Clear = new QPushButton(centralWidget);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(870, 620, 131, 23));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(370, 10, 131, 101));
        radioButton_Test = new QRadioButton(groupBox_4);
        radioButton_Test->setObjectName(QStringLiteral("radioButton_Test"));
        radioButton_Test->setGeometry(QRect(10, 20, 111, 17));
        radioButton_Test->setTabletTracking(false);
        radioButton_Test->setChecked(true);
        radioButton_Imp = new QRadioButton(groupBox_4);
        radioButton_Imp->setObjectName(QStringLiteral("radioButton_Imp"));
        radioButton_Imp->setGeometry(QRect(10, 40, 131, 17));
        radioButton = new QRadioButton(groupBox_4);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 60, 101, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1274, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit_U, lineEdit_a1);
        QWidget::setTabOrder(lineEdit_a1, lineEdit_a2);
        QWidget::setTabOrder(lineEdit_a2, lineEdit_m);
        QWidget::setTabOrder(lineEdit_m, lineEdit_h);
        QWidget::setTabOrder(lineEdit_h, lineEdit_N);
        QWidget::setTabOrder(lineEdit_N, lineEdit_Eb);
        QWidget::setTabOrder(lineEdit_Eb, pushButton_Enter);
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
        label_4->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201. \320\272\320\276\320\273-\320\262\320\276 \321\210\320\260\320\263\320\276\320\262(N)", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\217 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\270(Eb)", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 a1", nullptr));
        pushButton_Enter->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        lineEdit_h->setText(QApplication::translate("MainWindow", "0.01", nullptr));
        lineEdit_m->setText(QApplication::translate("MainWindow", "1", nullptr));
        lineEdit_U->setText(QApplication::translate("MainWindow", "1", nullptr));
        lineEdit_Eb->setText(QApplication::translate("MainWindow", "1e-7", nullptr));
        lineEdit_X->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "U(0)", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\320\230\320\264\321\202\320\270 \320\264\320\276 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 X", nullptr));
        checkBox_ContolH->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214 \321\210\320\260\320\263\320\260", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\201\320\260(m)", nullptr));
        lineEdit_a2->setText(QApplication::translate("MainWindow", "1", nullptr));
        lineEdit_N->setText(QApplication::translate("MainWindow", "1000", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263(h)", nullptr));
        lineEdit_a1->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 a2", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "h", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Vi", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "^Vi", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "U", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "S", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "e", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        label_Doub->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\203\320\264\320\262\320\276\320\265\320\275\320\270\320\271 h", nullptr));
        label_Div->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\264\320\265\320\273\320\265\320\275\320\270\320\271 h", nullptr));
        label_maxH->setText(QApplication::translate("MainWindow", "Max( h)", nullptr));
        label_minH->setText(QApplication::translate("MainWindow", "Min( h)", nullptr));
        label_maxE->setText(QApplication::translate("MainWindow", "Max(E)", nullptr));
        label_minE->setText(QApplication::translate("MainWindow", "Min(E)", nullptr));
        label_max_e->setText(QApplication::translate("MainWindow", "Max(e)", nullptr));
        label_min_e->setText(QApplication::translate("MainWindow", "Min(e)", nullptr));
        label_Dif->setText(QApplication::translate("MainWindow", "\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        pushButton_Clear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        radioButton_Test->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
        radioButton_Imp->setText(QApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\272\321\202\320\270\320\272\320\260 \342\204\2261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
