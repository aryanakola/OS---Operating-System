// passing multiple variable to the void * proc and trying to print them

#include<stdio.h>
#include<pthread.h>

typedef struct abc{
    int x,y;
}a;

void * proc1(void * m){
    a *s = (a *)m;
    printf("hello from proc1\n");
    printf("x = %d and y = %d\n",s->x,s->y);

}

int main()
{
    pthread_t t1;
    a s1;
    s1.x=1;
    s1.y=2;
    a * s = &s1;
    pthread_create(&t1,NULL,proc1,(void*)s);
    printf("main\n");
    pthread_join(t1,NULL);
}