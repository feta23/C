//George Fotiou
//mycp1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 225

void err_sys(char *str) {
	printf("%s\n", str);
	exit(1);
}

int main (int argc, char* argv[]){
	int nbyte;
	char buffer[BUFFER_SIZE];

	while ((nbyte = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
		if (write (STDOUT_FILENO, buffer, nbyte) != nbyte)
			err_sys("Write Error");
	if (nbyte < 0)
		err_sys("Read Error");

exit (0);
}
