#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Spline");

    ui->GRAPH->setInteraction(QCP::iRangeZoom, true); //удаление и приближение
    ui->GRAPH->setInteraction(QCP::iRangeDrag, true); //перетаскивание

    ui->GRAPH->xAxis->setLabel("X");
    ui->GRAPH->yAxis->setLabel("F");


    ui->GRAPH_ERROR->setInteraction(QCP::iRangeZoom, true); //удаление и приближение
    ui->GRAPH_ERROR->setInteraction(QCP::iRangeDrag, true); //перетаскивание

    ui->GRAPH_ERROR->xAxis->setLabel("X");
    ui->GRAPH_ERROR->yAxis->setLabel("ERROR F");


    ui->GRAPH_DER->setInteraction(QCP::iRangeZoom, true); //удаление и приближение
    ui->GRAPH_DER->setInteraction(QCP::iRangeDrag, true); //перетаскивание

    ui->GRAPH_DER->xAxis->setLabel("X");
    ui->GRAPH_DER->yAxis->setLabel("F'");

    ui->GRAPH_DER_ERROR->setInteraction(QCP::iRangeZoom, true); //удаление и приближение
    ui->GRAPH_DER_ERROR->setInteraction(QCP::iRangeDrag, true); //перетаскивание

    ui->GRAPH_DER_ERROR->xAxis->setLabel("X");
    ui->GRAPH_DER_ERROR->yAxis->setLabel("ERROR F'");


    ui->GRAPH_DER_DER->xAxis->setLabel("X");
    ui->GRAPH_DER_DER->yAxis->setLabel("F''");

    ui->GRAPH_DER_DER->setInteraction(QCP::iRangeZoom, true); //удаление и приближение
    ui->GRAPH_DER_DER->setInteraction(QCP::iRangeDrag, true); //перетаскивание

    ui->GRAPH_DER_DER_ERROR->setInteraction(QCP::iRangeZoom, true); //удаление и приближение
    ui->GRAPH_DER_DER_ERROR->setInteraction(QCP::iRangeDrag, true); //перетаскивание

    ui->GRAPH_DER_DER_ERROR->xAxis->setLabel("X");
    ui->GRAPH_DER_DER_ERROR->yAxis->setLabel("ERROR F''");


     numbGraph = 0;
     numbGraphError = 0;

    }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BUTTON_clicked()
{


    if(ui->radioButton_TEST->isChecked()){
        SPLINE.mode =0;
    }



    if(ui->radioButton_FIRST->isChecked()){
        SPLINE.mode =1;
    }


    if(ui->radioButton_SECOND->isChecked()){
        SPLINE.mode =2;
    }


    if(ui->radioButton_THIRD->isChecked()){
        SPLINE.mode =3;
    }



    SPLINE.splitting = ui->lineEdit_n->text().toInt();
    SPLINE.leftBorder = ui->lineEdit_a->text().toDouble();
    SPLINE.rightBorder = ui->lineEdit_b->text().toDouble();


    if(ui->checkBox_Auto->isChecked()){

        SPLINE.GetAuto();

    } else {

        SPLINE.sLB = ui->lineEdit_Sa->text().toDouble();
        SPLINE.sRB = ui->lineEdit_Sb->text().toDouble();
    }


    SPLINE.k = ui->lineEdit_k->text().toInt();


    SPLINE.SetStep();
    SPLINE.SetSplineStep();
    SPLINE.SetMassifs();
    SPLINE.mX[0] = SPLINE.leftBorder;
    SPLINE.mXSpline[0] = SPLINE.leftBorder;
    SPLINE.mF[0] = SPLINE.GetFunTest(SPLINE.mX[0]);
    SPLINE.mA[0] = SPLINE.GetFunTest(SPLINE.mX[0]);



    if(ui->checkBox_Auto->isChecked()){

    SPLINE.mC[0] = SPLINE.sLB;
    SPLINE.mC[SPLINE.splitting] = SPLINE.sRB;

    }  else {

        SPLINE.mC[0] = ui->lineEdit_Sa->text().toDouble();
        SPLINE.mC[SPLINE.splitting] = ui->lineEdit_Sb->text().toDouble();
    }

    SPLINE.mB[0] = 0;
    SPLINE.mD[0] = 0;

    SPLINE.mMain[0] = 1;
    SPLINE.mUnder[0] = 0;
    SPLINE.mOver[0] = 0;
    SPLINE.mFun[0] = SPLINE.sLB;

    SPLINE.mMain[SPLINE.splitting] = 1;
    SPLINE.mUnder[SPLINE.splitting] = 0;
    SPLINE.mOver[SPLINE.splitting] = 0;
    SPLINE.mFun[SPLINE.splitting] = SPLINE.sRB;

    ui->TABLE->setRowCount(0);
    ui->TABLE_1->setRowCount(0);


    for(int i = 0; i < SPLINE.splitting; i++){

        SPLINE.SetX(i); //xi+1
    }


    for(int i = 0; i < SPLINE.splittingSpline; i++){

        SPLINE.SetXSpline(i);
    }

    SPLINE.SetF_1();

    for(int i = 1; i < SPLINE.splitting; i++){
        SPLINE.SetMain(i);
        SPLINE.SetOver(i);
        SPLINE.SetUnder(i);
        SPLINE.SetFun(i);
    }

    SPLINE.SolveMatrix(SPLINE.splitting+1, SPLINE.mUnder, SPLINE.mMain, SPLINE.mOver, SPLINE.mFun, SPLINE.mC);



    if(ui->checkBox_Auto->isChecked()){

    SPLINE.mC[0] = SPLINE.sLB;
    SPLINE.mC[SPLINE.splitting] = SPLINE.sRB;

    }  else {

        SPLINE.mC[0] = ui->lineEdit_Sa->text().toDouble();
        SPLINE.mC[SPLINE.splitting] = ui->lineEdit_Sb->text().toDouble();
    }


    for(int i = 0; i < SPLINE.splitting; i++){


        SPLINE.SetA(i);
        SPLINE.SetB(i);
        SPLINE.SetD(i);
        SPLINE.SetF(i);

    }

    for(int i = 0; i < SPLINE.splitting+1; i++){

        ui->TABLE->insertRow(i);
        if(i<SPLINE.splitting){
        WriteTable(i, SPLINE.mX[i], SPLINE.mX[i+1], SPLINE.mA[i], SPLINE.mB[i], SPLINE.mC[i], SPLINE.mD[i]);
        } else {
            WriteTable(i, SPLINE.mX[i], SPLINE.mX[i] , SPLINE.mA[i], SPLINE.mB[i], SPLINE.mC[i], SPLINE.mD[i]);
        }

    }

    SPLINE.SetSpline();

    SPLINE.GetError(SPLINE.mF_1, SPLINE.mSpline, SPLINE.mZ, SPLINE.splittingSpline+1);

    SPLINE.SetF_1_();
    SPLINE.SetSpline_();
    SPLINE.GetError(SPLINE.mF_1_, SPLINE.mSpline_, SPLINE.mZ_, SPLINE.splittingSpline+1);

    SPLINE.SetF_1__();
    SPLINE.SetSpline__();
    SPLINE.GetError(SPLINE.mF_1__, SPLINE.mSpline__, SPLINE.mZ__, SPLINE.splittingSpline+1);

    for(int i = 0; i < SPLINE.splittingSpline+1; i++){
        ui->TABLE_1->insertRow(i);
        WriteTable_1(i, SPLINE.mXSpline[i], SPLINE.mF_1[i], SPLINE.mSpline[i], SPLINE.mZ[i], SPLINE.mF_1_[i], SPLINE.mSpline_[i], SPLINE.mZ_[i], SPLINE.mF_1__[i], SPLINE.mSpline__[i], SPLINE.mZ__[i]);
    }


      PaintGraphDer(SPLINE.mXSpline, SPLINE.mSpline_,SPLINE.splittingSpline+1,numbGraphDer,"S " + QVariant(numbGraphDer).toString());
      numbGraphDer++;

      PaintGraphDer(SPLINE.mXSpline, SPLINE.mF_1_,SPLINE.splittingSpline+1,numbGraphDer,"F " + QVariant(numbGraphDer).toString());
      numbGraphDer++;

      PaintGraphDerError(SPLINE.mXSpline, SPLINE.mZ_,SPLINE.splittingSpline+1,numbGraphDerError, QVariant(numbGraphDerError).toString());
      numbGraphDerError++;


      PaintGraphDerDer(SPLINE.mXSpline, SPLINE.mSpline__,SPLINE.splittingSpline+1,numbGraphDerDer,"S " + QVariant(numbGraphDerDer).toString());
      numbGraphDerDer++;

      PaintGraphDerDer(SPLINE.mXSpline, SPLINE.mF_1__,SPLINE.splittingSpline+1,numbGraphDerDer,"F " + QVariant(numbGraphDerDer).toString());
      numbGraphDerDer++;

      PaintGraphDerDerError(SPLINE.mXSpline, SPLINE.mZ__,SPLINE.splittingSpline+1,numbGraphDerDerError, QVariant(numbGraphDerDerError).toString());
      numbGraphDerDerError++;



      PaintGraph(SPLINE.mXSpline, SPLINE.mSpline,SPLINE.splittingSpline+1,numbGraph,"F " + QVariant(numbGraph).toString());
      numbGraph++;

      PaintGraph(SPLINE.mXSpline, SPLINE.mF_1 ,SPLINE.splittingSpline+1,numbGraph,"S " + QVariant(numbGraph).toString());
      numbGraph++;

      PaintGraphError(SPLINE.mXSpline, SPLINE.mZ, SPLINE.splittingSpline+1,numbGraphError, QVariant(numbGraphError).toString());
      numbGraphError++;

    int indexZ = SPLINE.GetIdMax(SPLINE.mZ, SPLINE.splittingSpline+1);
    int indexZ_ = SPLINE.GetIdMax(SPLINE.mZ_, SPLINE.splittingSpline+1);
    int indexZ__ = SPLINE.GetIdMax(SPLINE.mZ__, SPLINE.splittingSpline+1);

    ui->label_n->setText("n = " + QVariant(SPLINE.splitting).toString());
    ui->label_N->setText("N = " + QVariant(SPLINE.splittingSpline).toString());
    ui->label_maxFS->setText("max|F-S| = " + QVariant(SPLINE.mZ[indexZ]).toString());
    ui->label_maxFSX->setText("x = " + QVariant(SPLINE.mXSpline[indexZ]).toString());
    ui->label_maxFS_->setText("max|F'-S'| = " + QVariant(SPLINE.mZ_[indexZ_]).toString());
    ui->label_maxFSX_->setText("x = " + QVariant(SPLINE.mXSpline[indexZ_]).toString());
    ui->label_maxFS__->setText("max|F''-S''| = " + QVariant(SPLINE.mZ__[indexZ__]).toString());
    ui->label_maxFSX__->setText("x = " + QVariant(SPLINE.mXSpline[indexZ__]).toString());
}


void MainWindow::on_BUTTON_CLEAN_clicked()
{
    ui->GRAPH->clearGraphs();
    numbGraph = 0;
    ui->GRAPH->replot();


    ui->GRAPH_ERROR->clearGraphs();
    numbGraphError = 0;
    ui->GRAPH_ERROR->replot();


    ui->GRAPH_DER_ERROR->clearGraphs();
    numbGraphDerError = 0;
    ui->GRAPH_DER_ERROR->replot();


    ui->GRAPH_DER->clearGraphs();
    numbGraphDer = 0;
    ui->GRAPH_DER->replot();

    ui->GRAPH_DER_DER->clearGraphs();
    numbGraphDerDer = 0;
    ui->GRAPH_DER_DER->replot();

    ui->GRAPH_DER_DER_ERROR->clearGraphs();
    numbGraphDerDerError = 0;
    ui->GRAPH_DER_DER_ERROR->replot();



    ui->TABLE->setRowCount(0);



}

void MainWindow::PaintGraph(double* myX, double* myY, int N, const int nGraph, QString nameGraph){


    QVector<double> X(N);
    QVector<double> Y(N);

    for(int i = 0; i < N; i++){
        X[i] = myX[i];
        Y[i] = myY[i];
    }

    ui->GRAPH->legend->setVisible(true);
    ui->GRAPH->legend->setFont(QFont("Helvetica", 9));
    ui->GRAPH->legend->setRowSpacing(-3);

    QVector<QCPScatterStyle::ScatterShape> shapes;
    shapes << QCPScatterStyle::ssCross;
    shapes << QCPScatterStyle::ssPlus;
    shapes << QCPScatterStyle::ssCircle;
    shapes << QCPScatterStyle::ssDisc;
    shapes << QCPScatterStyle::ssSquare;
    shapes << QCPScatterStyle::ssDiamond;
    shapes << QCPScatterStyle::ssStar;
    shapes << QCPScatterStyle::ssTriangle;
    shapes << QCPScatterStyle::ssTriangleInverted;
    shapes << QCPScatterStyle::ssCrossSquare;
    shapes << QCPScatterStyle::ssPlusSquare;
    shapes << QCPScatterStyle::ssCrossCircle;
    shapes << QCPScatterStyle::ssPlusCircle;
    shapes << QCPScatterStyle::ssPeace;
    shapes << QCPScatterStyle::ssCustom;

    QPen pen;

    pen.setColor(QColor(qSin(nGraph%14*0.3)*100+100, qSin(nGraph%14*0.6+0.7)*100+100, qSin(nGraph%14*0.4+0.6)*100+100));

    ui->GRAPH->addGraph();
    ui->GRAPH->graph(nGraph)->setData(X, Y);

    ui->GRAPH->graph(nGraph)->setPen(pen);
    ui->GRAPH->graph(nGraph)->setName(nameGraph);
    ui->GRAPH->graph(nGraph)->setLineStyle(QCPGraph::lsLine);

    // set scatter style:

    if(N < 100){
     if (shapes.at(nGraph%14) != QCPScatterStyle::ssCustom)
     {
       ui->GRAPH->graph(nGraph)->setScatterStyle(QCPScatterStyle(shapes.at(nGraph%14), 10));
     }
     else
     {
       QPainterPath customScatterPath;
       for (int i=0; i<3; ++i)
         customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
           ui->GRAPH->graph(nGraph)->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(Qt::black, 0), QColor(40, 70, 255, 50), 10));
     }

}

     ui->GRAPH->graph(nGraph)->rescaleAxes();
     ui->GRAPH->replot();

   }

void MainWindow::PaintGraphError(double* myX, double* myY, int N, const int nGraph, QString nameGraph){


    QVector<double> X(N);
    QVector<double> Y(N);

    for(int i = 0; i < N; i++){
        X[i] = myX[i];
        Y[i] = myY[i];
    }

    ui->GRAPH_ERROR->legend->setVisible(true);
    ui->GRAPH_ERROR->legend->setFont(QFont("Helvetica", 9));
    ui->GRAPH_ERROR->legend->setRowSpacing(-3);

    QVector<QCPScatterStyle::ScatterShape> shapes;
    shapes << QCPScatterStyle::ssCross;
    shapes << QCPScatterStyle::ssPlus;
    shapes << QCPScatterStyle::ssCircle;
    shapes << QCPScatterStyle::ssDisc;
    shapes << QCPScatterStyle::ssSquare;
    shapes << QCPScatterStyle::ssDiamond;
    shapes << QCPScatterStyle::ssStar;
    shapes << QCPScatterStyle::ssTriangle;
    shapes << QCPScatterStyle::ssTriangleInverted;
    shapes << QCPScatterStyle::ssCrossSquare;
    shapes << QCPScatterStyle::ssPlusSquare;
    shapes << QCPScatterStyle::ssCrossCircle;
    shapes << QCPScatterStyle::ssPlusCircle;
    shapes << QCPScatterStyle::ssPeace;
    shapes << QCPScatterStyle::ssCustom;

    QPen pen;

    pen.setColor(QColor(qSin(nGraph%14*0.3)*100+100, qSin(nGraph%14*0.6+0.7)*100+100, qSin(nGraph%14*0.4+0.6)*100+100));

    ui->GRAPH_ERROR->addGraph();
    ui->GRAPH_ERROR->graph(nGraph)->setData(X, Y);

    ui->GRAPH_ERROR->graph(nGraph)->setPen(pen);
    ui->GRAPH_ERROR->graph(nGraph)->setName(nameGraph);
    ui->GRAPH_ERROR->graph(nGraph)->setLineStyle(QCPGraph::lsLine);

    // set scatter style:
 if(N<100){
    if (shapes.at(nGraph%14) != QCPScatterStyle::ssCustom)
     {
       ui->GRAPH_ERROR->graph(nGraph)->setScatterStyle(QCPScatterStyle(shapes.at(nGraph%14), 10));
     }
     else
     {
       QPainterPath customScatterPath;
       for (int i=0; i<3; ++i)
         customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
           ui->GRAPH_ERROR->graph(nGraph)->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(Qt::black, 0), QColor(40, 70, 255, 50), 10));
     }
}

     ui->GRAPH_ERROR->graph(nGraph)->rescaleAxes();
     ui->GRAPH_ERROR->replot();

   }

void MainWindow::PaintGraphDerError(double* myX, double* myY, int N, const int nGraph, QString nameGraph){


    QVector<double> X(N);
    QVector<double> Y(N);

    for(int i = 0; i < N; i++){
        X[i] = myX[i];
        Y[i] = myY[i];
    }

    ui->GRAPH_DER_ERROR->legend->setVisible(true);
    ui->GRAPH_DER_ERROR->legend->setFont(QFont("Helvetica", 9));
    ui->GRAPH_DER_ERROR->legend->setRowSpacing(-3);

    QVector<QCPScatterStyle::ScatterShape> shapes;
    shapes << QCPScatterStyle::ssCross;
    shapes << QCPScatterStyle::ssPlus;
    shapes << QCPScatterStyle::ssCircle;
    shapes << QCPScatterStyle::ssDisc;
    shapes << QCPScatterStyle::ssSquare;
    shapes << QCPScatterStyle::ssDiamond;
    shapes << QCPScatterStyle::ssStar;
    shapes << QCPScatterStyle::ssTriangle;
    shapes << QCPScatterStyle::ssTriangleInverted;
    shapes << QCPScatterStyle::ssCrossSquare;
    shapes << QCPScatterStyle::ssPlusSquare;
    shapes << QCPScatterStyle::ssCrossCircle;
    shapes << QCPScatterStyle::ssPlusCircle;
    shapes << QCPScatterStyle::ssPeace;
    shapes << QCPScatterStyle::ssCustom;

    QPen pen;

    pen.setColor(QColor(qSin(nGraph%14*0.3)*100+100, qSin(nGraph%14*0.6+0.7)*100+100, qSin(nGraph%14*0.4+0.6)*100+100));

    ui->GRAPH_DER_ERROR->addGraph();
    ui->GRAPH_DER_ERROR->graph(nGraph)->setData(X, Y);

    ui->GRAPH_DER_ERROR->graph(nGraph)->setPen(pen);
    ui->GRAPH_DER_ERROR->graph(nGraph)->setName(nameGraph);
    ui->GRAPH_DER_ERROR->graph(nGraph)->setLineStyle(QCPGraph::lsLine);

    // set scatter style:
 if(N<100){
    if (shapes.at(nGraph%14) != QCPScatterStyle::ssCustom)
     {
       ui->GRAPH_DER_ERROR->graph(nGraph)->setScatterStyle(QCPScatterStyle(shapes.at(nGraph%14), 10));
     }
     else
     {
       QPainterPath customScatterPath;
       for (int i=0; i<3; ++i)
         customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
           ui->GRAPH_DER_ERROR->graph(nGraph)->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(Qt::black, 0), QColor(40, 70, 255, 50), 10));
     }

 }
      ui->GRAPH_DER_ERROR->graph(nGraph)->rescaleAxes();
     ui->GRAPH_DER_ERROR->replot();

   }

void MainWindow::PaintGraphDer(double* myX, double* myY, int N, const int nGraph, QString nameGraph){


    QVector<double> X(N);
    QVector<double> Y(N);

    for(int i = 0; i < N; i++){
        X[i] = myX[i];
        Y[i] = myY[i];
    }

    ui->GRAPH_DER->legend->setVisible(true);
    ui->GRAPH_DER->legend->setFont(QFont("Helvetica", 9));
    ui->GRAPH_DER->legend->setRowSpacing(-3);

    QVector<QCPScatterStyle::ScatterShape> shapes;
    shapes << QCPScatterStyle::ssCross;
    shapes << QCPScatterStyle::ssPlus;
    shapes << QCPScatterStyle::ssCircle;
    shapes << QCPScatterStyle::ssDisc;
    shapes << QCPScatterStyle::ssSquare;
    shapes << QCPScatterStyle::ssDiamond;
    shapes << QCPScatterStyle::ssStar;
    shapes << QCPScatterStyle::ssTriangle;
    shapes << QCPScatterStyle::ssTriangleInverted;
    shapes << QCPScatterStyle::ssCrossSquare;
    shapes << QCPScatterStyle::ssPlusSquare;
    shapes << QCPScatterStyle::ssCrossCircle;
    shapes << QCPScatterStyle::ssPlusCircle;
    shapes << QCPScatterStyle::ssPeace;
    shapes << QCPScatterStyle::ssCustom;

    QPen pen;

    pen.setColor(QColor(qSin(nGraph%14*0.3)*100+100, qSin(nGraph%14*0.6+0.7)*100+100, qSin(nGraph%14*0.4+0.6)*100+100));

    ui->GRAPH_DER->addGraph();
    ui->GRAPH_DER->graph(nGraph)->setData(X, Y);

    ui->GRAPH_DER->graph(nGraph)->setPen(pen);
    ui->GRAPH_DER->graph(nGraph)->setName(nameGraph);
    ui->GRAPH_DER->graph(nGraph)->setLineStyle(QCPGraph::lsLine);

    // set scatter style:
  if(N<100){
    if (shapes.at(nGraph%14) != QCPScatterStyle::ssCustom)
     {
       ui->GRAPH_DER->graph(nGraph)->setScatterStyle(QCPScatterStyle(shapes.at(nGraph%14), 10));
     }
     else
     {
       QPainterPath customScatterPath;
       for (int i=0; i<3; ++i)
         customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
           ui->GRAPH_DER->graph(nGraph)->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(Qt::black, 0), QColor(40, 70, 255, 50), 10));
     }

  }
     ui->GRAPH_DER->graph(nGraph)->rescaleAxes();
     ui->GRAPH_DER->replot();

   }

void MainWindow::PaintGraphDerDer(double* myX, double* myY, int N, const int nGraph, QString nameGraph){


    QVector<double> X(N);
    QVector<double> Y(N);

    for(int i = 0; i < N; i++){
        X[i] = myX[i];
        Y[i] = myY[i];
    }

    ui->GRAPH_DER_DER->legend->setVisible(true);
    ui->GRAPH_DER_DER->legend->setFont(QFont("Helvetica", 9));
    ui->GRAPH_DER_DER->legend->setRowSpacing(-3);

    QVector<QCPScatterStyle::ScatterShape> shapes;
    shapes << QCPScatterStyle::ssCross;
    shapes << QCPScatterStyle::ssPlus;
    shapes << QCPScatterStyle::ssCircle;
    shapes << QCPScatterStyle::ssDisc;
    shapes << QCPScatterStyle::ssSquare;
    shapes << QCPScatterStyle::ssDiamond;
    shapes << QCPScatterStyle::ssStar;
    shapes << QCPScatterStyle::ssTriangle;
    shapes << QCPScatterStyle::ssTriangleInverted;
    shapes << QCPScatterStyle::ssCrossSquare;
    shapes << QCPScatterStyle::ssPlusSquare;
    shapes << QCPScatterStyle::ssCrossCircle;
    shapes << QCPScatterStyle::ssPlusCircle;
    shapes << QCPScatterStyle::ssPeace;
    shapes << QCPScatterStyle::ssCustom;

    QPen pen;

    pen.setColor(QColor(qSin(nGraph%14*0.3)*100+100, qSin(nGraph%14*0.6+0.7)*100+100, qSin(nGraph%14*0.4+0.6)*100+100));

    ui->GRAPH_DER_DER->addGraph();
    ui->GRAPH_DER_DER->graph(nGraph)->setData(X, Y);

    ui->GRAPH_DER_DER->graph(nGraph)->setPen(pen);
    ui->GRAPH_DER_DER->graph(nGraph)->setName(nameGraph);
    ui->GRAPH_DER_DER->graph(nGraph)->setLineStyle(QCPGraph::lsLine);

    // set scatter style:
   if(N<100){
    if (shapes.at(nGraph%14) != QCPScatterStyle::ssCustom)
     {
       ui->GRAPH_DER_DER->graph(nGraph)->setScatterStyle(QCPScatterStyle(shapes.at(nGraph%14), 10));
     }
     else
     {
       QPainterPath customScatterPath;
       for (int i=0; i<3; ++i)
         customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
           ui->GRAPH_DER_DER->graph(nGraph)->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(Qt::black, 0), QColor(40, 70, 255, 50), 10));
     }
}
     ui->GRAPH_DER_DER->graph(nGraph)->rescaleAxes();
     ui->GRAPH_DER_DER->replot();

   }

void MainWindow::PaintGraphDerDerError(double* myX, double* myY, int N, const int nGraph, QString nameGraph){


    QVector<double> X(N);
    QVector<double> Y(N);

    for(int i = 0; i < N; i++){
        X[i] = myX[i];
        Y[i] = myY[i];
    }

    ui->GRAPH_DER_DER_ERROR->legend->setVisible(true);
    ui->GRAPH_DER_DER_ERROR->legend->setFont(QFont("Helvetica", 9));
    ui->GRAPH_DER_DER_ERROR->legend->setRowSpacing(-3);

    QVector<QCPScatterStyle::ScatterShape> shapes;
    shapes << QCPScatterStyle::ssCross;
    shapes << QCPScatterStyle::ssPlus;
    shapes << QCPScatterStyle::ssCircle;
    shapes << QCPScatterStyle::ssDisc;
    shapes << QCPScatterStyle::ssSquare;
    shapes << QCPScatterStyle::ssDiamond;
    shapes << QCPScatterStyle::ssStar;
    shapes << QCPScatterStyle::ssTriangle;
    shapes << QCPScatterStyle::ssTriangleInverted;
    shapes << QCPScatterStyle::ssCrossSquare;
    shapes << QCPScatterStyle::ssPlusSquare;
    shapes << QCPScatterStyle::ssCrossCircle;
    shapes << QCPScatterStyle::ssPlusCircle;
    shapes << QCPScatterStyle::ssPeace;
    shapes << QCPScatterStyle::ssCustom;

    QPen pen;

    pen.setColor(QColor(qSin(nGraph%14*0.3)*100+100, qSin(nGraph%14*0.6+0.7)*100+100, qSin(nGraph%14*0.4+0.6)*100+100));

    ui->GRAPH_DER_DER_ERROR->addGraph();
    ui->GRAPH_DER_DER_ERROR->graph(nGraph)->setData(X, Y);

    ui->GRAPH_DER_DER_ERROR->graph(nGraph)->setPen(pen);
    ui->GRAPH_DER_DER_ERROR->graph(nGraph)->setName(nameGraph);
    ui->GRAPH_DER_DER_ERROR->graph(nGraph)->setLineStyle(QCPGraph::lsLine);


    if(N<100){
     if (shapes.at(nGraph%14) != QCPScatterStyle::ssCustom)
     {
       ui->GRAPH_DER_DER_ERROR->graph(nGraph)->setScatterStyle(QCPScatterStyle(shapes.at(nGraph%14), 10));
     }
     else
     {
       QPainterPath customScatterPath;
       for (int i=0; i<3; ++i)
         customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
           ui->GRAPH_DER_DER_ERROR->graph(nGraph)->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(Qt::black, 0), QColor(40, 70, 255, 50), 10));
     }
}
     ui->GRAPH_DER_DER_ERROR->graph(nGraph)->rescaleAxes();
     ui->GRAPH_DER_DER_ERROR->replot();

   }

QTableWidgetItem* MainWindow::CreateItem(QVariant it){
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(it.toString());
    return item;
}

void MainWindow::WriteTable(int i, double X, double Y, double Z, double W, double Q, double V){


    QVariant qX = X;
    QVariant qY = Y;
    QVariant qZ = Z;
    QVariant qW = W;
    QVariant qQ = Q;
    QVariant qV = V;

    ui->TABLE->setItem(i, 0, CreateItem(qX));
    ui->TABLE->setItem(i, 1, CreateItem(qY));
    ui->TABLE->setItem(i, 2, CreateItem(qZ));
    ui->TABLE->setItem(i, 3, CreateItem(qW));
    ui->TABLE->setItem(i, 4, CreateItem(qQ));
    ui->TABLE->setItem(i, 5, CreateItem(qV));


}

void MainWindow::WriteTable_1(int i, double X, double Y, double Z, double W, double Q, double V, double S,  double G, double T, double R){


    QVariant qX = X;
    QVariant qY = Y;
    QVariant qZ = Z;
    QVariant qW = W;
    QVariant qQ = Q;
    QVariant qV = V;
    QVariant qS = S;
    QVariant qG = G;
    QVariant qT = T;
    QVariant qR = R;


    ui->TABLE_1->setItem(i, 0, CreateItem(qX));
    ui->TABLE_1->setItem(i, 1, CreateItem(qY));
    ui->TABLE_1->setItem(i, 2, CreateItem(qZ));
    ui->TABLE_1->setItem(i, 3, CreateItem(qW));
    ui->TABLE_1->setItem(i, 4, CreateItem(qQ));
    ui->TABLE_1->setItem(i, 5, CreateItem(qV));
    ui->TABLE_1->setItem(i, 6, CreateItem(qS));
    ui->TABLE_1->setItem(i, 7, CreateItem(qG));
    ui->TABLE_1->setItem(i, 8, CreateItem(qT));
    ui->TABLE_1->setItem(i, 9, CreateItem(qR));



}




