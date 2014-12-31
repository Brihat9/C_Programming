#include<stdio.h>
typedef struct employee
{
    char name[50];
    char post[25];
    float salary;
}emp;

int j=0;
emp empl[10],temp[10];
void sal(emp empl[],int n);

void main(void)
{
    int n,i;
    for(i=0;i<10;i++)
    {
        printf("Enter detail of employee %d\nName: ",i+1);
        scanf("%s",empl[i].name);
        printf("Enter post: ");
        scanf("%s",empl[i].post);
        printf("Salary : ");
        scanf("%f",&empl[i].salary);
    }
    sal(empl,10);
    printf("Sorted list\n");
 //   printf("\n%d\n",j);
    for(i=0;i<j;i++)
    {
        printf("\nDetail of employee getting salary less than 10000.%d\nName: %s\n",i+1,temp[i].name);
        printf("post : %s\n",temp[i].post);
        printf("Salary : %.2f\n",temp[i].salary);
    }
    getch();
}

void sal(emp emrp[],int n)
{
    int i,k;
    for(i=0;i<n-1;i++)
        if (emrp[i].salary<10000)
            {
                temp[j]=emrp[i];
                j++;
            }
}
