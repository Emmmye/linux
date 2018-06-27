#include <signal.h>
#include <stdio.h>

void showpending(sigset_t *set)
{
    int i = 0;
    for(i=1;i<32;i++)//从1号信号开始
    {
        if(sigismember(set,i))//判断指定信号是否在目标信号集中
            putchar('1');
        else
            putchar('0');
    }
    puts("");
}
int main()
{
    sigset_t sig,pend;
    sigemptyset(&sig);
    sigfillset(&sig);
    sigaddset(&sig,2);//将2号信号作为有效信号添加进去
    sigprocmask(SIG_BLOCK,&sig,NULL);//添加2号信号到信号屏蔽字中，相当于阻塞2号信号
    while(1)
    {
        sigpending(&pend);//获取当前进程的未决信号集，用新定义的信号集类型pend接收
        showpending(&pend);//打印信号未决集
        sleep(1);//防止打印过快，结果不明显
    }
    return 0;
}
