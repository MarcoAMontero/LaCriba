/*************************************************
Francisco Molina Castro, Marco Antonio Montero Chavarría
This code generates prime numbers up to the first 5000 prime numbers  using
eratostenes' sieve method
/* to compile use gcc prime.c -o prime */
/* to run use ./prime/
/* to check execution time in unix type : time ./prime */
/**********************************************************/
# include <stdio.h>
//# include <mpi.h>
#include <stdio.h>
# define N 48616 /* size of array to iterate on */
//# include <omp.h>



int main() {

  int i, j, nums[N+1],  x = 1;
  printf("The first 5000 prime numbers are:\n");


  for( i = 2; i <= N; i ++ ){
      if( nums[i] != 1 ) {
        printf("%d,",i);
        for( j = 2; ( i * j ) <= N; j++){ //mark all even numbers as unusable
          nums[i * j] = 1;
        }
     }
}
  printf("\n");
}
