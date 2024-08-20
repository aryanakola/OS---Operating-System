#include<stdio.h>
#include<unistd.h>

int main()
{
    int pipefd[2];
    int a = pipe(pipefd);
    if(a == -1){
        printf("error in pipe creation \n");
    }
    char messForChild[]="hello child";
    char messFromParent[100];
    pid_t child1=fork();
    if(child1 == -1){
        printf("error while creating fork\n");
    }
    if(child1==0){
        //child process
        close(pipefd[1]); //closing the write end of child 
        read(pipefd[0],messFromParent,sizeof(messFromParent));
        printf("\n printing from child \n %s",messFromParent);
    }
    else if(child1>0){
        //parent process
        close(pipefd[0]); // closing the read end of parent
        write(pipefd[1],messForChild,sizeof(messForChild));
    }
    return 0;
}