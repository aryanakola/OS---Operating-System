// child and parent communication 
// child performs ls
// and parent performs sort

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <fcntl.h>


int main()
{
    int PtoCfd[2];
    int CtoPfd[2];
    int a = pipe(PtoCfd);
    int b =pipe(CtoPfd);
    char file[]="unsorted.txt";
    char fileNameReceived[100];
    char buf[1000];
    char buf1[1000];
    if(a == -1 || b==-1){
        printf("error in pipe creation \n");
    }
    pid_t child1=fork();
    // char buf[1000];
    if(child1 == -1){
        printf("error while creating fork\n");
    }
    if(child1==0){
        //child process
        printf("CHILD\n");
        close(PtoCfd[1]); //closing the write end of child 
        read(PtoCfd[0],fileNameReceived,sizeof(fileNameReceived));
        int n = open(fileNameReceived,O_RDONLY); //fopen is used to read only some content we want whole file to be read
        int n1 =read(n,buf,sizeof(buf));
        // printf("\n%s\n",buf);
        close(CtoPfd[0]); // closing the read end of child in 2nd pipe
        int d1= dup2(CtoPfd[1],1);
        write(CtoPfd[1],buf,n1);
        // execl("/bin/ls","ls",NULL);
    
    }
    else if(child1>0){
        //parent process
        printf("PARENT\n");
        close(PtoCfd[0]); // closing the read end of parent
        write(PtoCfd[1],file,sizeof(file));
        wait(&child1);
        printf("Hello\n");
        int d2= dup2(CtoPfd[0],0);
        int n1 =read(0,buf1,sizeof(buf1));
        // printf("\n%s\n",buf1);
        execl("/bin/sort","sort",NULL);
        int n=read(0,buf1,sizeof(buf1));
        // write(1,buf,n);
        printf("\n%s\n",buf);

    }
    return 0;
}