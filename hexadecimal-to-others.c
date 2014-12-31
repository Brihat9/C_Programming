#include "nsc.h"

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
