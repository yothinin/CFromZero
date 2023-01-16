#include <stdio.h>

int main(int argc, char **argv)
{
  int i, bits = 32;
  unsigned int val = 65;
  char arr[bits+1];
  
  for (i = 0; i < bits; i++){
    arr[i] = ((val << i) >> (bits-1))+'0';
  }

  
  arr[i] = '\0';
  
  printf ("arr = %s\n", arr);

  return 0;
}



