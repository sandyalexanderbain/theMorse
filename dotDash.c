// To simulate dot and dash in C.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DEBUG false
#define check(X) printf(#X " = %d \n", X);
#define five(Y, A, B, C, D, E) Y[0] = A; Y[1] = B, Y[2] = C; Y[3] = D; Y[4] = E;
#define four(Y, A, B, C, D) Y[0] = A; Y[1] = B, Y[2] = C; Y[3] = D;
#define three(Y, A, B, C) Y[0] = A; Y[1] = B, Y[2] = C;

void dot(void);
void dash(void);
int locate(char input);

int main(void)
{
   char input, morsePrint[5] = {false};
   int aP = 100; // artificialPointer variable

   printf("Enter a letter to convert to morse code: ");
   scanf(" %c", &input);
   printf("\n     ");

   if (DEBUG) check(aP);
   aP = locate(input);
   if (DEBUG) check(aP);

   // Prevent Changing the first character to • when not valid input.
   if (input != 'e' && aP == 0) aP = 100;

   switch (aP) {
      case 0: case 2: case 3: case 6: case 7: case 8: case 9: case 14: case 15: case 16: case 18:
      case 20: case 21: case 30: case 31: case 33: case 37: case 40: case 45: {
         morsePrint[0] = 1; 
         break;
      }
   }

   switch (aP) {
      case 2: case 6: case 7: case 14: case 15: case 16: case 30: case 31: case 33: case 37:
         morsePrint[1] = 1; break;
   }

   switch (aP) {
      case 6: case 14: case 15: case 30: case 31: case 33:
         morsePrint[2] = 1; break;
   }

   switch (aP) {
      case 7: case 16: case 37:
         morsePrint[2] = 2; break;
   }

   switch (aP) {
      case 14: case 16: case 30: case 31: morsePrint[3] = 1; break;
      case 15: case 33: case 37: morsePrint[3] = 2; break;
   }

   switch (aP) {
      case 30: morsePrint[4] = 1; break;
      case 31: case 33: case 37: morsePrint[4] = 2; break;
   }

   if (DEBUG) check(aP);

   for (int lC = 0; lC < 5; lC++) { // loopCount variable
      if (aP == 100) {
         printf("%c\n\t is an invalid input!!! \n", input);
         break;
      }
      if (morsePrint[lC] == 1) dot();
      else if (morsePrint[lC] == 2) dash();
   }

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
   return value;
}
