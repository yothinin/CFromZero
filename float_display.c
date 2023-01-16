#include <stdio.h>

unsigned int getVal(unsigned int *n3);
char *dispBits (unsigned int val, int bits);

void dispbits (unsigned int val);
void getval (float * n3);
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
  printf ("\n\n");

  // n7 เป็นตัวแปรแบบ float เมื่ออ้างถึงตำแหน่งก็จะเป็น pointer to float
  // ดังนั้นเราต้องแปลงจาก pointer to float ให้เป็น pointer to unsigned int
  // ค่า n7Ptr จะถูกส่งไปให้กับฟังค์ชัน getVar() 
  unsigned int *n7Ptr = (unsigned int*)&n7;
  char *hex = dispBits(getVal(n7Ptr), 32);
  printf ("hex: %s\n", hex);

  printf ("getVal(n7Ptr) = 0x%x\n", getVal(n7Ptr)); //ส่งค่า unsigned กลับ
  // แสดงค่าบิตโดยอ่านจากฟังค์ชัน getVar()
  printf ("dispBits(getVal(n7Ptr), 32)) = %s\n", dispBits(getVal(n7Ptr), 32)); 
   
  // สั่งให้แสดงค่าบิตโดยกำหนดตัวเลขโดยตรง
  printf ("dispBits(0x%x) = %s\n", 0x3f19999a, dispBits(0x3f19999a, 32));

  return 0;
}

/*
 * Function : unsigned int getVal(float *nn) 
 * Purpose  : ใช้อ่านค่าตัวเลขที่อยู่ในหน่วยความจำ
 * Parameter: โปรแกรมจะรับค่าพารามิเตอร์ 1 ค่า คือ
 *          : float *nn - เป็นพอยเตอร์ของตำแหน่งที่เราจะอ่าน
 * Return   : ส่งค่ากลับเป็น unsigned int ซึ่งเป็นค่าของตัวแปรที่อ่านได้ พิมพ์ด้วย %x ได้
 */
//unsigned int getVal(float *nn){
unsigned int getVal(unsigned int *nn){
  unsigned int num = *(unsigned int *)nn;
  return num;
}

/*
 * Function  : char * dispBits(unsigned int val, int bits)
 * Purpose   : ใช้สำหรับแปลงค่าตัวเลขฐานสิบหรือสิบหกให้เป็นเลขฐานสอง
 * Parameter : val   - ข้อมูลชนิด unsigned int เป็นตัวเลขที่ต้องการจะแปลงเป็นเลขฐานสอง
 *           : bits  - ข้อมูลชนิด int เป็นตัวเลขสำหรับกำหนดจำนวนบิตที่จะแสดงผล
 * Returned  : char* - ส่งข้อมูลชุดตัวอักษรกลับไปยังฟังค์ชันที่เรียก สามารถพิมพ์ด้วย %s ได้ 
 */
char *dispBits(unsigned int val, int bits){
  char arr[bits+1];
  int i;
  int mask = 1 << (bits-1);
  for (i = 0; i < bits; i++){
    arr[i] = val & mask ? '1':'0';
    val <<= 1;
  }

  arr[i] = '\0';
  char *ret = arr;
  return ret; // Wrong, should have unknowed bihavior because scope of stack.
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
