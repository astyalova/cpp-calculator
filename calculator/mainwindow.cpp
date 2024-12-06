#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <cmath>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pb_zero_clicked()
{
    if (current_operation_  == operations::NO_OPERATION) {
        ui->l_formula->setText("");
    }

    input_number_ += "0";
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_one_clicked()
{
    if (current_operation_  == operations::NO_OPERATION) {
        ui->l_formula->setText("");
    }

    input_number_ += "3";
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);

}


void MainWindow::on_pb_two_clicked()
{
    if (current_operation_  == operations::NO_OPERATION) {
        ui->l_formula->setText("");
    }

    input_number_ += "2";
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_three_clicked()
{
    if (current_operation_  == operations::NO_OPERATION) {
        ui->l_formula->setText("");
    }

    input_number_ += "1";
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_six_clicked()
{
    if (current_operation_  == operations::NO_OPERATION) {
        ui->l_formula->setText("");
    }

    input_number_ += "6";
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_five_clicked()
{
    if (current_operation_  == operations::NO_OPERATION) {
        ui->l_formula->setText("");
    }

    input_number_ += "5";
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_four_clicked()
{
    if (current_operation_  == operations::NO_OPERATION) {
        ui->l_formula->setText("");
    }

    input_number_ += "4";
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_nine_clicked()
{
    if (current_operation_  == operations::NO_OPERATION) {
        ui->l_formula->setText("");
    }

     input_number_ += "9";
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_eight_clicked()
{
    if (current_operation_  == operations::NO_OPERATION) {
        ui->l_formula->setText("");
    }

    input_number_ += "8";
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_seven_clicked()
{
    if (current_operation_  == operations::NO_OPERATION) {
        ui->l_formula->setText("");
    }

    input_number_  += "7";
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);
}

void MainWindow::on_pb_add_clicked()
{
    operation("+", operations::ADDITION);
}

void MainWindow::on_pb_sub_clicked()
{
    operation("−", operations::SUBTRACTION);
}

void MainWindow::on_pb_mul_clicked()
{
    operation("×", operations::MULTIPLICATION);
}

void MainWindow::on_pb_div_clicked()
{
    operation("÷", operations::DIVISION);
}

void MainWindow::on_pb_pow_clicked()
{
    operation("^", operations::POWER);
}

void MainWindow::operation(const QString& opSymbol, operations operationType)
{
    if (current_operation_ == operations::NO_OPERATION) {
        if (!input_number_.isEmpty()) {
            active_number_ = input_number_.toDouble();
            calculator_.Set(active_number_);
        }
    }

    ui->l_formula->setText(QString::number(calculator_.GetNumber()) + " " + opSymbol);

    input_number_.clear();
    current_operation_ = operationType;
}

void MainWindow::on_pb_free_num_clicked()

{

    input_number_ = "";

    active_number_ = 0;

    calculator_.Set(active_number_);

    ui->l_result->setText("0");

    ui->l_formula->setText("");

    current_operation_ = operations::NO_OPERATION;

}

void MainWindow::on_pb_chng_sign_clicked()
{
    if ((current_operation_ == operations::NO_OPERATION && input_number_.isEmpty()) || memory_saved_ == true) {
        return;
    }

    if (!input_number_.isEmpty()) {
        if (!input_number_.startsWith("-")) {
            input_number_ = "-" + input_number_;
        } else {
            input_number_ = input_number_.mid(1);
        }

        ui->l_result->setText(input_number_);
    } else {
        active_number_ = -active_number_;
        calculator_.Set(active_number_);

        ui->l_result->setText(QString::number(active_number_));
    }
}



void MainWindow::on_pb_mem_save_clicked()
{
    memory_cell_ = active_number_;
    memory_saved_ = true;
    ui->l_memory->setText("M");
    current_operation_ = operations::NO_OPERATION;
}


void MainWindow::on_pb_cout_save_num_clicked()
{
    if(memory_saved_) {
        ui->l_result->setText(QString::number(memory_cell_));
        active_number_ = memory_cell_;
        input_number_ = QString::number(memory_cell_);
    }
}



void MainWindow::on_pb_free_mem_clicked()
{
    ui->l_memory->setText("");
    memory_cell_ = 0;
    memory_saved_ = false;
}

void MainWindow::on_pb_dlt_clicked()
{
    if (!input_number_.isEmpty()) {
        input_number_.chop(1);
        ui->l_result->setText(input_number_);
    }

}


void MainWindow::on_pb_int_to_dbl_clicked()
{
    if (!input_number_.contains('.')) {
        if (input_number_.isEmpty()) {
            input_number_ = "0.";
        } else {
            input_number_ += ".";
        }
    }

    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}


void MainWindow::on_pb_res_clicked()
{
    QString result;

    if(current_operation_  == operations::NO_OPERATION) {
        return;
    } if(current_operation_  == operations::ADDITION) {
        result = QString("%1 %2 %3 %4").arg(calculator_.GetNumber())
                                               .arg("+")
                                               .arg(active_number_)
                                               .arg("=");
        calculator_.Add(active_number_);
    } if(current_operation_ == operations::SUBTRACTION) {
        result = QString("%1 %2 %3 %4").arg(calculator_.GetNumber())
                                               .arg("−")
                                               .arg(active_number_)
                                               .arg("=");
        calculator_.Sub(active_number_);
    } if(current_operation_== operations::MULTIPLICATION) {
        result = QString("%1 %2 %3 %4").arg(calculator_.GetNumber())
                                               .arg("×")
                                               .arg(active_number_)
                                               .arg("=");
        calculator_.Mul(active_number_);
    } if(current_operation_ == operations::DIVISION) {
        result = QString("%1 %2 %3 %4").arg(calculator_.GetNumber())
                                               .arg("÷")
                                               .arg(active_number_)
                                               .arg("=");
        calculator_.Div(active_number_);
    } if(current_operation_ == operations::POWER) {
        result = QString("%1 %2 %3 %4").arg(calculator_.GetNumber())
                                               .arg("^")
                                               .arg(active_number_)
                                               .arg("=");
        calculator_.Pow(active_number_);
    }
    active_number_ = calculator_.GetNumber();

    ui->l_result->setText(QString::number(active_number_));
    ui->l_formula->setText(result);

    input_number_ = "";
    current_operation_ = operations::NO_OPERATION;
}

