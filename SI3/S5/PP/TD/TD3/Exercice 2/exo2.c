#include <stdio.h>

void en_binaire(int n){
	if(n==0){
		printf("%d",n);
		return;
	}
	en_binaire(n>>1);

	printf("%d", n & 1);
}

int main(){
	en_binaire(10);
	printf("\n");

}