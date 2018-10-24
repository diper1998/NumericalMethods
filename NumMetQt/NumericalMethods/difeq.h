#ifndef DIFEQ_H
#define DIFEQ_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>

#include "mainwindow.h"
#include <QApplication>



class difeqData;

class difeq
{
public:

    difeq();
    difeq(const difeq &);
    difeq &operator=(const difeq &);
    ~difeq();

    //Параметры уравнения.
    QVariant a1 = 1;
    QVariant a2 = 1;
    QVariant m = 1;

    QVariant x = 0; //Начальный "x".
    QVariant V = 0; //Численное решение.

    QVariant h = 0.01; // Шаг.
    QVariant countDoub = 0; //Количество удвоения шага
    QVariant countDiv = 0; // Кроичество

    QVariant N = 100; //Количество шагов.
    QVariant p = 4; //Порядок метода.
    QVariant c = 0; //Константа для точного решения.

    QVariant V2 = 0; //Численное решение с двойным шагом.
    QVariant V3 = 0;
    QVariant U = 0; //Точное решение.

    QVariant E = 0; //Глобальная погрешность.
    QVariant S = 0; //Контрольный элемент.
    QVariant e = 0; //Локальная поргешность.
    QVariant X = 0; //Граница
    QVariant Eb = 0; //Параметр контроля погрешности.

    bool flagControlH = false;
    const double EPS = 1e-7;
    int numbGraph = 0;
    int color  = 0;
    int numFunct = 1;


    QVariant GetFunctSol();
    QVariant GetNextArg();
    QVariant GetMethodSol();

private:
    QSharedDataPointer<difeqData> data;
};

#endif // DIFEQ_H
