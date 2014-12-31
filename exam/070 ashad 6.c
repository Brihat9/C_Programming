#include <stdio.h>
typedef struct height
{
	int	feet,inch;
}stud;

void main(void)
{
	int n,i;
	stud s1,s2, s={0,0};
    printf("\nEnter height of student 1: feet inch");
    scanf("%d%d",&s1.feet,&s1.inch);
    printf("\nEnter height of student 2: feet inch");
    scanf("%d%d",&s2.feet,&s2.inch);
    s.inch=s1.inch-s2.inch;
    if(s.inch<0)
    {
        s.inch+=12;
        s.feet--;
    }
    else if(s.inch>11)
    {
        s.inch-=12;
        s.feet++;
    }
    s.feet+=s1.feet-s2.feet;
    printf("\ndiff is %d feet %d inch\n",s.feet, s.inch);
	getch();
}
