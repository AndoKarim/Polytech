#include <stdio.h>

int main(int argc, char* argv[]){
	argv++;
	while(*argv != NULL && argv[0][0]=='-'){
		if(argv[0][1]!='-')
			printf("Option courte : %s \n",*argv);
		else if(argv[0][2]=='\0')
			break;
		else
		printf("Option longue : %s \n",*argv);
		argv++;
	}
	while(*argv){
		printf("Argument : %s \n",*argv);
		argv++;
	}

}