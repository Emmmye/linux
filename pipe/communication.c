#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//匿名管道
int main()
{
    pid_t pid;
    int file[2];//用于接收文件描述符
    pipe(file);//创建管道
    char buf[256] = {0};
    pid = fork();
    if(pid < 0)
    {
        perror("fork");
    }else if(pid == 0)
    {
        //子进程进行写操作，关闭文件描述符fd[0]
        close(file[0]);
        write(file[1],"hello father",strlen("hello father"));
    }else
    {
        //父进程进行读操作，关闭文件描述符fd[1]
        close(file[1]);
        read(file[0],buf,sizeof(buf));
    }
    printf("%s\n",buf);
}

//int main()
//{
//    mkfifo("pipe",0644); 
//    int input = open("test",O_RDONLY);
//    if(input == -1)
//    {
//        perror("open");
//    }
//    int output = open("pipe",O_WRONLY);
//    if(output == -1)
//    {
//        perror("open");
//    }
//    char out[1024];
//    memset(out,0,sizeof(out));
//    read(output,out,sizeof(out));
//    write(input,out,sizeof(out));
//    return 0;
//}
