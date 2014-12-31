#include <stdio.h>
#include <conio.h>

int main(void) {
    char string[100], copied[100]; int i, len;

    printf("Enter a string : \n");
    fflush(stdin);
    gets(string);

    for (i=0; string[i] != '\0'; i++)
        copied[i] = string[i];
    copied[i] = '\0';

    printf("%s", copied);

    getch();
    return 0;
}
