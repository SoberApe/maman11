#include "header.h"

char peek();
void push(char);
char pop();

void ignoreCheck(char[],int);
int isOpenPar(char);
int isClosePar(char);
int isMatchPar(char,char);
int specialCheck(char[],int);

extern int comment;
extern int sp;
extern int specialCount;
extern int string;


int lineCheck(char line[])
{
	int i = -1;	
	int balanced = 1;
	int empty = 1;

	string = 0;

	do {	i++;
		
		if (isspace(current)) continue;

		ignoreCheck(line,i);
		
		if (comment || string) continue;
	
		if (empty && specialCheck(line,i))
			return 0;

		empty = 0;

		if (isOpenPar(current))
			push(current);

		if (isClosePar(current)){
			if (!isMatchPar(pop(),current))
				balanced = 0;
			}
				
	} while(balanced && current != EOF && current != '\n');	

	if (sp != specialCount){
		balanced = 0;
		sp = specialCount;
	}
		

	return balanced;
}

char stack[MAX_LINE_LEN] = {0};

char pop(){
	if (sp >0)
		return stack[--sp];
	else
		return 0;
}

void push(char item){
	if (sp < MAX_LINE_LEN)
		stack[sp++] = item;
	else
		printf("error: stack full\n");
}

char peek(){
	if (sp != 0)
		return stack[sp-1];
	return 0;
}

