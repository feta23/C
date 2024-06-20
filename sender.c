//George Fotiou
//sender.c

/* communicates with receiver.c */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char *argv[]){

        int fd, res;
        char *pth, buff[55];

        pth = argv[1];

        umask(0);
        res = mkfifo(pth, 0666);

        if (res == 0)
                printf("FIFO '%s' has been created.\n");


        while(1){

                fd = open(pth, O_WRONLY);
                if(fd < 0) exit(1);
                fgets(buff, sizeof(buff), stdin);
                write(fd, buff, strlen(buff));
                close(fd);
                memset(buff, 0, sizeof(buff));

                fd = open(pth, O_RDONLY);
                if(fd < 0) exit(1);
                read(fd, buff, 55);
                close(fd);
                printf("User2: %s\n", buff);
                memset(buff, 0, sizeof(buff));

        }

}
