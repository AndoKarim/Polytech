#include "hash.h"
#include <stdlib.h>
#include <string.h>

typedef struct cellule{
	char* id;
	void* info;
	struct cellule *suiv;

}cellule;


struct hash_table{
	struct cellule * *tab;
	int taille;
};



HashTable hash_new (int n){
	struct hash_table * ht  = malloc(sizeof(struct hash_table));
	ht->tab = malloc(sizeof(struct cellule*)*n);
	ht->taille = n;
	return ht;
}

int hash_value(char* k){
	int i=1;
	int n=0;
	while(*k!='\0'){
		n+=i*(*k);
		k++;
		i++;
	}
	return n ;
}

void * hash_find(const HashTable ht,const char * k){
	int i = hash_value(k) % ht->taille;
	struct cellule* ptr =ht->tab[i];
	while(ptr!=NULL){
		if(strcmp(k,ptr->id)==0)
			return ptr->info;
		ptr=ptr->suiv;
	}
	return NULL;
}

void hash_add(HashTable h, char *k, void* info){
	int i=hash_value(k)%h->taille;
	struct cellule * new = malloc(sizeof(struct cellule));
	new->id = strdup(k);
	new->info = info;
	new->suiv = h->tab[i];
	h->tab[i] = new;
}

