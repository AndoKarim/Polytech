#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * mystrcpy(char * dest, const char* src){
	int i;
	for(i=0;i<strlen(src);i++){
		dest[i]=src[i];
	}
	return dest;
}

size_t myStrlen(const char *s){
	int compteur=0;
	while(*s){
		compteur++;
	}
	return compteur;
}

char* myStrdup(const char* s){
	char* copy = malloc((strlen(s)+1)*sizeof(char));
	strcpy(copy,s);
	return copy;
}

char * myStrchr(const char* s, int c){

}



int main(){
	char* source = "abc";
	char* destination=malloc((strlen(source)+1)*sizeof(char));
	destination=mystrcpy(destination,source);

	printf("%d \n",myStrlen(destination));
	printf("%s \n",myStrdup(source));
}