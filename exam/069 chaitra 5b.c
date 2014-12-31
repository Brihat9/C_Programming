#include<stdio.h>
void main(void)
{
    int arr[50],i,j,n,temp;
    printf("enter no of numbers");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    printf("enter no %d",i+1);
    scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++)
    for(j=i;j<n;j++)
    if(arr[i]<arr[j])
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    printf("2nd largest number is %d",arr[1]);
    getch();
}
