/* Marco Antonio Montero Chavarría
this code generates prime numbers base on a variable entered by the user, using
erastostenes' criba method*/
/* to compile use g++ main.cpp -o main */
/* to run use ./main <type value>*/
using namespace std;

#include <iostream>  /* cin cout, args */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

int main(int argc, char *argv[])
{
  int size = atoi(argv[1]);
  bool numbers[size];
  numbers[0] = false;
  numbers[1] = false;
  for(int i = 2; i <= size; ++i){
      numbers[i] = true;
  }
  for(int i = 2; i*i <= size; ++i) {
      if(numbers[i]) {
          for(int j = 2; i*j <= size; ++j)
              numbers[i*j] = false;
      }
  }
  std::cout << "Los números primeros encontrados son" << std::endl;
  for(int i=2; i <= size; ++i){
  if(numbers[i]){
  std::cout <<  i  << ",";
  }


  }
  std::cout << " " << std::endl;
return 0;
}
