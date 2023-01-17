#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NS printf ("--------------------\n");
#define NE printf ("========\n");

void bitwise(unsigned int a, unsigned int b);
char *dispBitsM(unsigned int val, int bits);
void printhex(int val);

int main (int argc, char *argv[]){
  unsigned int a = 0x11;
  unsigned int b = 0xff;
  
  bitwise (a, b);  

  return 0;
}

void bitwise (unsigned int a, unsigned int b){
  int LED2 = 2;
  int LED5 = 5;

  char *cpA = dispBitsM(a, 8);
  char *cpB = dispBitsM(b, 8);
  char *cpAandB = dispBitsM(a&b, 8);
  char *cpAorB = dispBitsM(a|b, 8);
  char *cpZero = dispBitsM(0, 8);

  unsigned int nStatus = 1<<LED2 | 1<<LED5; 	//Open bit 2 and 5
  char *cpOpen2_5 = dispBitsM(nStatus, 8);
  
  printf ("a = %s\n", cpA);
  printf ("b = %s\n", cpB); 
  NS;
  
  printf ("%s &\ta&b\n", cpA);
  printf ("%s\n", cpB);
  NE;
  printf ("%s\tCheck bits\n\n", cpAandB);
  
  printf ("%s |\ta|b\n", cpA);
  printf ("%s\n", cpB);
  NE;
  printf ("%s\tSet bits\n", cpAorB);
  NS;
  printf ("%s\tAll bits is zero\n", cpZero);
  printf ("%s\t1<<2|<<5 Set bit 2 and 5 to 1\n", cpOpen2_5);
  NS;
  
  printf ("LED status is:  %s\n", cpOpen2_5);
  char *cpStatus2 = dispBitsM(nStatus & 1<<LED2, 8);
  char *cpStatus5 = dispBitsM(nStatus & 1<<LED5, 8);
  if (nStatus & 1<<LED2)
    printf ("LED 3 is open\t%s\t%s & %s\n", cpStatus2, cpOpen2_5, cpStatus2);
  if (nStatus & 1<<LED5)
    printf ("LED 6 is open\t%s\t%s & %s\n", cpStatus5, cpOpen2_5, cpStatus5);

  if (nStatus > 0)
    NS;
  
}

/*
 * Function : dispBitsM
 * Parameter: unsigned int val  เป็นตัวเลขที่จะแปลงให้เป็นเลขฐานสอง
 *            int bits          จำนวนบิตที่จะแสดง
 * Return   : char *            เป็นชุดข้อความที่จองไว้หน่วยความจำ
 *                              (ต้อง free ตัวแปรที่รองรับด้วยทุกครั้ง)
 *
 */
char *dispBitsM(unsigned int val, int bits){
  char arr[bits+1];
  char *arrRet = malloc(sizeof(arr)/sizeof(arr[0])); // เหมือนกับ malloc(bits+1);
  int i;
  int mask = 1 << (bits-1);
  for (i = 0; i < bits; i++){
    arr[i] = val & mask ? '1':'0';
    val <<= 1;
  }
  arr[i] = '\0';
  strcpy (arrRet, arr);

  return arrRet; // ต้องใช้คำสั่ง free กับตัวแปรที่รองรับด้วย
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
