#include "nsc.h"

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
