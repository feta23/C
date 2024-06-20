//George Fotiou
//COSC 350
//Lab 9 Task 2
//userSig.c

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signo){
	if (signo == SIGUSR1){
		printf("George are you making friends?\n");
	}

	if (signo == SIGUSR2){
		printf("Luis, what did you have for lunch at school today?\n");
	}
}

int main (int argc, char *argv[]){


	int pid, ppid;
	ppid = getpid();
	printf("ppid: %ld\n", ppid);
	pid = fork();

	if (pid == -1){
		perror("Fork error");
		exit(1);
	}

	if (pid > 0){	
		pid = fork();

		if (pid == 0){ /*child proc2*/
			sleep(1);
			printf("Hello its Luis! ppid=%ld\n", getppid());
			kill(getppid(), SIGUSR2);
		}

		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		while(1)
			pause();

	}	
	if (pid == 0){ /*child proc1*/
		sleep(1);
		printf("Hello parent I am George ppid=%ld\n", getppid());
		kill(getppid(), SIGUSR1);

	}

	
	exit(0);
}
