//George Fotiou
//COSC 350
//Lab 8 Task 1
//reciever.c

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main (int argc, char *argv[]){


        int fd, res;
        char *pth, buff[55];


        pth = argv[1];

        while (1){

                fd = open(pth, O_RDONLY);
                read(fd, buff, 55);
                close(fd);
                printf("User2: %s\n", buff);
                memset(buff, 0, sizeof(buff));

                fd = open(pth, O_WRONLY);
                if(fd < 0) exit(1);
                fgets(buff, sizeof(buff), stdin);
                write(fd, buff, strlen(buff));
                close(fd);
                memset(buff, 0, sizeof(buff));

        }

}
