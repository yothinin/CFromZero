#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *dispBits1 (unsigned int val, int bits);
char *dispBits2 (unsigned int val, int bits);
char *dispBitsM (unsigned int val, int bits);

int main(int argc, char **argv)
{
  float f = 0.3f;
  unsigned int *fPtr = (unsigned int*)&f;
  unsigned int num = *fPtr;

  char *cBits1 = dispBits1(num, 32);
  char *cBits2 = dispBits2(num, 32);
  char *cBitsM = dispBitsM(num, 32); //ในฟังค์ชันนี้ใช้ malloc

  printf ("dispBits1(%x, 32) = %s\n", num, cBits1);
  printf ("dispBits2(%x, 32) = %s\n", num, cBits2);
  printf ("dispBitsM(%x, 32) = %s\n", num, cBitsM);

  free (cBitsM); //คืนหน่วยความจำเพราะในฟังค์ชันจองพื้นที่ไว้

  return 0;
}

char *dispBits1(unsigned int val, int bits){
  int i, mask;
  char arr[bits+1]; // สร้างอะเรย์สำหรับเก็บตัวอักขระเลขฐานสอง

  mask = 1<<(bits-1);
  for (i = 0; i < bits; i++){
    arr[i] = val & mask ? '1' : '0';
    val <<= 1;
  }

  arr[i] = '\0';

  return arr;
}

char *dispBits2(unsigned int val, int bits){
  char arr[bits+1];
  int i;
  int mask = 1 << (bits-1);
  for (i = 0; i < bits; i++){
    arr[i] = val & mask ? '1':'0';
    val <<= 1;
  }

  arr[i] = '\0';
  char *ret = arr;
  return ret;
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
