#include <stdio.h>

main(){
	int a=1;
	int count = 0;
	scanf("%d",&a);
	while(a>0){	
		count++;
		scanf("%d",&a);
	}
	printf("You entered %d positiv integers \n",count);
		
}