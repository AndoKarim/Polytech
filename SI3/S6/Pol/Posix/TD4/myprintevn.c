//
// Created by karim on 21/03/16.
//

#include <stdio.h>
#include <string.h>

extern char **environ;

void myprintenv(char* var){
    int i =0 ;

    while(environ[i]!=NULL){
        if(strncmp(var,environ[i],strlen(var))==0) {
            printf("%s \n", environ[i]);
            break;
        }
        i++;
    }
}

void main(int argc, char* argv[]){
    if(argv[1]!=NULL) {
        int i;
        for(i = 0; i < argc ; i++){
            myprintenv(argv[i]);
        }
    }
}