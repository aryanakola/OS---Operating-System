#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

int count =0;
sem_t s1;

void * proc(){
    // int i =10000;
    // while(i>0)
    // {
        sem_wait(&s1);
        count++;
        printf("count = %d\n",count);
        sem_post(&s1);
        // i--;
    // }
}

int main()
{
    sem_init(&s1,0,1);

    pthread_t t1;
    pthread_create(&t1,NULL,proc,NULL);
    pthread_t t2;
    pthread_create(&t2,NULL,proc,NULL);
    pthread_t t3;
    pthread_create(&t3,NULL,proc,NULL);
    pthread_t t4;
    pthread_create(&t4,NULL,proc,NULL);

    printf("main\n");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
}
