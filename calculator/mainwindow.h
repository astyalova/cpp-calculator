#pragma once

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_zero_clicked();

    void on_pb_one_clicked();

    void on_pb_two_clicked();

    void on_pb_three_clicked();

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

    void on_pb_int_to_dbl_clicked();

    void on_pb_res_clicked();


private:
    Ui::MainWindow* ui;
    QString input_number_ = "";
    Calculator calculator_;
    double active_number_ = 0.0;
    double memory_cell_ = 0.0;
    bool memory_saved_ = false;
    operations current_operation_ = operations::NO_OPERATION;;
};


