// implementing ls-R

#include <stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include <string.h>

void abc(const char *argv){
	char path[250];
	strcpy(path,argv);
		// appending nextdir name to the current path
	DIR *dummy = opendir(path);	// opening the new directory
	struct dirent *ddum = readdir(dummy);
	while((ddum = readdir(dummy))!= NULL)
	{
		printf("\t%s\n",ddum->d_name);
		if(ddum->d_type== DT_DIR)
		{	
			strcat(path,"/");	// appending "/" to the current path
			strcat(path,ddum->d_name);
			abc(argv);
		}
		//printf("\t%s\n",ddum->d_name);
	}
}

int main(int argc, char **argv){
	DIR *d = opendir(argv[1]);
	struct dirent *de = readdir(d);
	char path[250];
	while((de = readdir(d))!= NULL)
	{
		printf("%s\n",de->d_name);
		if(de->d_type== DT_DIR)
		{	
			strcpy(path,argv[1]);
			strcat(path,"/");	// appending "/" to the current path
			strcat(path,de->d_name);
			abc(path);
		}
		
			
	}
	return 0;
}
