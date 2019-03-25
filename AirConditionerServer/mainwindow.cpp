#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parameter.h"

extern parameter para;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//制冷模式目标温度设定
void MainWindow::on_coldtmpr_box_editingFinished()
{
    para.cool_target_tmpr=ui->coldtmpr_box->value();
}


//制冷模式温度差值设定
void MainWindow::on_coldtmpr_toler_box_editingFinished()
{

}


//制冷模式风速设定
void MainWindow::on_coldwind_box_currentTextChanged(const QString &arg1)
{

}


//制热模式目标温度设定
void MainWindow::on_warmtmpr_box_editingFinished()
{

}


//制热模式温度差值设定
void MainWindow::on_warmtmpr_toler_box_editingFinished()
{

}


//制热模式目标风速设定
void MainWindow::on_warmwind_box_currentTextChanged(const QString &arg1)
{

}


//费用设定
void MainWindow::on_fee_box_editingFinished()
{

}


//配置修改
void MainWindow::on_apply_set_button_clicked()
{

}


//显示日报表
void MainWindow::on_daily_report_button_clicked()
{

}



//显示总账单
void MainWindow::on_bill_button_clicked()
{

}


//显示总详单
void MainWindow::on_cdr_button_clicked()
{

}


