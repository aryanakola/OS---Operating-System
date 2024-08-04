#include<unistd.h>
#include<stdio.h>
int main(){
	int n;
	char buf[50];
	n = read(0,buf,sizeof(buf));
	printf("\nn = %d",n);
	n= write(1,buf,n);
	printf("\n n = %d",n);
	return 0;
}
