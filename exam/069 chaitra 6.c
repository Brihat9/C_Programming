#include<stdio.h>
typedef struct employee
{
    char name[50];
    float salary;
}emp;
void sorte(emp empl[],int n);

void main(void)
{
    int n,i;
    emp empl[59],temp;
    printf("enter no of employee : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter detail of employee %d\nName: ",i+1);
        scanf("%s",empl[i].name);
        printf("Salary : ");
        scanf("%f",&empl[i].salary);
    }
    sorte(empl,n);
    printf("Sorted list\n");
    for(i=0;i<n;i++)
    {
        printf("\nDetail of employee %d\nName: %s\n",i+1,empl[i].name);
        printf("Salary : %.2f",empl[i].salary);
    }
    getch();
}

void sorte(emp emrp[],int n)
{
    int i,j,k;
    emp temp;
    for(i=0;i<n-1;i++)
        for(j=1;j<n;j++)
            if (emrp[i].salary>emrp[j].salary)
            {
                temp=emrp[i];
                emrp[i]=emrp[j];
                emrp[j]=temp;
            }
}
