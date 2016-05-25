#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <dirent.h>

#define BUFFERSIZE 256
#define FILENAMESIZE 256

int verbose=0;
int recursive=0;
int interactive=0;

int isRep(char *rep){
  struct stat sbuf;
  if (stat(rep,&sbuf)>=0){
      return S_ISDIR(sbuf.st_mode);
  }
  return 0;
}

char *repertoire(char *buffer,char *rep,char *fichier){
  strcpy(buffer,rep);
  strcat(buffer,"/");
  strcat(buffer,fichier);
  return buffer;
}


int copieFichier(char *source, char *destination){
  int fdin,fdout;
  int n;
  char buffer[BUFFERSIZE];
  char src2[BUFFERSIZE];
  char dest2[BUFFERSIZE];
  struct stat statbufdest;
  struct stat statbufsour;
  int oldmask;

  if (verbose==1){
    printf("Copier %s vers %s\n",source,destination);
  }

  strcpy(src2,source);
  strcpy(dest2,destination);

  if (isRep(dest2)){
      repertoire(dest2,dest2,basename(src2));
  }

  if (interactive==1 && stat(dest2,&statbufdest)!=-1){
      if (S_ISDIR(statbufdest.st_mode)){
	  fprintf(stderr,"Ne peut effacer le repertoire %s par un autre type.\n",dest2);
	  return -1;
      }
      fprintf(stderr,"Ecraser %s ? (Y/N)\n",dest2);
      switch(getchar()){
	  case 'N':
	  case 'n':
	    return 0;
      }
  }

  if ((fdin=open(src2,O_RDONLY))==-1){
      perror("open");
      return -1;
  }

  if (stat(src2,&statbufsour)==-1){
    perror("stat");
    close(fdin);
    return -1;
  }

  oldmask=umask(0);
  if ((fdout=open(dest2,O_WRONLY|O_CREAT|O_TRUNC,statbufsour.st_mode))==-1){
      perror("open");
      close(fdin);
      return -1;
  }
  umask(oldmask);
  
  while((n=read(fdin,buffer,BUFFERSIZE))>0){
    if(write(fdout,buffer,n)==-1){
      perror("write");
      close(fdin);
      close(fdout);
      return -1;
    }
  }
  if (n==-1){
    perror("read");
    close(fdin);
    close(fdout);
    return -1;
  }
  close(fdin);
  close(fdout);
  return 0;
}


int copieRep(char *source, char *destination){
  struct dirent *direntbuf;
  struct stat statbufsour;
  struct stat statbufdest;
  DIR *rep;
  char tmp[BUFFERSIZE];
  char tmp2[BUFFERSIZE];
  char src2[BUFFERSIZE];
  char dest2[BUFFERSIZE];
  int oldmask;
  
  strcpy(src2,source);
  strcpy(dest2,destination);

  if ((rep = opendir(src2)) == NULL){
      perror("opendir");
      return -1;
  }
  
  if (stat(src2,&statbufsour)==-1){
      perror("stat");
      closedir(rep);
      return -1;
  }

  if (stat(dest2,&statbufdest)==-1){
      oldmask = umask(0);
      mkdir(dest2, statbufsour.st_mode);
      umask(oldmask);
  }
  else{
      oldmask = umask(0);
      mkdir(repertoire(dest2,dest2,basename(src2)), statbufsour.st_mode);
      umask(oldmask);
  }


  while ((direntbuf = readdir(rep)) != NULL){
      if (strcmp(direntbuf->d_name, ".")!=0 && strcmp(direntbuf->d_name, "..")!=0){
	  if (isRep(repertoire(tmp,src2,direntbuf->d_name))){
	      copieRep(repertoire(tmp, src2,direntbuf->d_name),repertoire(tmp2,dest2,direntbuf->d_name));
	  }
	  else{
	      copieFichier(repertoire(tmp,src2,direntbuf->d_name),dest2);
	  }
      }
  }
  
  closedir(rep);
  return 0;
}


void messageErreur(char *name){
  fprintf(stderr,"Utiliser:\n");
  fprintf(stderr,"%s fichier1 fichier2\n",name);
  fprintf(stderr,"%s fichier1 [fichier2 ...fichierN] repertoire\n",name);
}

int main(int argc,char **argv){
  int i;
  int c;
  opterr=0;
  
  while ((c=getopt(argc,argv,"vri"))!=-1){
      switch(c){
	  case 'v':
	    verbose=1;
	    break;
	  case 'r':
	    recursive=1;
	    break;
	  case 'i':
	    interactive=1;
	    break;
	  case '?':
	    messageErreur(argv[0]);
	    return -1;
	  default:
	    abort();
      }
  }
  

  if (argc-optind<2){
      messageErreur(argv[0]);
      return -1;
  }
  if (argc-optind>2 && !isRep(argv[argc-1])){
      fprintf(stderr,"%s n'est pas un répertoire.\n",argv[argc-1]);
      return -1;
  }
  for(i=optind;i<argc-1;i++){
    if (isRep(argv[i])){
	  if (recursive==1){
	      return copieRep(argv[i],argv[argc-1]);
	  }
	  else{
	      fprintf(stderr,"Impossible de copier un repertoire.\n");
	  }
    }
      else{
	  return copieFichier(argv[i],argv[argc-1]);
      }
  }
  return 0;

}	
