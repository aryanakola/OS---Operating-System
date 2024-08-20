#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){

    int n =open("/proc/101/stat",O_RDONLY);
    char buf[500];
	int n1= read(n,buf,sizeof(buf));
	int n2 = write(0,buf,n1);
    // printf("%s",buf);
    return 0;
}