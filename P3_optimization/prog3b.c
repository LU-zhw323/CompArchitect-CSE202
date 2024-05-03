/*
 * CSE202 SP21 prog3b Program
 * Full Name:
 * Full Lehigh Email Address:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* The following C pre-processor statements allow you to compile
*  the program with options -DDOUBLE or -DLONG to select type double or long for data_t
*  data_t is set to int if none of the two options is used
*/
#if defined (DOUBLE)
 typedef double data_t;
#elif defined (LONG)
  typedef long data_t;
#else
    typedef int data_t;
#endif
/* The following C pre-processor statements allow you to compile
*  the program with options -DN=200 or any value for N
*  N is set to 100 if the option is not used
*/
#ifndef N
#define N 100
#endif
// Prototypes of the functions you need to write
void fillArray(data_t **a);
data_t** allocate_memory();
void multiply_no_opt_ijk(data_t **a, data_t **b, data_t **c);
void multiply_no_opt_jik(data_t **a, data_t **b, data_t **c);
void multiply_no_opt_jki(data_t **a, data_t **b, data_t **c);
void multiply_no_opt_kji(data_t **a, data_t **b, data_t **c);
void multiply_no_opt_kij(data_t **a, data_t **b, data_t **c);
void multiply_no_opt_ikj(data_t **a, data_t **b, data_t **c);

int main(){

  data_t **a;
  data_t **b;
  data_t **c;
  a = allocate_memory();
  b = allocate_memory();
  c = allocate_memory();
  fillArray(a);
  fillArray(b);
  clock_t start, end;

  start = clock();
  multiply_no_opt_ijk(a, b, c);
  end = clock();
  printf("%-5d\t%-10ld\t", N, (end-start));

  start = clock();
  multiply_no_opt_jik(a, b, c);
  end = clock();
  printf("%-10ld\t", (end-start));

  start = clock();
  multiply_no_opt_jki(a, b, c);
  end = clock();
  printf("%-10ld\t", (end-start));

  start = clock();
  multiply_no_opt_kji(a, b, c);
  end = clock();
  printf("%-10ld\t", (end-start));

  start = clock();
  multiply_no_opt_kij(a, b, c);
  end = clock();
  printf("%-10ld\t", (end-start));

  start = clock();
  multiply_no_opt_ikj(a, b, c);
  end = clock();
  printf("%-10ld\n", (end-start));
  return 0;
}
// Definition of the function to allocate memory for the array
data_t** allocate_memory(){
  data_t** array = (data_t** )malloc(sizeof(data_t*)*N);
  for(int i=0; i<N; i++){
    if ((array[i] = (data_t *)calloc(N, sizeof(data_t))) == 0) {  /* here I used calloc (slightly different syntax), and combined it with error checking; 
                                                                 we can combine in this way because the value assigned to arr[i] is also returned */
        fprintf(stderr, "Unable to allocate array of data_t objects\n");
        exit(99);  /* can use any nonzero exit code */
    }
}
  return array;
}
// function to fill a matrix with random numbers
void fillArray(data_t **a){
  int i, j;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      a[i][j] = rand();//get random number
    }
  }
}
// Multiply function using the order i-j-k for the three loops
void multiply_no_opt_ijk(data_t **a, data_t **b, data_t **c){
  int i,j,k;
  for(i = 0; i<N; i++)
    for(j = 0; j<N; j++){
      for(k = 0; k<N; k++){
        c[i][j] += a[i][k] * b[k][j];
      }
    }
}
// Multiply function using the order j-i-k for the three loops
void multiply_no_opt_jik(data_t **a, data_t **b, data_t **c){
  int i,j,k;
  for(j = 0; j<N; j++)
    for(i = 0; i<N; i++){
      for(k = 0; k<N; k++){
        c[i][j] += a[i][k] * b[k][j];
      }
    }
}
// Multiply function using the order j-k-i for the three loops
void multiply_no_opt_jki(data_t **a, data_t **b, data_t **c){
  int i,j,k;
  for(j = 0; j<N; j++)
    for(k = 0; k<N; k++){
      for(i = 0; i<N; i++){
        c[i][j] += a[i][k] * b[k][j];
      }
    }
}
// Multiply function using the order k-j-i for the three loops
void multiply_no_opt_kji(data_t **a, data_t **b, data_t **c){
  int i,j,k;
  for(k = 0; k<N; k++)
    for(j = 0; j<N; j++){
      for(i = 0; i<N; i++){
        c[i][j] += a[i][k] * b[k][j];
      }
    }
}
// Multiply function using the order k-i-j for the three loops
void multiply_no_opt_kij(data_t **a, data_t **b, data_t **c){
  int i,j,k;
  for(k = 0; k<N; k++)
    for(i = 0; i<N; i++){
      for(j = 0; j<N; j++){
        c[i][j] += a[i][k] * b[k][j];
      }
    }
}
// Multiply function using the order i-k-j for the three loops
void multiply_no_opt_ikj(data_t **a, data_t **b, data_t **c){
  int i,j,k;
  for(i = 0; i<N; i++)
    for(k = 0; k<N; k++){
      for(j = 0; j<N; j++){
        c[i][j] += a[i][k] * b[k][j];
      }
    }
}
