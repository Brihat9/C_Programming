#include<stdio.h>
typedef struct
{
	char name[20];
	int age, roll, sub[6];
}user;

int main()
{
	user u;
	int loop, sum;
	float avrg;
	printf("Enter your name:\t");
	scanf("%s",&u.name);
	printf("Enter your age:\t\t");
	scanf("%d",&u.age);
	printf("Enter your roll no.:\t");
	scanf("%d",&u.roll);
	printf("Enter your marks in 6 different subjects:\n");
	for(loop = 0; loop < 6; loop++) {
		printf("  sub \t%d\n",loop + 1);
		scanf("%d",&u.sub[loop]);
	}
	sum = 0;
	for(loop = 0; loop < 6; loop++)
		sum += u.sub[loop];
	avrg = sum / 6;
	printf("The average mark is:\t%.2f",avrg);
getch();
	return 0;
}
