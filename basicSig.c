//George Fotiou
//basicSig.c

/*infinite program to use ^C to start a 3 second timer. Use ^Z to end*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signo){
	
	if (signo == SIGINT){
		printf(" Recieved Cntl+C. Starting alarm for 3 seconds\n");
		alarm(3);
	}
	
	if (signo == SIGALRM){
		printf("Alarm is done!\n");
	}

}


int main(int argc, char *argv[]){

	
	if (signal(SIGINT, sig_handler) == SIG_ERR){
		printf("Cant catch signal\n");
	}
	
	if(signal(SIGALRM, sig_handler) == SIG_ERR){
		printf("Cant catch alarm\n");
	}

	while(1)
		pause();

	exit(0);
}
