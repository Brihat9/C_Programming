#include <stdio.h>
#include <conio.h>
int main ()
{
int i,j,s=0,a[3][3];
printf("Enter the elements in the array\n");

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
scanf("%d",&a[i][j]);
}

printf("\nthe matrix is\n");

for(i=0;i<=2;i++)
{
    for(j=0;j<=2;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
printf("\nThe transpose of the above matrix is \n");
for(i=0;i<=2;i++)
{
    for(j=0;j<=2;j++)
{
printf("%d\t",a[j][i]);
}
printf("\n");
}
}
