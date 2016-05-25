#include "table.h"
#include <stdio.h>

int main(){
	Table t;
	t=creer_table();
	ajouter_table(&t, "hello");
	ajouter_table(&t,"abc");
	ajouter_table(&t,"abc");
	ajouter_table(&t,"robo");
	imprimer_table(t);
	return 1;
}