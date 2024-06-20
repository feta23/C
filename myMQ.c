//George Fotiou
//COSC 350
//Lab 9 Task 3
//myMQ.c

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

struct my_msgbuf{
        long mtype;
        char mtext[200];
};

int main( int argc, char *argv[]){

        struct my_msgbuf buf;
        int msqid, pid;
        key_t key;
        key = ftok("myMQ.c", 'B');
        msqid = msgget(key, 0644 | IPC_CREAT);
        buf.mtype = 1;

        pid = fork();

        if (pid > 0){ //parent

                printf("Enter msg. ^D to send\n");

                while(fgets(buf.mtext, sizeof(buf.mtext), stdin) != NULL);
                msgsnd(msqid, (struct msgbuf *)&buf, sizeof(buf), 0);

        }
        if (pid == 0){
                int bytes = 0;
                
                msgrcv(msqid, (struct msgbuf *)&buf, sizeof(buf), 0,0);
                bytes += strlen(buf.mtext);
                printf("msg (%d bytes): %s\n",bytes, buf.mtext);
                
        }

        msgctl(msqid, IPC_RMID, NULL);

        exit(0);
}
