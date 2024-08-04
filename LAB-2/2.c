// implementing the ls command normal

// the absolute path is given like 
// "/home/user1/Desktop" with double quotes


#include <stdio.h>
#include<dirent.h>
#include<sys/types.h>
int main(int argc, char **argv){
	DIR *d = opendir(argv[1]);
	struct dirent *de = readdir(d);
	while((de = readdir(d))!= NULL)
	{
		printf("%s\t",de->d_name);
	}
	return 0;
}
