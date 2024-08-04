// trying to replicate cat command for displaying the file content 
// passing the argument from  terminal

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc, char * argv[]){
	int n= open(argv[1],O_RDONLY);
	char buf[500];
	int n1= read(n,buf,sizeof(buf));
	int n2 = write(1,buf,n1);
	printf("\nn = %d\n",n);
	printf("\nn1 = %d\n",n1);
	printf("\nn2 = %d\n",n2);
	return 0;
}
