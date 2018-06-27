#include <stdio.h>
#include <signal.h>

void my_hander(int signum)
{
    printf("got a %d signal\n",signum);
}

int main()
{
    signal(2,my_hander);
    while(1)
    {
        sleep(1);
    }
    return 0;
}

