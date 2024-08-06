#include<stdio.h>
#include<pthread.h>

void * proc(){
    printf("hello from thread 1\n");
}

int main()
{
    pthread_t t1;
    pthread_create(&t1,NULL,proc,NULL);
    printf("main\n");
    pthread_join(t1,NULL);
}