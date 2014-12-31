#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n[5], i, j, tmp;

    for (i=0;i<5;i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d",&n[i]);
    }

    for (i=0;i<5;i++)
    {
        for (j=i+1;j<5;j++)
        {
            if (n[i]>n[j])
            {
                tmp = n[i];
                n[i] = n[j];
                n[j] = tmp;
            }
        }
    }
printf("the numbers in ascending order is \n");
    for (i=0;i<5;i++)
    {
        printf("%d\n", n[i]);
    }

printf("the numbers in decending order is \n");
for (i=4;i>=0;i--)
    {
        printf("%d\n", n[i]);
    }


    getch();
    return 0;
}
