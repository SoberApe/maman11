#include "header.h"

void prompt();
void contract (char s1[],char s2[]);

int main()
{
    char s1[MAX_INPUT_LEN] ={0} , s2[MAX_INPUT_LEN] ={0};
    int i;

    prompt(); /* prompt user for input*/

    fgets(s1,MAX_INPUT_LEN,stdin); /* store input into s1 char array*/
    
    contract(s1,s2); /* call shortening function*/

    for (i=0; i < strlen(s2);i++) /*print s2*/
        printf("%c",s2[i]);
    return 1;
}


