#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        //子进程
        sleep(50);
        exit(2);
    }
    //父进程
    int ret,status;
    ret = waitpid(pid,&status,0);
    if(ret > 0 && (status&0x7F) == 0)//正常退出
    {
        printf("Child exit code:%d\n",(status>>8)&0xFF);//提取子进程退出码
    }else//异常退出
    {
        printf("Child exit code:%d\n",status&0xFF);
    }
    return 0;
}
