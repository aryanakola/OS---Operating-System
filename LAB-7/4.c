// child and parent communication 
// child performs ls
// and parent performs sort

// ls | sort 's program 
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    int fd[2];
    int a = pipe(fd);
    if(a == -1){
        printf("error in pipe creation \n");
    }
    pid_t child1=fork();
    char buf[1000];
    if(child1 == -1){
        printf("error while creating fork\n");
    }
    if(child1==0){
        //child process
        printf("CHILD\n");
        int d1= dup2(fd[1],1);
        execl("/bin/ls","ls",NULL);
    
    }
    else if(child1>0){
        //parent process
        wait(&child1);
        printf("PARENT\n");
        // write(1,buf,n);
        int d2= dup2(fd[0],0);
        execl("/bin/sort","sort",NULL);
        int n=read(0,buf,sizeof(buf));
        printf("\n%s\n",buf);

    }
    return 0;
}