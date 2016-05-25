#include <stdio.h>


void ligne(char ligne[], int lg)
{
  int j;

  for (j = 0; j <16 ; j++) {
    if (j < lg)
      printf("%02x ", (unsigned char) ligne[j]);
    else
      printf("    ");
  }

  for (j = 0; j < lg; j++) {
    char c = ligne[j];

    printf("%c", (' ' <= c && c <= '~') ? c: '.');
  }
  printf("\n");
}


int main()
{
  int c, i = 0;
  char ligne[16];

  while ((c = getchar()) != EOF) {
    ligne[i++] = c;
    if (i == 16) {
      ligne(ligne, i);
      i = 0;
    }
  }

  if (i != 0) ligne(ligne, i);

  return 0;
}