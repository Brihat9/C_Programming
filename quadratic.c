#include<stdio.h>
#include<math.h>
void main()
{
    float a,b,c,d,x1,x2;
    printf("\nEnter coefficients of quadratic equation : ");
    scanf("%f%f%f",&a,&b,&c);
    if (a==0.0)
    {
        printf("\nThe equation is not quadratic equation.");
    }
    else
    {
        d=b*b-4*a*c;
        if (d<0.0)
        {
            printf("\nRoots are imaginary.");
        }
        else if (d==0.0)
        {
            x1=-b/(2*a);
            x2=x1;
            printf("\nRoots are real and equal.");
            printf("\nRoots are x1=%.2f and x2=%.2f",x1,x2);
        }
        else if (d>0.0)
        {
            x1=(-b+sqrt(d))/(2*a);
            x2=(-b-sqrt(d))/(2*a);
            printf("\nRoots are real and unequal.");
            printf("\nRoots are x1=%.2f and x2=%.2f",x1,x2);
        }
        else
        {
            printf("\nAn error has occured.");
        }
    }
    printf("\n\n\n");
    getch();
}
