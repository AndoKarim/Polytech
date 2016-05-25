#include <stdio.h>

main(){
	int a=1;
	int sum = 0;
	int max;
	scanf("%d",&a);
	max=a;
	while(a>0){	 ca-
		sum+=a;
		scanf("%d",&a);
		if(a>max){
			max=a;
		}
	}
	printf("The bigger number is %d and the sum = %d \n",max,sum);
		
}