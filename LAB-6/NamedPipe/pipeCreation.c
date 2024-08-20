#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int res = mkfifo("mypipe1",0666);
    if(res== 0)
        printf("pipe creation successful\n");
    return 0;
}