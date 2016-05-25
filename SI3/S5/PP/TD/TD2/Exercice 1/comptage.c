#include <stdio.h>
#include <ctype.h>

int main(){ 
	int i, c;
	int occAlpha[26]={0};
	int occNum[10]={0};
	c = getchar();

	while (c != EOF) {
		if(isdigit(c)){
			occNum[c-'0']++;
		}else{
			occAlpha[c-'a']++;
		}
		c = getchar();
	}
	for(i=0;i<26;i++){
		printf("nombre de lettre %c : %d \n", (char)i+'a',occAlpha[i]);
	}
	for(i=0;i<10;i++){
		printf("nombre de chiffres %c : %d \n",(char) i+'0',occNum[i]);

	}
	printf("\n");
	return 0;
}