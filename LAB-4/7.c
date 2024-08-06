// using mutex_lock and mutex_unlock in the critical section of 6.c 
// critical section is count++; and printf(); of proc 

// reason of doing this is because in without lock the output is not reaching till 40000

#include<stdio.h>
#include<pthread.h>

int count=0;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;

void * proc(){
    int i =10000;
    while(i>0)
    {
        pthread_mutex_lock(&m);
        count++;
        printf("count = %d\n",count);
        pthread_mutex_unlock(&m);
        i--;
    }
}

int main()
{
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
