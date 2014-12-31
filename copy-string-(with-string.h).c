#include <stdio.h>
#include <conio.h>
#include <string.h>

char* getstr(char* string, int size, FILE* file);

int main(void) {
    char string[100]; int i;
    gets(string);
    int len = strlen(string);

    char* copied = malloc((len+1) * sizeof(*copied));

    strcpy(copied, string);

    for (i=0; i<=len; i++) {
        printf("\n  copied[%d] = %c (%3d) ", i, copied[i], copied[i]);
    }

    getch();
    free(copied); return 0;
}
