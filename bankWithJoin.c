//George Fotiou
//
//COSC 350
//Lab 10 Task 2
//bankWithJoin.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define THREADS 2

long int balance = 0;

void *addBread( void *arg ){
	
	balance += 10;
	
}

void *takeBread( void *arg ){
	
	balance -= 10;
	
}


int main (int argc, char *argv[]){

	pthread_t *threads = malloc (sizeof(pthread_t) * THREADS);
	
	for (int i = 0; i < 20; ++i){
		pthread_create(&threads[0], NULL, addBread, NULL);
		pthread_create(&threads[1], NULL, takeBread, NULL);
		
		printf("Balance before join: %ld\n", balance);

		pthread_join(threads[0], NULL);
		pthread_join(threads[1], NULL);

		printf("Balance: %ld\n", balance); 
	}

	printf("\n Final Balance: %ld\n", balance);

exit(0);
}
