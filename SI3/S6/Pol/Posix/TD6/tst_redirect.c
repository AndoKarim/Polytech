#include <unistdh.h>

int main(){
	int fd = open("out",O_WRONLY|O_CREATE,0666);

	switch(fork()){
		case -1 : 
			printf("Erreur fork");
			break
		case 0 : 
			printf("On est dans le fils");
			dup(1,2);
			dup2(fd,1);
			execlp("/bin/ls","ls","A B foo bar",NULL);
			break;

		default : 
			printf("On est dans le père");
			break;
	}
}