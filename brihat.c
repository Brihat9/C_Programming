#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// main.c
void main_menu (void);
void convert_decimal (void);
void convert_binary (void);
void convert_octal (void);
void convert_hexadecimal (void);

// utilities.c
char* getstr(char* name, int size, FILE* fp);
char int2char (int n);
int char2int (char c);
float power (float x, int y);
void again (void);
int isdecimal (char *);
int isbinary(char* string);
int isoctal(char *);
int ishexa(char *);


// decimal-to-others.c
char* decimal2others(int decimal, unsigned short int base);
int others2decimal (char* others, unsigned short int base);

int main(void) {
     main_menu();
     return 0;
}

void main_menu (void) {
     int choice; char temp[100]={0};
     printf("\n\n");
     printf("WELCOME TO THE NUMBER SYSTEM CONVERTER\n");
     printf("----------------------------------------------\n");
     printf("   Select the type of input:   \n");
     printf("      1 - Decimal             \n");
     printf("      2 - Binary              \n");
     printf("      3 - Octal               \n");
     printf("      4 - Hexadecimal         \n");
     printf("    [ Q - Quit  ]              \n");
     printf("\n");
     while (strlen(temp) < 1) {
          printf("   Your choice? ");
          getstr(temp, sizeof(temp), stdin);
     }
     choice = temp[0];

     printf("\n");
     switch (choice) {
          case 'q': case 'Q':
               exit(0); break;
          case '1':
               convert_decimal(); break;
          case '2':
               convert_binary(); break;
          case '3':
               convert_octal(); break;
          case '4':
               convert_hexadecimal(); break;
          default:
               main_menu(); break;
     }
}

void convert_hexadecimal (void) {
     char hex[50]={0};
     while (strlen(hex) < 1) {
          printf("Enter an hexadecimal number: ");
          getstr(hex, sizeof(hex), stdin);
          if (!ishexa(hex)) {
               printf("ERROR --- NOT A VALID HEX NUMBER \n");
               *hex=0;
          }
     }
     int decimal = others2decimal(hex, 16);

     printf("\n");
     printf("   DEC = %d \n", decimal);
     printf("   BIN = %s \n", decimal2others(decimal, 2));
     printf("   OCT = %s \n", decimal2others(decimal, 8));
     printf("   HEX = %s \n", decimal2others(decimal, 16));

     again();
}


void convert_binary (void) {
     char binary[50]={0};
     while (strlen(binary)<1) {
          printf("Enter a binary number: ");
          getstr(binary, sizeof(binary), stdin);
          if (!isbinary(binary)) {
               printf("ERROR --- NOT A VALID BINARY NUMBER\n");
               *binary = 0;
          }
     }

     int decimal = others2decimal(binary, 2);

     printf("\n");
     printf("   DEC = %d \n", decimal);
     printf("   BIN = %s \n", decimal2others(decimal, 2));
     printf("   OCT = %s \n", decimal2others(decimal, 8));
     printf("   HEX = %s \n", decimal2others(decimal, 16));

     again();
}

void convert_decimal (void) {
     int decimal; char temp[10]={0};
     while (strlen(temp) < 1) {
          printf("Enter a decimal number: ");
          getstr(temp, sizeof(temp), stdin);
          if (!isdecimal(temp)) {
               printf("ERROR --- NOT A VALID DECIMAL NUMBER \n");
               *temp=0;
          }
     }
     decimal = atoi(temp);

     printf("\n");
     printf("   DEC = %d \n", decimal);
     printf("   BIN = %s \n", decimal2others(decimal, 2));
     printf("   OCT = %s \n", decimal2others(decimal, 8));
     printf("   HEX = %s \n", decimal2others(decimal, 16));

     again();
}

char* decimal2others (int decimal, unsigned short int base) {
     char newvalue[50]={0};
     int n = decimal;
     int len = 0, i=0;
     int rem[50]={0};

     for (len=0; n>0; len++, n/=base) {
          rem[len] = n % base;
     }

     for (i=0; i<len; i++) {
          newvalue[i] = int2char (rem[(len-1)-i]);
     }

     return newvalue;
}

int others2decimal (char* others, unsigned short int base) {
     int decimal = 0;
     int i;
     int len = strlen(others);
     for (i=0; i<strlen(others); i++) {
          decimal += char2int(others[len-1-i]) * power(base, i);
     }
     return decimal;
}

void convert_octal (void) {
     char octal[50]={0};
     while (strlen(octal) < 1) {
          printf("Enter an octal number: ");
          getstr(octal, sizeof(octal), stdin);
          if (!isoctal(octal)) {
               printf("ERROR --- NOT A VALID OCTAL NUMBER\n");
               *octal = 0;
          }
     }
     int decimal = others2decimal(octal, 8);

     printf("\n");
     printf("   DEC = %d \n", decimal);
     printf("   BIN = %s \n", decimal2others(decimal, 2));
     printf("   OCT = %s \n", decimal2others(decimal, 8));
     printf("   HEX = %s \n", decimal2others(decimal, 16));

     again();
}

char* getstr (char* name, int size, FILE* fp) {
     fgets(name, size, fp);
     if (strlen(name)>0 && name[strlen(name)-1]=='\n')
               name[strlen(name)-1]='\0';
     return name;
}

char int2char (int n) {
     if (n>=10)
          return (n+55);
     else if (n>=0 && n<10)
          return (n+48);
     else
          return int2char(-n);
}

int char2int (char c) {
     if (c>='A' && c<='Z')
          return (c-55);
     else
          return (c-48);
}

float power (float x, int y) {
     if (y==0)
          return 1;
     else if (y==1)
          return x;
     else if (y<0)
          return (1 / power(x, -y));
     else
          return x*power(x, y-1);
}

void again (void) {
     char c, temp[10];
     printf("\n");
     printf("Start again? (y/n) ");
     getstr(temp, sizeof(temp), stdin);
     c = temp[0];
     if (tolower(c)=='y')
          main_menu();
     else
          exit(0);
}

int isdecimal(char *s) {
     int i;
     for (i=0; i<strlen(s); i++) {
          if (s[i] < '0' || s[i] > '9')
               return 0;
     } return 1;
}

int isbinary(char *s) {
     int i;
     for (i=0; i<strlen(s); i++) {
      void convert_octal (void) {
     char octal[50]={0};
     while (strlen(octal) < 1) {
          printf("Enter an octal number: ");
          getstr(octal, sizeof(octal), stdin);
          if (!isoctal(octal)) {
               printf("ERROR --- NOT A VALID OCTAL NUMBER\n");
               *octal = 0;
          }
     }
     int decimal = others2decimal(octal, 8);

     printf("\n");
     printf("   DEC = %d \n", decimal);
     printf("   BIN = %s \n", decimal2others(decimal, 2));
     printf("   OCT = %s \n", decimal2others(decimal, 8));
     printf("   HEX = %s \n", decimal2others(decimal, 16));

     again();
}
    if (s[i] < '0' || s[i] > '1') {
               return 0;
          }
     } return 1;
}

int isoctal(char *s) {
     int i;
     for (i=0; i<strlen(s); i++) {
          if (s[i] < '0' || s[i] > '7')
               return 0;
     } return 1;
}

int ishexa(char *s) {
     int i;
     for (i=0; i<strlen(s); i++) {
          if (s[i] < '0') return 0;
          if (s[i] > '9' && s[i] < 'A') return 0;
          if (s[i] > 'F') return 0;
     } return 1;
}
