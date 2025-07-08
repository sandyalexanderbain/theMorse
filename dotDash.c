// To simulate dot and dash in C.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DEBUG false
// Indented MACRO for checking value of a certain variable.
#define check(X) if (DEBUG) printf(#X " = %d \n", X);

// MACROS to use in function "translate"
#define five(Y, A, B, C, D, E) Y[0] = A; Y[1] = B, Y[2] = C; Y[3] = D; Y[4] = E;
#define four(Y, A, B, C, D) Y[0] = A; Y[1] = B, Y[2] = C; Y[3] = D;
#define three(Y, A, B, C) Y[0] = A; Y[1] = B, Y[2] = C;
#define two(Y, A, B) Y[0] = A; Y[1] = B;

void dot(void);
void dash(void);
int locate(char letter);
void translate(char letter, char morsePrint[]);

int main(void)
{
   char morsePrint[5] = {false};
   int temporary = 100; // Use integer 100 as a base point and invalid input will break the loop.

   char letter,
        one[5] = {'a', 'i'},
        two[5][2] = {{'h', 'i'}, {'t', 'o'}, {'a', 'm'}, {'o', 'r'}, {'d', 'o'}},
        three[5][3] = {{'t', 'h', 'e'}, {'p', 'e', 'n'}, {'a', 'n', 't'}, 
                       {'r', 'a', 't'}, {'c', 'a', 't'}};

   // noW stands for NumberOfWords. noL is NumberOfLetters --> (n)umber(o)f(L)etters
   int noW, noL;

   srand((unsigned) time(NULL)); // Initalises a random number generation.

   noW = rand() % 5 + 1; printf("noW = %d \n", noW); // + 1 changes the range from 0-2 to 1-3
   noL = rand() % 3 + 1; printf("noL = %d \n", noL);

   for (int i = 0; i < noW; i++) {
      printf("\n");
      for (int j = 0; j < noL; j++) {
         // printf("J = %d \n", j);
         //  FIX: one[j] does not cycle.
         if (noL == 1) letter = one[j];
         else if (noL == 2) letter = two[i][j];
         else if (noL == 3) letter = three[i][j];

         printf("letter = %c  ", letter);
         printf("     ");

         letter = locate(letter);

         // Toggle letter view and number listing.
         // printf(" %d. %c\n", j, userInput);

         translate(letter, morsePrint);

         for (int lC = 0; lC < 5; lC++) { // loopCount variable
            if (letter == 100) break;
            if (morsePrint[lC] == 1) dot();
            else if (morsePrint[lC] == 2) dash();
         }
         // Clean the array "morsePrint" after each char printed.
         five(morsePrint, 0, 0, 0, 0, 0);
         printf("\n");
      }
      // printf("i = %d \n", i);
   }

// Add small gaps between morse code characters.
printf("\n");

   if (DEBUG) {
      for (int lC = 0; lC < 5; lC++) {
         printf(" morsePrint[%d] = %d \n", lC, morsePrint[lC]);
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

int locate(char letter)
{
   int value = 0;

   switch (letter) {
      case 'a': value = 3; break;
      case 'b': value = 22; break;
      case 'c': value = 24; break;
      case 'd': value = 10; break;
      case 'e': value = 0; break;
      case 'f': value = 16; break;
      case 'g': value = 12; break;
      case 'h': value = 14; break;
      case 'i': value = 2; break;
      case 'j': value = 21; break;
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
      case 'w': value = 9; break;
      case 'x': value = 23; break;
      case 'y': value = 25; break;
      case 'z': value = 26; break;
      case '0': value = 61; break;
      case '1': value = 45; break;
      case '2': value = 37; break;
      case '3': value = 33; break;
      case '4': value = 31; break;
      case '5': value = 30; break;
      case '6': value = 46; break;
      case '7': value = 54; break;
      case '8': value = 58; break;
      case '9': value = 60; break;
      case '+': value = 40; break;
      case '=': value = 47; break;
      case '/': value = 48; break;
   }
   // printf("LOCATE, value = %d \n", value);
   return value;
}

void translate(char letter, char morsePrint[])
{
   switch (letter) {
      case 30: five(morsePrint, 1, 1, 1, 1, 1); break;
      case 31: five(morsePrint, 1, 1, 1, 1, 2); break;
      case 33: five(morsePrint, 1, 1, 1, 2, 2); break;
      case 37: five(morsePrint, 1, 1, 2, 2, 2); break;
      case 40: five(morsePrint, 1, 2, 1, 2, 1); break;
      case 45: five(morsePrint, 1, 2, 2, 2, 2); break;
      case 46: five(morsePrint, 2, 1, 1, 1, 1); break;
      case 47: five(morsePrint, 2, 1, 1, 1, 2); break;
      case 48: five(morsePrint, 2, 1, 1, 2, 1); break;
      case 54: five(morsePrint, 2, 2, 1, 1, 1); break;
      case 58: five(morsePrint, 2, 2, 2, 1, 1); break;
      case 60: five(morsePrint, 2, 2, 2, 2, 1); break;
      case 61: five(morsePrint, 2, 2, 2, 2, 2); break;

      case 14: four(morsePrint, 1, 1, 1, 1); break;
      case 15: four(morsePrint, 1, 1, 1, 2); break;
      case 16: four(morsePrint, 1, 1, 2, 1); break;
      case 18: four(morsePrint, 1, 2, 1, 1); break;
      case 20: four(morsePrint, 1, 2, 2, 1); break;
      case 21: four(morsePrint, 1, 2, 2, 2); break;
      case 22: four(morsePrint, 2, 1, 1, 1); break;
      case 23: four(morsePrint, 2, 1, 1, 2); break;
      case 24: four(morsePrint, 2, 1, 2, 1); break;
      case 27: four(morsePrint, 2, 1, 2, 2); break;
      case 26: four(morsePrint, 2, 2, 1, 1); break;
      case 25: four(morsePrint, 2, 2, 1, 2); break;

      case 6: three(morsePrint, 1, 1, 1); break;
      case 7: three(morsePrint, 1, 1, 2); break;
      case 8: three(morsePrint, 1, 2, 1); break;
      case 9: three(morsePrint, 1, 2, 2); break;
      case 10: three(morsePrint, 2, 1, 1); break;
      case 11: three(morsePrint, 2, 1, 2); break;
      case 12: three(morsePrint, 2, 2, 1); break;
      case 13: three(morsePrint, 2, 2, 2); break;

      case 2: two(morsePrint, 1, 1); break;
      case 3: two(morsePrint, 1, 2); break;
      case 4: two(morsePrint, 2, 1); break;
      case 5: two(morsePrint, 2, 2); break;

      case 0: morsePrint[0] = 1; break;
      case 1: morsePrint[0] = 2; break;
   }
   return;
}
