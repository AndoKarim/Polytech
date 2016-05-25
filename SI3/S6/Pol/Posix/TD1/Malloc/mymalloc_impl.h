#ifndef _MYMALLOC_IMPL_H_
#define _MYMALLOC_IMPL_H_


struct Header {
	size_t nheaders; //taille en nombre d'en-têtes
	struct Header *next; //liste des blocs libres
};

#define HEADER_SZ sizeof(struct Header)
#define MINSYSTBLOCK 64*HEADER_SZ


/*
Mettez ici toutes les information dont mymalloc.c a besoin mais qui n'ont pas à
être visible du code "client (main_mymalloc*.c).
*/

#endif

