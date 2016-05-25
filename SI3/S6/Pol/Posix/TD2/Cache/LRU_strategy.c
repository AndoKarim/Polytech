#include <assert.h>
#include "strategy.h"
#include "low_cache.h"
#include "cache_list.h"

#define CAST_LIST(cache) (struct Cache_List *) cache->pstrategy

void *Strategy_Create(struct Cache *pcache) 
{
    return Cache_List_Create();
}

void Strategy_Close(struct Cache *pcache)
{
	Cache_List_Delete(CAST_LIST(pcache));
}

void Strategy_Invalidate(struct Cache *pcache)
{
    Cache_List_Clear(CAST_LIST(pcache));
}

struct Cache_Block_Header *Strategy_Replace_Block(struct Cache *pcache) 
{
    struct Cache_Block_Header *pbh;
    struct Cache_List* list = CAST_LIST(pcache);

    /* On cherche d'abord un bloc invalide */
    if ((pbh = Get_Free_Block(pcache)) != NULL) {
    	Cache_List_Append(list, pbh);
    	return pbh;
    }

    /* Sinon on tire on retire le bloc qui est le plus "vieux" de ceux de la liste, celui qui a été inséré en premier */
    pbh = Cache_List_Remove_First(list);
    Cache_List_Append(list, pbh);
    
    return pbh;
}

void Strategy_Read(struct Cache *pcache, struct Cache_Block_Header *pbh) 
{
    Cache_List_Move_To_End(CAST_LIST(pcache),pbh);
}  

void Strategy_Write(struct Cache *pcache, struct Cache_Block_Header *pbh)
{
    Cache_List_Move_To_End(CAST_LIST(pcache),pbh);

} 

char *Strategy_Name()
{
    return "FIFO";
}