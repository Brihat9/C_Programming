#include <stdio.h>
#include <conio.h>
int main ()
{
int i,s=0,a[10];
printf("Enter the ten number in the array\n");
for(i=0;i<=9;i++)
scanf("%d",&a[i]);
for(i=0;i<=9;i++)
{
s=s+a[i];
}
printf("\nThe sum of all the elements in array is %d",s);
}
