#include <stdio.h>
void main(void)
{
    char string[100], copied[100];
    int i;
    printf("Enter a string : \n");
    gets(string);

    for (i=0; string[i-1] != '\0'; i++)
        copied[i] = string[i];

    printf("\nYou entered: \n%s\n\n", copied);
    getch();
}
