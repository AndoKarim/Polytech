#include <stdio.h>

main(char* argv, int argc){
	printf("Veuillez entrer une valeur \n");
	int a;
	scanf("%d",&a);
	if(a>=0)
		printf("%d \n",a);
	}else{
		printf("%d \n",-a);  
	}
}