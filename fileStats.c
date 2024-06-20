//George Fotiou
//Lab 5 task 4
//fileStats.c

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main (int argc, char *argv[]){


	struct stat buff;

	if ( stat(argv[1], &buff) < 0 ){
		perror("Stat error");
		exit(1);
	}
	
	printf("File type: ");
	if ( S_ISREG(buff.st_mode) )
		printf("regular file\n");
	else if ( S_ISDIR(buff.st_mode) )
		printf("directory\n");
	else if ( S_ISCHR(buff.st_mode) )
		printf("char special\n");
	else if ( S_ISBLK(buff.st_mode) )
		printf("Block special\n");
	else if ( S_ISLNK(buff.st_mode) )
		printf("Symbolic link\n");
	else if ( S_ISSOCK(buff.st_mode) )
		printf("Socket\n");
	else
		printf("Unknown\n");


	printf("I-node number: %ld\n", (long) buff.st_ino); 
	printf("Mode: %lo (octal)\n", (unsigned long) buff.st_mode);
	printf("Link count: %ld\n", (long) buff.st_nlink);
	printf("Ownership: UID=%ld GID=%ld\n", (long) buff.st_uid, (long) buff.st_gid); 
	printf("Preferred I/O block size: %ld bytes\n", (long) buff.st_blksize);
	printf("File size: %ld bytes\n", (long) buff.st_size);
	printf("Blocks allocated: %ld\n", (long) buff.st_blocks);
	printf("Last status change: %s", ctime(&buff.st_ctime));
	printf("Last file access: %s", ctime(&buff.st_atime));
	printf("Last file modification: %s", ctime(&buff.st_mtime));
	exit(0);
}

