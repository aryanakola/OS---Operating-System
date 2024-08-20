#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{

    int pipe1fd[2];
    int pipe2fd[2];
    int a = pipe(pipe1fd);
    int b = pipe(pipe2fd);
    char fileNameToChild[]="1.c";
    char fileNameFromParent[100];
    char buf[10000];
    char buf2[10000];
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
        // then it will open ->read ->send the content of the file to the parent using different pipe i.e. pipe2fd
        close(pipe1fd[1]); //closing the write end of child 
        read(pipe1fd[0],fileNameFromParent,sizeof(fileNameFromParent));
        int n = open(fileNameFromParent,O_RDONLY); //fopen is used to read only some content we want whole file to be read
        int n1 =read(n,buf,sizeof(buf));
        close(pipe2fd[0]); // closing the read end of child in 2nd pipe
        write(pipe2fd[1],buf,n1);
    }
    else if(child1>0){
        // this is the part executed by the parent
        // close the read end of parent (not known whether necessary or not)
        // parent will pass the file name to be opened by child 
        // through the pipe using write end from parent pipe1fd[1]
        // through another pipe i.e. pipe2fd parent will get the content of file name it has passed
        close(pipe1fd[0]); // closing the read end of parent
        write(pipe1fd[1],fileNameToChild,sizeof(fileNameToChild));
        close(pipe2fd[1]); // closing the write end of parent in 2nd pipe
        wait(&child1);
        int n= read(pipe2fd[0],buf2,sizeof(buf));
        printf("\nprinting the program from parent \n");
        write(1,buf2,n);
    }
    return 0;
}