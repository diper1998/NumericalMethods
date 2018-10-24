#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <iostream>

using namespace std;

 const double EPS = 0;
 //double Eb = 1e-5;
 int numbGraph = 0;
 int color  = 0;
 bool flagControlH = false;
 int numFunct = 1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("LabWork");

    ui->graph->setInteraction(QCP::iRangeZoom,true);
    ui->graph->setInteraction(QCP::iRangeDrag, true); // Включаем взаимодействие перетаскивания графика
   //ui->graph->axisRect()->setRangeDrag(Qt::Horizontal); // Включаем перетаскивание только по горизонтальной оси
   // ui->graph->axisRect()->setRangeZoom(Qt::Horizontal); // Включаем удаление/приближение только по горизонтальной оси

    //Начальная отрисовка осей "x" и "y"
    ui->graph->xAxis->setLabel("t");
    ui->graph->yAxis->setLabel("V");
    ui->graph->xAxis->setRange(0, 1);
    ui->graph->yAxis->setRange(0, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QVariant GetNextArg(QVariant x, double h) {
    return x.toDouble()+h ;
}

QVariant GetFunctSol(double U, double x, double a1, double a2, double m){

    if(numFunct == 0) return (-1)*(a1*U+a2*U*U*U)/m;
    if(numFunct == 1) return (2)*U;
    if(numFunct == 2) return ((pow(x,3)+1)/(pow(x,5)+1))*U*U+U-pow(U,3)*sin(10*x);

}

QVariant GetMethodSol(double U, double x, double h, double a1, double a2, double m){
    double k1, k2, k3, k4;
    k1 = GetFunctSol(U, x, a1, a2, m).toDouble();
    k2 = GetFunctSol(U+(h/2)*k1, x+(h/2), a1,a2,m).toDouble();
    k3 = GetFunctSol(U+(h/2)*k2, x+(h/2), a1,a2,m).toDouble();
    k4 = GetFunctSol(U+h*k3, x+h, a1,a2,m).toDouble();
    return U+(h/6)*(k1 + 2 * k2 + 2 * k3 + k4);
}

QVariant GetCorrectSol(double x, double c1, double a1, double a2, double m) {
   if(numFunct == 0) return pow(a1/m,0.5)/(pow(exp((c1+x)*2*a1)-a2/m,0.5));
   if(numFunct == 1) return c1*exp((4*x)/2);
   if(numFunct == 2) return 0;
}

QVariant GetConstant(double U, double x, double h, double a1, double a2, double m){
    QVariant c1 = 0;
    if(numFunct == 0) return c1 = log(a1/(m*U*U)+a2/m)/(2*a1);
    if(numFunct == 1) return c1 = U*exp((-4*x)/2);
    if(numFunct ==2) return c1 = 0;
}

QVariant GetS(double V3, double V2, int p) {
    return abs((V3-V2)/(pow(2,p)-1));
}

QTableWidgetItem* CreateItem(QVariant it){
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(it.toString());
    return item;
}

void MainWindow::paintGraph(int numbColumnX, int numbColumnY, int N, int numbGraph, int style, int color){

    QVector<double> X(N);
    QVector<double> Y(N);

    QVariant check;
    QTableWidgetItem *itemX;
    QTableWidgetItem *itemY;

    QPen pen;

    pen.setColor(Qt::GlobalColor(color+7));


    for(int i = 0; i < N; i++){
        itemX = ui->tableWidget->item(i,numbColumnX);
        itemY = ui->tableWidget->item(i,numbColumnY);
        if(itemX!=NULL && itemY!= NULL){

            check = itemX->text();


            X[i] = check.toDouble();


            check = itemY->text();
            if(!isnan(check.toDouble()))
            Y[i] = check.toDouble();
            else {
                N = i-1;
                break;}
            }

        }


    ui->graph->addGraph();

    if(style)
    pen.setStyle(Qt::DotLine);

    ui->graph->graph(numbGraph)->setData(X,Y);
    ui->graph->graph(numbGraph)->setPen(pen);


    ui->graph->xAxis->setRange(X[0],X[N-1]);

    double minY = Y[0], maxY = Y[0];
    for(int i = 1; i < N; i++){
        if(Y[i]<minY) minY = Y[i];
        if(Y[i]>maxY) maxY = Y[i];
    }

    ui->graph->yAxis->setRange(minY, maxY);
    ui->graph->replot();
}

void MakeStep(QVariant &x, QVariant &h, QVariant a1, QVariant a2, QVariant m, QVariant p, QVariant &V, QVariant &V2, QVariant &U, QVariant &c1, QVariant &E, QVariant &S, QVariant &e, QVariant &Eb) {

    if (!std::isnan(V.toDouble())){


    //GetNextArg x
    x = GetNextArg(x.toDouble(),h.toDouble());

    //GetMethod V

    V2 = GetMethodSol(V.toDouble(),x.toDouble(),h.toDouble()/2,a1.toDouble(),a2.toDouble(),m.toDouble());

    V = GetMethodSol(V.toDouble(),x.toDouble(),h.toDouble(),a1.toDouble(),a2.toDouble(),m.toDouble());


    //GetMethod V^2



    //GetCorrectSol

    U = GetCorrectSol(x.toDouble(),c1.toDouble(),a1.toDouble(),a2.toDouble(),m.toDouble());

    //Global

    if(numFunct!= 2)
    E = abs(U.toDouble()-V.toDouble());

    //Корректировка шага
    V2 = GetMethodSol(V2.toDouble(),x.toDouble(),h.toDouble()/2,a1.toDouble(),a2.toDouble(),m.toDouble());
    S = abs(GetS(V2.toDouble(),V.toDouble(),p.toInt()).toDouble());
    e = abs(S.toDouble()*pow(2,p.toDouble()));

}
}

void MainWindow::GetMaxMin(int numbColum, int numbColumX, int N, QVariant* arrayMaxMinX) {

    QVector<double> myItem(N);
    QVector<double> myX(N);


    QVariant check;
    QTableWidgetItem *item;
    QTableWidgetItem *itemX;

    for(int i = 0; i < N; i++){
        item = ui->tableWidget->item(i,numbColum);
        itemX = ui->tableWidget->item(i,numbColumX);
        if(item!=NULL){

            check = itemX->text();
            myX[i] = check.toDouble();

            check = item->text();
            if(!isnan(check.toDouble())){
            myItem[i] = check.toDouble();
            } else {
                N = i-1;
                break;}
            }
            }

    arrayMaxMinX[0] = myItem[1];
    arrayMaxMinX[1] = myItem[1];
    arrayMaxMinX[2] = myX[1];
    arrayMaxMinX[3] = myX[1];

    for(int i = 1; i < N; i++){
            if(myItem[i]<arrayMaxMinX[1].toDouble()){
                arrayMaxMinX[1] = myItem[i];
                arrayMaxMinX[3] = myX[i];
            }
            if(myItem[i]>arrayMaxMinX[0].toDouble()){
                arrayMaxMinX[0] = myItem[i];
                arrayMaxMinX[2] = myX[i];
        }

        }


}


void MainWindow::on_pushButton_Enter_clicked()
{

    //Параметры уравнения.
    QVariant a1 = 0;
    QVariant a2 = 0;
    QVariant m = 1;
    QVariant x = 0; //Начальный "x".
    QVariant h = 0.01; // Шаг.
    QVariant N = 100; //Количество шагов.
    QVariant p = 4; //Порядок метода.
    QVariant c1 = 0; //Константа для точного решения.
    QVariant V = 0; //Численное решение.
    QVariant V2 = 0; //Численное решение с двойным шагом.
    QVariant U = 0; //Точное решение.
    QVariant E = 0; //Глобальная погрешность.
    QVariant S = 0; //Корректирующий элемент.
    QVariant e = 0;
    QVariant X = 0; //Граница
    QVariant Eb = 0;
    QVariant countDoub = 0;
    QVariant countDiv = 0;
    int step = 0;

    //bool flag=true;

    if(ui->checkBox_ContolH->isChecked()){
        flagControlH = true;
    } else {
        flagControlH = false;
    }


    V = ui->lineEdit_U->text().toDouble();
    a1 = ui->lineEdit_a1->text().toDouble();
    a2 = ui->lineEdit_a2->text().toDouble();
    m = ui->lineEdit_m->text().toDouble();
    h = ui->lineEdit_h->text().toDouble();
    N = ui->lineEdit_N->text().toInt();
    Eb = ui->lineEdit_Eb->text().toDouble();
    X = ui->lineEdit_X->text().toDouble();

    //if(Eb>EPS){Eb = EPS;}

    QVector<double> vectorX(N.toInt()), vectorV(N.toInt()), vectorU(N.toInt()), vectorV2(N.toInt());


    U = V2 = V;

    c1 = GetConstant(U.toDouble(),x.toDouble(),h.toDouble(),a1.toDouble(),a2.toDouble(),m.toDouble()); // Вычисление константы для точного решения

    //Инциализация нулевой строки таблицы;

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->insertRow(0);
    vectorX[0]= x.toDouble();
    ui->tableWidget->setItem(0,0, CreateItem(x));
    ui->tableWidget->setItem(0,1,CreateItem(h));
    vectorV[0] = V.toDouble();
    ui->tableWidget->setItem(0,2,CreateItem(V));
    vectorV2[0] = V2.toDouble();
    ui->tableWidget->setItem(0,3,CreateItem(V2));
    vectorU[0] = U.toDouble();
    ui->tableWidget->setItem(0,4,CreateItem(U));
    ui->tableWidget->setItem(0,5,CreateItem(E));
    ui->tableWidget->setItem(0,6,CreateItem(S));
    ui->tableWidget->setItem(0,7,CreateItem(e));
    QVariant arrayMaxMinX[4];

    if(ui->checkBox->isChecked()){

       for(int i = 1; X.toDouble()>x.toDouble() && i<N.toInt(); i++){

           // flag=true;
           step = i;
           if (std::isnan(V.toDouble())){
               break;
           }

           MakeStep(x,h,a1,a2,m,p,V,V2,U,c1,E,S,e,Eb);


      if(flagControlH){

            if((abs(S.toDouble())-Eb.toDouble()/(pow(2,p.toDouble()+1)))<EPS) {
              h = h.toDouble()*2;
              countDoub = countDoub.toInt()+1;
    } else {

            if(S.toDouble()>Eb.toDouble()   && i>0){

                   h = h.toDouble()/2;

                    i--;

                    ui->tableWidget->setItem(i,1,CreateItem(h));
                    x = vectorX[i];
                    U = vectorU[i];
                    V = vectorV[i];
                    V2 = vectorV2[i];
                    countDiv = countDiv.toInt()+1;
                    continue;
    }

        }
      }

      if(isnan(V.toDouble())){
          step =  step-1;
          break;
      }


    ui->tableWidget->insertRow(i);

    vectorX[i]= x.toDouble();
    ui->tableWidget->setItem(i,0, CreateItem(x));


    ui->tableWidget->setItem(i,1,CreateItem(h));

    vectorV[i] = V.toDouble();
    ui->tableWidget->setItem(i,2,CreateItem(V));

    vectorV2[i] = V2.toDouble();
    ui->tableWidget->setItem(i,3,CreateItem(V2));

    vectorU[i] = U.toDouble();
    ui->tableWidget->setItem(i,4,CreateItem(U));

    ui->tableWidget->setItem(i,5,CreateItem(E));

    ui->tableWidget->setItem(i,6,CreateItem(S));

    ui->tableWidget->setItem(i,7,CreateItem(e));

    }
    } else {
    for(int i = 1; i < N.toInt(); i++){

        step = i;
        if (std::isnan(V.toDouble())){
            break;
        }
         MakeStep(x,h,a1,a2,m,p,V,V2,U,c1,E,S,e,Eb);

        if(flagControlH){

        if((abs(S.toDouble())-Eb.toDouble()/(pow(2,p.toDouble()+1)))<EPS) {
          h = h.toDouble()*2;
          countDoub = countDoub.toInt()+1;
}

        if((abs(S.toDouble())-Eb.toDouble())>EPS && i>0){

                h = h.toDouble()/2;
              \
                i--;
                ui->tableWidget->setItem(i,1,CreateItem(h));
                x = vectorX[i];

                U = vectorU[i];

                V = vectorV[i];

                V2 = vectorV2[i];

                countDiv = countDiv.toInt()+1;
                continue;
}

    }

  if(isnan(V.toDouble())){
     step =  step-1;
      break;
  }

ui->tableWidget->insertRow(i);

vectorX[i]= x.toDouble();
ui->tableWidget->setItem(i,0, CreateItem(x));


ui->tableWidget->setItem(i,1,CreateItem(h));

vectorV[i] = V.toDouble();
ui->tableWidget->setItem(i,2,CreateItem(V));

vectorV2[i] = V2.toDouble();
ui->tableWidget->setItem(i,3,CreateItem(V2));

if(numFunct == 1 || numFunct == 0){
vectorU[i] = U.toDouble();
ui->tableWidget->setItem(i,4,CreateItem(U));
}

if(numFunct == 1 || numFunct == 0){
ui->tableWidget->setItem(i,5,CreateItem(E));
}
ui->tableWidget->setItem(i,6,CreateItem(S));

ui->tableWidget->setItem(i,7,CreateItem(e));

}
     }

     N = step+1;

    //Отрисовка

    paintGraph(0,2,N.toInt(),numbGraph, 0, color);
    numbGraph++;

    if(numFunct == 1){
    paintGraph(0,4,N.toInt(),numbGraph, 1, color);
    numbGraph++;
    }
    color++;
    flagControlH = false;


    ui->label_Doub->setText("Количество удвоений h: " + countDoub.toString());
    ui->label_Div->setText("Количество делений h: " + countDiv.toString());

    GetMaxMin(1, 0, N.toInt(), arrayMaxMinX);
    ui->label_maxH->setText("Max(h): " + arrayMaxMinX[0].toString()+" при x = "+arrayMaxMinX[2].toString());
    ui->label_minH->setText("Min(h): " + arrayMaxMinX[1].toString()+" при x = "+arrayMaxMinX[3].toString());

    if(numFunct == 1 || numFunct == 0 ){
    GetMaxMin(5, 0, N.toInt(), arrayMaxMinX);
    ui->label_maxE->setText("Max(E): " + arrayMaxMinX[0].toString()+" при x = "+arrayMaxMinX[2].toString());
    ui->label_minE->setText("Min(E): " + arrayMaxMinX[1].toString()+" при x = "+arrayMaxMinX[3].toString());
    }

    if(numFunct == 2){
    GetMaxMin(5, 0, N.toInt(), arrayMaxMinX);
    ui->label_maxE->setText("");
    ui->label_minE->setText("");
    }


    GetMaxMin(7, 0, N.toInt(), arrayMaxMinX);
    ui->label_max_e->setText("Max(e): " + arrayMaxMinX[0].toString()+" при x = "+arrayMaxMinX[2].toString());
    ui->label_min_e->setText("Min(e): " + arrayMaxMinX[1].toString()+" при x = "+arrayMaxMinX[3].toString());

    if(numFunct == 1 ){
        ui->label_Dif->setText("dU/dx = (2)*U");
    }

    if(numFunct == 2){
        ui->label_Dif->setText("dU/dx = ((pow(x,3)+1)/(pow(x,5)+1))*U*U+U-pow(U,3)*sin(10*x)");
    }

    if(numFunct == 0){
        ui->label_Dif->setText("(-1)*(a1*U+a2*U*U*U)/m");
    }
}

void MainWindow::on_pushButton_Clear_clicked()
{
    ui->graph->clearGraphs();//очищаем все графики.
    ui->tableWidget->setRowCount(0);
    numbGraph = 0;
    color = 0;
    ui->graph->replot();

    ui->label_Doub->setText("");
    ui->label_Div->setText("");
    ui->label_maxH->setText("");
    ui->label_minH->setText("");

    ui->label_maxE->setText("");
    ui->label_minE->setText("");



    ui->label_maxE->setText("");
    ui->label_minE->setText("");


    ui->label_max_e->setText("");
    ui->label_min_e->setText("");

    ui->label_Dif->setText("");

   // QPixmap myPixmap("D:\\ITMM\\NumericalMethods\\NumMetQt\\NumericalMethods\\myCat");
    //ui->label_PixMap->setPixmap(myPixmap);



}

void MainWindow::on_checkBox_pressed()
{

}

void MainWindow::on_radioButton_Test_clicked()
{
    numFunct = 1;
}

void MainWindow::on_radioButton_Imp_clicked()
{
    numFunct = 2;
}

void MainWindow::on_radioButton_clicked()
{
    numFunct = 0;
}
