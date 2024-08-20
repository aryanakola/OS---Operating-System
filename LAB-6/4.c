#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>

int main()
{

    int pipefd[2];
    int a = pipe(pipefd);
    char fileNameToChild[]="1.c";
    char fileNameFromParent[1000];
    char buf[10000];
    if(a ==-1){
        // error while creating the pipe
        printf("error while creating the pipe\n");
    }
    int child1 =fork();
    if(child1==-1){
        // error while creating the child
        printf("error while creating the child\n");
    }
    if(child1==0){
        // this is the part which is executed by child
        // close the write end of child (not known whether necessary or not)
        // child will read the file name passed by parent through pipe using
        // the read end pipefd[0]
        // then it will open ->read ->display the content of the file on terminal 
        close(pipefd[1]); //closing the write end of child 
        read(pipefd[0],fileNameFromParent,sizeof(fileNameFromParent));
        int n = open(fileNameFromParent,O_RDONLY); //fopen is used to read only some content we want whole file to be read
        int n1 =read(n,buf,sizeof(buf));
        // printf("\n%s",buf);
        int n2 = write(1,buf,n1); 
    }
    else if(child1>0){
        // this is the part executed by the parent
        // close the read end of parent (not known whether necessary or not)
        // parent will pass the file name to be opened by child 
        // through the pipe using write end from parent pipefd[1]
        close(pipefd[0]); // closing the read end of parent
        write(pipefd[1],fileNameToChild,sizeof(fileNameToChild));
        
    }
    return 0;
}