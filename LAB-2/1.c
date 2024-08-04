#include<stdio.h>
#include<unistd.h>

int main(){
	char buf[100];
	//char * ptr = 
	getcwd(buf, sizeof(buf));
	//printf("%s\n",ptr);
	printf("%s\n",buf);
	return 0;
}
