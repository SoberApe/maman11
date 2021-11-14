#par makefile:

par: par.o  prompt.o linecheck.o charchecks.o
	gcc -g -Wall -ansi -pedantic prompt.o par.o linecheck.o charchecks.o -o par

par.o: par.c prompt.o linecheck.o header.h data.h
	gcc -c -g -Wall -ansi -pedantic par.c  -o par.o

prompt.o: prompt.c data.h
	gcc -c -g -Wall -ansi -pedantic prompt.c -o prompt.o

linecheck.o: linecheck.c charchecks.o header.h
	gcc -c -g -Wall -ansi -pedantic linecheck.c -o linecheck.o

charchecks.o: charchecks.c data.h
	gcc -c -g -Wall -ansi -pedantic charchecks.c -o charchecks.o 




