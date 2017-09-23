progetto_2016: lib_num_complessi.o progetto_2016.o Makefile
	gcc -ansi -Wall -O lib_num_complessi.o progetto_2016.o -o progetto_2016 -lm

lib_num_complessi.o: lib_num_complessi.c lib_num_complessi.h Makefile
	gcc -ansi -Wall -O -c lib_num_complessi.c

progetto_2016.o: progetto_2016.c lib_num_complessi.h Makefile
	gcc -ansi -Wall -O -c progetto_2016.c

pulisci:
	rm -f lib_num_complessi.o progetto_2016.o

pulisci_tutto:
	rm -f progetto_2016 lib_num_complessi.o progetto_2016.o
