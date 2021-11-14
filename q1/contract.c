#include "header.h"

void contract (char s1[],char s2[])
{
    int i = 0; /* index over s1*/
    int len = 0; /* length of consecutive letters in substring*/
    int offset = 0; /*entry offset to s2 for chars off s1*/

    while (s1[i] != '\0')
    {
        s2[i+offset] = s1[i];

        if (isalnum(s1[i]) && s1[i]+1==s1[i+1]) /* check if letter is alpha-numeric (standard lib function), and then check if next letter in string is following ascii value*/
            len++; 
        else  /* subsequent letters streak broke*/
            len = 0;

        if (len == MIN_LEN_SHORT) /* subsequent letters streak reach 2, replace the middle letter with '-' */
            s2[i+offset] = '-';
        else if (len > MIN_LEN_SHORT) /* for every additional subsequent char, reduce offset by 1 so that chars being copied from s1 to s2, replace the char symbolizing the end of the shortcut*/
            offset -= 1;
        i++; /* next letter*/
    }  
    /*s2[i+offset] = EOF; /* add end of file symbol in correct place in s2 */
}
