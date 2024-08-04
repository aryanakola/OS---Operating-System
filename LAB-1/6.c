// trying to implementing the "cat" command on full fledge
// if cat with no argument then just replicating the input from terminal and printing it on the terminal 
// if cat with argument then displaying all the files whose name has been passed whether it is one or more than one

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	if(argc>1)
	{
		for(int i =1;i<argc;i++)
		{
			int n= open(argv[i],O_RDONLY);
			char buf[500];
			int n1= read(n,buf,sizeof(buf));
			int n2 = write(1,buf,n1);
			//printf("\nn = %d\n",n);
			//printf("\nn1 = %d\n",n1);
			//printf("\nn2 = %d\n",n2);
		}
		//printf("showing the all files\n");
	}
	else
	{
		int n;
		char buf[5];
		while(1)
		{
			n = read(0,buf,sizeof(buf));
			n= write(1,buf,n);
		}
		//printf("\n n = %d",n);
		//printf("Duplication of text from terminal \n");
	}
	return 0;
}
