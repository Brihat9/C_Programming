#include <stdio.h>
#include<conio.h>
#include<windows.h>

//#define YY 2014
//#define MM 3
//#define DD 27
#define X 21

typedef struct student
{
	char name[25];
	int	y,m,d;
}stud;

void main(void)
{
	int n,i;
	int DD,MM,YY;
	stud s[X],age[X];
	printf("Enter current date [DD MM YYYY] :");
	scanf("%d %d %d",&DD,&MM,&YY);
    do{
    system("cls");
	printf("Enter number of student(Max 20) :");
	scanf("%d",&n);
	for(i = 0; i<n; i++)
    {
		printf("\nEnter name of student %d:",i + 1);
		scanf("%s",&s[i].name);
		printf("Enter Date of Birth [DD MM YYYY]:");
		scanf("%d %d %d",&s[i].d,&s[i].m,&s[i].y);
		if(s[i].y>=2014 || s[i].m>12 || s[i].d>30)
        {
            printf("\nInvalid DOB");
            getch();
            exit(0);
        }
	}
	for(i = 0; i<n; i++)
    {
		age[i].y = YY - s[i].y;
		age[i].m = MM - s[i].m;
		age[i].d = DD - s[i].d;
		if(age[i].d<0)
        {
            age[i].d+=30;
            age[i].m--;
        }
		if(age[i].m<0)
        {
            age[i].m+=12;
            age[i].y--;
        }
		printf("\nName of student %d:%s\n",i+1, s[i].name);
		printf("Age of student %d:%d years %d months %d days\n",i+1,age[i].y,age[i].m,age[i].d);
		printf("\n\nAGAIN??? (y/n) :");
    }
	}while(getch()=='y');
	getch();
}
