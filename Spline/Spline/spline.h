#include <cmath>
#include <QMainWindow>
#include "ui_mainwindow.h"


class Spline
{
public:

    double leftBorder;
    double rightBorder;
    double sLB;
    double sRB;
    double step;
    double stepSpline;

    double* mA;
    double* mB;
    double* mC;
    double* mD;
    double* mS;
    double* mX;
    double* mXSpline;
    double* mF;
    double* mF_1;
    double* mF_1_;
    double* mF_1__;
    double* mZ;
    double* mZ_;
    double* mZ__;

    double* mUnder;
    double* mOver;
    double* mMain;
    double* mFun;
    double* mSpline;
    double* mSpline_;
    double* mSpline__;

    unsigned int splitting;
    unsigned int splittingSpline;
    unsigned int k;


    int mode;


    Spline();



    void SetStep(){
             step = (abs(leftBorder-rightBorder))/splitting;
    }

    void SetSplineStep(){
         splittingSpline = k*splitting;
         stepSpline = (abs(leftBorder-rightBorder))/(splittingSpline);
         }

    void SetMassifs(){
        mA = new double[splitting+1];
        mB = new double[splitting+1];
        mC = new double[splitting+1];
        mD = new double[splitting+1];
        mS = new double[splitting+1];
        mX = new double[splitting+1];
        mF = new double[splitting+1];
        mF_1 = new double[splittingSpline+1];
        mF_1_ = new double[splittingSpline+1];
        mF_1__ = new double[splittingSpline+1];

        mUnder = new double[splitting+1];
        mOver = new double[splitting+1];
        mMain = new double[splitting+1];
        mFun = new double[splitting+1];
        mSpline = new double[splittingSpline+1];
        mSpline_ = new double[splittingSpline+1];
        mSpline__ = new double[splittingSpline+1];

        mXSpline = new double[splittingSpline+1];
        mZ = new double[splittingSpline+1];
        mZ_ = new double[splittingSpline+1];
        mZ__ = new double[splittingSpline+1];

    }

    void SetSpline(){
        double x = leftBorder;
        int j = 0;


        for(int i = 0; i < splitting+1; i++){
            while(x<=mX[i]){
                mSpline[j] = mA[i]+mB[i]*(x-mX[i])+(mC[i]/2)*(x-mX[i])*(x-mX[i])+(mD[i]/6)*(x-mX[i])*(x-mX[i])*(x-mX[i]);
                x+=stepSpline;
                j++;
            }
        }


        while(j < splittingSpline+1){
        mSpline[j] = GetFunTest(mXSpline[j]);
        j++;
        }

     //   mSpline[j] = GetFunTest(mX[splitting]);

    }

    void SetSpline_(){

        double x = leftBorder;
        int j = 0;


        for(int i = 0; i < splitting+1; i++){
            while(x<=mX[i]){
                mSpline_[j] = mB[i]+(mC[i])*(x-mX[i])+(mD[i]/2)*(x-mX[i])*(x-mX[i]);
                x+=stepSpline;
                j++;
            }
        }

        //mSpline_[j] = GetFunTest_(mX[splitting]);

        while(j < splittingSpline+1){
        mSpline_[j] = GetFunTest_(mXSpline[j]);
        j++;
        }

        mSpline_[0] = GetFunTest_(mX[0]);

        }

    void SetSpline__(){

        double x = leftBorder;
        int j = 0;


        for(int i = 0; i < splitting+1; i++){
            while(x<=mX[i]){
                mSpline__[j] = mC[i]+(mD[i])*(x-mX[i]);
                x+=stepSpline;
                j++;
            }
        }



    //    while(j < splittingSpline+1){
    //    mSpline__[j] = GetFunTest__(mXSpline[j]);
    //    j++;
    //    }

    //    mSpline__[0] = GetFunTest__(mX[0]);
          mSpline__[0] = sLB;
          mSpline__[j] = sRB;
        }

    void SetX(int i){
        mX[i+1] = mX[0]+(i+1)*step;
    }

    void SetXSpline(int i){
        mXSpline[i+1] = mXSpline[0]+(i+1)*stepSpline;
    }

    void SetA(int i){
        mA[i+1] = GetFunTest(mX[i+1]); //i [0; n-1]
        }

    void SetB(int i){
        mB[i+1] = (GetFunTest(mX[i+1]) - GetFunTest(mX[i]))/step
                + mC[i+1]*step/3
                + mC[i]*step/6; //i [0; n-1]
    }

    void SetD(int i){
        mD[i+1] = (mC[i+1]-mC[i])/step; //i [0; n-1]
        }

    void SetF(int i){
        mF[i+1] = GetFunTest(mX[i+1]);
    }

    void SetF_1(){
        for(int i = 0; i < splittingSpline+1; i++){
            mF_1[i] = GetFunTest(mXSpline[i]);
        }
    }


    void SetF_1_(){
        for(int i = 0; i < splittingSpline+1; i++){
            mF_1_[i] = GetFunTest_(mXSpline[i]);
        }
    }


    void SetF_1__(){
        for(int i = 0; i < splittingSpline+1; i++){
            mF_1__[i] = GetFunTest__(mXSpline[i]);
        }
    }

    void SetMain(int i){

        mMain[i] = 2*(step+step);
    }

    void SetUnder(int i){
        mUnder[i] = step;
    }

    void SetOver(int i){
        mOver[i] = step;
    }

    void SetFun(int i){
        mFun[i] = 6*((GetFunTest(mX[i+1])-GetFunTest(mX[i]))/step - (GetFunTest(mX[i])-GetFunTest(mX[i-1]))/step);
    }

    double GetFunTest(double x){
        double res = 0;


        if(mode == 0){
            if(x <= 0 && x >= -1){
              res = x*x*x+3*x*x;
            }
            if(x >= 0 && x <=1){
                res = -x*x*x+3*x*x;
            }

}
        if(mode == 1){

            res = pow(x,0.5)*cos(x);

}
        if(mode == 2){

           res = pow(x,0.5)*cos(x)+cos(10*x);

}

        if(mode == 3){

           res = pow(x,0.5)*cos(x)+cos(100*x);

}


        return res;
    }

    double GetFunTest_(double x){

        double res = 0;

       if(mode == 0){
         if(x <= 0 && x >= -1){
           res = 3*x*x+6*x;
         }
         if(x >= 0 && x <=1){
             res = -3*x*x+6*x;
         }
    }

       if(mode == 1){

           res = 0.5*pow(x,-0.5)*cos(x)-pow(x, 0.5)*sin(x);

}

       if(mode == 2){

           res = 0.5*pow(x,-0.5)*cos(x)-pow(x, 0.5)*sin(x)-10*sin(10*x);

}
       if(mode == 3){

           res = 0.5*pow(x,-0.5)*cos(x)-pow(x, 0.5)*sin(x)-100*sin(100*x);

}



     return res;
 }

    double GetFunTest__(double x){

        double res = 0;

       if(mode == 0){
         if(x <= 0 && x >= -1){
           res = 6*x+6;
         }
         if(x >= 0 && x <=1){
             res = -6*x+6;
         }
    }

       if(mode == 1){

          res = (-(4*x*x+1)*cos(x)-4*x*sin(x))/(4*pow(x,3.0/2));
        //     res = (-1.0/4.0)*pow(x,-3.0/2.0)*cos(x) - sin(x)*pow(x, -0.5) - pow(x, 0.5)*cos(x);

}

       if(mode == 2){

           res = (-(4*x*x+1)*cos(x)-4*x*(sin(x)+100*pow(x,0.5)*cos(10*x)))/(4*pow(x,3.0/2));

}
       if(mode == 3){

           res = (-(4*x*x+1)*cos(x)-4*x*(sin(x)+10000*pow(x,0.5)*cos(100*x)))/(4*pow(x,3.0/2));

}



     return res;
 }

    void SolveMatrix (int n, double *underMain, double *thisMain, double *overMain, double *thisF, double *thisAnswer) {
        double m;
        for (int i = 1; i < n; i++) {
            m = underMain[i]/thisMain[i-1];
            thisMain[i] = thisMain[i] - m*overMain[i-1];
            thisF[i] = thisF[i] - m*thisF[i-1];
        }

        thisAnswer[n-1] = thisF[n-1]/thisMain[n-1];

        for (int i = n - 2; i >= 0; i--) {
            thisAnswer[i]=(thisF[i]-overMain[i]*thisAnswer[i+1])/thisMain[i];
            }
    }

    void GetError(double* X, double* Y, double* Z, int n ){

        for(int i = 0; i < n; i++ ){
            Z[i] = abs(X[i] - Y[i]);
        }
    }

    int GetIdMax(double* X, int n){
       int index = 0;

        for(int i = 0; i < n; i++ ){
            if(X[index]<X[i])
            index = i;
        }
        return index;
    }

    void GetAuto(){

        if(mode == 0){

            leftBorder = -1;
            rightBorder = 1;
            sRB = -6*rightBorder+6;
            sLB = 6*leftBorder+6;

        }


        if(mode == 1){
            leftBorder = 1.0;
            rightBorder = M_PI;
            //rightBorder = acos(-1.0);
            sRB = (-(4*rightBorder*rightBorder+1)*cos(rightBorder)-4*rightBorder*sin(rightBorder))/(4*pow(rightBorder,3.0/2));
            sLB = (-(4*leftBorder*leftBorder+1)*cos(leftBorder)-4*leftBorder*sin(leftBorder))/(4*pow(leftBorder,3.0/2));
        }


        if(mode == 2){
            leftBorder = 1.0;
            rightBorder = M_PI;
            //rightBorder = acos(-1.0);
            sRB = (-(4*rightBorder*rightBorder+1)*cos(rightBorder)-4*rightBorder*(sin(rightBorder)+100*pow(rightBorder,0.5)*cos(10*rightBorder)))/(4*pow(rightBorder,3.0/2));
            sLB = (-(4*leftBorder*leftBorder+1)*cos(leftBorder)-4*leftBorder*(sin(leftBorder)+100*pow(leftBorder,0.5)*cos(10*leftBorder)))/(4*pow(leftBorder,3.0/2));
        }

        if(mode == 3){
            leftBorder = 1.0;
            rightBorder = M_PI;
           //rightBorder = acos(-1.0);
            sRB = (-(4*rightBorder*rightBorder+1)*cos(rightBorder)-4*rightBorder*(sin(rightBorder)+10000*pow(rightBorder,0.5)*cos(100*rightBorder)))/(4*pow(rightBorder,3.0/2));
            sLB = (-(4*leftBorder*leftBorder+1)*cos(leftBorder)-4*leftBorder*(sin(leftBorder)+10000*pow(leftBorder,0.5)*cos(100*leftBorder)))/(4*pow(leftBorder,3.0/2));
        }

    }

};


