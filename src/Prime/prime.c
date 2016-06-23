/*************************************************
Francisco Molina Castro, Marco Antonio Montero Chavarría
This code generates prime numbers up to the first 5000 prime numbers  using
eratostenes' sieve method
/* run make
after that "time ./C_PRIME" to run
/**********************************************************/
# include <stdio.h>
#include <stdio.h>
# define N 48616 /* size of array to iterate on */



int main() {

  int i, j, nums[N+1],  x = 1;
  printf("The first 5000 prime numbers are:\n");


  for( i = 2; i <= N; i ++ ){ //iterate on element array mark non uneven number as 1
      if( nums[i] != 1 ) {
        printf("%d,",i);
        for( j = 2; ( i * j ) <= N; j++){ //mark all even numbers as unusable
          nums[i * j] = 1;
        }
     }
}
  printf("\n");
}
