#include "nsc.h"

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
