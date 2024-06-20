//George Fotiou
//funTiming.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <utime.h>
#include <time.h>

int main (int argc, char *argv[]){
	
	struct utimbuf timebuf1, timebuf2, timebuf3;
	struct stat statbuf1, statbuf2, statbuf3;
	time_t time(time_t *t_loc);
	
	if (argc != 4){
		printf("Missing args\n");
		exit(1);
	}
	
	//oldfile info
	if ( ( stat(argv[1], &statbuf1 ) ) < 0 ){
		perror("statbuf1 error");
		exit(1);
	}

	timebuf1.actime = statbuf1.st_atime;
	timebuf1.modtime = statbuf1.st_mtime;
	
	//copyfile info
	if ( ( stat(argv[2], &statbuf2) ) < 0 ){
		perror("statbuf2 error");
		exit(1);
	}

	timebuf2.actime = statbuf2.st_atime;
	timebuf2.modtime = statbuf2.st_mtime;

	
	printf("Stats completed.\n");
	printf("Setting new times to copy file...\n");
	sleep(1);

	
	//copy file gets set to same stats as oldfile	
	if ( ( utime(argv[2], &timebuf1) ) < 0 ){
		perror("utime error");
		exit(1);
	}

	printf("copy file time has been set the same as old file\n");
	printf("setting current time to new file...\n");
	sleep(1);

	timebuf3.actime = time(NULL);
	timebuf3.modtime = time(NULL);
	
	if ( ( utime(argv[3], &timebuf3) ) < 0 ){
		perror("new file utime error");
		exit(1);
	}

	printf("current time and date set\n");
	
	exit(0);
}
