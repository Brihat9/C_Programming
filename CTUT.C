#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include"d:\ctut\proghdr.h"
#include"d:\ctut\runprg.h"


void main(void)
{
 int chapno=2,progno;
 char submenu;

 char chaplist[10][80]={"c:\\ctut\\chap1.txt",
			"c:\\ctut\\chap2.txt",
			"c:\\ctut\\chap3.txt",
			"c:\\ctut\\chap4.txt",
			"c:\\ctut\\chap5.txt",
			"c:\\ctut\\chap6.txt",
			"c:\\ctut\\chap7.txt",
			"c:\\ctut\\chap8.txt",
			"c:\\ctut\\chap9.txt"};

  char scode[7][10][80]= {
			       {"c:\\ctut\\codes\\ascnchar.c",
				"c:\\ctut\\codes\\tempconv.c",
				"c:\\ctut\\codes\\hexdec.c",    //chap1progs
				"c:\\ctut\\codes\\interest.c",
				"c:\\ctut\\codes\\eqnsolv2.c"
				"\0"},

			       {"c:\\ctut\\codes\\large2.c",
				"c:\\ctut\\codes\\reverse.c",
				"c:\\ctut\\codes\\compquad.c",
				"c:\\ctut\\codes\\hcf.c",       //chap2progs
				"c:\\ctut\\codes\\compprim.c",
				"c:\\ctut\\codes\\armstrng.c",
				"c:\\ctut\\codes\\expser.c",
				"c:\\ctut\\codes\\sinser.c",
				"c:\\ctut\\codes\\pscltri.c",
				"\0"},

			       {"c:\\ctut\\codes\\cosser.c",
				"c:\\ctut\\codes\\xpowy.c",
				"c:\\ctut\\codes\\fibgen.c",  //chap3progs
				"c:\\ctut\\codes\\pmcmbfct.c",
				"c:\\ctut\\codes\\pyrdisp.c",
				"\0"},

			       {"c:\\ctut\\codes\\mtrxsum.c",
				"c:\\ctut\\codes\\mtrxmlt.c",
				"c:\\ctut\\codes\\mtrxtpos.c", //chap4progs
				"c:\\ctut\\codes\\mgcsqr.c",
				"c:\\ctut\\codes\\pndrm.c",
				"\0"},

			      {"c:\\ctut\\codes\\rotvar.c",
			       "c:\\ctut\\codes\\sortpntr.c",
			       "c:\\ctut\\codes\\strcnt.c",
			       "\0"},

			  "\0" };


  char progdoc[7][10][80]= {
			       {"c:\\ctut\\doc\\ascnchar.c",
				"c:\\ctut\\doc\\tempconv.c",
				"c:\\ctut\\doc\\hexdec.c",    //chap1progdocs
				"c:\\ctut\\doc\\interest.c",
				"c:\\ctut\\doc\\eqnsolv2.c",
				"\0"},

			       {"c:\\ctut\\doc\\large2.c",
				"c:\\ctut\\doc\\reverse.c",
				"c:\\ctut\\doc\\compquad.c",
				"c:\\ctut\\doc\\hcf.c",       //chap2progdocs
				"c:\\ctut\\doc\\compprim.c",
				"c:\\ctut\\doc\\armstrng.c",
				"c:\\ctut\\doc\\expser.c",
				"c:\\ctut\\doc\\sinser.c",
				"c:\\ctut\\doc\\pscltri.c",
				"\0"},

			       {"c:\\ctut\\doc\\cosser.c",
				"c:\\ctut\\doc\\xpowy.c",
				"c:\\ctut\\doc\\fibgen.c",   //chap3progdocs
				"c:\\ctut\\doc\\pmcmbfct.c",
				"c:\\ctut\\doc\\pyrdisp.c",
				"\0"},

			       {"c:\\ctut\\doc\\mtrxsum.c",
				"c:\\ctut\\doc\\mtrxmlt.c",
				"c:\\ctut\\doc\\mtrxtpos.c",  //chap4progdocs
				"c:\\ctut\\doc\\mgcsqr.c",
				"c:\\ctut\\doc\\pndrm.c",
				"\0"},

				{"c:\\ctut\\doc\\rotvar.c",
				 "c:\\ctut\\doc\\sortpntr.c",
				 "c:\\ctut\\doc\\strcnt.c",
				 "\0"},

			     "\0"};



 clrscr();
 readfile("c:\\ctut\\intro.txt"); //Main Intro Display
 printf("\n\n\n\nEnter the chapter number [Press 0 to exit tutorial]: ");

 scanint(&chapno); //Chapter Input
 while(chapno<0||chapno>6)
 {
  printf("Invalid entry - Reenter chapter number: ");
  scanint(&chapno);
 }
 if(!chapno) exitseq(); //Press 0 to exit

 chapstart:
 clrscr();
 readfile(chaplist[chapno-1]); //Chapter Display

 printf("\n\n\nEnter Program Number [Press 0 to return to Main Menu]: ");
 scanint(&progno); //Input Prog no.

 while(progno<0)
 {
  printf("Invalid entry - Reenter program number: ");
  scanint(&progno);
 }
 if(!progno) {loaderanim();main();}//exit to main menu

 dispsubmenu(); //Display Options for Execution,Source Code and Documentation
 scanf("\n%c",&submenu);


 switch(toupper(submenu))
 {
  case 'A':  //Execution of Program
   {
    char in='d';
    runprog(chapno,progno);//running selected program
    printf("\n\n\n\nPress 'S' to continue to Source Code");
    printf("\nOR\nPress 0 to return to Chapter #%d\t\t",chapno);
    while(in !='S'&& in !='s'&& in !='0') in = getch();
    if(in=='0') goto chapstart;
   }//end of case 'A'

  case 'B': //Display Source Code
  {
   char ins='f';
   clrscr();
   printf("Source Code:\n");
   readfile(scode[chapno-1][progno-1]);
   printf("\n\nEnd Of Source Code");
   getch();
   printf("\n\nPress 'D' to continue to Program Documentation");
   printf("\nOR\nPress 0 to return to Chapter #%d\t\t",chapno);
   while(ins !='D'&& ins !='d'&& ins !='0') ins = getch();
   if(ins=='0') goto chapstart;
  }//End of case'B'

  case 'C': //Display Documentation
  {
   char inx='g';
   clrscr();
   printf("Documentation\n\n");
   readfile(progdoc[chapno-1][progno-1]);
   printf("\n\nEnd Of Documentation\n");
   printf("\n\nPress 'E' to return to Chapter #%d\t\t",chapno);
   while(inx !='E'&& inx !='e') inx = getch();
   goto chapstart;
  }//End of case'C'


  default: //Any other key returns to chapter menu
  {
   loaderanim();
   goto chapstart;
  }//End of default
 }//End of switch(submenu)

}//End of main()

