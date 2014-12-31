#include "nsc.h"

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
