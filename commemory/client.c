#include "common.h"

int main()
{
    int shmid = GetShm(4096);
    sleep(1);
    char *addr =shmat(shmid, NULL, 0);
    sleep(2);
    int i = 0;
    while(i<26)
    {
        //每隔1秒写一个字母进去
        addr[i] = 'A'+i;
        i++;
        addr[i] = 0;
        sleep(1);
    }

    shmdt(addr);
    sleep(2);
    DestroyShm(shmid);
    return 0;
}
