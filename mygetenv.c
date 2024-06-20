#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

int mygetenv(char *var){

	char **p = environ;
	char* token;
	

	while (*p != NULL){
		
		token = strtok(*p, "=");
		if ( (strcmp(var, token) == 0 ) ){
			token = strtok(0, "=");
			printf("%s's value is: %s \n", var, token);
			exit(0);
		}
		p++;
	}

	return -1; //returns -1 on failure
}

int main (int argc, char *argv[]){
	
	if (argc != 2){
		printf("Missing argument\n");
		exit(1);
	}

	if( (mygetenv(argv[1])) < 0 ){
		printf("Environment variable not found\n");
		exit(1);
	}

	exit(0);

}
