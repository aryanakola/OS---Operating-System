// passing the string to the void * proc which only accepts the argument of type (void *)

#include<stdio.h>
#include<pthread.h>

void * proc1(void * m){
    char *s = (char *)m;
    printf("hello from %s\n",s);
}
// void * proc2(void * m){
//     printf("hello from thread 2\n");
// }

int main()
{
    pthread_t t1;
    pthread_t t2;
    char * s1 ="thread 1";
    char * s2 = "thread 2";
    pthread_create(&t1,NULL,proc1,(void*)s1);
    pthread_create(&t1,NULL,proc1,(void *)s2);
    printf("main\n");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}