#contract makefile:

con: contract.o prog.o prompt.o
	gcc -g -Wall -ansi -pedantic prompt.o contract.o prog.o -o con

prog.o: prog.c header.h data.h
	gcc -c -Wall -ansi -pedantic prog.c -o prog.o

prompt.o: prompt.c data.h
	gcc -c -Wall -ansi -pedantic prompt.c -o prompt.o

contract.o: contract.c header.h data.h
	gcc -c -Wall -ansi -pedantic contract.c -o contract.o


