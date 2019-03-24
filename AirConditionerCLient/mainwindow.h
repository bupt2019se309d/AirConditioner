#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //显示状态
    void show_state();

    //显示当前温度
    void show_temp();

    //显示当前风速
    void show_wind();

    //显示消耗的金额
    void show_cost();

    //显示消耗的能量
    void show_energy();



private slots:
    void on_open_button_clicked();

    void on_close_button_clicked();

    void on_bill_button_clicked();

    void on_cdr_button_clicked();

    void on_cold_button_clicked();

    void on_warm_button_clicked();

    void on_target_tmp_box_editingFinished();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
