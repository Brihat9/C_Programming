//Program to read files


readfile(char fname[80])

{
	FILE *fp;
	int scroll=0;
	char freadtemp[200];

	if(!(fp = fopen(fname,"r")))
	{
	 printf("File Not Found");
	 getch();
	 exit();//consider this while debugging
	}
	while(!feof(fp))
	  {
		fgets(freadtemp,85,fp);
		printf("%s",freadtemp);
		scroll++;
		if (scroll>21)getch();
	  }
	fclose(fp);
	puts("");

}

//Program to accept only integers

//Syntax: scanint(&variablename);


scanint(int *pnum)
{
 int i,temp;
 char dump[70];

 for(i=0;i<50;i++)
  {
   if(scanf("\n%d",&temp)) break;
   else
   {
    scanf("\n%s",dump);
    printf("Invalid entry - Reenter: ");
   }
 }
  *pnum= temp;
}

//Program to execute sub programs
runprog(int chapno,int progno)
{
  switch(chapno)
  {
   case 1://Basic I/O
   {
    switch(progno)
    {
     case 1:{ascnchar();break;}
     case 2:{tempconv();break;}
     case 3:{hexdec();break;}
     case 4:{interest();break;}
     case 5:{eqnsolv2();break;}
    }//end of progno, chap1
    break;
   } //end of case1: basic i/o
   case 2://Control Program Flow
   {
    switch(progno)
    {
     case 1:{large2();break;}
     case 2:{reverse();break;}
     case 3:{compquad();break;}
     case 4:{hcf();break;}
     case 5:{compprim();break;}
     case 6:{armstrng();break;}
     case 7:{expser();break;}
     case 8:{sinser();break;}
     case 9:{pscltri();break;}
    }
    break;
   }//end of case 2: control program flow
   case 3://Functions
   {
    switch(progno)
    {
     case 1:{cosser();break;}
     case 2:{xpowy();break;}
     case 3:{fibgen();break;}
     case 4:{pmcmbfct();break;}
     case 5:{pyrdisp();break;}
    }
    break;
   }//end of case 3: functions
   case 4://Arrays and String
   {
    switch(progno)
    {
     case 1:{mtrxsum();break;}
     case 2:{mtrxmlt();break;}
     case 3:{mtrxtpos();break;}
     case 4:{mgcsqr();break;}
     case 5:{pndrm();break;}
    }
    break;
   }//end of case 4: arrays and strings
   case 5://Pointers
   {
    switch(progno)
    {
    case 1:{rotvar();break;}
    case 2:{sortpntr();break;}
    case 3:{strcnt();break;}
    }
    break;
   }//end of case 5: pointers
   default: //unnecessary
   {
    clrscr();
    printf("\nChapter does not exist");
    exitseq();
   }
  }//end of switch (chapno)
}//end of runprog

//Function to display submenu

dispsubmenu()
{
 clrscr();
 printf("\n\n\n");
 printf("\t\t\tOption A: Run the program\n");
 printf("\t\t\tOption B: View Source Code\n");
 printf("\t\t\tOption C: View Documentation\n");
 printf("\n\t\t\tPress any other key to return to Chapter menu\n");
 printf("\n\n\t\t\tEnter your choice => ");
}


loaderanim() //Loading Animation
{
 int loader;
 clrscr();
 printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t  Loading Menu...\n\t\t\t   ");
 for (loader=1;loader<30;loader++){ delay(15); printf("%c",219); }
 delay(900);
 //printf("\n\n\n\t\t\t  Press any key to continue...");
 //getch();
}

exitseq()
      {
       clrscr();
       printf("\n\n\n\n\n\n\t\t\t\t     Exiting....");
       delay(650);
       clrscr();
       printf("\n\n\t\t\t***Thank you for using the program***\n");


       printf("\n\n\n\n\n\t\t\t        Program designed by\n");
       printf("\n\t\t\t\t     Shaswot\n");

       printf("\n\n\n\n\n\t\t\t      Press any key to continue...");
       getch();
       exit();
      }
