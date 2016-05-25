#include <stdarg.h>
#include <stdio.h>

void catStrings(char *str1, ...){
	va_list ap;
	va_start(ap,str1);

	while(str1 !=NULL){
		printf("%s \n",str1);
		str1 = va_arg(ap, char*);
	}	
	va_end(ap);
}

void myPrintf(char *format,...){
	va_list ap;
	va_start(ap,format);
	int c;
	char* s ; 

	while(*format !='\0'){
		if(*format != '%'){
			putchar(*format);
		}
		else switch(*++format){
			case '%' : 
				putchar('%');
				break;
			case 'c' : 
				c= va_arg(ap,int);
				putchar(c);
				break;

			case 'd' : 
				afficher_base_10(va_arg(ap,in)){
				break;

			case 's' : 
				s=va_arg(ap,char*);
				break;
		}
		format++;
	}	
	va_end(ap);
}

void afficher_base_10(int n){
	if(n==0)return;
	afficher_base_10(n/10);
	putchar(n%10+'0');
}

int main(){

	//catStrings("Salut","Bonjour","Yes", NULL);
	myPrintf("toto %c \n",'a');
}