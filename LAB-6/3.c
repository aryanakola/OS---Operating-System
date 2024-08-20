#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];
    int a = pipe(pipefd);
    if(a == -1){
        printf("error in pipe creation \n");
    }
    char messForParent[]="hey parent";
    char messFromChild[100];
    pid_t child1=fork();
    if(child1 == -1){
        printf("error while creating fork\n");
    }
    if(child1==0){
        //child process
        close(pipefd[0]); //closing the read end of child 
        write(pipefd[1],messForParent,sizeof(messForParent));
    }
    else if(child1>0){
        //parent process
        close(pipefd[1]); // closing the write end of parent
        pid_t waitKey = wait(&child1);
        read(pipefd[0],messFromChild,sizeof(messFromChild));
        printf("\n printing from Parent \n %s",messFromChild);
    }
    return 0;
}