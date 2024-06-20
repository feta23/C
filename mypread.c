//George Fotiou
//mypread.c


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main () {

	int fdin, fdout, pw, pr;
	char buff[1];

	fdin = open ("foo", O_RDONLY);
	umask(0);
	fdout = open("fooReserved.c", O_RDONLY | O_WRONLY | O_CREAT, 0760);

	int offset = 0;
	
	
	//use pread to search through whole file and save offset of entire file
	while ( pread(fdin, &buff, 1, offset++ ) > 0);

	offset--;
	
	while ( (pw = pread(fdin, &buff, 1, --offset)) > 0 ){
		if(write(fdout, &buff, 1) != 1)
			printf("Write error\n");
	}

	exit(0);
}
