#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <iostream>
#include <qcustomplot.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    int columnX = 0;
    int columnH = 1;
    int columnV1 = 2;
    int columnV2 = 3;
    int columnV1_ = 4;
    int columnV2_ = 5;
    int columne1 = 6;
    int columne2 = 7;
    int columnS = 8;

    int numbGraph = 0;

    int numbGraphPortret = 0;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTableWidgetItem* CreateItem(QVariant it);
    void WriteTable(int i, double X, double H, double V1, double V2, double V1_, double V2_, double e1, double e2, double S);
    void paintGraph(int numbColumnX, int numbColumnY, int N, int numbGraph, int style, int color);
    void paintGraphPortret(int numbColumnX, int numbColumnY, int numbColumnT, int N, int numbGraph, int style, int color);
    void Do();
    void Do(double V1, double V2);

    void GetMaxMin(int numbColum, int numbColumX, int N, QVariant* arrayMaxMinX);

private slots:


    void on_pushButton_Enter_clicked();



    void on_pushButton_Clear_clicked();

    void on_pushButton_Portret_clicked();

    void on_checkBox_Control_clicked();



    void on_checkBox_End_clicked();

private:
    Ui::MainWindow *ui;
};


class DifEq {

public:

    int p = 4;

    double m = 4.5;
    double k = 175;
    double f = 0.3;
    double g = 10;

    double x = 0;
    double* arrayx;
    double h = 0.01;
    double* arrayh;
    int countDoub = 0;
    int countDiv = 0;

    int N = 100;
    int step = 0;
    double X = 1;

    double V1 = 7.5;
    double* arrayV1;
    double V2 = 0;
    double* arrayV2;
    double V1_ = V1;
    double* arrayV1_;
    double V2_ = V2;
    double* arrayV2_;
    double U = 1;

    double e1 = 0;
    double e2 = 0;
     double e3 = 0;
    double E = 0;
    double S1 = 0;
    double S2 = 0;
    double S3 = 0;
    double Eb = 1e-7;
    double EPS = 0;

    bool correctStep = false;
     bool end = false;

    QVariant arrayMaxMin[4];

    DifEq(){

        m = 4.5;
        k = 175;
        f = 0.3;

        x = 0;
        h = 0.01;

        V1 = 7.5;
        V2 = 0;
        U = 1;

        e1 = 0;
        e2 = 0;
        e3 = 0;
        E = 0;
        S1 = 0;
        S2 = 0;
        S3 = 0;
        p = 4;
        Eb = 1e-7;
        EPS = 1e-5;

        correctStep = false;
    }

    double GetFirstFunSol(double x, double V1, double V2){
        double funSol = V2;
       //  double funSol = 0.5*V1 - 0.2*V1*V2 - 0.7*V1*V1;
        return funSol ;
    }


    double GetSecondFunSol(double x, double V1, double V2){
      //double funSol = f*g - k*V1/m;
       double funSol = m*V2*abs(V2)+k*V2+f*V1;
       // double funSol = -0.3*V2+0.4*V1*V2-0.4*V2;
        return funSol;
    }

    void GetMethodSol(){

        // Для первого k, для второго m;
        double k1, k2, k3, k4;
        double m1, m2, m3, m4;

        k1 = GetFirstFunSol(x, V1, V2);
        m1 = GetSecondFunSol(x, V1, V2);

        k2 = GetFirstFunSol(x + h/2, V1 + k1/2, V2 + m1/2);
        m2 = GetSecondFunSol(x + h/2, V1 + k1/2, V2 + m1/2);
        \
        k3 = GetFirstFunSol(x + h/2, V1 + k2/2, V2 + m2/2);
        m3 = GetSecondFunSol(x + h/2, V1 + k2/2, V2 + m2/2);

        k4 = GetFirstFunSol(x + h/2, V1 + k3, V2 + m3);
        m4 = GetSecondFunSol(x + h/2, V1 +k3, V2 + m3);

        V1 = V1 + h/6*(k1 + 2*k2 + 2*k3 + k4);
        V2 = V2 + h/6*(m1 + 2*m2 + 2*m3 + m4);

    }


    void GetMethodSol_(){

        // Для первого k, для второго m;
        double k1, k2, k3, k4;
        double m1, m2, m3, m4;

        h = h/2;

        k1 = GetFirstFunSol(x, V1, V2);
        m1 = GetSecondFunSol(x, V1, V2);

        k2 = GetFirstFunSol(x + h/2, V1 + k1/2, V2 + m1/2);
        m2 = GetSecondFunSol(x + h/2, V1 + k1/2, V2 + m1/2);
        \
        k3 = GetFirstFunSol(x + h/2, V1 + k2/2, V2 + m2/2);
        m3 = GetSecondFunSol(x + h/2, V1 + k2/2, V2 + m2/2);

        k4 = GetFirstFunSol(x + h/2, V1 + k3, V2 + m3);
        m4 = GetSecondFunSol(x + h/2, V1 +k3, V2 + m3);

        V1_ = V1 + h/6*(k1 + 2*k2 + 2*k3 + k4);
        V2_ = V2 + h/6*(m1 + 2*m2 + 2*m3 + m4);

        x = x + h;


        k1 = GetFirstFunSol(x, V1_, V2_);
        m1 = GetSecondFunSol(x, V1_, V2_);

        k2 = GetFirstFunSol(x + h/2, V1_ + k1/2, V2_ + m1/2);
        m2 = GetSecondFunSol(x + h/2, V1_ + k1/2, V2_ + m1/2);
        \
        k3 = GetFirstFunSol(x + h/2, V1_ + k2/2, V2_ + m2/2);
        m3 = GetSecondFunSol(x + h/2, V1_ + k2/2, V2_ + m2/2);

        k4 = GetFirstFunSol(x + h/2, V1_ + k3, V2_ + m3);
        m4 = GetSecondFunSol(x + h/2, V1_ +k3, V2_ + m3);

        V1_ = V1_ + h/6*(k1 + 2*k2 + 2*k3 + k4);
        V2_ = V2_ + h/6*(m1 + 2*m2 + 2*m3 + m4);

        x = x - h;
        h = h*2;
       }


    void GetNextArg(){
        x = x+h;
    }

    void Gete(){
        e1 =  abs(V1 - V1_);
        e2 = abs(V2 - V2_);

    }

    void GetS(){
        S1 = e1/(pow(2,p)-1);
        S2 = e2/(pow(2,p)-1);
        S3 = pow(S1*S1+S2*S2,0.5);
        e3 = S3*(pow(2,p)-1);
    }

    int CorrectStep(){

        if(abs(S3)<Eb/(pow(2,p+1))) {
          h = h*2;
          countDoub = countDoub+1;
          return 0;
        }

        if(abs(S3)>Eb){
        h = h/2;
        countDiv = countDiv + 1;
        return 1;

    }

        return 0;

    }
    void MakeStep() {

        //x = x + h
        GetNextArg();
        GetMethodSol_();
        GetMethodSol();
        Gete();
        GetS();

    }

};






#endif // MAINWINDOW_H
