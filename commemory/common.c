#include "common.h"
//与创建消息队列很类似，就不做介绍了
int CommonShm(int size, int flags)
{
    key_t key = ftok(PATHNAME,PROJ_ID);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }
    int shmid = 0;
    if((shmid = shmget(key,size,flags)) < 0)
    {
        perror("shmget");
        return -2;
    }
    return shmid;       
}
int CreateShm(int size)
{
    return CommonShm(size,IPC_CREAT|IPC_EXCL|0666);
}
int DestroyShm(int shmid)
{
    if(shmctl(shmid,IPC_RMID,NULL) < 0)
    {
        return -1;
    }
    return 0;
}
int GetShm(int size)
{
    return CommonShm(size,IPC_CREAT);
}
