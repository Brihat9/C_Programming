#include<string.h>
#include<ctype.h>
#include<conio.h>
void main (void)
{
    int i,j,n,k,l,m;
    char arr[9]="PULCHOWK";
    n=strlen(arr);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(((i%2)==0) && ((j%2)==1))
            {
                arr[j]=tolower(arr[j]);
            }
            putchar(arr[j]);
            arr[j]=toupper(arr[j]);
        }
        putchar('\n');
    }
    getch();
}
