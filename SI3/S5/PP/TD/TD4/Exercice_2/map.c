#include <stdio.h>

void map(void fnc(int), int tab[],int taille){
 int i;

  /* Appliquer la fonction f à chaque élément du tableau */
  for (i = 0; i < taille; i++)
    fnc(tab[i]);
}

void plus4(int k){
	printf("%d \n", k+4);
}

int main(){
	int tableau[]={1,2,3,4,5};
	map(plus4, tableau, 5);
	return 0;


}

