#include <stdio.h>
#include <conio.h>
int main ()
{
int i,s=0,t=0,a[10];
printf("Enter the ten number in the array\n");
for(i=0;i<=9;i++)
scanf("%d",&a[i]);

for(i=0;i<=9;i++)
{
if (a[i]>s)
s=a[i];
}

t=s;

for(i=0;i<=9;i++)
{
if (a[i]<t)
t=a[i];
}

printf("the largest number is %d\n",s);
printf("th smallest number is %d\n",t);
getch();
}
