#include "common.h"

int main()
{
    int shmid = CreateShm(4096);
    char *addr = shmat(shmid, NULL, 0);
    sleep(2);
    int i = 0;
    while(i++<26)
    {
        printf("client# %s\n",addr);
        sleep(1);
    }
    //将共享内存段与当前进程脱离
    shmdt(addr);
    sleep(2);
    DestroyShm(shmid);
    return 0;
}
