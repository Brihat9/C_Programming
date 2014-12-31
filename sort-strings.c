#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void swapstr(char* str1, char* str2);

int main(void) {
    int n, i, j;
    printf("How many strings? ");
    scanf("%d", &n);
    fflush(stdin);

    char** str = malloc(n * sizeof(*str));
    for (i=0; i<n; i++)
        str[i] = malloc(51 * sizeof(*str[i]));

    printf("\n");
    for (i=0; i<n; i++)
    {
        printf("Enter string %d : ", i+1);
        gets(str[i]);
    }

    for (i=0; i<n; i++)
        for (j=i; j<n; j++)
            if (strcmpi(str[j], str[i]) < 0)
            {
                swapstr(str[i], str[j]);
            }

    printf("\nASCENDING ORDER : ");
    for (i=0; i<n; i++)
        printf("\n %2d. %s ", i+1, str[i]);

    getch();

    for (i=0; i<n; i++)
        free(str[i]);
    free(str);
    return 0;
}

void swapstr(char* str1, char* str2) {
    char temp[51];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
