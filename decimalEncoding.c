#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void conversion (char*);

int main (int argc, char* argv[]) {

	if (argc != 3){
		printf("Invalid args\n");
		exit(1);
	}

	int fdin, fdout, nbyte;
	char buff[1];

	printf(argv[1]);
	printf(argv[2]);
	printf("\n");

	fdin = open(argv[1], O_RDONLY);
	fdout = open(argv[2], 666);
	char temp[1];

	while( nbyte = read(fdin, buff, 1) > 0 ){			
	//add conversion to hex here then write into new file
		
		


		write(fdout, buff, nbyte);
	}

	close(fdin);
	close(fdout);
	exit(0);
}

void conversion (char* b){
	
	

}
