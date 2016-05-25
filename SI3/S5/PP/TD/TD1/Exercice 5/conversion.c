#include <stdio.h>
#include <math.h>

main(){
float celsius;
float farhenheit;
int farheinInt;
	for(celsius=0; celsius<=20;celsius+=0.5){
		farhenheit=9*celsius/5+32;
		farheinInt=(int)rint(farhenheit); 
		printf("Celsius : %0.1f Fahrenheit : %d \n",celsius,farheinInt);

	}
}