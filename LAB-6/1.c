#include<stdio.h>
#include<unistd.h>

int main()
{
    int pipefd[2];
    int a = pipe(pipefd);
    if(a == -1){
        printf("error");
    }
    else
    {
        printf("correct");
        printf("\n%d\n%d",pipefd[0],pipefd[1]);
    }
    // char buf[100];
    char buf[50];
	// int n = read(0,buf,sizeof(buf));
	// printf("\nn = %d",n);
	// n= write(1,buf,n);
	// printf("\n n = %d",n);
    write(pipefd[1],"hello123",8);
    read(pipefd[0],buf,sizeof(buf));
    printf("\n%s\n",buf);
}