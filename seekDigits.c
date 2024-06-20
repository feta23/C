//George Fotiou
//seekDigits.c

/* needs to be refactored. Way easier way to do this. */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//used for initial char array
bool isCPrime(char);
//used after conversion
bool isNPrime(int);

int main (int argc, char *argv[]) {

	if (argc != 2){
		printf("Argument error\n");
		exit(1);
	}

	char *ptr = argv[1];
	int flag = 0, count = 0;
	char arr[80];
	 

	while (*(ptr) != '\0') {
	
		//will ignore leading zeros
		if ( *(ptr) > '0' && *(ptr) <= '9' ){
			flag = 1;
		}

		if ( flag == 1 ) {

			if ( *(ptr) >= '0' && *(ptr) <= '9' ) {
				//printf("This is a number\n");

					if ( isCPrime( *(ptr) ) ) { // this is where to determine if the value is prime
						//printf("I think this is a prime num ^\n");
						arr[count++] = *(ptr);
				}
			}
		}

		++ptr;
	}

	if( arr[0] == '\0'){
		printf("No prime numbers were found\n");
		exit(1);
	}else{
		printf("The prime numbers from the args are %s\n", arr); 
	}	

	int n = strlen(arr);
	int num = 0;

	for (int i = 0; i < n; ++i){
		num = num * 10 + (arr[i] - 48);
	}
	
	//printf("%d\n", num);
	
	if ( isNPrime(num) ) 
		printf("%d is a prime number\n", num);
	else
		printf("%d is not prime number\n", num);

	exit(0);
}

bool isCPrime(char c){
	
	if (c == '2')
		return true;
	if(c == '3')
		return true;
	if(c == '5')
		return true;
	if(c == '7')
		return true;
	else
		return false;
}

bool isNPrime(int n){
	bool tf;

	for (int i = 2; i <= (n - 1); ++i) {
		if ( n % i == 0){
			tf = false;
			break;
		}else{
			tf = true;
		}
	}

	return tf;
}
