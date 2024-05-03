/*
 * CSE202 SP21 prog3 Program
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

// prototypes of the functions you need to write
data_t** allocate_memory();
void fillArray(data_t **a);
void multiply_no_opt(data_t **a, data_t **b, data_t **c);
void multiply_no_mem(data_t **a,data_t **b,data_t **c);
void multiply_unroll_2_1(data_t **a,data_t **b,data_t **c);
void multiply_unroll_2_2(data_t **a,data_t **b,data_t **c);
void multiply_unroll_4_1(data_t **a,data_t **b,data_t **c);
void multiply_unroll_4_4(data_t **a,data_t **b,data_t **c);
void multiply_unroll_8_1(data_t **a,data_t **b,data_t **c);
void multiply_unroll_8_8(data_t **a,data_t **b,data_t **c);


// main method
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
  // case 1: No optimization
  start = clock();
  multiply_no_opt(a, b, c);
  end = clock();
  printf("%-5d\t%-10ld\t", N, (end-start));
  // case 2: Eliminating memory reference
  start = clock();
  multiply_no_mem(a, b, c);
  end = clock();
  printf("%-10ld\t", (end-start));
  // case 3: loop unrolling 2x1
  start = clock();
  multiply_unroll_2_1(a, b, c);
  end = clock();
  printf("%-10ld\t", (end-start));
  // case 4: loop unrolling 2x2
  start = clock();
  multiply_unroll_2_2(a, b, c);
  end = clock();
  printf("%-10ld\t", (end-start));
   // case 5: loop unrolling 4x1
  start = clock();
  multiply_unroll_4_1(a, b, c);
  end = clock();
  printf("%-10ld\t", (end-start));
   // case 6: loop unrolling 4x4
  start = clock();
  multiply_unroll_4_4(a, b, c);
  end = clock();
  printf("%-10ld\t", (end-start));
   // case 7: loop unrolling 8x1
  start = clock();
  multiply_unroll_8_1(a, b, c);
  end = clock();
  printf("%-10ld\t", (end-start));
   // case 8: loop unrolling 8x8
  start = clock();
  multiply_unroll_8_8(a, b, c);
  end = clock();
  printf("%-10ld\n", (end-start));

}
/* Definition of the function allocate_memory
*  return a pointer to a two-dimensional array of size N x N
*/
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
// function to fill a matrix a[N][N] with random numbers
void fillArray(data_t **a){
  int i, j;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      a[i][j] = rand();//get random number
    }
  }
}
// Matrix multiplication with no optimization
void multiply_no_opt(data_t **a,data_t **b,data_t **c){
  int i, j,k;
  for(i=0; i<N; i++)
    for(j=0; j<N; j++){
      c[i][j] = 0;
      for(k=0; k<N; k++){
        c[i][j] += a[i][k] * b[k][j];
      }
    }
}
// Matrix multiplication with elimination
// of memory reference when possible
void multiply_no_mem(data_t **a,data_t **b,data_t **c){
  int i, j,k;
  for(i=0; i<N; i++)
    for(j=0; j<N; j++){
     data_t acc = 0; //use local variable to accumulate the result
      for(k=0; k<N; k++){
        acc += a[i][k] * b[k][j];
      }
      c[i][j] = acc;
    }
}
// Matrix multiplication with loop unrolling 2x1
void multiply_unroll_2_1(data_t **a,data_t **b,data_t **c){
  int i, j,k;
  int limit = N-1;
  for(i=0; i<N; i++)
    for(j=0; j<N; j++){
      data_t acc = 0;
      for(k=0; k<limit; k+=2){
        acc += a[i][k] * b[k][j] + a[i][k+1] * b[k+1][j];
      }
      c[i][j] = acc;
    }

  for(; i<N; i++){// to check any missing element
    for(; j<N; j++){
      data_t acc = 0;
      for(; k<N; k++){
        acc += a[i][k] * b[k][j];
      }
      c[i][j] = acc;
    }
  }
}
// Matrix multiplication with loop unrolling 2x2
void multiply_unroll_2_2(data_t **a,data_t **b,data_t **c){
  int i, j,k;
  int limit = N-1;
  for(i=0; i<N; i++)
    for(j=0; j<N; j++){
      data_t temp = 0;
      data_t temp2 = 0;
      for(k=0; k<limit; k+=2){
        temp += a[i][k] * b[k][j];
        temp2 += a[i][k+1] * b[k+1][j];
      }
      c[i][j] = temp + temp2;
    }

  for(; i<N; i++){// to check any missing element
    for(; j<N; j++){
      data_t acc = 0;
      for(; k<N; k++){
        acc += a[i][k] * b[k][j];
      }
      c[i][j] = acc;
    }
  }
}
// Matrix multiplication with loop unrolling 4x1
void multiply_unroll_4_1(data_t **a,data_t **b,data_t **c){
  int i, j,k;
  int limit = N-3;
  for(i=0; i<N; i++)
    for(j=0; j<N; j++){
      data_t temp = 0;
      for(k=0; k<limit; k+=4){
        temp += a[i][k] * b[k][j] + a[i][k+1] * b[k+1][j] + a[i][k+2] * b[k+2][j] + a[i][k+3] * b[k+3][j];
      }
      c[i][j] = temp;
    }

  for(; i<N; i++){// to check any missing element
    for(; j<N; j++){
      data_t acc = 0;
      for(; k<N; k++){
        acc += a[i][k] * b[k][j];
      }
      c[i][j] = acc;
    }
  }
}
// Matrix multiplication with loop unrolling 4x4
void multiply_unroll_4_4(data_t **a,data_t **b,data_t **c){
  int i, j,k;
  int limit = N-3;
  for(i=0; i<N; i++)
    for(j=0; j<N; j++){
      data_t temp = 0;
      data_t temp2 = 0;
      data_t temp3 = 0;
      data_t temp4 = 0;
      for(k=0; k<limit; k+=4){
        temp += a[i][k] * b[k][j];
        temp2 += a[i][k+1] * b[k+1][j];
        temp3 += a[i][k+2] * b[k+2][j];
        temp4 += a[i][k+3] * b[k+3][j];
      }
      c[i][j] = temp + temp2 + temp3 + temp4;
    }

  for(; i<N; i++){// to check any missing element
    for(; j<N; j++){
      data_t acc = 0;
      for(; k<N; k++){
        acc += a[i][k] * b[k][j];
      }
      c[i][j] = acc;
    }
  }
}
// Matrix multiplication with loop unrolling 8x1
void multiply_unroll_8_1(data_t **a,data_t **b,data_t **c){
  int i, j,k;
  int limit = N-7;
  for(i=0; i<N; i++)
    for(j=0; j<N; j++){
      data_t temp = 0;
      for(k=0; k<limit; k+=8){
        temp += a[i][k] * b[k][j] + a[i][k+1] * b[k+1][j] + a[i][k+2] * b[k+2][j] + a[i][k+3] * b[k+3][j] + a[i][k+4] * b[k+4][j] + a[i][k+5] * b[k+5][j] + a[i][k+6] * b[k+6][j] + a[i][k+7] * b[k+7][j];
      }
      c[i][j] = temp;
    }

  for(; i<N; i++){// to check any missing element
    for(; j<N; j++){
      data_t acc = 0;
      for(; k<N; k++){
        acc += a[i][k] * b[k][j];
      }
      c[i][j] = acc;
    }
  }
}
// Matrix multiplication with loop unrolling 8x8
void multiply_unroll_8_8(data_t **a,data_t **b,data_t **c){
  int i, j,k;
  int limit = N-7;
  for(i=0; i<N; i++)
    for(j=0; j<N; j++){
      data_t temp = 0;
      data_t temp2 = 0;
      data_t temp3 = 0;
      data_t temp4 = 0;
      data_t temp5 = 0;
      data_t temp6 = 0;
      data_t temp7 = 0;
      data_t temp8 = 0;
      for(k=0; k<limit; k+=8){
        temp += a[i][k] * b[k][j];
        temp2 += a[i][k+1] * b[k+1][j];
        temp3 += a[i][k+2] * b[k+2][j];
        temp4 += a[i][k+3] * b[k+3][j];
        temp5 += a[i][k+4] * b[k+4][j];
        temp6 += a[i][k+5] * b[k+5][j];
        temp7 += a[i][k+6] * b[k+6][j];
        temp8 += a[i][k+7] * b[k+7][j];
        
      }
      c[i][j] = temp + temp2 + temp3 + temp4 + temp5 + temp6 + temp7;
  }
  for(; i<N; i++){// to check any missing element
    for(; j<N; j++){
      data_t acc = 0;
      for(; k<N; k++){
        acc += a[i][k] * b[k][j];
      }
      c[i][j] = acc;
    }
  }
}
