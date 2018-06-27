#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//匿名管道
//int main()
//{
//    pid_t pid;
//    int file1[2];
//    pipe(file1);
//    char buf[256] = {0};
//    pid = fork();
//    if(pid < 0)
//    {
//        perror("fork");
//    }else if(pid == 0)
//    {
//        close(file1[0]);
//        write(file1[1],"hello father",strlen("hello father"));
//    }else
//    {
//        close(file1[1]);
//        read(file1[0],buf,sizeof(buf));
//    }
//    printf("%s\n",buf);
//}
//
int main()
{
    //创建命名管道，权限是644
    mkfifo("pipe",0644); 
    //test 文件已在当前目录下创建，以只读方式打开
    int input = open("test",O_RDONLY);
    if(input == -1)
    {
        perror("open");
    }
    //以只写方式打开命名管道
    int output = open("pipe",O_WRONLY);
    if(output == -1)
    {
        perror("open");
    }
    char out[1024];
    int n;
    while((n = read(input,out,sizeof(out))) > 0)
    {
        //向管道写数据
        write(output,out,n);
    }
    close(input);
    close(output);
    return 0;
}




