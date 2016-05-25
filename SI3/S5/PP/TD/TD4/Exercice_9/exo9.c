#include <stdio.h>
#include <stdlib.h>

typedef struct pile_elem {
int valeur;
struct pile_elem *suivant;
}pile_elem;

void push(pile_elem** top, int val){

	pile_elem* ptr = malloc(sizeof(pile_elem));
	ptr->valeur = val;
	ptr->suivant = *top;
	*top =ptr;
}

int peek(pile_elem* pile){
	return pile->valeur;
}

int pop(pile_elem* pile){
	int tmp = pile->valeur;
	*pile = *(pile->suivant);
	return tmp;

}

int main(){
	
	pile_elem * debut = NULL;
	push(&debut,3);
	push(&debut,4);
	push(&debut,5);

	int val = peek(debut);
	printf("%d \n",val);
	int i = pop(debut);
	printf("%d \n",i);

	 val = peek(debut);
	printf("%d \n",val);

	 i = pop(debut);
	printf("%d \n",i);

	 val = peek(debut);
	printf("%d \n",val);

	return 1;

}