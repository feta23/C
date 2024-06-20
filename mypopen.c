//George Fotiou
//mypopen.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char *argv[]){

        if(argc != 3){
                printf("Invalid args\n");
                exit(1);
        }

        /*format the cmd*/
        char *cmd = (char*)malloc(strlen(argv[1]) + strlen(argv[2]) + 2);
        strcpy(cmd, argv[1]);
        strcat(cmd, " ");
        strcat(cmd, argv[2]);
        printf("cmd: %s\n", cmd);

        char buf[BUFSIZ];
        FILE *ptr;

        if ((ptr = popen(cmd, "r")) != NULL)
                while (fgets(buf, BUFSIZ, ptr) != NULL)
                        (void)printf("%s", buf);
        pclose(ptr);

        exit(0);
}
