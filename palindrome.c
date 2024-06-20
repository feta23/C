//George Fotiou
//Lab 5 task 2
//palindrome.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main (int argc, char *argv[]){

	int fd1, fd2, offset;
	char buff1[1], buff2[1], p;
	
	if (argc != 2){
		printf("Invalid args\n");
		exit(1);
	}



	//fd1 will read byte by byte from the front 
	//fd2 will be read byte by byte from the back
	//so we do need to find the entire file size o


	if ( (fd1 = open(argv[1], O_RDONLY ) ) < 0){
		perror("Opening fd1 error");
		exit(1);
	}
	
	if ( (fd2 = open(argv[1], O_RDONLY ) ) < 0){
		perror("Opening fd2 error");
		exit(1);
	}

	//fd2 is now at the end of the file 
	if ( (offset = lseek(fd2, 0, SEEK_END)) == -1){
		perror("seeking error");
		exit(1);
	}else{
		printf("Offset found with offset=%d\n", offset);
	}
	

	while ( offset = lseek(fd2, -2, SEEK_CUR) >= 0){
		read (fd1, &buff1, 1);
		read (fd2, &buff2, 1);
			
		if ( buff1[0] == buff2[0] )
			p = 'T';
		else
			p = 'F';
	}


	if ( p == 'T' )
		printf("This was a palindrome\n");
	else if ( p == 'F' )
		printf("This was not a palindrome\n");

	close(fd1);
	close(fd2);
	exit(0);


}
