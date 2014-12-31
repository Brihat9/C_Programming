#include<stdio.h>
void main(void)
{
    int i,j=0,k,l;
    printf("Enter no");
    scanf("%d",&l);
    do{
        do{
            i=l%10;
            j+=i;
            l/=10;
        }while(l!=0);
        l=j;
        j=0;
    }while(l>=10);
    printf("Sum is %d",l);
    getch();
}
