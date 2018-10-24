#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("LabWork1");
    ui->graph->setInteraction(QCP::iRangeZoom,true);
    ui->graph->setInteraction(QCP::iRangeDrag, true);
    ui->graph->xAxis->setLabel("t");
    ui->graph->yAxis->setLabel("V1, V2");

  //  ui->graphPortret->setName("V1, V2");
    ui->graphPortret->xAxis->setLabel("V1");
    ui->graphPortret->yAxis->setLabel("V2");

    ui->graphPortret->setInteraction(QCP::iRangeZoom,true);
    ui->graphPortret->setInteraction(QCP::iRangeDrag, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}



QTableWidgetItem* MainWindow::CreateItem(QVariant it){
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(it.toString());
    return item;
}

void MainWindow::WriteTable(int i, double X, double H, double V1, double V2, double V1_, double V2_, double e1, double e2, double S){

    columnX = 0;
    columnH = 1;
    columnV1 = 2;
    columnV2 = 3;

    QVariant qX = X;
    QVariant qH = H;
    QVariant qV1 = V1;
    QVariant qV2 = V2;
    QVariant qV1_ = V1_;
    QVariant qV2_ = V2_;
    QVariant qe1 = e1;
    QVariant qe2 = e2;
     QVariant qS = S;

    ui->tableWidget->setItem(i, columnX, CreateItem(qX));


    ui->tableWidget->setItem(i, columnH, CreateItem(qH));


    ui->tableWidget->setItem(i, columnV1, CreateItem(qV1));


    ui->tableWidget->setItem(i, columnV2, CreateItem(qV2));

    ui->tableWidget->setItem(i, columnV1_, CreateItem(qV1_));

    ui->tableWidget->setItem(i, columnV2_, CreateItem(qV2_));

     ui->tableWidget->setItem(i, columne1, CreateItem(qe1));
     ui->tableWidget->setItem(i, columne2, CreateItem(qe2));

     ui->tableWidget->setItem(i, columne2, CreateItem(qe2));

     ui->tableWidget->setItem(i, columnS, CreateItem(S));

}

void MainWindow::paintGraph(int numbColumnX, int numbColumnY, int N, int numbGraph, int style, int color){

    QVector<double> X(N);
    QVector<double> Y(N);

    QVariant check;
    QVariant pastCheckX;
     QVariant pastCheckY;
    QTableWidgetItem *itemX;
    QTableWidgetItem *itemY;

    QPen pen;

    pen.setColor(Qt::GlobalColor(color+7));


    for(int i = 0; i < N; i++){
        itemX = ui->tableWidget->item(i,numbColumnX);
        itemY = ui->tableWidget->item(i,numbColumnY);

        if(itemX!=NULL && itemY!= NULL){

            if(i == 0){
            pastCheckX = itemX->text();
            pastCheckY = itemY->text();
            }



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

void MainWindow::paintGraphPortret(int numbColumnX, int numbColumnY, int numbColumnT, int N, int numbGraph, int style, int color){

    QVector<double> X(N);
    QVector<double> Y(N);
    QVector<double> T(N);

    QVariant check;
    QTableWidgetItem *itemX;
    QTableWidgetItem *itemY;
    QTableWidgetItem *itemT;



    QPen pen;

    pen.setColor(Qt::GlobalColor(color+7));




    //ui->graphPortret->clearPlottables();



    for(int i = 0; i < N; i++){
        itemX = ui->tableWidget->item(i,numbColumnX);
        itemY = ui->tableWidget->item(i,numbColumnY);
        itemT = ui->tableWidget->item(i,numbColumnT);
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

              check = itemT->text();
              T[i] = check.toDouble();

        }



   ui->graphPortret->addGraph();

    if(style)
    pen.setStyle(Qt::DotLine);


   // ui->graphPortret->setData(T,X,Y);



    ui->graphPortret->graph(numbGraph)->data();
   // ui->graphPortret->graph(numbGraph)->setData(X,Y);
    ui->graphPortret->graph(numbGraph)->setPen(pen);



    ui->graphPortret->xAxis->setRange(X[0],X[N-1]);

    double minY = Y[0], maxY = Y[0];
    for(int i = 1; i < N; i++){
        if(Y[i]<minY) minY = Y[i];
        if(Y[i]>maxY) maxY = Y[i];
    }

    ui->graphPortret->yAxis->setRange(minY, maxY);

    QCPCurve *newCurve = new QCPCurve(ui->graphPortret->xAxis,ui->graphPortret->yAxis);
    newCurve->setData(T,X,Y);

    ui->graphPortret->replot();

   // QCPCurve *newCurve = new QCPCurve(ui->graphPortret->xAxis, ui->graphPortret->yAxis);
   // newCurve->setData(X,X,Y);
  //  newCurve->replot();

}





void MainWindow::Do(){

    DifEq difEq;



    difEq.V1 = ui->lineEdit_V1->text().toDouble();
    difEq.V2 = ui->lineEdit_V2->text().toDouble();
    difEq.h = ui->lineEdit_h->text().toDouble();
    difEq.N = ui->lineEdit_N->text().toInt();
    difEq.X = ui->lineEdit_X->text().toDouble();
    difEq.m = ui->lineEdit_m->text().toDouble();
    difEq.f = ui->lineEdit_f->text().toDouble();
    difEq.k = ui->lineEdit_k->text().toDouble();
     difEq.Eb = ui->lineEdit_Eb->text().toDouble();

   if(ui->checkBox_Control->isChecked()){
    difEq.correctStep = true;
   } else {
    difEq.correctStep = false;
   }


if(ui->checkBox_End->isChecked()){
 difEq.end = true;
} else {
    difEq.end = false;
   }

    difEq.V1_ = difEq.V1;
    difEq.V2_ = difEq.V2;

    difEq.arrayV1 = new double[difEq.N];
    difEq.arrayV2 = new double[difEq.N];
    difEq.arrayx = new double[difEq.N];
    difEq.arrayh = new double[difEq.N];
    difEq.arrayV1_ = new double[difEq.N];
    difEq.arrayV2_ = new double[difEq.N];


    difEq.EPS = 0;



    ui->tableWidget->setRowCount(0);

    ui->tableWidget->insertRow(0);
    WriteTable(0, difEq.x, difEq.h, difEq.V1, difEq.V2, difEq.V1_, difEq.V2_, difEq.e1, difEq.e2, difEq.S3);

    difEq.arrayV1[0]  =  difEq.V1;
    difEq.arrayV2[0]  =  difEq.V2;
    difEq.arrayx[0]   =  difEq.x;
    difEq.arrayh[0]   =  difEq.h;
    difEq.arrayV1_[0] =  difEq.V1_;
    difEq.arrayV2_[0] =  difEq.V2_;

    difEq.step = 0;

    if(difEq.end){
    for(int i = 1; i < difEq.N && difEq.x < difEq.X; i++){
        difEq.step++;
        ui->tableWidget->insertRow(i);
        difEq.MakeStep();
        if(difEq.correctStep){
            if( difEq.CorrectStep() && i > 1) {
                difEq.step--;
                i--;

                difEq.V1  = difEq.arrayV1[i] ;
                difEq.V2  = difEq.arrayV2[i] ;
                difEq.x   = difEq.arrayx[i]  ;
                difEq.V1_ = difEq.arrayV1_[i];
                difEq.V2_ = difEq.arrayV2_[i];
                continue;

            };
        }



        WriteTable(i, difEq.x, difEq.h, difEq.V1, difEq.V2, difEq.V1_, difEq.V2_, difEq.e1, difEq.e2, difEq.S3);

        difEq.arrayV1[i] = difEq.V1;
        difEq.arrayV2[i] = difEq.V2;
        difEq.arrayx[i]= difEq.x;
        difEq.arrayh[i]= difEq.h;
        difEq.arrayV1_[i] = difEq.V1_;
        difEq.arrayV2_[i] = difEq.V2_;

    }
} else {

        for(int i = 1; i < difEq.N; i++){
            difEq.step++;
            ui->tableWidget->insertRow(i);
            difEq.MakeStep();
            if(difEq.correctStep){
                if( difEq.CorrectStep() && i > 0) {
                    difEq.step--;
                    i--;

                    difEq.V1  = difEq.arrayV1[i] ;
                    difEq.V2  = difEq.arrayV2[i] ;
                    difEq.x   = difEq.arrayx[i]  ;
                    difEq.V1_ = difEq.arrayV1_[i];
                    difEq.V2_ = difEq.arrayV2_[i];
                    continue;

                };
            }



            WriteTable(i, difEq.x, difEq.h, difEq.V1, difEq.V2, difEq.V1_, difEq.V2_, difEq.e1, difEq.e2, difEq.S3);

            difEq.arrayV1[i] = difEq.V1;
            difEq.arrayV2[i] = difEq.V2;
            difEq.arrayx[i]= difEq.x;
            difEq.arrayh[i]= difEq.h;
            difEq.arrayV1_[i] = difEq.V1_;
            difEq.arrayV2_[i] = difEq.V2_;


    }

}

    GetMaxMin(6, 0, difEq.step, difEq.arrayMaxMin);

    ui->label_maxe1->setText("Max(e1): " + difEq.arrayMaxMin[0].toString()+" при x="+difEq.arrayMaxMin[2].toString());
    ui->label_mine1->setText("Min(e1): " + difEq.arrayMaxMin[1].toString()+" при x="+difEq.arrayMaxMin[3].toString());

     GetMaxMin(7, 0, difEq.step, difEq.arrayMaxMin);
     ui->label_maxe2->setText("Max(e2): " + difEq.arrayMaxMin[0].toString()+" при x="+difEq.arrayMaxMin[2].toString());
     ui->label_mine2->setText("Min(e2): " + difEq.arrayMaxMin[1].toString()+" при x="+difEq.arrayMaxMin[3].toString());

     GetMaxMin(8, 0, difEq.step, difEq.arrayMaxMin);
     ui->label_maxS->setText("Max(S): " + difEq.arrayMaxMin[0].toString()+" при x="+difEq.arrayMaxMin[2].toString());
     ui->label_minS->setText("Min(S): " + difEq.arrayMaxMin[1].toString()+" при x="+difEq.arrayMaxMin[3].toString());

    paintGraph(0,2,difEq.step,numbGraph,0,0);
    numbGraph++;
    paintGraph(0,3,difEq.step,numbGraph, 0, 1);
    numbGraph++;
    paintGraphPortret(2,3,0,difEq.step, numbGraphPortret, 0, 0);
    numbGraphPortret++;
}

void MainWindow::on_pushButton_Enter_clicked()
{
   Do();

}

void MainWindow::Do(double V1, double V2){


    DifEq difEq;

    difEq.V1 = V1;
    difEq.V2 = V2;

    difEq.h = ui->lineEdit_h->text().toDouble();
    difEq.N = ui->lineEdit_N->text().toInt();
    difEq.X = ui->lineEdit_X->text().toDouble();

    difEq.m = ui->lineEdit_m->text().toDouble();
    difEq.f = ui->lineEdit_f->text().toDouble();
    difEq.k = ui->lineEdit_k->text().toDouble();

     difEq.Eb = ui->lineEdit_Eb->text().toDouble();

    difEq.V1_ = difEq.V1;
    difEq.V2_ = difEq.V2;

    difEq.arrayV1 = new double[difEq.N];
    difEq.arrayV2 = new double[difEq.N];
    difEq.arrayx = new double[difEq.N];
    difEq.arrayh = new double[difEq.N];
    difEq.arrayV1_ = new double[difEq.N];
    difEq.arrayV2_ = new double[difEq.N];

    //difEq.Eb = 1e-7;
    difEq.EPS = 0;


    difEq.arrayV1[0]  =  difEq.V1;
    difEq.arrayV2[0]  =  difEq.V2;
    difEq.arrayx[0]   =  difEq.x;
    difEq.arrayh[0]   =  difEq.h;
    difEq.arrayV1_[0] =  difEq.V1_;
    difEq.arrayV2_[0] =  difEq.V2_;

    difEq.step = 0;

    ui->tableWidget->setRowCount(0);

    ui->tableWidget->insertRow(0);
    WriteTable(0, difEq.x, difEq.h, difEq.V1, difEq.V2, difEq.V1_, difEq.V2_, difEq.e1, difEq.e2, difEq.S3);

    if(ui->checkBox_Control->isChecked()){
     difEq.correctStep = true;
    } else {
     difEq.correctStep = false;
    }


 if(ui->checkBox_End->isChecked()){
  difEq.end = true;
 } else {
     difEq.end = false;
    }


 if(difEq.end){
 for(int i = 1; i < difEq.N && difEq.x < difEq.X; i++){
     difEq.step++;
     ui->tableWidget->insertRow(i);
     difEq.MakeStep();
     if(difEq.correctStep){
         if( difEq.CorrectStep() && i > 0) {
             difEq.step--;
             i--;

             difEq.V1  = difEq.arrayV1[i] ;
             difEq.V2  = difEq.arrayV2[i] ;
             difEq.x   = difEq.arrayx[i]  ;
             difEq.V1_ = difEq.arrayV1_[i];
             difEq.V2_ = difEq.arrayV2_[i];
             continue;

         };
     }



     WriteTable(i, difEq.x, difEq.h, difEq.V1, difEq.V2, difEq.V1_, difEq.V2_, difEq.e1, difEq.e2, difEq.S3);

     difEq.arrayV1[i] = difEq.V1;
     difEq.arrayV2[i] = difEq.V2;
     difEq.arrayx[i]= difEq.x;
     difEq.arrayh[i]= difEq.h;
     difEq.arrayV1_[i] = difEq.V1_;
     difEq.arrayV2_[i] = difEq.V2_;

 }
} else {

     for(int i = 1; i < difEq.N; i++){
         difEq.step++;
         ui->tableWidget->insertRow(i);
         difEq.MakeStep();
         if(difEq.correctStep){
             if( difEq.CorrectStep() && i > 0) {
                 difEq.step--;
                 i--;

                 difEq.V1  = difEq.arrayV1[i] ;
                 difEq.V2  = difEq.arrayV2[i] ;
                 difEq.x   = difEq.arrayx[i]  ;
                 difEq.V1_ = difEq.arrayV1_[i];
                 difEq.V2_ = difEq.arrayV2_[i];
                 continue;

             };
         }



         WriteTable(i, difEq.x, difEq.h, difEq.V1, difEq.V2, difEq.V1_, difEq.V2_, difEq.e1, difEq.e2, difEq.S3);

         difEq.arrayV1[i] = difEq.V1;
         difEq.arrayV2[i] = difEq.V2;
         difEq.arrayx[i]= difEq.x;
         difEq.arrayh[i]= difEq.h;
         difEq.arrayV1_[i] = difEq.V1_;
         difEq.arrayV2_[i] = difEq.V2_;


 }

}

 GetMaxMin(6, 0, difEq.step, difEq.arrayMaxMin);

 ui->label_maxe1->setText("Max(e1): " + difEq.arrayMaxMin[0].toString()+" при x="+difEq.arrayMaxMin[2].toString());
 ui->label_mine1->setText("Min(e1): " + difEq.arrayMaxMin[1].toString()+" при x="+difEq.arrayMaxMin[3].toString());

  GetMaxMin(7, 0, difEq.step, difEq.arrayMaxMin);
  ui->label_maxe2->setText("Max(e2): " + difEq.arrayMaxMin[0].toString()+" при x="+difEq.arrayMaxMin[2].toString());
  ui->label_mine2->setText("Min(e2): " + difEq.arrayMaxMin[1].toString()+" при x="+difEq.arrayMaxMin[3].toString());

 paintGraph(0,2,difEq.step,numbGraph,0,0);
 numbGraph++;
 paintGraph(0,3,difEq.step,numbGraph, 0, 1);
 numbGraph++;
 paintGraphPortret(2,3,0,difEq.step, numbGraphPortret, 0, 0);
 numbGraphPortret++;


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

void MainWindow::on_pushButton_Clear_clicked()
{
    ui->graph->clearGraphs();//очищаем все графики.
    ui->graphPortret->clearGraphs();
    ui->graphPortret->clearPlottables();
    ui->tableWidget->setRowCount(0);
    numbGraph = 0;
    numbGraphPortret = 0;

    ui->graph->replot();
    ui->graphPortret->replot();
}



void MainWindow::on_pushButton_Portret_clicked()
{
    double h = ui->lineEdit_h->text().toDouble();
    int N = ui->lineEdit_N->text().toInt();
    double X = ui->lineEdit_X->text().toDouble();
    double cf = 0.1;


        Do(0, 0);

    //////////////
    for(int i = 1; i < 3; i++){
        Do(0, cf*i);
    }

    for(int i = 1; i < 3; i++){
        Do(0, -cf*i);
    }


    for(int i = 1; i < 3; i++){
        Do(-cf*i, 0);
    }


    for(int i = 1; i < 3; i++){
        Do(cf*i, 0);
    }

    for(int i = 1; i < 3; i++){
        Do(cf*i, cf*i);
    }

    for(int i = 1; i < 3; i++){
        Do(-cf*i, -cf*i);
    }

    for(int i = 1; i < 3; i++){
        Do(cf*i, -cf*i);
    }

    for(int i = 1; i < 3; i++){
        Do(-cf*i, cf*i);
    }
}


void MainWindow::on_checkBox_Control_clicked()
{

}



void MainWindow::on_checkBox_End_clicked()
{

}
