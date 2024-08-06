// implenting calculator using multi thread
//still incomplete

#include<stdio.h>
#include<pthread.h>

typedef struct storage{
    float a;
    float b;
    float a_add,a_sub,a_mul,a_div;
}str;


void * addition(void * m){
    str * s = (str *)m;
    s->a_add=s->a+s->b;
    printf("Addition is %f\n",s->a_add);
}

void * subtraction(void * m){
    str * s = (str *)m;
    s->a_sub=s->a-s->b;
    printf("Subtraction is %f\n",s->a_sub);
}

void  * multiplication(void * m){
    str * s = (str *)m;
    s->a_mul=s->a*s->b;
    printf("Multiplication is %f\n",s->a_mul);
}

void * division(void * m){
    str * s = (str *)m;
    s->a_div=s->a/s->b;
    printf("Division is %f\n",s->a_div);
}


int main(){
    pthread_t add;
    pthread_t sub;
    pthread_t mul;
    pthread_t div;
    str xyz;
    str * x = &xyz;
    x->a=10.0;
    x->b=5.0;
    pthread_create(&add,NULL,addition,(void *)x);
    pthread_create(&sub,NULL,subtraction,(void *)x);
    pthread_create(&mul,NULL,multiplication,(void *)x);
    pthread_create(&div,NULL,division,(void *)x);
    pthread_join(add,NULL);
    pthread_join(sub,NULL);
    pthread_join(mul,NULL);
    pthread_join(div,NULL);
    return 0;
}