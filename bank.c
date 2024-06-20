//George Fotiou
//bank.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define THREADS 2

long int balance = 0;

void *deposit(void *arg){
	balance += 10;
}

void *withdraw(void *arg){
	balance -= 10;
} 

int main (int argc, char *argv[]){

	pthread_t *threads = malloc(sizeof(pthread_t) * THREADS);
		
	for (int i = 0; i < 20; ++i){
		pthread_create(&threads[0], NULL, deposit, NULL);
		pthread_create(&threads[0], NULL, withdraw, NULL);
		printf("Balance: %ld\n", balance);	
	}

	printf("\n Final Balance: %ld\n", balance);

exit(0);
}
