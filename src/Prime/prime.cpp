/*************************************************
Francisco Molina Castro, Marco Antonio Montero Chavarría
This code generates prime numbers base on a variable entered by the user, using
eratostenes' criba method
/* to compile use g++ prime.cpp -o prime */
/* to run use ./prime <type value>*/
/* to check execution time in unix run time ./prime
/**********************************************************/
using namespace std;
#include <iostream>
#include <stdio.h>
#define N 48616 /* size of array to iterate on */
     

     
int main() {
  int i, j, nums[N+1],  x = 1;
  puts("The first 5000 prime numbers are:\n");
  for( i = 2; i <= N; i ++ ){
      if( nums[i] != 1 ) {
        printf("%d,",i);
        for( j = 2; ( i * j ) <= N; j++){ //mark all even numbers as unusable
          nums[i * j] = 1;
        }
     }
}
  
  return 0;
}
