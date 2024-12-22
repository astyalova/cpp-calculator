#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->l_result->setText("");
    ui->l_memory->setText("");
    ui->l_formula->setText("");

    QList<QPushButton*> digitButtons = {
        ui->pb_zero, ui->pb_one, ui->pb_two, ui->pb_three, ui->pb_four,
        ui->pb_five, ui->pb_six, ui->pb_seven, ui->pb_eight, ui->pb_nine
    };
    for (QPushButton* button : digitButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    }

    QList<QPushButton*> operationButtons = {
        ui->pb_add, ui->pb_sub, ui->pb_mul, ui->pb_div, ui->pb_pow
    };
    for (QPushButton* button : operationButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::onOperationButtonClicked);
    }

    connect(ui->pb_res, &QPushButton::clicked, this, &MainWindow::onControlButtonClicked);
    connect(ui->pb_free_num, &QPushButton::clicked, this, &MainWindow::onControlButtonClicked);
    connect(ui->pb_mem_save, &QPushButton::clicked, this, &MainWindow::onControlButtonClicked);
    connect(ui->pb_cout_save_num, &QPushButton::clicked, this, &MainWindow::onControlButtonClicked);
    connect(ui->pb_free_mem, &QPushButton::clicked, this, &MainWindow::onControlButtonClicked);
    connect(ui->pb_chng_sign, &QPushButton::clicked, this, &MainWindow::onControlButtonClicked);
    connect(ui->pb_dlt, &QPushButton::clicked, this, &MainWindow::onControlButtonClicked);
    connect(ui->tb_extra, &QPushButton::clicked, this, &MainWindow::onControlButtonClicked);

    connect(ui->cmb_controller, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onControllerTypeChanged);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetDigitKeyCallback(std::function<void(int key)> cb) {
    digit_cb_ = cb;
}

void MainWindow::SetProcessOperationKeyCallback(std::function<void(Operation key)> cb) {
    operation_cb_ = cb;
}

void MainWindow::SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb) {
    control_cb_ = cb;
}

void MainWindow::SetControllerCallback(std::function<void(ControllerType controller)> cb) {
    controller_cb_ = cb;
}

void MainWindow::onDigitButtonClicked() {
    if (digit_cb_) {
        QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
        int digit = senderButton->text().toInt();
        digit_cb_(digit);
    }
}

void MainWindow::onOperationButtonClicked() {
    if (operation_cb_) {
        QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
        Operation op;
        if (senderButton == ui->pb_add) op = Operation::ADDITION;
        else if (senderButton == ui->pb_sub) op = Operation::SUBTRACTION;
        else if (senderButton == ui->pb_mul) op = Operation::MULTIPLICATION;
        else if (senderButton == ui->pb_div) op = Operation::DIVISION;
        else if (senderButton == ui->pb_pow) op = Operation::POWER;

        operation_cb_(op);
    }
}

void MainWindow::onControlButtonClicked() {
    if (control_cb_) {
        QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
        ControlKey key;
        if (senderButton == ui->pb_res) key = ControlKey::EQUALS;
        else if (senderButton == ui->pb_free_num) key = ControlKey::CLEAR;
        else if (senderButton == ui->pb_mem_save) key = ControlKey::MEM_SAVE;
        else if (senderButton == ui->pb_cout_save_num) key = ControlKey::MEM_LOAD;
        else if (senderButton == ui->pb_free_mem) key = ControlKey::MEM_CLEAR;
        else if (senderButton == ui->pb_chng_sign) key = ControlKey::PLUS_MINUS;
        else if (senderButton == ui->pb_dlt) key = ControlKey::BACKSPACE;
        else if (senderButton == ui->tb_extra) key = ControlKey::EXTRA_KEY;

        control_cb_(key);
    }
}


void MainWindow::onControllerTypeChanged() {
    if (controller_cb_) {
        ControllerType type = static_cast<ControllerType>(ui->cmb_controller->currentIndex());
        controller_cb_(type);
    }
}
