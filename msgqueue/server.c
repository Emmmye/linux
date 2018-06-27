#include "common.h"

int main()
{
    int msgid = CreateMsgQueue();

    char buf[1024];
    while(1)
    {
        buf[0] = 0;
        RecvMsg(msgid,CLIENT_TYPE,buf);
        printf("Client say# %s \n",buf);

        printf("Please Enter# ");
        fflush(stdout);//刷新缓冲区
        ssize_t s = read(0,buf,sizeof(buf));//从标准输出读取数据到buf中
        if(s > 0)
        {
            buf[s-1] = 0;
            SendMsg(msgid,SERVER_TYPE,buf);
            printf("send done,wait for client:..\n");
        }
        if(strcmp(buf,"exit") == 0)
        {
            break;
        }
    }
    DestroyMsgQueue(msgid);
    return 0;
}

