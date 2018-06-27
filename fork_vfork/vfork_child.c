#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int count = 100;

int main()
{
    pid_t pid = vfork();
    if(pid < 0)
    {
        perror("fork");
        return 0;
    }
    else if(pid == 0)
    {
        //创建的子进程
        count = 200;//修改全局变量
        printf("I am child! The count is %d\n",count);
        exit(1);
    }
    //父进程
    printf("I am father! The count is %d\n",count);
//    else
//    {
//        int status;
//        printf("I am father! My id is %d\n",getpid());
//        wait(&status);
//    }
    waitpid(pid,NULL,0);
    return 2;
}
