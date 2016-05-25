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

/*
*-------------------------------------------------
*Permet de verifier si le paramétre de la fonction est un répertoire
*-------------------------------------------------
*/
int is_Dir(char *rep){
  struct stat sbuf;

  //IsDir
  if (stat(rep,&sbuf)>=0){
    return S_ISDIR(sbuf.st_mode);
  }
  //IsNotDir
  return 0;
}


/*
*-------------------------------------------------
*Permet de renvoyer le chemin ou va être copié le fichier avec 
*le rep dans le nom.
*-------------------------------------------------
*/
char *repertoire(char *buffer,char *rep,char *fichier){
  strcpy(buffer,rep);
  strcat(buffer,"/");
  strcat(buffer,fichier);
  return buffer;
}

/*
*-------------------------------------------------
*Copie un fichier dans la destination
*-------------------------------------------------
*/
int copieFichier(char *source, char *destination){
  int fdin,fdout;
  int n;
  char buffer[BUFFERSIZE];
  char src2[BUFFERSIZE];
  char dest2[BUFFERSIZE];
  struct stat statbufsour;
  int oldmask;

  if (verbose==1){
    printf("Copier %s vers %s\n",source,destination);
  }

  strcpy(src2,source);


  //Si la destination est un repertoire on copie bien dans le rep
  if (is_Dir(destination)){
    repertoire(dest2,destination,basename(src2));
  }


//Si le fichier à copier est un répertoire
if (stat(src2,&statbufsour)==-1){
  perror("stat");
  close(fdin);
  return -1;
}

//On sauvegarde les permissions
oldmask=umask(0);

//On ouvre le dossier de destination
if ((fdout=open(dest2,O_WRONLY|O_CREAT|O_TRUNC,statbufsour.st_mode))==-1){
  perror("open");
  close(fdin);
  return -1;
}

//On retablit les permissions
umask(oldmask);

//On lit dans le fichier octect par octet
while((n=read(fdin,buffer,BUFFERSIZE))>0){
  //On copie dans la destination
  if(write(fdout,buffer,n)==-1){
    perror("write");
    close(fdin);
    close(fdout);
    return -1;
  }
}

//Si erreur de lecture
if (n==-1){
  perror("read");
  close(fdin);
  close(fdout);
  return -1;
}


return 0;
}

/*
*-------------------------------------------------
*Copie le contenue d'un rep (source) dans un rep (destination)
*-------------------------------------------------
*/
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


  //On regarde si la source est valide
  if (stat(src2,&statbufsour)==-1){
    perror("stat");
    return -1;
  }

  //On ouvre le dossier source
  if ((rep = opendir(src2)) == NULL){
    perror("opendir");
    return -1;
  }

  //Si le dossier destination n'existe pas on le crée
  if (stat(dest2,&statbufdest)==-1){
    oldmask = umask(0);
    mkdir(dest2, statbufsour.st_mode);
    umask(oldmask);
  }

  //Sinon on le créé
  else{
    oldmask = umask(0);
    mkdir(repertoire(dest2,dest2,basename(src2)), statbufsour.st_mode);
    umask(oldmask);
  }


  //On parcours le répertoire source
  while ((direntbuf = readdir(rep)) != NULL){
    if (strcmp(direntbuf->d_name, ".")!=0 && strcmp(direntbuf->d_name, "..")!=0){
      //Si il y a un repertoire on appel recursivement la fonction pour pouvoir copier son contenu
     if (is_Dir(repertoire(tmp,src2,direntbuf->d_name))){
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



int main(int argc,char **argv){
  int i;
  int c;
  opterr=0;
  
  while ((c=getopt(argc,argv,"vri"))!=-1){
    switch(c){
     case 'v':
     verbose = 1;
     break;
     case 'r':
     recursive=1;
     break;
     default:
     abort();
   }
 }


  //Si le dernier argument n'est pas un repertoire
if (argc-optind>2 && !is_Dir(argv[argc-1])){
  fprintf(stderr,"%s n'est pas un répertoire\n",argv[argc-1]);
  return -1;
} 

for(i=optind;i<argc-1;i++){
    //Si on est dans un repertoire 
  if (is_Dir(argv[i])){
      //-r dans les paramètres
    if (recursive==1){
      copieRep(argv[i],argv[argc-1]);
   }
   else{
     fprintf(stderr,"Impossible de copier un repertoire.\n");
   }
 }
    //Sinon on copie le fichier dans le rep de destination
 else{
   copieFichier(argv[i],argv[argc-1]);
}
}
return 0;

}   
