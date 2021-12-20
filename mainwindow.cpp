#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Calculadora");
    waitingOperation = true;
    newOperation = false;
    operation = -1;
    degreeOrRadians = GRADOS;
    reset_clicks();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset_clicks()
{
    clicks[CLICK_SENO] = 1;
    clicks[CLICK_COSENO] = 1;
    clicks[CLICK_TANGENTE] = 1;
    clicks[CLICK_LOGARITMO] = 1;
}

void MainWindow::operation_clicked()
{
    if (ui->op1LE->text().isEmpty()){
        return;
    }
    waitingOperation = false;
}

void MainWindow::digit_clicked()
{
    if (newOperation){
        ui->resultLE->clear();
        ui->op1LE->clear();
        ui->op2LE->clear();
        ui->operationLB->clear();
        newOperation = false;
        waitingOperation = true;
        result = 0;
    }

    if (waitingOperation){
        if (ui->op1LE->text() == "0"){
            ui->op1LE->clear();
        }
    }
    else{
        if (ui->op2LE->text() == "0"){
            ui->op2LE->clear();
        }
    }
}


void MainWindow::on_clearBT_clicked()
{
    ui->resultLE->clear();
    ui->op1LE->clear();
    ui->op2LE->clear();
    ui->operationLB->clear();
    waitingOperation = true;
}

void MainWindow::putDigit(QString digit)
{
    if (waitingOperation){
        ui->op1LE->setText(ui->op1LE->text() + digit);
    }
    else{
        ui->op2LE->setText(ui->op2LE->text() + digit);
    }
}

void MainWindow::on_number0BT_clicked()
{
    if (waitingOperation){
        if (ui->op1LE->text() == "0"){
            return;
        }
        ui->op1LE->setText(ui->op1LE->text() + ui->number0BT->text());
    }
    else{
        if (ui->op2LE->text() == "0"){
            return;
        }
        ui->op2LE->setText(ui->op2LE->text() + ui->number0BT->text());
    }
}

void MainWindow::on_number1BT_clicked()
{
    digit_clicked();
    putDigit(ui->number1BT->text());
}

void MainWindow::on_number2BT_clicked()
{
    digit_clicked();
    putDigit(ui->number2BT->text());
}

void MainWindow::on_number3BT_clicked()
{
    digit_clicked();
    putDigit(ui->number3BT->text());
}

void MainWindow::on_number4BT_clicked()
{
    digit_clicked();
    putDigit(ui->number4BT->text());
}

void MainWindow::on_number5BT_clicked()
{
    digit_clicked();
    putDigit(ui->number5BT->text());
}

void MainWindow::on_number6BT_clicked()
{
    digit_clicked();
    putDigit(ui->number6BT->text());
}

void MainWindow::on_number7BT_clicked()
{
    digit_clicked();
    putDigit(ui->number7BT->text());
}

void MainWindow::on_number8BT_clicked()
{
    digit_clicked();
    putDigit(ui->number8BT->text());
}

void MainWindow::on_number9BT_clicked()
{
    digit_clicked();
    putDigit(ui->number9BT->text());
}

void MainWindow::on_deleteBT_clicked()
{
    QLineEdit* op;
    if (waitingOperation){
        op = ui->op1LE;
    }
    else{
        op = ui->op2LE;
    }
    if (op->text().isEmpty()){
        return;
    }
    else{
        op->setText(op->text().remove(op->text().length()-1,1));
    }
}

void MainWindow::on_pointBT_clicked()
{
    QLineEdit* op;
    digit_clicked();
    if (waitingOperation){
        op = ui->op1LE;
    }
    else{
        op = ui->op2LE;
    }
    if (op->text().contains(".")){
        return;
    }
    putDigit(ui->pointBT->text());
}

void MainWindow::on_changeSignBT_clicked()
{
    QLineEdit* op;
    digit_clicked();
    if (waitingOperation){
        op = ui->op1LE;
    }
    else{
        op = ui->op2LE;
    }
    if (op->text().isEmpty()){
        return;
    }
    if (op->text().contains("-")){
        op->setText(op->text().remove("-"));
    }else{
        op->setText(op->text().insert(0,"-"));
    }
}

void MainWindow::on_addBT_clicked()
{
    operation_clicked();
    if (!waitingOperation){
        operation = SUMA;
        ui->operationLB->setText(ui->addBT->text());
    }
}

void MainWindow::on_substractBT_clicked()
{
    operation_clicked();
    if (!waitingOperation){
        operation = RESTA;
        ui->operationLB->setText(ui->substractBT->text());
    }
}

void MainWindow::on_multiplicationBT_clicked()
{
    operation_clicked();
    if (!waitingOperation){
        operation = MULTIPLICACION;
        ui->operationLB->setText(ui->multiplicationBT->text());
    }
}

void MainWindow::on_divisionBT_clicked()
{
    operation_clicked();
    if (!waitingOperation){
        operation = DIVISION;
        ui->operationLB->setText(ui->divisionBT->text());
    }
}

void MainWindow::on_raizCuadradaBT_clicked()
{
    operation_clicked();
    if (!waitingOperation){
        operation = RAIZ;
        ui->operationLB->setText(ui->raizCuadradaBT->text());
    }
}

void MainWindow::on_elevarCuadradoBT_clicked()
{
    operation_clicked();
    if (!waitingOperation){
        operation = POTENCIA;
        ui->operationLB->setText(ui->elevarCuadradoBT->text());
    }
}

void MainWindow::on_senoBT_clicked()
{
    operation_clicked();
    if (!waitingOperation){
        if (clicks[CLICK_SENO] == 1){
            clicks[CLICK_SENO]++;
            operation = SENO;
            ui->operationLB->setText(ui->senoBT->text());
        }
        else{
            reset_clicks();
            operation = ARCOSENO;
            ui->operationLB->setText("ARCOSEN");
        }
    }
}

void MainWindow::on_cosenoBT_clicked()
{
    operation_clicked();
    if (!waitingOperation){
        if (clicks[CLICK_COSENO] == 1){
            clicks[CLICK_COSENO]++;
            operation = COSENO;
            ui->operationLB->setText(ui->cosenoBT->text());
        }
        else{
            reset_clicks();
            operation = ARCOCOSENO;
            ui->operationLB->setText("ARCOCOS");
        }
    }
}

void MainWindow::on_tangenteBT_clicked()
{
    operation_clicked();
    if (!waitingOperation){
        if (clicks[CLICK_TANGENTE] == 1){
            clicks[CLICK_TANGENTE]++;
            operation = TANGENTE;
            ui->operationLB->setText(ui->tangenteBT->text());
        }
        else{
            reset_clicks();
            operation = ARCOTANGENTE;
            ui->operationLB->setText("ARCOTAN");
        }
    }
}

void MainWindow::on_logaritmoBT_clicked()
{
    operation_clicked();
    if (!waitingOperation){
        if (clicks[CLICK_LOGARITMO] == 1){
            clicks[CLICK_LOGARITMO]++;
            operation = LOGARITMO;
            ui->operationLB->setText(ui->logaritmoBT->text());
        }
        else{
            reset_clicks();
            operation = ANTILOGARITMO;
            ui->operationLB->setText("ANTILOG");
        }
    }
}

void MainWindow::on_equalsBT_clicked()
{
    if (!waitingOperation){
        switch (operation){
            case SUMA:
            case RESTA:
            case MULTIPLICACION:
            case DIVISION:
                if (ui->op2LE->text().isEmpty()){
                    return;
                }
                num2 = ui->op2LE->text().toDouble();
                break;
            default:    break;
        }
    }

    num1 = ui->op1LE->text().toDouble();

    switch (operation){
        case SENO:
        case ARCOSENO:
        case COSENO:
        case ARCOCOSENO:
        case TANGENTE:
        case ARCOTANGENTE:
        case LOGARITMO:
        case ANTILOGARITMO:
            if (degreeOrRadians == GRADOS){
                num1 = aRadianes(num1);
                num1 = aGrados(num1);
            }
            break;
    }

    switch (operation){
    case SUMA:          result = suma(num1,num2);           break;
    case RESTA:         result = resta(num1,num2);          break;
    case MULTIPLICACION:result = multiplicacion(num1,num2); break;
    case DIVISION:
        if (num2 == 0.0){
            QMessageBox alert;
            alert.setIcon(QMessageBox::Warning);
            alert.setText("No se puede dividir entre 0.");
            alert.exec();
            return;
        }
        result = division(num1,num2);
        break;
    case RAIZ:          result = raizCuadrada(num1);    break;
    case POTENCIA:      result = potenciaCuadrada(num1);break;
    case SENO:          result = seno(num1);            break;
    case ARCOSENO:      result = arcoseno(num1);        break;
    case COSENO:        result = coseno(num1);          break;
    case ARCOCOSENO:    result = arcocoseno(num1);      break;
    case TANGENTE:      result = tangente(num1);        break;
    case ARCOTANGENTE:  result = arcotangente(num1);    break;
    case LOGARITMO:     result = logaritmo(num1);       break;
    case ANTILOGARITMO: result = antiLogaritmo(num1);   break;
    default:
        return;
    }
    ui->resultLE->setText(QString::number(result));
    newOperation = true;
}

void MainWindow::on_gradosRadianesBT_clicked()
{
    if (ui->gradosRadianesBT->text() == "DEG"){
        ui->gradosRadianesBT->setText("RAD");
        degreeOrRadians = RADIANES;
    }
    else{
        ui->gradosRadianesBT->setText("DEG");
        degreeOrRadians = GRADOS;
    }
}
