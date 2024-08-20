#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    // int res = mkfifo("mypipe",0777);
    // if(res== 0)
    //     printf("pipe creation successful\n");
    int fd = open("mypipe",O_WRONLY);
    printf("dfjkhl\n");
    int n = write(fd,"welcome",7);
    printf("sender process %d sent data",getpid());
    return 0;
}