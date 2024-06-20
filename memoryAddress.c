#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int global;

int foo (int n){
	int foo = 1; 
	int uninit;
	uninit = n;

	//printf("Value recieved: %d\n", uninit);
	printf("int uninit (unitialized): 0x%x\n", (unsigned long) &uninit);
	printf("int foo (initialized): 0x%x\n", (unsigned long) &foo);
	if(uninit < foo){
		printf("Invalid value!\n");
		return -1;
	}

	return 0; //returns 0 on success
}

int main (int argc, char *argv[]){
	
	int j;
	int i = 0;
	int *arr = (int*) malloc( sizeof(int) ) ;

	if (arr == NULL){
		printf("Memory allocation failure\n");
		exit(1);
	}else{
		printf("Memory successfully allocated\n");
	}
	sleep(1);
	printf("\n");
	printf("Now printing global variables\n");
	printf("int global (unitialized): 0x%x\n", (unsigned long) &global);
	
	printf("\n");
	
	printf("Now printing variable address in main\n");
	printf("int j (uninitialized): 0x%x\n", (unsigned long) &j);
	printf("int i (initialized): 0x%x\n", (unsigned long) &i);
	printf("int *arr (dynamically allocated): 0x%x\n", (unsigned long) &arr);
	sleep(1);
	
	printf("\n");

	printf("Printing the variables of the foo function\n");
	foo(5);
	

	exit(0);
}
