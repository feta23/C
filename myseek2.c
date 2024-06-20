//George Fotiou
//Lab 4
//Task 2
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main () {


	int fd, fdout, offset, nbyte;
	char buff[1];

	fd = open("foo", O_RDONLY); 
	umask(0);
	fdout = open("fooReserved.c", O_RDONLY | O_WRONLY | O_CREAT, 0760);


	//Use lseek to get to the end of the file
	if ( offset = lseek(fd, 0, SEEK_END) == -1){
		printf("Error seeking\n");
	}

	//now read char, need to go back over current char and then char before it, so offset is -2
	while ( offset = lseek(fd, -2, SEEK_CUR) >= 0){
		nbyte = read(fd, buff, 1);
		write(fdout, buff, nbyte);
	}

	
	close(fd);
	close(fdout);
	

	exit(0);
}
