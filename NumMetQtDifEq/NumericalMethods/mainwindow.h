#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Enter_clicked();

    void on_pushButton_Clear_clicked();

    void on_checkBox_pressed();

    void on_radioButton_Test_clicked();

    void on_radioButton_Imp_clicked();

    void paintGraph(int numbColumnX,int numbColumnY, int N, int numbGraph, int style, int color);
    void GetMaxMin(int numbColum, int numbColumX , int N, QVariant* arrayMaxMinX);

    void on_radioButton_clicked();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
