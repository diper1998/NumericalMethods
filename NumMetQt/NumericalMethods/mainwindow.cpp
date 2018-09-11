#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QVariant GetNextArg(double x, double h) {
    return x+h;
}

double GetFunctSol(double U, double a1, double a2, double m){
    return (-1)*(a1*U+a2*U*U*U)/m;
}

QVariant GetMethodSol(double U, double h, double a1, double a2, double m){
    double k1, k2, k3, k4;
    k1 = GetFunctSol(U, a1, a2, m);
    k2 = GetFunctSol(U+(h/2)*k1,a1,a2,m);
    k3 = GetFunctSol(U+(h/2)*k2,a1,a2,m);
    k4 = GetFunctSol(U+h*k3,a1,a2,m);
    return U+(h/6)*(k1+2*k2+2*k3+k4);
}

QVariant GetCorrectSol(double x, double c1, double a1, double a2, double m) {
    return pow(a1/m,0.5)/(pow(exp((c1+x)*2*a1)-a2/m,0.5));
}

void MainWindow::on_pushButton_Enter_clicked()
{
    double a1,a2,h,X,x,m;
    int N;
    QVariant V,V2,U;
    a1 = 0;
    a2 = 0;
    h = 0;
    V = 0;
    X = 0;
    x= 0;
    m =1;


    a1 = ui->lineEdit_a1->text().toDouble();
    a2 = ui->lineEdit_a2->text().toDouble();
    N = ui->lineEdit_N->text().toInt();
    h = ui->lineEdit_h->text().toDouble();
    V = ui->lineEdit_U->text().toDouble();
    X = ui->lineEdit_X->text().toDouble();
    m = ui->lineEdit_m->text().toDouble();

    V2 = U = V ;

     double c1 = log(a1/(m*V.toDouble()*V.toDouble())+a2/m)/(2*a1);

    for(int i = 0; i < N; i++){

        ui->tableWidget->insertRow(i);

        //GetNextArg x
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(GetNextArg(x,h*i).toString());
        ui->tableWidget->setItem(i,0,item);

        //GetMethod V
        QTableWidgetItem *item2 = new QTableWidgetItem();
        item2->setText(V.toString());
        ui->tableWidget->setItem(i,1,item2);
        V = GetMethodSol(V.toDouble(),h,a1,a2,m);

        //GetMethod V^2
        QTableWidgetItem *item3 = new QTableWidgetItem();
        item3->setText(V2.toString());

        ui->tableWidget->setItem(i,2,item3);

        V2 = GetMethodSol(V2.toDouble(),h/2,a1,a2,m);
        V2 = GetMethodSol(V2.toDouble(),h/2,a1,a2,m);

        //GetCorrectSol
        QTableWidgetItem *item4 = new QTableWidgetItem();
        item4->setText(U.toString());
        ui->tableWidget->setItem(i,3,item4);
        U = GetCorrectSol(GetNextArg(x,h*i).toDouble(),c1,a1,a2,m);

    }

}


