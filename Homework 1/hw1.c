#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
pid_t pid, pid1;
int n;

	if (argc == 1) {
		fprintf(stderr,"Usage: ./a.out <starting value>\n");

		return -1;
	}

	n = atoi(argv[1]);

	/* add your code below, following the code structure of Figure 3.34 (page 152) */

	
	pid=fork();

	//check if n is positive
	if(n<=0){
		fprintf(stderr,"Argument is not a positive integer.\n");
		return 1;
	}
	//check if fork fails
	if(pid<0){
		fprintf(stderr,"Fork failed.");
		return 1;
	}
	else if(pid==0){ //child process
		pid1=getpid();
		printf("child: pid = %d\n",pid);
		printf("child: pid1 = %d\n",pid1);
		while(n>1){
			if(n%2==0){
				printf("%d, ",n);
				n=n/2;
			}
			else{
				printf("%d, ",n);
				n=(3*n)+1;
			}
		}
		printf("%d\n",n);
	}
	else{ //parent process
		pid1=getpid();
		printf("parent: pid = %d\n",pid);
		printf("parent: pid1 = %d\n",pid1);
		wait(NULL);
	}

	return 0;
}
