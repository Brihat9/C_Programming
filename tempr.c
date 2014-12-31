#include<stdio.h>
void main()
{
float c,f;
printf("Enter temperature in celsius : ");
scanf("%f",&c);
f=((9*c)/5)+32;
printf("\n %.2f C is equal to %.2f F.",c,f);
}
