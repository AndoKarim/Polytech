#include "table.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct t_table{
	char * elt;
	int nbAppartition;
	struct t_table* suiv;
}t_table;

char* my_strdup(char* s){
	char* result = malloc(strlen(s));

	return strcpy(result,s);
}

Table creer_table(void){
	return NULL;
}

void inserer_debut(Table* table, char * elt){
	struct t_table* ptr = malloc(sizeof(t_table));
	ptr->elt = elt;
	ptr->nbAppartition = 1;
	ptr->suiv = *table;
	*table = ptr;
}

void inserer_milieu(struct t_table *prev, char *id){
	struct t_table * ptr = malloc(sizeof(t_table));
	ptr->elt = my_strdup(id);
	ptr->nbAppartition = 1;
	ptr->suiv = prev -> suiv;
	prev->suiv = ptr;
}

int ajouter_table(Table *table, char *id){
	Table p,pp;
	for(pp=NULL,p=*table;p!=NULL && strcmp(p->elt,id)==-1;pp=p,p=p->suiv);
		if(p!=NULL && strcmp(p->elt,id)==0){
			return ++ (p->nbAppartition);
		}
		if(pp==NULL)
			inserer_debut(table,id);
		else
			inserer_milieu(pp,id);
		return 1;

	}

	void imprimer_table(struct t_table *table){
		while(table){
			printf("Element : %s Occurence : %d \n",table->elt,table->nbAppartition);
			table=table->suiv;
		}
	}