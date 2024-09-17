#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){



    int b =open("file-3.txt",O_WRONLY);
    printf("%d\n",b);
    printf("This text will go onto terminal\n");
    int a = dup2(b,1);
    printf("This text will go into file-3.txt file\n");
    printf("%d\n",a);
    // int c = dup2(b,7);
    printf("%d\t%d",b,a);
    return 0;
}