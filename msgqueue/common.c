#include "common.h"
int CommonMsgQueue(int flags)
{
    key_t key = ftok(PATHNAME,PROJ_ID);//ftok函数可以生成key
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }
    int msgid = msgget(key,flags);
    if(msgid < 0)
    {
        perror("msgget");
        return -1;
    }
    return msgid;
}
int CreateMsgQueue()//创建一个消息队列
{
    //flag由9个权限标志构成
    //IPC_CREAT|IPC_EXCL一起用表示如果没有该消息队列，则创建一个新的，并返回队列ID
    return CommonMsgQueue(IPC_CREAT|IPC_EXCL|0666);
}
int GetMsgQueue()//获得一个消息队列
{
    //返回已创建的消息队列ID
    return CommonMsgQueue(IPC_CREAT);
}
int DestroyMsgQueue(int msgid)//销毁一个消息队列
{
    if (msgctl(msgid,IPC_RMID,NULL) < 0 )
    {
        perror("msgctl");
        return -1;
    }
    return 0;
}
int SendMsg(int msgid, int who, char *msg)//往消息队列中发送数据
{
    struct msgbuf buf;
    buf.mtype = who;
    strcpy(buf.mtext,msg);

    if(msgsnd(msgid,(void*)&buf,sizeof(buf.mtext),0) < 0)
    {
        perror("msgsnd");
        return -1;
    }
    return 0;
}
int RecvMsg(int msgid, int recvType, char out[])//从消息队列中读取数据
{
    struct msgbuf buf;
    if((msgrcv(msgid,(void *)&buf,sizeof(buf.mtext),recvType,0)) < 0)
    {
        perror("msgrcv");
        return -1;
    }
    strcpy(out,buf.mtext);
    return 0;
}
