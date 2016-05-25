#include <stdio.h>

main(){
	int c;
	int count=1;
	printf("%d.",count);
	c = getchar();
	while (c != EOF) {
		if(c=='\n'){
			count++;
			putchar(c);
			printf("%d.",count);
			
		}else{
			putchar(c);
		}
		c = getchar();
	}
	putchar('\n');

}