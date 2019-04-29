#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"
#include "dirichlet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    dirichlet myDir;
    void SetRecord(QTableWidget* pTable, int i, int j, double myX);
    void MainWindow::SetTable(QTableWidget* pTable, double** myX, int  n, int m);
    QTableWidgetItem* CreateItem(QVariant it);
    QTableWidget* pTable;

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonShow_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
