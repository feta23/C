#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define SIZE 255

int main (int argc, char *argv[]){

	pid_t pid;
	char *buff;
	int fd1[2], n;	//0 for read 1 for write
	       
	char cmd[] = "ping -c 5 amazon.com|grep \"rtt\""; 
	

	const char* childC = strtok(cmd, "|");
        const char* parentC = strtok(0, ".");
        


	if (pipe(fd1) < 0){
		perror("pipe 1 failure");
		exit(1);
	}
		
	if ((pid = fork()) < 0){
		perror("fork error");
		exit(1);

	} 
	else if (pid > 0){
		
		/*parent process*/

		int waitPid = 0;
		int status;

		printf("parent cmd: %s\n", parentC);
		
	}
	else {
				
		/*child process*/	
		
		printf("child cmd: %s\n", childC);
		
		dup2(fd[1], 0);

		execvp("ping", childC); 
		


	}

	exit(0);
}
