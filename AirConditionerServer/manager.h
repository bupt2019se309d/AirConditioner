#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include <QWidget>
#include <QDateTime>

enum mode {cool,warm};

struct client
{
    //从控机的ip地址
    QString ip;

    //开始被服务的时间
    QDateTime start_t;

    //累计被服务的时长
    float service_dur;

    //等待计时器
    float wait_timer;

    //指向下一个的指针
    client* next;

    //构造函数
    client(const QString _ip, const QDateTime _start_t,
           const float _service_dur,const float _wait_timer)
    {
        ip=_ip;
        start_t=_start_t;
        service_dur=_service_dur;
        wait_timer=_wait_timer;
    }
};



//空调管理员，负责运行空调，处理客户端的指令和监视空调状态
class Manager
{

private:

    //服务队列头，按服务时长降序排序
    client* service_list=NULL;

    //服务队列尾
    client* service_list_tail=NULL;

    //等待队列，按等待时长降序排序
    client* wait_list=NULL;

    //等待队列尾
    client* wait_list_tail=NULL;

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
    bool set_para(int mode);

    //启动从控机（发送开启消息）
    bool start();

    //从控机进入待机（尝试启动从控机，由于资源不够失败，加入等待队列）
    bool wait();

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
