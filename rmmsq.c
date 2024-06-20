#include <stdlib.h>
#include <sys/msg.h>

int main(){

	msgctl(3, IPC_RMID, NULL);
	msgctl(4, IPC_RMID, NULL);

	exit(0);
}
