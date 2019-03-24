#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include <QWidget>
#include <QDateTime>

enum mode {cold,warm};

struct client
{
    //从控机的编号
    int no;

    //开始被服务的时间
    QDateTime start_t;

    //累计被服务的时长
    int service_dur;

    //等待计时器
    int wait_timer;
};



//空调管理员，负责运行空调，处理客户端的指令和监视空调状态
class Manager
{

private:

    //服务队列，按服务时长降序排序
    client service_list;

    //等待队列，按等待时长降序排序
    client await_list;

    //可供使用的从控机总数
    int all_obj;
    
    //正在服务的从控机总数
    int using_obj;

public:

    //初始化该类的属性变量
    Manager();

    //释放申请的内存
    ~Manager();

    //打开从控机（收到开启命令，先设置从控机的参数，再调度）
    bool power_on(int mode);

    //设置从控机参数（可能被power_on调用，也可能被mainwindow调用）
    bool set_para(int mode,int default_temp,int temp_rang,
                  int default_fan,int no_of_service);

    //启动从控机（发送开启消息）
    bool start();

    //关闭从控机（发送关闭消息，将其从服务队列删除）
    bool power_off();

    //检查从控机状态
    void check_client_state();

    //设置温度(收到设置温度的命令)
    void set_tmpr();

    //设置风速(收到设置风速的命令)
    void set_wind();


};

#endif // MANAGER_H
