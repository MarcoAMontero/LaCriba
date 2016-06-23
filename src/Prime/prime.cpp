/*************************************************
Francisco Molina Castro, Marco Antonio Montero Chavarría
This code generates prime numbers up to the first 5000 prime numbers  using
eratostenes' sieve method
/* to compile use make
then "time ./C_PLUS_PRIME" to run
/**********************************************************/
using namespace std;
#include <iostream>
#include <stdio.h>
#define N 48616 /* size of array to iterate on */




int main() {
  int i, j, nums[N+1],  x = 1;
  std::cout << "The first 5000 prime numbers are:\n" << std::endl;


  for( i = 2; i <= N; i ++ ){
      if( nums[i] != 1 ) {
        printf("%d,",i);
        for( j = 2; ( i * j ) <= N; j++){ //mark all even numbers as unusable
          nums[i * j] = 1;
        }
     }
}
  std::cout << "\n" << std::endl;
  return 0;
}
