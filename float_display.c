#include <stdio.h>
#include <string.h>

void getval (float * n3);
void dispbits (unsigned int val);
void floatbits (float val);
void printhex (int val);
void intbits (unsigned int val, int bit);

int main(int argc, char **argv)
{
  float n3 = 0.30f;
  float n7 = 0.70f;
  
  intbits(0x3f33333a, 32);
  
  printf ("%0.24f = ", 0.3f);
  floatbits (0.3f);
  
  printf ("n3 = %0.24f, n7 = %0.24f\n\n", n3, n7);
  printf ("address of n3 is: %p, \n", &n3);
  getval (&n3);
  printf ("address of n7 is: %p, \n", &n7);
  getval (&n7);

  printhex(200);

  return 0;
}

void getval(float * nn){
  unsigned int num = *(unsigned int*)nn;

  printf ("value inside is: 0x%x = ", num);
  dispbits (num);
}

void dispbits(unsigned int val){
  int mask = 1<<31;
  int i;
  for (i = 1; i<=32; i++){
    putchar (val & mask?'1':'0');
    val <<= 1;
  }
  printf ("\n\n");
}
	
	
void floatbits(float val){
  int i;
  int mask = 1<<31;
  unsigned int num = *(unsigned int*)&val;
  for (i = 1; i<=32; i++){
    putchar (num&mask?'1':'0');
    num <<= 1;
  }
  printf ("\n\n");
}

void intbits(unsigned int val, int bit){
 int i;
 int mask = 1<<(bit-1);
 for (i = 0; i < bit; i++){
    putchar (val & mask ? '1':'0');
    val <<= 1;
 }
 putchar ('\n');
}

void printhex(int val){
  int quotient;
  int i=1, temp;
  char hexadecimalNumber[100];
  quotient = val;
  while (quotient !=0){
    temp = quotient % 16;
    if (temp < 10)
      temp = temp+48; // 0-9
    else
      temp = temp+87; // a-f
    hexadecimalNumber[i++] = temp;
    quotient = quotient/16;
  }
  int j;
  printf ("Hexadecimal of %d is 0x", val);
  for (j = i; j>0; j--)
    putchar (hexadecimalNumber[j]);
}
