#include <stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include <stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

// int main(int argc, char **argv){
// 	DIR *d = opendir("/proc");
// 	struct dirent *de = readdir(d);
// 	while((de = readdir(d))!= NULL)
// 	{
// 		printf("%s\t",de->d_name);
// 	}
//     printf("\n");
// 	return 0;
// }

int main(){
    char * s1 ="/proc";
    char * s3="/stat";
    
    DIR *d = opendir(s1);
	struct dirent *de = readdir(d);
    while((de = readdir(d))!= NULL)
	{
        int pid =atoi(de->d_name);
		if( pid>0 ){
            char path[100]="";
            char c1[100]="";
            char c2[100]="";
            // printf("%d ",pid);
            strcat(path,s1);
            strcat(path,"/");
            strcat(path,de->d_name);
            strcat(path,s3);
            strcat(path,"\0");
            //not using open and read will be using fopen and fscanf
            
            // int n =open(path,O_RDONLY);
            // char buf[500];
	        // int n1= read(n,buf,sizeof(buf));
	        // int n2 = write(0,buf,n1);
            
            FILE* t;
            t= fopen(path,"r");
            fscanf(t,"%s\t%s",c1,c2);
            printf("%s\t%s",c1,c2);
            printf("\n");
        }
        //printf("%s\t",de->d_name);
	}
    printf("\n");
	return 0;
}