#include<stdio.h>
#include<conio.h>
#include<math.h>
int series(int);

void main(void)
{
    printf("This program displaya the series 6^2+9^2+12^2+...+48^2 and the sum.\n\n");
    int i,j=0;
    for(i=5;i<50;i++)
        {
            if(i%3==0)
            {
              j+=series(i);
              printf("%d^2\t",i);
            }
        }
    printf("\n\nThe sum of series is %d.",j);
    getch();
    return ;
}

int series(int i)
{
    int sum=0;
    sum+=pow(i,2);
    return sum;
}
