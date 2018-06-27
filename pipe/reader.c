#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    int output;
    //创建一个文件，并以只写方式打开它
    //目的是将test文件中的内容拷贝到test.bak中
    output = open("test.bak",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(output == -1)
    {
        perror("open");
    }
    int input;
    input = open("pipe",O_RDONLY);
    if(input == -1)
    {
        perror("open");
    }
    char buf[1024];
    int n;
    while((n = read(input,buf,sizeof(buf))) > 0)
    {
        write(output,buf,n);
    }
    close(input);
    close(output);
    unlink("pipe");
    return 0;
}
