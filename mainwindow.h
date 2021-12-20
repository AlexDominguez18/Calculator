#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>

#include "mathFunctions.h"

enum{
    CLICK_SENO,
    CLICK_COSENO,
    CLICK_TANGENTE,
    CLICK_LOGARITMO,
    CLICKS
};

enum{
    GRADOS,
    RADIANES
};

enum{
    SUMA,
    RESTA,
    MULTIPLICACION,
    DIVISION,
    SENO,
    COSENO,
    TANGENTE,
    ARCOSENO,
    ARCOCOSENO,
    ARCOTANGENTE,
    RAIZ,
    POTENCIA,
    LOGARITMO,
    ANTILOGARITMO
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void reset_clicks();

    void operation_clicked();

    void digit_clicked();

    void on_clearBT_clicked();

    void on_number0BT_clicked();

    void on_number1BT_clicked();

    void on_number2BT_clicked();

    void on_number3BT_clicked();

    void on_number4BT_clicked();

    void on_number5BT_clicked();

    void on_number6BT_clicked();

    void on_number7BT_clicked();

    void on_number8BT_clicked();

    void on_number9BT_clicked();

    void on_deleteBT_clicked();

    void on_pointBT_clicked();

    void on_changeSignBT_clicked();

    void on_addBT_clicked();

    void on_substractBT_clicked();

    void on_multiplicationBT_clicked();

    void on_divisionBT_clicked();

    void on_raizCuadradaBT_clicked();

    void on_elevarCuadradoBT_clicked();

    void on_senoBT_clicked();

    void on_cosenoBT_clicked();

    void on_tangenteBT_clicked();

    void on_logaritmoBT_clicked();

    void on_equalsBT_clicked();

    void on_gradosRadianesBT_clicked();

private:
    Ui::MainWindow *ui;
    bool waitingOperation;
    bool newOperation;
    int degreeOrRadians;
    int operation;
    int clicks[CLICKS];
    double num1;
    double num2;
    double result;

    void putDigit(QString digit);
};
#endif // MAINWINDOW_H
