#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){

    int b =open("1.c",O_RDONLY);
    printf("%d\n",b);
    int a = dup(b);
    printf("%d\n",a);
    int c = dup2(b,7);
    printf("%d\t%d",b,c);
    return 0;
}