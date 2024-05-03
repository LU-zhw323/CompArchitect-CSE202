#include <stdio.h>
#include <stdlib.h>

extern int fn1arg(int);     /* the extern keyword informs the compiler the function is defined outside this file */
extern int fn2args(int, int);
extern int fn3args(int, int, int);
extern int fn6args(int, int, int, int, int, int);
extern int fn8args(int *, char **);

int main(int argc, char **argv) {
  if (argc >= 2 && argc <= 9) {
    int numInts = argc - 1;             /* var to hold number of integers passed */
    int arr[numInts];                   /* create array to hold integers passed on command-line */
    for (int i = 0; i < numInts; i++)   /* load up the array of integers */
      arr[i] = atoi(argv[i+1]);         /* convert input string to int */
    switch (numInts) {                  /* call one or more functions based on number of integers passed */
      case 8: ;                         /* ';' added to avoid error that occurs when a declaration immediatly follows a label */
        fprintf(stdout, "%d", fn8args(&argc, argv)); /* need to access arguments through argv array */
        fprintf(stdout, " = fn(%d, %d, %d, %d, %d, %d, %d, %d)", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]);
        fprintf(stdout, "  <== Prof. Erle's cra-cra function\n");
        __attribute__ ((fallthrough));  /* supresses warning by informing compiler we intend to fall through */
      case 7:
      case 6:
        fprintf(stdout, "%d", fn6args(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]));
        fprintf(stdout, " = fn(%d, %d, %d, %d, %d, %d)  <== length of line in 3D space\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
        __attribute__ ((fallthrough));
      case 5:
      case 4:
      case 3:
        fprintf(stdout, "%d", fn3args(arr[0], arr[1], arr[2]));
        fprintf(stdout, " = fn(%d, %d, %d)  <== area of trapezoid\n", arr[0], arr[1], arr[2]);
        __attribute__ ((fallthrough));
      case 2:
        fprintf(stdout, "%d", fn2args(arr[0], arr[1]));
        fprintf(stdout, " = fn(%d, %d)  <== absolute difference\n", arr[0], arr[1]);
        __attribute__ ((fallthrough));
      default:
        fprintf(stdout, "%d", fn1arg(arr[0]));
        fprintf(stdout, " = fn(%d)  <== negate\n", arr[0]);
    }
  } else {
    fprintf(stderr, "Error: expecting 1 to 8 argument(s) on command-line\n");
    return 1;
  }
  return 0;
}

