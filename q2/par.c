#include "header.h"

void prompt();
void promptLine(int);
void promptText(int);
int lineCheck(char[]);

int comment;
int specialFlag;
int specialCount;
int sp;
int string;

int main(){
	/*declarations.*/
	char line[MAX_LINE_LEN] = {0};
	int balanced = 1;
	int lineBal = 1;
	comment = 0;
	specialFlag = 0;
	sp = 0;

	/* prompt user for input*/
	prompt();

	/* take input from user*/
	while (fgets(line,MAX_LINE_LEN,stdin) != 0){
		specialFlag = 0;
		string = 0;

		lineBal = lineCheck(line);

		promptLine(lineBal); /* print line balance*/
		printf("%s",line); /*print line*/

		balanced =  balanced & (lineBal | specialFlag) & (specialCount == sp);
		
	}
	
	/* when reach EOF, print summary*/
	promptText(balanced);
	return balanced;
}
