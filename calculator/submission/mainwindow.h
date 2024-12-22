#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <functional>
#include "calculator.h"
#include "enums.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Колбэки для обработки сигналов
    void SetDigitKeyCallback(std::function<void(int key)> cb);
    void SetProcessOperationKeyCallback(std::function<void(Operation key)> cb);
    void SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb);
    void SetControllerCallback(std::function<void(ControllerType controller)> cb);
    void SetInputText(const std::string& text) {
        ui->l_result->setStyleSheet("");
        ui->l_result->setText(QString::fromStdString(text));
    }
    void SetErrorText(const std::string& text) {
        ui->l_result->setStyleSheet("color: red;");
        ui->l_result->setText(QString::fromStdString(text));
    }
    void SetFormulaText(const std::string& text) {
        ui->l_formula->setText(QString::fromStdString(text));
    }
    void SetMemText(const std::string& text) {
        ui->l_memory->setText(QString::fromStdString(text));
    }
    void SetExtraKey(const std::optional<std::string>& key) {
        if(key.has_value()) {
            ui->tb_extra->setText(QString::fromStdString(*key));
            ui->tb_extra->show();
        } else {
            ui->tb_extra->hide();
        }
    }

private slots:
    void onDigitButtonClicked();             // Обработка кнопок цифр
    void onOperationButtonClicked();         // Обработка кнопок операций
    void onControlButtonClicked();           // Обработка управляющих кнопок
    void onControllerTypeChanged();          // Изменение типа контроллера

private:
    Ui::MainWindow *ui;
    std::function<void(int)> digit_cb_;
    std::function<void(Operation)> operation_cb_;
    std::function<void(ControlKey)> control_cb_;
    std::function<void(ControllerType)> controller_cb_;
};

#endif // MAINWINDOW_H

/*
#include "calculator.h"
#include "enums.h"
#include "ui_mainwindow.h"


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetDigitKeyCallback(std::function<void(int key)> cb);
    void SetProcessOperationKeyCallback(std::function<void(Operation key)> cb);
    void SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb);
    void SetControllerCallback(std::function<void(ControllerType controller)> cb);

    void SetInputText(const std::string& text) {
        ui->l_result->setStyleSheet("");
        ui->l_result->setText(QString::fromStdString(text));
    }
    void SetErrorText(const std::string& text) {
        ui->l_result->setStyleSheet("color: red;");
        ui->l_result->setText(QString::fromStdString(text));
    }
    void SetFormulaText(const std::string& text) {
        ui->l_formula->setText(QString::fromStdString(text));
    }
    void SetMemText(const std::string& text) {
        ui->l_memory->setText(QString::fromStdString(text));
    }
    void SetExtraKey(const std::optional<std::string>& key) {
        if(key.has_value()) {
            ui->tb_extra->setText(QString::fromStdString(*key));
            ui->tb_extra->show();
        } else {
            ui->tb_extra->hide();
        }
    }

    void onControllerTypeChanged();
private slots:

    void on_pb_zero_clicked();


    void on_pb_two_clicked();


    void on_pb_six_clicked();

    void on_pb_five_clicked();

    void on_pb_four_clicked();

    void on_pb_nine_clicked();

    void on_pb_eight_clicked();

    void on_pb_seven_clicked();

    void on_pb_add_clicked();

    void on_pb_sub_clicked();

    void on_pb_mul_clicked();

    void on_pb_div_clicked();

    void on_pb_pow_clicked();

    void on_pb_free_num_clicked();

    void on_pb_chng_sign_clicked();

    void on_pb_mem_save_clicked();

    void on_pb_cout_save_num_clicked();

    void on_pb_free_mem_clicked();

    void on_pb_dlt_clicked();

    void on_tb_extra_clicked();

    void on_pb_res_clicked();

    void on_pb_one_clicked();

    void on_pb_three_clicked();


private:

    ControllerType currentType;
    std::function<void(int)> digit_cb_;
    std::function<void(Operation)> operation_cb_;
    std::function<void(ControlKey)> control_cb_;
    std::function<void(ControllerType)> controller_cb_;
};
*/
