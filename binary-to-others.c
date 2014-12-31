#include "nsc.h"

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
