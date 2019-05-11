#ifndef DIRICHLET_H
#define DIRICHLET_H

#include <math.h>
#include "method.h"

class dirichlet
{
public:


  method method;

    double** V ;
    double** V2;
    double** U ;
    double** F;
    double** F2;
    double** Error;
    double** Discrepancy;
    double discrepancy;

    double xError;
    double yError;

    double t;

    int n; //разбиение x
    int m; //разбиение y

    double a, b, c, d;

    double h, k;

    double Eps;
    int N;

    double resEpsCount[2];


    int Task;


    double xBorder;
    double yBorder;

    void CreateVUFXY(){

        V = new double*[n+1];
        V2 = new double*[2*n+1];
        U = new double*[n+1];
        F = new double*[n+1];
        F2 = new double*[2*n+1];
        Error = new double*[n+1];
        Discrepancy = new double*[n+1];

        for(int i = 0; i < n+1; i++){
            V[i] = new double[m+1];
            U[i] = new double[m+1];
            F[i] = new double[m+1];
            Error[i] = new double[m+1];
            Discrepancy[i] = new double[m+1];
        }

        for(int i = 0; i < 2*(n+1); i++){
            V2[i] = new double[2*m+1];
            F2[i] = new double[2*m+1];
        }



    }

    dirichlet(){;}

   void SetParam(double mya, double myb, double myc, double myd,
              int myn, int mym, double myt, double myEps, int myN, int myTask){
        a = mya;
        b = myb;
        c = myc;
        d = myd;
        n = myn;
        m = mym;
        t = myt;
        Eps = myEps;
        N = myN;
        Task = myTask;

    }

    void SetSteps(){
        h = (b-a)/n;
        k = (d-c)/m;
    }


    void SetSteps2(){
        h = (b-a)/(2*n);
        k = (d-c)/(2*m);
    }





    double GetBorderX_1(double x){ // 1, 2

        double res = 0;

        if(Task == 0){
          res = GetU(x, c);
        }

        if(Task == 1){
          res = x - x * x;
        }

        return  res;
    }

    double GetBorderX_2(double x){ // 1, 2

        double res = 0;

        if(Task == 0){
          res = GetU(x, d);
        }

        if(Task == 1){
          res = x - x * x;
        }
        return  res;
    }


    double GetBorderY_1(double y){ // 1, 2

        double res = 0;

        if(Task == 0){
          res = GetU(a, y);
        }

        if(Task == 1)
            res = sin(acos(-1) * y);

        return  res;
    }


    double GetBorderY_2(double y){ // 1, 2

        double res = 0;

        if(Task == 0){
           res = GetU(b, y);
        }

        if(Task == 1)
            res = sin(acos(-1) * y);

        return  res;
    }


    double GetU(double x, double y){

        double res = 0;

        if(Task == 0){

             res = exp(sin(acos(-1) * x * y)*sin(acos(-1) * x * y));
        }

        if(Task == 1)
            res = exp(sin(acos(-1) * x * y)*sin(acos(-1) * x * y));

        return res;
    }

    double GetF(double x, double y){
    double res = 0;

    if(Task == 0){
        res = 0.5*acos(-1)*acos(-1)*GetU(x, y)*(x*x+y*y)*(-4*cos(2*acos(-1)*x*y)+cos(4*acos(-1)*x*y)-1);
    }

    if(Task == 1){
        res = sin(acos(-1) * x * y)*sin(acos(-1) * x * y);
    }
        return res;
    }



    void SetF(){

        for(int i = 0; i < n+1; i++ ){
            for(int j = 0; j < m+1; j++){
                F[i][j] = GetF(a+h*i, c+k*j);
            }
        }

    }

    void SetF2(){

        for(int i = 0; i < 2*n+1; i++ ){
            for(int j = 0; j < 2*m+1; j++){
                F2[i][j] = GetF(a+h*i, c+k*j);
            }
        }

    }


    void SetFirstV(){
        for(int i = 1; i < n; i++ ){
            for(int j = 1; j < m; j++){
                V[i][j] = 0;
            }
        }


        for(int i = 0; i < n+1; i++){

            V[i][0] =  GetBorderX_1(a+i*h);
            V[i][m] =  GetBorderX_2(a+i*h);
        }


        for(int i = 0; i < m+1; i++){
            V[0][i] =  GetBorderY_1(c+i*k);
            V[n][i] =  GetBorderY_2(c+i*k);
        }

    }



    void SetFirstVBorder(){
        int saveI = 0;

        for(int i = 1; i < n+1; i++ ){
            for(int j = 1; j < m+1; j++){
                V[i][j] = 0;
            }
        }



        for(int i = 0; i < n+1; i++){

            V[i][0] =  GetBorderX_1(a+i*h);
        }


        for(int i = 0; i < m+1; i++){
            V[0][i] =  GetBorderY_1(c+i*k);
        }


        for(int i = 0; a+i*h <= xBorder; i++){
            V[i][m] = GetU(a+i*h, d);
            saveI = i;
        }

        for(int i = saveI; i < n+1; i++){
            V[i][int(yBorder/k - c)] = GetU(a+i*h, yBorder);
        }


        for(int i = 0; c+i*k <= yBorder; i++){
            V[n][i] = GetU(b, c+i*k);
            saveI = i;
        }

        for(int i = saveI; i < m+1; i++){
            V[int(xBorder/h - a)][i] = GetU(xBorder, c+i*k);
        }


    }



    void SetFirstV2(){
        for(int i = 1; i < 2*n; i++ ){
            for(int j = 1; j < 2*m; j++){
                V2[i][j] = 0;
            }
        }


        for(int i = 0; i < 2*n+1; i++){

            V2[i][0] =  GetBorderX_1(a+i*h);
            V2[i][2*m] =  GetBorderX_2(a+i*h);
        }


        for(int i = 0; i < 2*m+1; i++){
            V2[0][i] =  GetBorderY_1(c+i*k);
            V2[2*n][i] =  GetBorderY_2(c+i*k);
        }

    }


    double SetErrorGetMax(double** A, double** B){

        double max = 0;
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < m+1; j++){
                Error[i][j] = fabs(A[i][j] - B[i][j]);
                if(max < Error[i][j]){
                    max = Error[i][j];

                    xError = a+i*h;
                    yError = c+j*k;

                }


            }
        }

        return max;
    }



    double SetErrorGetMax2(double** A, double** B){

        double max = 0;
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < m+1; j++){
                Error[i][j] = fabs(A[i][j] - B[2*i][2*j]);
                if(max < Error[i][j]){
                    max = Error[i][j];

                    xError = a+i*h;
                    yError = c+j*k;

                }


            }
        }

        return max;
    }


   void MethodSeidel(){

        CreateVUFXY();
        SetSteps();
        SetF();
        SetFirstV();


       method.SolveSystemSeidel(V, F, Eps, N, n, m, h, k, resEpsCount);


    }





   void MethodSeidelBorder(){

        CreateVUFXY();
        SetSteps();
        SetF();
        SetFirstVBorder();


       method.SolveSystemSeidelBorder(V, F, Eps, N, n, m, h, k, resEpsCount, xBorder, yBorder);


    }


   void MethodIteration(){

        CreateVUFXY();
        SetSteps();
        SetF();
        SetFirstV();

        double midStep;
        int midN;
        double maxL;
        double minL;

        if(t == 0 ){

             //midStep = (h+k)/2.0;


            if(h>k){
            midStep = k;
            } else {
            midStep = h;
            }

             midN = (n+m)/2;
             maxL = (8.0/(midStep*midStep))*cos(acos(-1)/(2*midN))*cos(acos(-1)/(2*midN));
             minL = (8.0/(midStep*midStep))*sin(acos(-1)/(2*midN))*sin(acos(-1)/(2*midN));

            //maxL = (4.0/(h*h))*sin(acos(-1)*(n-1)/(2*n))*sin(acos(-1)*(n-1)/(2*n)) + (4.0/(k*k))*sin(acos(-1)*(m-1)/(2*m))*sin(acos(-1)*(m-1)/(2*m));
            // minL = (4.0/(h*h))*sin(acos(-1)/(2*n))*sin(acos(-1)/(2*n)) + (4.0/(k*k))*sin(acos(-1)/(2*m))*sin(acos(-1)/(2*m));

             t = 2/(maxL+minL);

             if(Task == 0)
             t = midStep*midStep/4;

             if(Task == 1)
             t = midStep*midStep/16;
        }


       method.SolveSystemIteration(V, F, Eps, N, n, m, h, k, t, resEpsCount);


    }



   void MethodIterationBorder(){

        CreateVUFXY();
        SetSteps();
        SetF();
        SetFirstVBorder();

        double midStep;
        int midN;
        double maxL;
        double minL;

        if(t == 0){

             //midStep = (h+k)/2.0;


            if(h>k){
            midStep = k;
            } else {
            midStep = h;
            }

             midN = (n+m)/2;
             maxL = (8.0/(midStep*midStep))*cos(acos(-1)/(2*midN))*cos(acos(-1)/(2*midN));
             minL = (8.0/(midStep*midStep))*sin(acos(-1)/(2*midN))*sin(acos(-1)/(2*midN));


             t = midStep*midStep/4;


        }


       method.SolveSystemIterationBorder(V, F, Eps, N, n, m, h, k, t, resEpsCount, xBorder, yBorder);


    }



   void MethodSeidel2(){

        //CreateVUFXY();
        SetSteps2();
        SetF2();
        SetFirstV2();


       method.SolveSystemSeidel(V2, F2, Eps, N, 2*n, 2*m, h, k, resEpsCount);


    }

   void MethodIteration2(){

        //CreateVUFXY();
        SetSteps2();
        SetF2();
        SetFirstV2();

        double midStep;
        int midN;
        double maxL;
        double minL;

        if(t == 0){
             //midStep = (h+k)/2.0;


            if(h>k){
            midStep = k;
            } else {
            midStep = h;
            }

             midN = (2*n+2*m)/2;
             maxL = (8.0/(midStep*midStep))*cos(acos(-1)/(2*midN))*cos(acos(-1)/(2*midN));
             minL = (8.0/(midStep*midStep))*sin(acos(-1)/(2*midN))*sin(acos(-1)/(2*midN));

             if(Task == 0)
                 t = midStep*midStep/4;


             if(Task == 1)
                 t = midStep*midStep/(16*2);
        }

       method.SolveSystemIteration(V2, F2, Eps, N, 2*n, 2*m, h, k, t, resEpsCount);


    }



    void SetU(){
        for(int i = 0; i < n+1; i++ ){
            for(int j = 0; j < m+1; j++){
                U[i][j] = GetU(a+h*i, c+k*j);
            }
        }

    }


    void SetUBorder(){
        for(int i = 0; i < n+1; i++ ){
            for(int j = 0; j < m+1; j++){
                if(a+h*i > xBorder && c+k*j > yBorder){
                    U[i][j] = 0;
                    continue;
                }
                U[i][j] = GetU(a+h*i, c+k*j);
            }
        }

    }


    void SetDiscrepancy(double** u, double **f, int N_, int M_, double h_, double k_){

        double A = 0.5*(h_*h_*k_*k_)/(h_*h_+k_*k_);
        double H = 1.0/(h_*h_);
        double K = 1.0/(k_*k_);
        discrepancy = 0;


        for (int i = 1; i < N_ ; i++)
            for (int j = 1; j < M_ ; j++)
            {

                Discrepancy[i][j] = fabs(-f[i][j] - (H*(u[i-1][j]-2*u[i][j]+u[i+1][j]) + K*(u[i][j-1]-2*u[i][j]+u[i][j+1])));

                //Discrepancy[i][j] = fabs(A * ((u[i - 1][j] + u[i + 1][j])*H + (u[i][j -1] + u[i][j + 1])*K + f[i][j]) - u[i][j]);

                if(Discrepancy[i][j] > discrepancy)
                    discrepancy  = Discrepancy[i][j];
               // discrepancy+=Discrepancy[i][j]*Discrepancy[i][j];
            }

        //discrepancy = sqrt(discrepancy);


    }

};

#endif // DIRICHLET_H
