table_exe : table_liste.o main.c
	gcc -Wall table_liste.o main.c -o main

table_liste.o : table_liste.c table.h
	gcc -Wall table_liste.c -c

clean : 
	rm -f *.o *.~