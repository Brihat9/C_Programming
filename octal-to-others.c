#include "nsc.h"

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
