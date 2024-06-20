// George Fotiou
//mycp2.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BUFF_SIZE 1

int main (int argc, char* argv[]){
	
	int fdin, fdout, nbyte;
	char buff[BUFF_SIZE];
	
	if(argc != 2){
		printf("Invalid args\n");
		exit(1);
	}

	if((fdin = open(argv[1], O_RDONLY)) == -1){
		printf("Error opening in file\n");
		exit(1);
	}

	umask(0);
	if((fdout= open("out.txt", O_CREAT | O_WRONLY , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) == -1){
		printf("Error opening out file\n");
		exit(1);
	}
	
	//printf("fdin = %d\n", fdin);
	//printf("fdout = %d\n", fdout);

	//files are now opened. read from one and write to other
	
	while ((nbyte = read(fdin, buff, BUFF_SIZE)) > 0) 
		write(fdout, buff, BUFF_SIZE);
	
	printf("Write completed.\n");

close(fdin);
close(fdout);

exit(0);
}
