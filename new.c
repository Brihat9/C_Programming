#include <stdio.h>
#include<conio.h>
#include<windows.h>

//#define YY 2014
//#define MM 3
//#define DD 19
#define X 20

typedef struct today
{
    int YY,MM,DD;
}today;

typedef struct student
{
	char name[25];
	int	y,m,d;
}stud;

today dat(today);

void main(void)
{
	int n=1,i=0;
	stud s[X],age[X];
	today date;
	printf("\n\tThis program calculates your age according to reference date given.\n\t\t\t\tPress any key...\n\t\t\t\t\t");
	getch();
	system("cls");
	date=dat(date);

    printf("\nEnter your name:",i + 1);
    scanf("%s",&s[i].name);
    printf("Enter Date of Birth [DD MM YYYY]:");
    scanf("%d %d %d",&s[i].d,&s[i].m,&s[i].y);
    if(s[i].y>=2014 || s[i].m>12 || s[i].d>30)
    {
        printf("\nInvalid DOB");
        getch();
        exit(0);
    }

	for(i = 0; i<n; i++)
    {
		age[i].y = date.YY - s[i].y;
		age[i].m = date.MM - s[i].m;
		age[i].d = date.DD - s[i].d;
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
		printf("\nYour name is : %s\n", s[i].name);
		printf("Your age is : %d years %d months %d days\n",age[i].y,age[i].m,age[i].d);
	}
	getch();
}

today dat(today date)
{
    printf("Enter reference date [DD MM YY] : ");
    scanf("%d %d %d",&date.DD,&date.MM,&date.YY);
    return date;
}
