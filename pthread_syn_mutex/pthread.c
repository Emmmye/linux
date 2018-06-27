#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/syscall.h>


 int ticket = 20;
pthread_mutex_t lock;

void* thread_run(void* arg)
{
    const void* msg = (const void*)arg;
   while(1)
   {
       pthread_mutex_lock(&lock);
       if(ticket>0)
       {
           usleep(1000);
           printf("%s get a ticket,ticket: %d\n",msg,ticket);
           ticket--;
           pthread_mutex_unlock(&lock);
       }else
       {
           pthread_mutex_unlock(&lock);
           break;
       }
   }
}


int main()
{
    pthread_t tid1,tid2,tid3,tid4;

    pthread_mutex_init(&lock,NULL);
    pthread_create(&tid1,NULL,thread_run,(void*)"thread1");
    pthread_create(&tid2,NULL,thread_run,(void*)"thread2");
    pthread_create(&tid3,NULL,thread_run,(void*)"thread3");
    pthread_create(&tid4,NULL,thread_run,(void*)"thread4");

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);

    pthread_mutex_destroy(&lock);
    return 0;

}
