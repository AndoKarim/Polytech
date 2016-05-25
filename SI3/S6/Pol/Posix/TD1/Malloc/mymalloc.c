
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "mymalloc.h"
#include "mymalloc_impl.h"


/*
    Fichier à compléter avec votre implémentation de mymalloc() et myfree().
*/

static struct Header base = {0,&base};

static struct Header *pfree = &base;

void *mymalloc(size_t sz){

	size_t nb = 2 + (sz - 1) / HEADER_SZ;
	struct Header *ptrh = (struct Header *)ptr-1;
	struct Header *phprev,*ph;

	for(phprev = pfree, ph = pfree->next ;; phprev = ph, ph = ph -> next){
		if(ph->next >= nb)
		{
			if(ph->nheaders == nb){
				phprev->next = ph->next;
			}
		}
		else{
			ph->nheaders -=nb;
			ph += ph -> nheaders;
			ph->nheaders = nb;
		}
		return ph+1;
	}
	if(ph==pfree){
		if((ph = system_alloc(nb))==NULL){
			return  NULL;
		}
	}

	
			//Retirer de la liste libre

    // Remplacer la ligne suivante par votre propre code
    return malloc(sz);
}

void myfree(void *ptr)
{
	
		for(phprev = pfree, ph = pfree->next ;; phprev = ph, ph = ph -> next){

}

extern void* system_alloc(size_t nbBlocs){

	size_t nbOctets = 2+(nbBlocs-1)/MINSYSTBLOCK;
	struct Header * bloc; 
	int freemem;


	if(nbOctets<MINSYSTBLOCK){
		freemem = MINSYSTBLOCK;
		bloc=sbrk(freemem);
	}
	else{
		freemem = ((nbOctets/MINSYSTBLOCK)+1)*MINSYSTBLOCK;
		bloc=sbrk(freemem);
	}
	bloc->nheaders=freemem;

	myfree(bloc+1);
	return bloc;
}

void mymalloc_instrum(){
    // Mettre ici votre propre code
}
