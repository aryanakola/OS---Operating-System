// reader's priority
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

int readCount=0;
sem_t x,wsem;

/*

this part is basic level function i have advanced it 

// void reading(){
//     printf("Reading %d \n",readCount);
// }
// void writing(){
//     printf("Writing \n");
// }
// void * Reader(){
//     sem_wait(&x);
//     readCount++;
//     if(readCount==1)sem_wait(&wsem);
//     sem_post(&x);

//     // reading func
//     reading();

//     sem_wait(&x);
//     readCount--;
//     if(readCount==0)sem_post(&wsem);
//     sem_post(&x);

// }

// void * Writer(){
//     sem_wait(&wsem);
//     // writing func 
//     writing();
//     sem_post(&wsem);
// }*/

void reading(int d){
    printf("Reading %d \n",d);
}

void writing(int d ){
    printf("Writing %d\n",d);
}

void * Reader(void * m ){
    int * z = (int *) m;
    int d=*z;
    sem_wait(&x);
    readCount++;
    if(readCount==1)sem_wait(&wsem);
    sem_post(&x);

    // reading func
    reading(d);

    sem_wait(&x);
    readCount--;
    if(readCount==0)sem_post(&wsem);
    sem_post(&x);

}

void * Writer(void * m){
    int * z = (int *) m;
    int d=*z;
    sem_wait(&wsem);
    // writing func 
    writing(d);
    sem_post(&wsem);
}



int main(){

    int rn =4,wn=4;
    sem_init(&x,0,1);
    sem_init(&wsem,0,1);
    pthread_t reader[rn];
    pthread_t writer[wn];
    int i;
    for ( i = 0; i < rn; i++)
    {
        int * dd =&i;
        // pthread_create(&reader[i],NULL,Reader,NULL);
        pthread_create(&reader[i],NULL,Reader,(void *)dd);
    }
    for ( i = 0; i < wn; i++)
    {
        int * dd =&i;
        // pthread_create(&writer[i],NULL,Writer,NULL);
        pthread_create(&writer[i],NULL,Writer,(void * )dd);
    }
    
    // joining loop
    for (int i = 0; i < rn; i++)
    {
        pthread_join(reader[i],NULL);
    }
    for (int i = 0; i < wn; i++)
    {
        pthread_join(writer[i],NULL);
    }
    return 0;
}