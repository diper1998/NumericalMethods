#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Dirichlet");
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

void MainWindow::SetRecord(QTableWidget* pTable, int i, int j, double myX) {

        pTable->setItem(i, j, CreateItem(QVariant(myX)));


}


void MainWindow::SetTable(QTableWidget* pTable, double** myX, int  n, int m) {

   pTable->setColumnCount(n);
   pTable->setRowCount(m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
        pTable->setItem(j, i, CreateItem(QVariant(myX[i][j])));
    }

}



void MainWindow::on_pushButtonStart_clicked()
{

    double a = QVariant(ui->lineEdit_a->text()).toDouble();
    double b = QVariant(ui->lineEdit_b->text()).toDouble();
    double c = QVariant(ui->lineEdit_c->text()).toDouble();
    double d = QVariant(ui->lineEdit_d->text()).toDouble();

    int n = QVariant(ui->lineEdit_n->text()).toInt();
    int m = QVariant(ui->lineEdit_m->text()).toInt();

    int N = QVariant(ui->lineEdit_N->text()).toInt();
    double Eps = QVariant(ui->lineEdit_E->text()).toDouble();


    double t = QVariant(ui->lineEdit_t->text()).toDouble();


    int Task;

    if(ui->radioButton_Test->isChecked());
        Task = 0;


    if(ui->radioButton_Main->isChecked())
        Task = 1;

    double maxError = 0;


   myDir.SetParam(a, b, c, d, n, m, t, Eps, N, Task);

// Test
    if(ui->radioButton_Test->isChecked()){

        if(ui->radioButton_Seidel->isChecked())
        myDir.MethodSeidel();

        if(ui->radioButton_Iteration->isChecked())
        myDir.MethodIteration();

        myDir.SetU();

        maxError = myDir.SetErrorGetMax(myDir.V, myDir.U);

        myDir.SetDiscrepancy(myDir.V, myDir.F, n, m, myDir.h, myDir.k);

        if(ui->radioButton_V->isChecked())
        SetTable(ui->firstTable, myDir.V, n+1, m+1);

        if(ui->radioButton_U->isChecked())
        SetTable(ui->firstTable, myDir.U, n+1, m+1);

        if(ui->radioButton_U_V->isChecked())
        SetTable(ui->firstTable, myDir.Error, n+1, m+1);




        ui->label_it->setText("Iterations = " + QVariant(myDir.resEpsCount[1]).toString());
        ui->label_Eps->setText("Eps = " + QVariant(myDir.resEpsCount[0]).toString());
        ui->label_Error->setText("||U-V|| = " + QVariant(maxError).toString());
        ui->label_xError->setText("x = " + QVariant(myDir.xError).toString());
        ui->label_yError->setText("y = " + QVariant(myDir.yError).toString());
        ui->label_Discrepancy->setText("Discrepancy = " + QVariant(myDir.discrepancy).toString());
        ui->label_Discrepancy2->setText("");

    }
// Main
    if(ui->radioButton_Main->isChecked()){
        if(ui->radioButton_Seidel->isChecked()){

       myDir.MethodSeidel();

        ui->label_it->setText("Iterations = " + QVariant(myDir.resEpsCount[1]).toString());
        ui->label_Eps->setText("Eps = " + QVariant(myDir.resEpsCount[0]).toString());

        myDir.MethodSeidel2();

        }


        if(ui->radioButton_Iteration->isChecked()){

       myDir.MethodIteration();

        ui->label_it->setText("Iterations = " + QVariant(myDir.resEpsCount[1]).toString());
        ui->label_Eps->setText("Eps = " + QVariant(myDir.resEpsCount[0]).toString());

        myDir.MethodIteration2();

        }


        myDir.SetDiscrepancy(myDir.V, myDir.F, n, m, myDir.h, myDir.k);
         ui->label_Discrepancy->setText("Discrepancy = " + QVariant(myDir.discrepancy).toString());
        myDir.SetDiscrepancy(myDir.V2, myDir.F, n, m, myDir.h, myDir.k);
        ui->label_Discrepancy2->setText("Discrepancy2 = " + QVariant(myDir.discrepancy).toString());


        myDir.SetSteps();
        maxError = myDir.SetErrorGetMax2(myDir.V, myDir.V2);

        if(ui->radioButton_V->isChecked())
        SetTable(ui->firstTable, myDir.V, n+1, m+1);


        if(ui->radioButton_V2->isChecked())
        SetTable(ui->firstTable, myDir.V2, 2*n+1, 2*m+1);

        if(ui->radioButton_V_V2->isChecked())
        SetTable(ui->firstTable, myDir.Error, n+1, m+1);



        ui->label_Error->setText("||V-V2|| = " + QVariant(maxError).toString());
        ui->label_xError->setText("x = " + QVariant(myDir.xError).toString());
        ui->label_yError->setText("y = " + QVariant(myDir.yError).toString());




    }

}

void MainWindow::on_pushButtonShow_clicked()
{
    if(ui->radioButton_V->isChecked())
    SetTable(ui->firstTable, myDir.V, myDir.n+1, myDir.m+1);


    if(ui->radioButton_V2->isChecked())
    SetTable(ui->firstTable, myDir.V2, 2*myDir.n+1, 2*myDir.m+1);

    if(ui->radioButton_V_V2->isChecked())
    SetTable(ui->firstTable, myDir.Error, myDir.n+1, myDir.m+1);

    if(ui->radioButton_V->isChecked())
    SetTable(ui->firstTable, myDir.V, myDir.n+1, myDir.m+1);

    if(ui->radioButton_U->isChecked())
    SetTable(ui->firstTable, myDir.U, myDir.n+1, myDir.m+1);

    if(ui->radioButton_U_V->isChecked())
    SetTable(ui->firstTable, myDir.Error, myDir.n+1, myDir.m+1);

}
