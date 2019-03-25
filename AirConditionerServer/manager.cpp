#include "manager.h"
#include "parameter.h"

extern parameter para;

Manager::Manager()
{

}

//打开从控机（收到开启命令，先设置从控机的参数，再调度）
bool power_on(int mode)
{
    set_para(mode);

    if(using_obj<all_obj)
    {
        return start();
    }
    else
    {
        return wait();
    }
}

//设置从控机参数（可能被power_on调用，也可能被mainwindow调用）
bool set_para(int mode)
{
    if (mode==cool)
    {

    }
    else
    {

    }
}

//启动从控机（发送开启消息）
bool start()
{
    //发送开启消息

    //添加到服务队列
    client* adder=new client;
    if(adder==NULL)//内存申请失败
        return false;
    //client.ip=
    client->start_t=QDateTime::currentDateTime();
    client->service_dur=0;//暂时以单次连续时长作为服务时长，如果要是累积时长，需要去根据ip查数据库
    client->wait_timer=0;
    client->next=NULL;

    if (service_list==NULL)
    {
        service_list=adder;
        service_list_tail=adder;
    }
    else
    {
        //如果是累积服务时长作为服务时长，不能那么简单地直接放在后面，需要排序！
        service_list_tail->next=adder;
        service_list_tail=adder;
    }
    using_obj++;
    return true;
}

//从控机进入待机（尝试启动从控机，由于资源不够失败，加入等待队列）
bool wait()
{
    client* adder=new client;
    if(adder==NULL)//内存申请失败
        return false;
    //client.ip=
    client->start_t=0;
    client->service_dur=0;//暂时以单次连续时长作为服务时长，如果要是累积时长，需要去根据ip查数据库
    client->wait_timer=para.wait_timer;
    client->next=NULL;

    if (wait_list==NULL)
    {
        wait_list=adder;
        wait_list_tail=adder;
    }
    else
    {
        //如果是累积服务时长作为服务时长，不能那么简单地直接放在后面，需要排序！
        wait_list_tail->next=adder;
        wait_list_tail=adder;
    }
    return true;
}


//关闭从控机（发送关闭消息，将其从服务队列删除）
bool power_off()
{

}

//检查从控机状态
void check_client_state();

//设置温度(收到设置温度的命令)
void set_tmpr();

//设置风速(收到设置风速的命令)
void set_wind();
