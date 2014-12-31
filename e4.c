#include<stdio.h>
#include<conio.h>

struct student
{
	char name[20];
	int age, roll, sub[6];
};

void main(void)
{
	int loop,sum=0;
	struct student stud;
	float avg;
	printf("Enter your name:");
	scanf("%s",&stud.name);
    printf("Enter your age:");
	scanf("%d",&stud.age);
	printf("Enter your roll no.:");
    scanf("%d",&stud.roll);
	printf("\nEnter your marks in 6 subjects\n");
	for(loop=0;loop<6;loop++)
    {
		printf("Enter mark in subject %d :",loop + 1);
		scanf("%d",&stud.sub[loop]);
	}
	for(loop = 0; loop < 6; loop++)
        sum += stud.sub[loop];
	avg = sum/6.0;
	printf("\nYour average mark is : %.2f",avg);
    getch();
}
