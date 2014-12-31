#include<stdio.h>
#include<conio.h>
void main (void)
{
    int i=0,j=0,n;
    do
    {
        printf("\nEnter any positive number : ");
        scanf("%d",&n);
        if(n<0)
        {
            printf("Wrong Input. This no. will not be counted.\n");
        }
        else if(n>0)
        {
            if(n%2==0)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }while(n!=0);
    printf("\nTotal even numbers entered : %d",i);
    printf("\nTotal odd numbers entered : %d",j);
    getch();
}
