#include <unistd.h>
#include <stdio.h>

int main(){
	int n = write(1,"hello\n",4);
	printf("\n n = %d",n);
	return 0;
}

