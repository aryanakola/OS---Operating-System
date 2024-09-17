#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    pid_t child1=fork();
    if(child1 == -1){
        printf("error while creating fork\n");
    }
    if(child1==0){
        //child process
        printf("CHILD\n");
        execl("/bin/pwd","pwd",NULL);
    
    }
    else if(child1>0){
        //parent process
        wait(&child1);
        printf("PARENT\n");
        execl("/bin/ls","ls",NULL);
    }
    return 0;
}