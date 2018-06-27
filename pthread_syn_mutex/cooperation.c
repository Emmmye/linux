#include<pthread.h>
#include<unistd.h>

#include<stdio.h>

volatile int banana = 0;
pthread_cond_t cond1;
pthread_mutex_t lock;

void *comsumer(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        if(banana<=0)
        {
            printf("I want to eat a banana\n");
            pthread_cond_wait(&cond1,&lock);
        } else{
            banana--;
            printf("I eat a banana!\n");
        }
        pthread_mutex_unlock(&lock);
}

}


void *product(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        banana++;
        printf("I put a banana\n");

        int r = pthread_cond_broadcast(&cond1);
        if ( r != 0  ) {
            fprintf(stderr, "=======%s\n", strerror(r));
        }
        pthread_mutex_unlock(&lock);
        sleep(5);
    }
}

int main()
{

    pthread_t com,pro;
    pthread_cond_init(&cond1,NULL);
    pthread_mutex_init(&lock,NULL);

    pthread_create(&com,NULL,comsumer,NULL);
    pthread_create(&pro,NULL,product,NULL);

    pthread_join(com,NULL);
    pthread_join(pro,NULL);

    pthread_cond_destroy(&cond1);
    pthread_mutex_destroy(&lock);


    return 0;
}
