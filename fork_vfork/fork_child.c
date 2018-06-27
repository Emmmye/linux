#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return 0;
    }
    else if(pid == 0)
    {
        //创建的子进程
        printf("I am child! My id is %d\n",getpid());
    }
    //父进程
    printf("I am father! My id is %d\n",getpid());
//    else
//    {
//        int status;
//        printf("I am father! My id is %d\n",getpid());
//        wait(&status);
//    }
    waitpid(pid,NULL,0);
    return 0;
}
