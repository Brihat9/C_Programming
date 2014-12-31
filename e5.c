#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct employee
{
	char name[20];
	int sal;
};

void main(void)
{
    struct employee *emp;
    int n,i,sum=0,highest,lowest,count = 0;
	float avg;
	char *high, *low;
	printf("Enter number of employee : ");
	scanf("%d",&n);
	emp=malloc(n*sizeof(*emp));
	for(i = 0; i< n; i++)
    {
		printf("\nEnter name of employee %d :",i + 1);
		scanf("%s",&emp[i].name);
		printf("Enter salary of employee %d :",i+1);
		scanf("%d",&emp[i].sal);
	}
	for(i=0; i<n; i++)
		sum += emp[i].sal;
    avg = (float)sum/n;
	printf("\nAverage salary :%.2f",avg);
	highest = lowest = emp[0].sal;
	high = low = emp[0].name;
	for(i = 1; i< n; i++)
    {
		if(highest < emp[i].sal)
        {
			high = emp[i].name;
			highest = emp[i].sal;
		}
		if(lowest > emp[i].sal)
        {
			low = emp[i].name;
			lowest = emp[i].sal;
		}
	}
	printf("\n\nEmplyoee having highest salary:");
	printf("\nName:%s",high);
	printf("\nSalary:%d",highest);
	printf("\n\nEmployee having lowest salary:");
	printf("\nName:%s",low);
	printf("\nSalary:%d",lowest);
	printf("\n\nEmployees getting salary above 15000:");
	for(i=0; i<n;i++)
    {
		if(emp[i].sal > 15000)
        {
			printf("\n\nName of employee : %s",emp[i].name);
            printf("\nSalary : %d",emp[i].sal);
			count++;
		}
	}
	if(count == 0)
		printf("\nNONE");
    getch();
}
