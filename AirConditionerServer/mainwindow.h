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

private slots:
    void on_coldtmpr_box_editingFinished();

    void on_coldtmpr_toler_box_editingFinished();

    void on_coldwind_box_currentTextChanged(const QString &arg1);

    void on_warmtmpr_box_editingFinished();

    void on_warmtmpr_toler_box_editingFinished();

    void on_warmwind_box_currentTextChanged(const QString &arg1);

    void on_fee_box_editingFinished();

    void on_apply_set_button_clicked();

    void on_daily_report_button_clicked();

    void on_bill_button_clicked();

    void on_cdr_button_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
