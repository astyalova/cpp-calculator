/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pb_sub;
    QPushButton *pb_free_mem;
    QPushButton *pb_zero;
    QPushButton *pb_one;
    QPushButton *pb_mul;
    QPushButton *pb_pow;
    QPushButton *pb_eight;
    QPushButton *pb_res;
    QPushButton *pb_free_num;
    QPushButton *pb_add;
    QLabel *l_formula;
    QPushButton *pb_three;
    QPushButton *pb_mem_save;
    QHBoxLayout *horizontalLayout;
    QLabel *l_memory;
    QLabel *l_result;
    QPushButton *pb_five;
    QPushButton *pb_cout_save_num;
    QPushButton *pb_int_to_dbl;
    QPushButton *pb_two;
    QPushButton *pb_seven;
    QPushButton *pb_dlt;
    QPushButton *pb_nine;
    QPushButton *pb_six;
    QPushButton *pb_div;
    QPushButton *pb_four;
    QPushButton *pb_chng_sign;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(310, 362);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pb_sub = new QPushButton(centralwidget);
        pb_sub->setObjectName("pb_sub");

        gridLayout->addWidget(pb_sub, 5, 3, 1, 1);

        pb_free_mem = new QPushButton(centralwidget);
        pb_free_mem->setObjectName("pb_free_mem");

        gridLayout->addWidget(pb_free_mem, 2, 0, 1, 1);

        pb_zero = new QPushButton(centralwidget);
        pb_zero->setObjectName("pb_zero");

        gridLayout->addWidget(pb_zero, 7, 1, 1, 1);

        pb_one = new QPushButton(centralwidget);
        pb_one->setObjectName("pb_one");

        gridLayout->addWidget(pb_one, 6, 2, 1, 1);

        pb_mul = new QPushButton(centralwidget);
        pb_mul->setObjectName("pb_mul");

        gridLayout->addWidget(pb_mul, 4, 3, 1, 1);

        pb_pow = new QPushButton(centralwidget);
        pb_pow->setObjectName("pb_pow");

        gridLayout->addWidget(pb_pow, 2, 3, 1, 1);

        pb_eight = new QPushButton(centralwidget);
        pb_eight->setObjectName("pb_eight");

        gridLayout->addWidget(pb_eight, 4, 1, 1, 1);

        pb_res = new QPushButton(centralwidget);
        pb_res->setObjectName("pb_res");

        gridLayout->addWidget(pb_res, 7, 3, 1, 1);

        pb_free_num = new QPushButton(centralwidget);
        pb_free_num->setObjectName("pb_free_num");

        gridLayout->addWidget(pb_free_num, 3, 0, 1, 2);

        pb_add = new QPushButton(centralwidget);
        pb_add->setObjectName("pb_add");

        gridLayout->addWidget(pb_add, 6, 3, 1, 1);

        l_formula = new QLabel(centralwidget);
        l_formula->setObjectName("l_formula");
        l_formula->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(l_formula, 0, 3, 1, 1);

        pb_three = new QPushButton(centralwidget);
        pb_three->setObjectName("pb_three");

        gridLayout->addWidget(pb_three, 6, 0, 1, 1);

        pb_mem_save = new QPushButton(centralwidget);
        pb_mem_save->setObjectName("pb_mem_save");

        gridLayout->addWidget(pb_mem_save, 2, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout->setSpacing(-1);
#endif
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, 0, 0);
        l_memory = new QLabel(centralwidget);
        l_memory->setObjectName("l_memory");

        horizontalLayout->addWidget(l_memory);

        l_result = new QLabel(centralwidget);
        l_result->setObjectName("l_result");
        l_result->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(l_result);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 4);

        pb_five = new QPushButton(centralwidget);
        pb_five->setObjectName("pb_five");

        gridLayout->addWidget(pb_five, 5, 1, 1, 1);

        pb_cout_save_num = new QPushButton(centralwidget);
        pb_cout_save_num->setObjectName("pb_cout_save_num");

        gridLayout->addWidget(pb_cout_save_num, 2, 1, 1, 1);

        pb_int_to_dbl = new QPushButton(centralwidget);
        pb_int_to_dbl->setObjectName("pb_int_to_dbl");

        gridLayout->addWidget(pb_int_to_dbl, 7, 0, 1, 1);

        pb_two = new QPushButton(centralwidget);
        pb_two->setObjectName("pb_two");

        gridLayout->addWidget(pb_two, 6, 1, 1, 1);

        pb_seven = new QPushButton(centralwidget);
        pb_seven->setObjectName("pb_seven");

        gridLayout->addWidget(pb_seven, 4, 0, 1, 1);

        pb_dlt = new QPushButton(centralwidget);
        pb_dlt->setObjectName("pb_dlt");

        gridLayout->addWidget(pb_dlt, 7, 2, 1, 1);

        pb_nine = new QPushButton(centralwidget);
        pb_nine->setObjectName("pb_nine");

        gridLayout->addWidget(pb_nine, 4, 2, 1, 1);

        pb_six = new QPushButton(centralwidget);
        pb_six->setObjectName("pb_six");

        gridLayout->addWidget(pb_six, 5, 2, 1, 1);

        pb_div = new QPushButton(centralwidget);
        pb_div->setObjectName("pb_div");

        gridLayout->addWidget(pb_div, 3, 3, 1, 1);

        pb_four = new QPushButton(centralwidget);
        pb_four->setObjectName("pb_four");

        gridLayout->addWidget(pb_four, 5, 0, 1, 1);

        pb_chng_sign = new QPushButton(centralwidget);
        pb_chng_sign->setObjectName("pb_chng_sign");

        gridLayout->addWidget(pb_chng_sign, 3, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        pb_sub->setText(QCoreApplication::translate("MainWindow", "\342\210\222", nullptr));
        pb_free_mem->setText(QCoreApplication::translate("MainWindow", "MC", nullptr));
        pb_zero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pb_one->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pb_mul->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        pb_pow->setText(QCoreApplication::translate("MainWindow", "x\312\270", nullptr));
        pb_eight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pb_res->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pb_free_num->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pb_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        l_formula->setText(QString());
        pb_three->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pb_mem_save->setText(QCoreApplication::translate("MainWindow", "MS", nullptr));
        l_memory->setText(QString());
        l_result->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><br/></p></body></html>", nullptr));
        pb_five->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pb_cout_save_num->setText(QCoreApplication::translate("MainWindow", "MR", nullptr));
        pb_int_to_dbl->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pb_two->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pb_seven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pb_dlt->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        pb_nine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pb_six->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pb_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pb_four->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pb_chng_sign->setText(QCoreApplication::translate("MainWindow", "\302\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
