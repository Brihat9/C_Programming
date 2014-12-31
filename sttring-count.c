#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int main(void)
{
    char str[150];
    int len, i, words;
    printf("Enter a sentence :");
    gets(str);
    len = strlen(str);
    words = 0;
    for (i=1; i<=len; i++)
    {
        if((isspace(str[i]) || str[i]=='\0') && !(isspace(str[i-1])))
            words++;
    }
    printf("\n\n Number of words = %d", words);
    getch();
    return 0;
}
