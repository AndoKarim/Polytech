#include <stdio.h>

main(){	
	int c,comptChar=0,comptWord=0,comptLine=0;
	int word=0;
	while((c=getchar())!= EOF){
		comptChar++;
		if(c!='\n' && c!=' ' && c!='\t'){
			word=1;	
		}
		else{
			if(word==1){
				word=0;
				comptWord++;
			}
		}
		if(c=='\n'){
			comptLine++;
		}
	}
	printf("Nombre de caractères : %d \n",comptChar);
	printf("Nombre de mots : %d \n",comptWord);
	printf("Nombre de lignes : %d \n",comptLine);
}