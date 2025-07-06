// To simulate dot and dash in C.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DEBUG true

void dot(void);
void dash(void);
int locate(char input);

int main(void)
{
   char input, array[5] = {false};
   int aP = 0; // artificialPointer variable
   int database[5][40] = {[0][0] = 1, // DOT
                          [0][1] = 2,
                          [1][2] = 1, [1][3] = 2, // DOT
                          [1][4] = 1, [1][5] = 2,
                          [2][6] = 1, [2][7] = 2, [2][8] = 1, [2][9] = 2, // DOT
                          [2][10] = 1, [2][11] = 2, [2][12] = 1, [2][13] = 2,
      [0][2] = 1, [0][3] = 1, [0][6] = 1, [0][7] = 1}; //[0][8] = 1, [0][9] = 1,

// 0, 2, 3, 6, 7, 8, 9//, 14, 15, 16, 18, 20, 21, 30, 31, 33, 37, 40, 45  NOTE: set to 1
// 3, 6//, 14, 15, 30, 31, 33  NOTE: set to 1
// 7//, 16, NOTE: set to 2

   printf("Enter a letter to convert to morse code: ");
   scanf(" %c", &input);
   printf("\n     ");

   aP = locate(input);

   for (int lC = 0; lC < 5; lC++) { // loopCount variable
      if (database[lC][aP] == 1) dot();
      else if (database[lC][aP] == 2) dash();
      else break;
   }

   printf("\n");

   if (DEBUG) {
      for (int lC = 0; lC < 5; lC++) {
         for (int lR = 0; lR < 40; lR++) {
            printf("database[%d][%d] = %d    ", lC, lR, database[lC][lR]);
         }
         printf("\n");
      }
   }

   return 0;
}

void dot() {
   printf("• ");
}

void dash() {
   printf("--- ");
}

int locate(char input)
{
   int value = 0;

   switch (input) {
      case 'a': value = 3; break;
      case 'b': value = 22; break;
      case 'c': value = 24; break;
      case 'd': value = 10; break;
      case 'e': value = 0; break;
      case 'f': value = 16; break;
      case 'g': value = 12; break;
      case 'h': value = 14; break;
      case 'i': value = 2; break;
      case 'j': value = 20; break;
      case 'k': value = 11; break;
      case 'l': value = 18; break;
      case 'm': value = 5; break;
      case 'n': value = 4; break;
      case 'o': value = 13; break;
      case 'p': value = 20; break;
      case 'q': value = 27; break;
      case 'r': value = 8; break;
      case 's': value = 6; break;
      case 't': value = 1; break;
      case 'u': value = 7; break;
      case 'v': value = 15; break;
      case 'w': value = 8; break;
      case 'x': value = 23; break;
      case 'y': value = 25; break;
      case 'z': value = 26; break;
   }
   return value;
}
