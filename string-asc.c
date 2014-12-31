#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define L 15

void main(void)
{
        int n,i,j,k;
        printf("Enter no. of string : ");
        scanf("%d",&n);
        char **s = malloc(n * sizeof(*s));
            for (i=0; i<n; i++)
                s[i] = malloc(L * sizeof(*s[i]));
        for(i=0;i<n;i++)
        {
            printf("Enter string %d :",i+1);
            scanf("%s",s[i]);
        }
        for (i=0; i<n; i++)
            for (j=i; j<n; j++)
            {
                k=strcmp(s[i], s[j]);
                if (k>0)
                {
                    char temp[L];
                    strcpy(temp, s[i]);
                    strcpy(s[i], s[j]);
                    strcpy(s[j], temp);
                }
            }
        printf("\nASCENDING ORDER : ");
        for (i=0; i<n; i++)
            printf("\n %2d. %s ", i+1, s[i]);
        for (i=0; i<n; i++)
            free(s[i]);
        free(s);
        getch();
}
