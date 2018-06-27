#include "common.h"

int main()
{
    int msgid = GetMsgQueue();

    char buf[1024];
    while(1)
    {
        buf[0] = 0;
        printf("Please Enter# ");
        fflush(stdout);//刷新缓冲区
        ssize_t s = read(0,buf,sizeof(buf));//从标准输出读取数据到buf中
        if(s > 0)
        {
            buf[s-1] = 0;
            SendMsg(msgid,CLIENT_TYPE,buf);
            printf("send done, wait recv...\n");
        }
        RecvMsg(msgid,SERVER_TYPE,buf);
        printf("Server say# %s \n",buf);
        if(strcmp(buf,"exit") == 0)
        {
            return 0;
        }
    }
    return 0;
}

