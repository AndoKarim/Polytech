#include "hash.h"

int main(){
	HashTable h = hash_new(4);
	hash_find(h,"toto");
	return 1;

}  