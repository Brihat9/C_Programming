#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int main(void)
{
    char str[161];
    int len, i, count;
    fflush(stdin);

    printf("Enter a sentence. (Max 160 characters) \n");
    gets(str);

    len = strlen(str);

    count = 0;
    for (i=1; i<=len; i++)
    {
        if((isspace(str[i]) || str[i]=='\0') && !(isspace(str[i-1])))
            count++;
    }

    printf("\n\n Number of words = %d", count);

    getch();
    return 0;
}
