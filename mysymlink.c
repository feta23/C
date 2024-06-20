//George Fotiou
//mysymlink.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]){

	if (argc != 3){
		printf("Missing args\n");
		exit(1);
	}
		
	if ( ( symlink (argv[1], argv[2]) ) < 0 ){
		perror("symlink error");
		exit(1);
	}

	printf("New symbolic link created.\n");


	exit(0);
}
