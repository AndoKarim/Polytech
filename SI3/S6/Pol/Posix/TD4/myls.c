//
// Created by karim on 21/03/16.
//

#include <time.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>


void myls(char* path){
    DIR* rep = NULL;

    rep = opendir(path);

    if(rep == NULL);
        exit;

    struct dirent * direntRead = readdir(rep);

    printf("%s \n",direntRead->d_name);
    printf("%s",strcat(strcat(path,"/"),direntRead->d_name));

    if(direntRead->d_type==DT_DIR){
    	myls(direntRead->d_name);

	}
}


void main(int argc, char * argv[]){
	myls("/home/karim");
}