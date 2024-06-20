//George Fotiou
//dynem.c


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


int main (int argc, char *argv[]){

        if(argc != 2){
                printf("Invalid args!\n");
                exit(1);
        }

        char *poem[] ={"Hello I am George!", "Hows it over there?", "How was your day?", "Whats for lunch?", "See ya!"};
        char *rep = "Um I said bye... ";
        int n = atoi(argv[1]);

        char **lines = malloc(n*sizeof(char*));

        for (int i = 0; i < n; ++i){
                if(i < 5){
                        lines[i] = (char*)malloc(strlen(poem[i])+1);
                        strcpy(lines[i], poem[i]);
                }
                if(i >= 5){
                        lines[i] = (char*)malloc(strlen(rep));
                        strcpy(lines[i], rep);
                }
                printf("Line %d (Length: %ld): %s\n", i, strlen(lines[i]), lines[i]);
        }

        free(lines);

        exit(0);
}
