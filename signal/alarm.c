#include <stdio.h>
#include<signal.h>


int main()
{
    int count = 0;
    alarm(1);//设置闹钟时间为1秒
    while(1)
    {
        printf("count = %d\n",count);
        count++;
    }//这个函数实现1秒钟内不停地数数，1秒钟到了就被alarm发送的SIGALRM信号所终止
    return 0;
}
