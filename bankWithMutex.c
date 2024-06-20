//George Fotiou
//bankWithMutex.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define THREADS 2

long int balance = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *deposit(void *arg){
	pthread_mutex_lock(&mutex);
	balance += 10;
	pthread_mutex_unlock(&mutex);

}

void *withdraw(void *arg){
	pthread_mutex_lock(&mutex);
	balance -= 10;
	pthread_mutex_unlock(&mutex);
}

int main (int argc, char *argv[]){
	
	pthread_t *threads = malloc (sizeof(pthread_t)*THREADS);
	
	for (int i = 0; i < 20; ++i){
		pthread_create(&threads[0], NULL, deposit, NULL);
		pthread_create(&threads[1], NULL, withdraw, NULL);
		
		pthread_join(threads[0], NULL);
		pthread_join(threads[1], NULL);
		printf("Balance: %ld\n", balance);
	}
	
	printf("Final Balance: %ld\n", balance);

exit(0);
}
