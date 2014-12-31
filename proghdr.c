//Program to convert ASCII to character and viceversa.
ascnchar()
{
 //This program doesn't have filters for misinputs
 int asc;
 char ch;
 clrscr();
 puts("Input the ASCII code(0-255): ");
 scanf("\n%d",&asc);
 printf("ASCII code %d is equivalent to character   %c ",asc,asc);
 printf("\n\n");
 puts("Input a character: ");
 scanf("\n%c",&ch);
 printf("The ASCII code for ' %c ' is %d",ch,ch);
 getch();
}

//Program to convert Hexadecimal numbers to decimal and viceversa

hexdec()
{
 int input;
 clrscr();
 puts("Enter decimal");
 scanf("%d",&input);
 puts("Hexadecimal output:");
 printf("%X",input);
 printf("\n\n\n");
 puts("Enter hexadecimal");
 scanf("%x",&input);
 puts("Decimal output:");
 printf("%d",input);
 getch();
}

//Program to calculate simple and compound interest

interest()
{
 float prncpal,rate,time,cmprate;
 float smplint,cmpamnt;
 clrscr();
 puts("Input Principal: ");
 scanf("\n%f",&prncpal);
 puts("Input Rate percentage:");
 scanf("\n%f%*[/\%]",&rate);
 puts("Input Time(in years):");
 scanf("\n%f",&time);
 puts("Input Compounding per year: ");
 scanf("\n%f",&cmprate);

 //gives compounding amount
 cmpamnt= prncpal * pow(1 + rate/(cmprate*100),cmprate*time);



 printf("\n\nSimple Interest = %.2f",prncpal*rate*time/100);
 printf("\n\nCompound Interest = %.2f",cmpamnt-prncpal);//gives compound interest
 getch();
}

//Program to read file

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

//Program to convert centigrade to fahrenheit and viceversa

tempconv()
{

 float centi,fahren;
 clrscr();
 puts("Input temperature in degrees Centigrade");
 scanf("\n%f",&centi);
 printf("\n%+-.2f degrees Centigrade equals\n",centi);
 printf("%+-.2f degrees Fahrenheit\n",(centi*9/5)+32);
 printf("%+-.2f Kelvin",centi+273.15);

 puts("\n\nInput temperature in degrees Fahrenheit");
 scanf("\n%f",&fahren);
 printf("\n%+-.2f degrees Fahrenheit equals\n",fahren);
 printf("%+-.2f degrees Centigrade\n",(fahren-32)*5/9);
 printf("%+-.2f Kelvin",(fahren-32)*5/9+273.15);

 getch();
}


//Program to calculate solution for equations with two variables

eqnsolv2()
{
 float a,b,c,m,n,d;
 clrscr();
 printf("For equations:  ax + by + c = 0\n");
 printf("	        mx + ny + d = 0\n");
 printf("Enter values of a,b,c,m,n,d => ");
 scanf("%f %f %f %f %f %f",&a,&b,&c,&m,&n,&d);
 if (a*n-m*b == 0)      // correction required!!!!!
 {
  printf("\nInvalid Input");
  printf("\nPress any key to restart...");
  getch();
  eqnsolv2();
 }
 printf("The solution for the equation is:\n");
 printf("x = %g\n",(b*d - c*n)/(a*n - m*b));
 printf("y = %g\n",(m*c - d*a)/(a*n - m*b));
 getch();
}



//Program to find the largest among three variable
large2()

{
 float num1,num2,num3,large;
 clrscr();
 printf("Enter three numbers: ");
 scanf("%f %f %f",&num1,&num2,&num3);
 printf("\nYou entered %.2f %.2f %.2f",num1,num2,num3);
 large = num1;
 if(num2>large) large = num2;
 if(num3>large) large = num3;
 printf("\nThe largest of the numbers is %.2f",large);
 getch();

}

//Program to reverse a number and print sum of digits

reverse()
{
 long int i,input,sum=0,rev=0,nod=0,count=0;
 char dump[10];
 clrscr();
 puts("Input number [0-65535]: ");

 if(!(scanf("%ld",&input))||input<0||input>65535)
 {
  scanf("%s",dump);
  printf("Invalid input");
  getch();
  reverse();
 }
 else if(input<10)
 {
  sum=rev=input;
 }
 else
 {
  for(i=1;i<100000;i=i*10)
  {
   if(input/i)  nod++;
  }
  printf("Number Of Digits = %d\n",nod);

  while(count<nod)
  {
   rev = rev*10+input%10;
   sum = sum + input%10;
   input=input/10;
   count++;
  }
  printf("Reversed digit =>  %d\n",rev);
  printf("Sum of digits => %d\n",sum);
 }
 getch();
}

//Program to compute complete quadriatic roots

compquad()
{
 float a,b,c,disc;
 char dump[10];
 clrscr();
 puts("For a quadriatic equation of form Ax^2 + Bx + C = 0");
 printf("\n\nInput the values of A,B,C: ");
 if(!scanf("%f%f%f",&a,&b,&c))
  {
   scanf("%s",dump);
   puts("Invalid Input");
   getch();
   compquad();
  }

 if(!a)
 {
  puts("The equation is linear");
  getch();
 }
 else
 {
	disc = (pow(b,2) - 4*a*c);
	 if(disc < 0)//roots are imaginary and conjugate
	 {
	  disc = -disc;
	  puts("The roots are imaginary and conjugate");
	  printf("\n\n\Root 1: \t%.2f + i %.2f\n",-b/2*a,pow(disc,.5)/(2*a));
	  printf("Root 2: \t%.2f - i %.2f\n",-b/2*a,pow(disc,.5)/(2*a));
	 }
	 else if( disc == 0)//roots are real and equal
	 {
	  puts("The roots are real and equal");
	  printf("\n\nRoots: \t%.2f\n",-b/2*a);
	 }
	 else //roots are real and unequal
	 {
	  puts("The roots are real and unequal");
	  printf("\n\nRoot 1: \t%.2f + %.2f\n",-b/2*a,pow(disc,.5)/(2*a));
	  printf("Root 2: \t%.2f - %.2f\n",-b/2*a,pow(disc,.5)/(2*a));
	 }
 }
 getch();
}

/*Program to find HCF of two numbers*/


hcf()
{
	int a,b,x=1,num1,num2;
	clrscr();
	printf("\nEnter the two numbers: ");
	scanf("\n%d\n%d",&num1,&num2);
	a=num1;
	b=num2;

	while(x!=0)
	 {
	   x= b%a;
	   b=a;
	   a=x;
	 }
	printf("\nHCF of %d and %d is %d",num1,num2,b);
	getch();

}


//Program to compute prime numbers

void compprim()

{
  unsigned int num=0, i=2,a=3,b=1;
  while(a>b)
	{
          printf("\nEnter Lower limit: ");
	  scanint(&a);
	  printf("\nEnter Upper limit: ");
	  scanint(&b);
	}

  for(num=a;num<=b;num++)
   {
     if(num!=0&&num!=1&&num!=2&&num!=3)
     {
       for(i=2;i<num;i++)
	{
          if((num%i)==0)
	    {/*printf("\nThe number %d is not prime.\n",num);*/
	       goto end;
             }
	}
     }
     printf("\nThe number %d is prime.\n",num);
     end:
   }
}





//Program to display Armstrong Numbers
//Armstrong Numbers are those numbers such that the number is equal to the
//sum of the digits raised to the power to the number of digits
// 153 = 1^3 + 5^3 + 3^3
// 1634 = 1^4 + 6^4 + 3^4 + 4^4


armstrng()
{
 unsigned long int i,j,nod,temp,digit,sum=0,low,high,count;
 clrscr();
 printf("Enter lower limit: ");
 scanf("%lu",&low);
 printf("Enter upper limit: ");
 scanf("%lu",&high);

 for(i=low;i<=high;i++)
 {
   nod=0;
   for(j=1;j<100000;j=j*10)
   {
    if(i/j)  nod++;
   }
   temp=i;
   sum = 0;
   while(temp>0)
   {
    digit = temp%10;
    sum =sum + pow(digit,nod);
    temp = temp/10;
   }
   if (sum==i)
   {
     printf("\n%d is an Armstrong Number",i,sum);
     count++;
   }

   else continue;
 }

if(!count) printf("\nThere are no Armstrong Numbers in the given range");
getch();
}

//Program to calculate exponential series

expser()
{
 int i;
 float x,temp=1,sum;
 clrscr();
 puts("For the expression e^x");
 printf("Enter value for x: ");
 scanf("%f",&x);
 sum = 1+x;//e^x = [1 + x] + x^2/2! + ....
 temp = x;//temp = 2nd term of series
 for(i=2;i<100;i++)
 {
   temp = temp * (x/i);
   sum = sum+temp;
   //printf("\ntemp = %f",temp);
   //printf("\nSUm = %f",sum);
 }
 printf("\ne^(%.2f) = %.5f",x,sum);
 getch();
}

//Program to calculate sine series

sinser()
{

 double in,inx,nth,sum;
 int i, n=1000;		//n = no of terms
 clrscr();
 puts("For the expression sin x: ");
 printf("Enter x(in degrees): ");
 scanf("%lf",&in);
 inx = in;

 inx = inx * 3.141592654/180;

 sum=nth=inx;
 for(i=1;i<=n;i++)
 {
  nth = (-1*nth*inx*inx)/((2*i)*(2*i+1));
  sum = sum+nth;
 }
 printf("sin(%+-5.2lf) = %+-5.7lf",in,sum);
 getch();
}

/* i = 1; nth = +x ; 	      nth = +x 	    * -1 * x^2/(2*3)
   i = 2; nth = -x^3/3!;      nth = -x^3/3! * -1 * x^2/(4*5)
   i = 3; nth = +x^5/5!;      nth = +x^5/5! * -1 * x^2/(6*7)
   i = 4; nth = +x^7/7!;      nth = +x^7/7! * -1 * x^2/(8*9)
   ....
*/


//Program to display Pascal's Triangle

pscltri()
{
  int binom,p,q,r,x;
  binom = 1;
  q = 0;
  clrscr();
  printf("Input the number of rows: ");
  scanf("%d",&p);
  printf("\nPascal's Triangle: \n");
  while(q < p)
  {
   for(r=35-3*q;r>0;--r) printf("*");
   for(x=0;x<=q;x++)
   {
    if((x==0)||(q==0)) binom =1;
    else binom = binom * (q-x+1)/x;
    printf("%6d",binom);
   }//for end
  printf("\n");
  q++;

  }//while end
 getch();
}
NOTE: This Program was copied from “Programming with C” by K.R.Venugopal and Sudeep R. Prasad[Pg.99]


//Function to calculate cosine value

cosser()
{
 double cosine(double);       //Function declaration

 double in;
 clrscr();
 puts("For the expression cos x: ");
 printf("Enter x(in degrees): ");
 scanf("%lf",&in);
 printf("cos(%+-5.2lf) = %+-5.7lf",in,cosine(in)); //function call
 getch();

}


double cosine(double inx)  //function definition
{
 double nth,sum;
 int i, n=1000;		//n = no of terms

 inx = inx * 3.141592654/180;
 sum = nth = 1;
 for(i=1;i<=n;i++)
 {
  nth = -nth*inx*inx/((2*i)*(2*i-1));
  sum = sum+nth;
 }
 return sum;
}

//Program to calculate x^y [recursive and only for integers]

xpowy()
{
 float power(int, int);
 int x,y;
 clrscr();
 puts("For the expression x^y");
 printf("Enter values of x and y: ");
 scanf("%d %d",&x,&y);
 printf("\n\n%d^%d = %.2f",x,y,power(x,y));
 getch();
}

float power(int x, int y)
{
 if(y==0) return 1;
 else if(y<0) return 1/power(x,-y);
 else return x*power(x,y-1);
}

//Program to generate Fibonacci Numbers using recursion

fibgen()
{
 int ln,i;
 clrscr();
 printf("Enter the number of elements: ");
 scanf("%d",&ln);
 printf("\n\n");
 for(i=1;i<=ln;i++) printf("Element No. %d => %d\n",i,fib(i));
 getch();
}

int fib(int n)
{
 if(n==0) return 1;
 else if(n==1) return 1;
 else return fib(n-1) + fib(n-2);
}


//Program to calculate Factorial, Permutation and Combination


pmcmbfct()
{
 long double fact(long double);
 long double perm(long double,long double);
 long double comb(long double,long double);

 long double n,r;


 clrscr();
 printf("Enter number to find factorial: ");
 scanf("%Lf",&n);
 printf("\nThe factorial of %.0Lf is %.0Lf.\n",n,fact(n));


 printf("\n\nEnter n,r for nPr and nCr: ");
 scanf("%Lf %Lf",&n,&r);
 printf("\n\n%.0LfP%.0Lf = %.0Lf",n,r,perm(n,r));
 printf("\n\n%.0LfC%.0Lf = %.0Lf",n,r,comb(n,r));
 getch();
}

long double fact(long double k)
{
 if(k<=0) return 1;
 else return k*fact(k-1);
}


long double perm(long double n, long double r)
{
return (fact(n)/fact(n-r));
}

long double comb(long double n, long double r)
{
return (perm(n,r)/fact(r));
}



//Program to display pyramids

pyrdisp()
{
 clrscr();
 puts("Pyramid Formation 1\n\n");
 pyr1();

 clrscr();
 puts("Pyramid Formation 2\n\n");
 pyr2();

 clrscr();
 puts("Pyramid Formation 3\n\n");
 pyr3();

 clrscr();
 puts("Pyramid Formation 4\n\n");
 pyr4();
 printf("\n\n");
 puts("Press any key to continue...");
 getch();
}

pyr1()
{
 int i,n,spc,asc,dsc;
 puts("Input no. of rows");
 scanf("%d",&n);

 printf("\n\n\n\n");
 for (i=1;i<=n;i++)
 {
    for(spc=n;spc>i;spc--) printf("*");//to print ****1,***1,**1....

    for(asc=1;asc<=i;asc++) printf("%d",asc); //to print 1, 12, 123, 1234...

    for(dsc=1;dsc<=i-1;dsc++) printf("%d",dsc);//to print 2, 23, 234....

    printf("\n");
 }
 getch();
}

pyr2()
{
 int i,n,dsc,asc,spc;

 puts("Input no. of rows");
 scanf("%d",&n);
 printf("\n\n\n\n");
 for(i=1;i<=n;i++)
 {
  for (spc=0;spc<i;spc++) printf("*");
  for (asc=0;asc<n-i;asc++) printf("%d",asc);
  for (dsc=n-i;dsc>=0;dsc--) printf("%d",dsc);
  printf("\n");
 }
 getch();
}

pyr3()
{
 int i,n,spc,asc,dsc;

 puts("Input no. of rows");
 scanf("%d",&n);

 printf("\n\n\n\n");
 for (i=1;i<=n;i++)
 {
    for(spc=n;spc>i;spc--) printf("*");//to print ****1,***1,**1....

    for(asc=1;asc<=i;asc++) printf("%d",asc); //to print 1, 12, 123, 1234...

    for(dsc=i-1;dsc>0;dsc--) printf("%d",dsc);//to print 4321, 321, 21, 1...

    printf("\n");

 }
 getch();
}


pyr4()
{
 char input[20];
 int l,i,spc,asc,dsc;

 puts("\nEnter string: ");
 scanf("%s",input);

 printf("\n\n\n\n");

 l=strlen(input);

 for (i=0;i<l;i++)
 {
    for(spc=l-1;spc>i;spc--) printf("*");//to print ****1,***1,**1....

    for(asc=0;asc<=i;asc++) printf("%c",input[asc]); //to print 1, 12, 123, 1234...

    for(dsc=i-1;dsc>=0;dsc--) printf("%c",input[dsc]);//to print 2, 23, 234....

    printf("\n");
  }
 getch();
}


/*Program to sum two matrices*/

mtrxsum()

{
 //Input of orders of matrices A and B
 int rA,cA,rB,cB,i,j;
 float a[20][20], b[20][20], sum[20][20];
 clrscr();
 printf("Input number of rows and columns for matrix A: ");
 scanf("%d %d",&rA,&cA);
 printf("\nInput number of rows and columns for matrix B: ");
 scanf("%d %d",&rB,&cB);

 //Checking orders
 if(rA!=rB || cA!=cB)
 { printf("\n\nThe matrices cannot be added");
   printf("\n\nPress any key to continue...");
   getch();
   goto eof1;
 }

 //Input matrix A: i = row, j =column
 printf("\n\nEnter Matrix A:\n\n");
 for(i=1;i<=rA;i++)
  for(j=1;j<=cA;j++)
   scanf("%f",&a[i][j]);

 //Input matrix B: i = row, j =column
 printf("\n\nEnter Matrix B:\n\n");
 for(i=1;i<=rB;i++)
  for(j=1;j<=cB;j++)
   scanf("%f",&b[i][j]);

 //Summation of A and B
 for(i=1;i<=rA;i++)  //rA and rB have same values
  for(j=1;j<=cB;j++) //cA and cB have same values
    sum[i][j] = a[i][j]+b[i][j];

 //Display of A, B, C
 clrscr();
 printf("\n\nMatrix A:\n");
 for(i=1;i<=rA;i++)
  {
    for(j=1;j<=cA;j++)
    printf("%8.2f",a[i][j]);
    printf("\n");
  }

 printf("\n\nMatrix B:\n");
 for(i=1;i<=rB;i++)
  {
    for(j=1;j<=cB;j++)
    printf("%8.2f",b[i][j]);
    printf("\n");
  }

 printf("\n\nMatrix C = A+B:\n");
 for(i=1;i<=rA;i++)
  {
    for(j=1;j<=cA;j++)
    printf("%8.2f",sum[i][j]);
    printf("\n");
  }
 getch();
eof1:
}//end of main




/*Program to multiply two matrices*/

mtrxmlt()
{
 //Input of orders of matrices A and B
 int rA,cA,rB,cB,i,j,k;
 float a[20][20], b[20][20], c[20][20],temp[30];
 //Value initialization of c to zero
 for(i=1;i<=30;i++)
  temp[i] = 0;


 clrscr();
 printf("Input number of rows and columns for matrix A: ");
 scanf("%d %d",&rA,&cA);
 printf("\nInput number of rows and columns for matrix B: ");
 scanf("%d %d",&rB,&cB);

 //Checking orders
 if(cA!=rB)
 { printf("\n\nThe matrices cannot be multiplied");
   printf("\n\nPress any key to continue...");
   getch();
   goto eof2;
 }

 //Input matrix A: i = row, j =column
 printf("\n\nEnter Matrix A:\n\n");
 for(i=1;i<=rA;i++)
  for(j=1;j<=cA;j++)
   scanf("%f",&a[i][j]);

 //Input matrix B: i = row, j =column
 printf("\n\nEnter Matrix B:\n\n");
 for(i=1;i<=rB;i++)
  for(j=1;j<=cB;j++)
   scanf("%f",&b[i][j]);

 //Multiplication of A and B
 for(i=1;i<=rA;i++)  //rA and rB have same values
  for(j=1;j<=cB;j++) //cA and cB have same values
   { c[i][j]=0;
     for(k=1;k<=cA;k++)
     c[i][j] = c[i][j] + a[i][k] * b[k][j];
   }

 //Display of A, B, C
 clrscr();
 printf("\n\nMatrix A:\n");
 for(i=1;i<=rA;i++)
  {
    for(j=1;j<=cA;j++)
    printf("%8.2f",a[i][j]);
    printf("\n");
  }

 printf("\n\nMatrix B:\n");
 for(i=1;i<=rB;i++)
  {
    for(j=1;j<=cB;j++)
    printf("%8.2f",b[i][j]);
    printf("\n");
  }

 printf("\n\nMatrix C = A * B:\n");
 for(i=1;i<=rA;i++)
  {
    for(j=1;j<=cB;j++)
    printf("%8.2f",c[i][j]);
    printf("\n");
  }

 getch();
eof2:
}//end of main


//Program to find transpose of matrix and determine symmetry


mtrxtpos()
{
 int i,j,rA,cA,flag=0;
 float a[20][20],t[20][20];

 clrscr();
 printf("Input number of rows and columns for matrix A: ");
 scanf("%d %d",&rA,&cA);


 //Input matrix A: i = row, j =column
 printf("\n\nEnter Matrix A:\n\n");
 for(i=1;i<=rA;i++)
  for(j=1;j<=cA;j++)
   {
    scanf("%f",&a[i][j]);
    t[j][i] = a[i][j];
   }

 //Check for symmetry
 for(i=1;i<=rA;i++)
  for(j=1;j<=cA;j++)
   if (a[i][j]!=t[i][j]) flag++;

 //Display of matrices
 clrscr();
 printf("\n\nMatrix A:\n");
 for(i=1;i<=rA;i++)
  {
    for(j=1;j<=cA;j++)
    printf("%8.2f",a[i][j]);
    printf("\n");
  }

 printf("\n\nTranspose of Matrix A :\n");
 for(i=1;i<=cA;i++)
  {
    for(j=1;j<=rA;j++)
    printf("%8.2f",t[i][j]);
    printf("\n");
  }

 if(rA!=cA) printf("\nThe matrix is not a square matrix and therfore not symmetrix.");
 else if(flag) printf("\nThe matrix is not symmetric");
 else printf("The matrix is symmetric");
 getch();
}



//Program to dispaly magic square


mgcsqr()

{
 int x,y,n=100,i,j,a[50][50];
 clrscr();
 start:
 printf("Enter an odd number: ");
 scanint(&n);

 if(!(n%2))
  {
   printf("\nOnly odd numbers are allowed\n");
   goto start;
  }

 if(n>11)
  {
   printf("Screen size insufficient to display square\n");
   goto end;
  }
 x=(n+1)/2;
 y = n;

 for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
     a[i][j]=0;


 for(i=1;i<=n*n;i++)
  {

   if(a[x][y]==0) //place number only if the array cell is unoccupied
     a[x][y]=i;

else			//if array cell is occupied, move to the cell above the last occupied cell
     {
     // printf("\nSpace occupied");
      x=x-1;
      y=y-2;
      a[x][y]=i;
     }

   y=y+1;//increase diagnolly to bottom
   x=x+1;//increase diagnolly to bottom
   if(y>n&&x>n){ y = y-2; x = x-1;} /*if both coordinates reach outside the array limit,move to the cell above the last 							occupied cell*/
   if(y>n) y = y-n;// if column size is exceeded, goto 1st column
   if(x>n) x= x-n; // if row size is exceeded, goto 1st row

  }


  //display magic square
  clrscr();
  printf("The magic square of order %d is:\n\n",n);
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
    printf("%5d",a[j][i]);
   printf("\n\n");
  }
  end:
  getch();
}



//Program to check for palindromes

pndrm()

{
 char temp[50],input[50],rev[50];
 int chck;
 clrscr();
 printf("Enter string: ");
 scanf("\n%[^\n]",input);
 printf("\nYou typed \"%s\"",input);

 strcpy(temp,input);        //Copying input string in temp location

 strrev(temp);  //Reversing temp string and storing in rev
 printf("\nThe reverse of \"%s\" is \"%s\"",input,temp);

 if(!stricmp(input,temp))
  printf("\n\nThe string \"%s\" is a palindrome.",input);

 else
  printf("\n\nThe string \"%s\" is not a palindrome.",input);
 getch();
}




//Program to swap the contents of variable using pointers

rotvar()
{
 int a,b,c,*pa,*pb,*pc;
 clrscr();
 printf("Enter variables a,b,c: ");
 scanf("%d %d %d",pa=&a,pb=&b,pc=&c);
 printf("Before rotation:\n");
 printf("\na = %d\nb = %d\nc = %d\n",a,b,c);
 rotate(pa,pb,pc);
 printf("\n\nAfter rotation:\n");
 printf("\na = %d\nb = %d\nc = %d\n",a,b,c);
 getch();
}

rotate(int *x,int*y,int*z)
{
 int temp;
 temp=*x;
 *x=*y;
 *y=*z;
 *z=temp;
}


//Program to sort numbers in ascending and descending order

sortpntr()

{
 int i,n;
 float a[100];
 clrscr();
 printf("Enter the no. of elements => ");
 scanf("%d",&n);
 for(i=0;i<n;i++)     /*To input the data*/
 {
  printf("Enter element %d => ",i+1);
  scanf("%f",&a[i]);
 }

 clrscr();           /*Displaying the input data*/
 printf("Your input is: \n");
 for(i=0;i<n;i++)
 {
  printf("Element %d = %g\n",i+1,a[i]);
 }

 ascsort(a,n);
 printf("\n\nThe array sorted in ascending order is: \n");
 for(i=0;i<n;i++)
 {
  printf("%g\t",a[i]);
 }

 dscsort(a,n);
 printf("\n\nThe array sorted in descending order is: \n");
 for(i=0;i<n;i++)
 {
  printf("%g\t",a[i]);
 }
 getch();

}


ascsort(float*a,int n)
{
 int i,j;
 float temp;
 for(i=0;i<n;i++)
  for(j=i+1;j<n;j++)
   {
    if(a[i]>a[j])
    {                 /*swap the contents of a[i] and a[j]*/
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
    }//end of if statement
   }//end of j loop
}


dscsort(float *a,int n)
{
 int i,j;
 float temp;

 for(i=0;i<n;i++)
  for(j=i+1;j<n;j++)
   {
    if(a[i]<a[j])
    {                 /*swap the contents of a[i] and a[j]*/
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
    }//end of if statement
   }//end of j loop
}

//Program to count number of vowels, consonants, digits,special chars and white spaces


strcnt()
{
 char in[80],input[80],dump[20];
 int i,v=0,c=0,d=0,s=0,w=0,a=0;

 clrscr();
 gets(dump);
 puts("Input a string");
 scanf("%s",in);
 strcpy(input,in);

 for(i=0;i<strlen(input);i++) input[i]=toupper(input[i]);
 strprop(input,&v,&c,&d,&s,&w,&a);

 printf("\nThe input string is %s",in);
 printf("\nThe number of digits = %d",d);
 printf("\nThe number of white spaces = %d",w);
 printf("\nThe number of alpabets are %d where there are\n%d\tvowel(s)\n%d\tconsonant(s)",a,v,c);
 printf("\nThe number of special characters are %d",s);
 getch();
}

strprop(char *pin,int *pv,int *pc,int*pd,int*ps,int*pw,int*pa)
{

 int i;

 for(i=0;*(pin+i)!='\0';i++)
 {

  if('0' <= *(pin+i)  &&  *(pin+i) <= '9') 	*pd=*pd+1;
  else if(' '== *(pin+i) || '\t' == *(pin+i))   *pw=*pw+1;
  else if('A'<= *(pin+i) && *(pin+i) <='Z')
   {
    *pa=*pa+1;
    if(*(pin+i)=='A'||
       *(pin+i)=='E'||
       *(pin+i)=='I'||
       *(pin+i)=='O'||
       *(pin+i)=='U') 	    *pv=*pv+1;
    else 		    *pc=*pc+1;
   }
  else *ps=*ps+1;
 }
}
