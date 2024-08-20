#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buf[10000];
    int fd = open("mypipe",O_RDONLY);
    int n = read(fd,buf,sizeof(buf));
    printf("receiver process %d receiver data\n%s",getpid(),buf);
    return 0;
}