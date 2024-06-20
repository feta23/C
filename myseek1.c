//George Fotiou
//Lab 4
//Task 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BUFF 100

int main () {
	
	int fd1, fd2, fdout, offset, nbyte;
	char buff[BUFF];

	fd1 = open("foo1", O_RDONLY);
	fd2 = open("foo2", O_RDONLY);
	
	umask(0);
	fdout = open("foo12", O_RDONLY | O_WRONLY | O_CREAT, 0760);


	//will read fd1 first and write into new out file, then use lseek to find the end and write fd2 to out file
	//need to read/write byte by byte to avoid extra space by buffer
	
	//read foo1 with fd1
	while ( nbyte = read(fd1, buff, 1)  > 0 ) {
		if(write(fdout, buff, nbyte) != nbyte)
			printf("Error writing 1\n");
	}

	
	//use lseek to find end of text
	if ( offset = lseek(fdout, 0, SEEK_END) < 0 ){
		printf("Error seeking\n");
		exit(1);
	}
	//cursor is set to the size of bytes of the file

	//read foo2 with fd2
	while ( nbyte = read(fd2, buff, 1) > 0){
		if( write(fdout, buff, nbyte) != nbyte)
			printf("Error writing 2\n");
	}

	
	close(fd1);
	close(fd2);
	close(fdout);
	


	exit(0);
}
