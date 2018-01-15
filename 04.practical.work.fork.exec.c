#include "stdio.h"
#include<unistd.h>

int main(){
	printf("Main before Fork()\n");
	int pid = fork();
	if (pid == 0){
		int pid01 = fork();
		if (pid01 == 0){
			printf("I am a child after fork(),launching free -h\n");
			char *args[]= { "free", "-h" , NULL};
			execvp("free", args);
	}
	else{
		printf("I am a child after fork(),launching ps -ef\n");
		char *args[] = { "/bin/ps", "-ef" ,NULL};
		execvp("/bin/ps", args);
	}
	return 0;
}
}
