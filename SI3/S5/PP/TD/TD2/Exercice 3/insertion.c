#include <stdio.h>



void insertion(int tab[], int nbVal, int val){	
	int i;	
	for (i = nbVal-1; i >= 0; i--) {
		if(tab[i] > val){
			tab[i+1] = tab[i];	
		}	
	}	
	tab[i+1] = val;
}



int main(){
	int nb = 4;
	int tab[5]={0,2,3} ;

	insertion(tab,nb,1);
	
	int i;
	for(i = 0 ; i<nb ; i++){
		printf("%d \n",tab[i]);	
	}
	return 0 ;
}