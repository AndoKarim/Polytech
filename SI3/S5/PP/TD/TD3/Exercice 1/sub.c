#include <stdio.h>
#include <string.h>

int isSubstr(char s[], char ss[], int i ){
	for(int j = 0; i<strlen(s) && j<strlen(ss); i++){
		if(s[i]!=ss[j])
			return 0;
		j++;
	}
	return 1;

}

int strStr(char s[], char ss[]){
	for(int i =0 ; i<strlen(s) ; i++){1
		if(isSubstr(s,ss,i)==1)
			return 1;
	}
	return 0;

}


void main(int argc, char *argv[]){


	char a[] = "abc123";
	char b1[] = "123";
	char b2[] = "bc1";
	char b3[] = "c1";
	char b4[] = "xyz";

	printf("is %s contained in %s at rank 3 = %d \n",b1,a,isSubstr(a,b1,3));
	printf("is %s contained in %s at rank 3= %d \n",b4,a,isSubstr(a,b4,3));
	printf("is %s contained in %s = %d \n",b1,a,strStr(a,b1));
	printf("is %s contained in %s = %d \n",b4,a,strStr(a,b4));
	printf("is %s contained in %s = %d \n",b2,a,strStr(a,b2));
	printf("is %s contained in %s = %d \n",b3,a,strStr(a,b3));




}