#include <stdio.h>

int iterate(int fnc(int,int),int tab[], int nb){
	if(nb < 0){
		return -1;
	} else if(nb == 0){
		return 0;
	} else if(nb == 1){
		return tab[0];
	} else {
		int res = fnc(tab[0], tab[1]);
		for(int i =2 ; i < nb; i++){
			res = fnc(tab[i], res);
			printf("%d \n",res);
		}
		return res;
	}
	
}

int fnc(int i, int j){
	return i + j;
}

int main(){
	int tableau[] = {1,2,3,4,5};
	printf("%d \n",iterate(fnc,tableau,5));
	return 0;
}