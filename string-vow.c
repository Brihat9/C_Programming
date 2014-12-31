#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void main(void)
{
    char text[101], twov[101];
    int i, c;
    printf("Enter a string :");
    gets(text);
    c=0;
    for (i=0; i<=strlen(text); i++)
    {
        switch(toupper(text[i]))
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                continue;
            default:
                twov[c++] = text[i];
        }
    }
    printf("\nText without vowel:\n%s", twov);
    getch();
}
