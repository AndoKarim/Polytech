#include <unistdh.h>

int main(){

	int fd[2]; 
	switch(fork()){
		case -1 : 
			printf("Erreur fork");
			break
		case 0 : 
			printf("On est dans le fils");
			
			break;

		default : 
			printf("On est dans le père");
			break;
	}
}