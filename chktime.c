#include <stdio.h>
#include <string.h>
#include <time.h>

int main (int argc, char *argv[]){

  clock_t startClock;
  clock_t endClock;
  double cpuSecondsConsumed;

  {
    startClock = clock();

    int i;
    char str[400];
    sprintf (str, "%0*d\n", 368, 0);
    for (i = 0; i < strlen(str); i++)
      printf ("%c", str[i]);

    endClock = clock();
    cpuSecondsConsumed = ((double)(endClock-startClock)) / CLOCKS_PER_SEC;
    printf ("#1 Time consumtion is: %f (Clocks per Sec, %u)\n", cpuSecondsConsumed, CLOCKS_PER_SEC);
  }

  printf ("\n");

  {
    startClock = clock();

    int i;
    char str[400];
    sprintf (str, "%0*d\n", 368, 0);
    int len = strlen(str);
    for (i = 0; i < len; i++)
      printf ("%c", str[i]);

    endClock = clock();
    cpuSecondsConsumed = ((double)(endClock-startClock)) / CLOCKS_PER_SEC;
    printf ("#2 Time consumtion is: %f (Clocks per Sec, %u)\n", cpuSecondsConsumed, CLOCKS_PER_SEC);
  }

  return 0;
}
