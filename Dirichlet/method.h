#ifndef SEIDEL_H
#define SEIDEL_H
#include "math.h"

class method{

public:

/*
    n - количество узлов по каждой из координат области D.

    m - число операций, выполняемых методом для одного узла сетки.

    k - количество итераций метода до выполнения условия остановки.
  */

    void SolveSystemSeidel(double** u, double **f, double eps, int count, int N, int M, double h, double k, double* resEpsCount)
    {

        double A = 0.5*(h*h*k*k)/(h*h+k*k);
        double H = 1.0/(h*h);
        double K = 1.0/(k*k);
        int checkCount = 0;
        double max = 0;

     do
       {
            if(checkCount < count){

                checkCount++;
                max = 0;

                for (int i = 1; i < N ; i++)
                    for (int j = 1; j < M ; j++)
                    {

                        double u0 = u[i][j];

                        u[i][j] = A * ((u[i - 1][j] + u[i + 1][j])*H + (u[i][j -1] + u[i][j + 1])*K +  f[i][j]);

                        double d = fabs(u[i][j] - u0);

                        if (d > max)

                            max = d;
                    }

            } else {

                break;
            }

        } while (max > eps); // eps --- заданная точность .


        resEpsCount[0] = max;
        resEpsCount[1] = checkCount;
    

    }






void SolveSystemIteration(double** u, double **f, double eps, int count, int N, int M, double h, double k, double t, double* resEpsCount)
{

    double A = 0.5*(h*h*k*k)/(h*h+k*k);
    double H = 1.0/(h*h);
    double K = 1.0/(k*k);
    int checkCount = 0;
    double max = 0;
    double** oldU = new double*[N+1];

    for(int i = 0; i < N+1; i++){
        oldU[i] = new double[M+1];
    }



 do
   {
        if(checkCount < count){


            checkCount++;
            max = 0;

            for(int i = 0; i < N+1; i++){
                for(int j = 0; j < M+1; j++){
                    oldU[i][j] = u[i][j];
                }
            }


            for (int i = 1; i < N ; i++){
                for (int j = 1; j < M ; j++)
                {

                    double u0 = u[i][j];

                    u[i][j] = oldU[i][j] - t*(-f[i][j] - (H*(oldU[i-1][j]-2*oldU[i][j]+oldU[i+1][j]) + K*(oldU[i][j-1]-2*oldU[i][j]+oldU[i][j+1])));

                    double d = fabs(u[i][j] - u0);

                    if (d > max)
                        max = d;

                }
            }




        } else {

            break;
        }

    } while (max > eps); // eps --- заданная точность .


    resEpsCount[0] = max;
    resEpsCount[1] = checkCount;


}


};





#endif // SEIDEL_H
