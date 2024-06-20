//George Fotiou
//mydub.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]){
	
	int pid;
	int newfd;
	
	char* cmd_list[] = {"echo", "hello", "world", NULL};

	if (argc != 2){
		printf("Missing file path\n");
		exit(1);
	}

	if ( (newfd = open(argv[1], O_WRONLY) ) < 0 ){
		perror("opening file error");
		exit(1);
	}

	printf("opened new fd#%d\n", newfd);
	printf("Writing cmd '%s' to \"%s\"\n", cmd_list[0], argv[1]);	
	sleep(1);

	if ( ( dup2(newfd,1) ) < 0 ){
		perror("dup2 error");
		exit(1);
	}
	
	if ( ( execvp(cmd_list[0], cmd_list) ) == -1){
		perror("execvp error");
		exit(1);
	}
	

	close(newfd);
	printf("Command executed\n");

	exit(0);
}
