#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char text[101], temp[101], current;
    int i, c;

    printf("Enter a string. (max 100 chars) \n");
    fflush(stdin);
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
                break;
            default:
                temp[c++] = text[i];
                break;
        }
    }

    strcpy(text, temp);

    // to cocantenate two strings (ie merge them) use the strcat() function
    // its syntax is:
    //     strcat(string1, string2);
    // it will add the contents of string2 at the end of string1

    printf("\n\n%s", text);

    getch();

    return 0;
}
