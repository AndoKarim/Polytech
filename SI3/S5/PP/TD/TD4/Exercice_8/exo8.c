#include <stdlib.h> 
#include <stdio.h>
#define TBLOC 5
int main(){
	int taille = TBLOC;
	int c, i =0;
	char* t = malloc(TBLOC);
	while((c=getchar())!=EOF){
		if(i>=taille-1){
			taille+=TBLOC;
			t=realloc(t,taille);
			printf("realloc fait");
		}
		t[i]=c;
		i++;
	}
	t[i]='\0';
	printf("%s",t);
}