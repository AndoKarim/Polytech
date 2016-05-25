#include <stdio.h>

int main (int argc, char* argv[]){
	int c;
	int paramE=0;
	int paramN=0;
	int i=1;
	printf("%d",i);
	int j=0;
	for(j=0;j<argc;j++){
		if(argv[j][2]=='E')
			paramE=1;
		if(argv[j][2]=='n')
			paramN=1;
	}

	while((c=getc(stdin))!=EOF)	{
		if(c=='\n' && paramE==1){
			printf("$");
			i++;
		}
		putchar(c);
		if(c=='\n' && paramN==1)
			printf("%d",i);
	}




}