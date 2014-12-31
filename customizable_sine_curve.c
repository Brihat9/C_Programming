#include <windows.h>						// header file for gotoxy()
#include <stdio.h>     							// header file for printf()
#include <math.h>							// header file for sin(), asin()
#include <conio.h>							// header file for getch()


// This is the function to make gotoxy() work in CodeBlocks (copied from internet)
		COORD coord={0,0}; 					// center of axis is set to (0,0)
		void gotoxy(int x,int y)
		{
			coord.X=x;
 			coord.Y=y;
 			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
		}

int main (void)
{
	// YOU CAN CHANGE THE FOLLOWING 3 PARAMETERS
	float Amp = 10;						// This is the amplitude (should be equal to amplitude/6)
	float L = 60; 						// This is the wavelength (should be equal to amplitude*6)
	int N = 01;							// No of waves to display

	// DON'T CHANGE THE DATA BELOW!!! OTHERWISE IT MAY NOT WORK!!!
	float	L2 = L/2;						// Half-wavelength
	float	L4 = L/4;						// Quarter-wavelength

	int x, y;							// X and Y coordinate for gotoxy() function
	for (y=0; y<=Amp; y++) 					// We'll find the X-coord for every Y-coord (by using sin_inverse)
	{
		float angle = asin(y/Amp); 				// This is the sin_inverse function (so that when y=amp, angle=PI/2=1.57)
		x = (int) (angle*10*L4/15);   				// An expression (so that when y=amp, x=L4)...from unitary method

		int i;
		for (i=0; i<N; i++)					// To display multiple waves
		{
			gotoxy(x+(L*i), Amp-y); printf("*");		// 1st quadrant... down to up
			gotoxy(L2-x+(L*i), Amp-y); printf("*");		// 2nd quadrant... down to up
			gotoxy(L2+x+(L*i), Amp+y); printf("*");		// 3rd quadrant... up to down
			gotoxy(L-x+(L*i), Amp+y); printf("*");		// 4th quadrant... up to down
		}
	}

	getch(); return 0;
}
