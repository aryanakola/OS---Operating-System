#include<stdio.h>
#include<unistd.h>


int main(){

    printf("hello\n");
    execl("/bin/ls","ls",NULL);
    printf("hello\n");
    return 0;
}