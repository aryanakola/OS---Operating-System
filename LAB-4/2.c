#include<stdio.h>
#include<pthread.h>

void * proc1(){
    printf("hello from thread 1\n");
}
void * proc2(){
    printf("hello from thread 2\n");
}

int main()
{
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1,NULL,proc1,NULL);
    pthread_create(&t1,NULL,proc2,NULL);
    printf("main\n");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}