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
    void onDigitButtonClicked();
    void onOperationButtonClicked();
    void onControlButtonClicked();
    void onControllerTypeChanged();

private:
    Ui::MainWindow *ui;
    std::function<void(int)> digit_cb_;
    std::function<void(Operation)> operation_cb_;
    std::function<void(ControlKey)> control_cb_;
    std::function<void(ControllerType)> controller_cb_;
};

#endif

