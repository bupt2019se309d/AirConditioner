#include "mainwindow.h"
#include "ui_mainwindow.h"

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


//显示当前从控机状态
void MainWindow::show_state()
{
    ui->state_label->setText("打开");
}


//显示当前室温
void MainWindow::show_temp()
{
    ui->tmpr_number->display(25);
}


//显示当前风速
void MainWindow::show_wind()
{
    ui->wind_label->setText("中");
}


//显示当前能量
void MainWindow::show_energy()
{
    ui->ene_number->display(0);
}


//显示当前金额
void MainWindow::show_cost()
{
    ui->cost_number->display(0);
}


//按下制冷按钮
void MainWindow::on_cold_button_clicked()
{

}


//按下制热按钮
void MainWindow::on_warm_button_clicked()
{

}


//设置目标温度
void MainWindow::on_target_tmp_box_editingFinished()
{

}


//设置目标风速
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

}


//按下开机按键
void MainWindow::on_open_button_clicked()
{
    //发送启动请求
}


//按下关机按键
void MainWindow::on_close_button_clicked()
{
    //发送关闭请求
}


//按下账单查看按钮
void MainWindow::on_bill_button_clicked()
{
    //发送账单查看请求
    //或者，打印本地的账单信息
}

//按下详单查看按钮
void MainWindow::on_cdr_button_clicked()
{
    //发送详单查看请求
    //或者，打印本地的详单信息
}


