#include "header.h"

extern int comment;
extern int string;
extern int specialCount;
extern int specialFlag;
extern int sp;

int isOpenPar(char c){
	return (c == '(' || c == '{' || c == '[');
}

int isClosePar(char c){
	return (c == ')' || c == '}' || c == ']');
}

int isMatchPar(char c1, char c2){
	switch (c1){
	case '(':
		return (c2 == ')');
	case '{':
		return (c2 == '}');
	case '[':
		return (c2 == ']');
	default:
		return 0;} 
}


void ignoreCheck(char line[],int i){
	/*Testing for ignore*/
	if ((!string) && (i < MAX_LINE_LEN-1)){
		/*Testing for comment start/end*/
		if (comment){
			/*Testing for comment end*/
			if (current == '*' && next == '/'){
				/*comment end*/
				comment = 0;
			}
		}
		else {
			/*testing for comment start*/
			if (current == '/' && next == '*'){
				/*comment start*/
				comment = 1;
			}
		}
	}
	if (!comment) {
		/*testing for string start/end*/
		if (string){
			/*testing for string end*/
			if (current == '"'){
				/*string end*/
				string = 0;
			}
		}
		else {
			/*testing for string start*/
			if (current == '"'){
				/*string start*/
				string = 1;
			}
		}
	}
}

int specialCheck(char line[],int i){
	int empty = 1;
	if (current == '{' || current == '}'){
		while (line[++i])
			empty *= isspace(current);
		i = 0;
		if (empty){
			specialFlag = 1;
			if (isOpenPar(current)){
				specialCount++;
				sp++;
			}
			else if (isClosePar(current)){
				if (sp == 0){
					specialFlag = 0;
					return 1;
				}
				else
					specialCount--;
					sp--;
			}
		}
	}
	
	return specialFlag;
}







