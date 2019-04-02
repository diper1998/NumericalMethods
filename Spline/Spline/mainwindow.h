#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "spline.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void MainWindow::PaintGraph(double* myX, double* myY, int N, const int numbGraph, QString nameGraph);
    void MainWindow::PaintGraphError(double* myX, double* myY, int N, const int numbGraph, QString nameGraph);
    void MainWindow::PaintGraphDerError(double* myX, double* myY, int N, const int nGraph, QString nameGraph);
    void MainWindow::PaintGraphDer(double* myX, double* myY, int N, const int nGraph, QString nameGraph);
    void MainWindow::PaintGraphDerDerError(double* myX, double* myY, int N, const int nGraph, QString nameGraph);
    void MainWindow::PaintGraphDerDer(double* myX, double* myY, int N, const int nGraph, QString nameGraph);
    QTableWidgetItem* MainWindow::CreateItem(QVariant it);

    void MainWindow::WriteTable(int i, double X, double Y, double Z, double W, double Q, double V);
    void MainWindow::WriteTable_1(int i, double X, double Y, double Z, double W, double Q, double V, double S,  double G, double T, double R);

    Spline SPLINE;
    int numbGraph = 0;
    int numbGraphError = 0;

    int numbGraphDer = 0;
    int numbGraphDerError = 0;

    int numbGraphDerDer = 0;
    int numbGraphDerDerError = 0;


    private slots:
      void on_BUTTON_clicked();

      void on_BUTTON_CLEAN_clicked();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
