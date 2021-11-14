#include <stdio.h>
#include "data.h"

void prompt(){
	printf(INPUT_PROMPT);
	printf(OUTPUT_PROMPT);
	printf(REQUEST_PROMPT);
}

void promptLine(int bal){
	if (bal){
		printf("balanced     :  ");
		return;}
	printf("unbalanced   :  ");	
}

void promptText(int bal){
	printf("\n******************************\n");
	if (bal)
		printf("**  Text is balanced.       **\n");
	else
		printf("**  Text is Unbalanced.     **\n");
	printf("******************************\n");
		
}


