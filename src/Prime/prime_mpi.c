
/*************************************************
Francisco Molina Castro, Marco Antonio Montero Chavarría
This code generates prime numbers up to the first 5000 prime numbers  using
eratostenes' sieve method and open MPI library
/* run make
after that "mpirun -np <Insert a number of processes> C_PRIME_MPI" to run
/**********************************************************/
# include <stdio.h>
# include "mpi.h"
#include <stdlib.h>
# define N 48616 /* size of array to iterate on */
# include <math.h>
int sieve_eras(int Var);


int main(int argc, char *argv[]) {
  //important constants
  int i;
  long Endy;
  int Id;
  int Num;
  double Time;
  int Siz;
  int ProcSiz;
  long Start;
  long TempCont;
  long Cont;
  Cont,TempCont = 0;
  int Temp;
  int even_limit;
  even_limit = 48616;
  //MPI initialize according to OpenMpi.org
   MPI_Init (NULL, NULL);

   MPI_Comm_rank (MPI_COMM_WORLD, &Id); //get process id

   MPI_Comm_size (MPI_COMM_WORLD, &Num); //get number of proceses

   MPI_Barrier(MPI_COMM_WORLD);
// Timer initializes timer using N defined at the begining
   Time = -MPI_Wtime();
   Start = 2 + Id*(even_limit -1)/Num;
   Endy = 1 + (Id+1)*(even_limit -1)/Num;
   ProcSiz = (even_limit-1)/Num;
   Siz = Endy - Start+ 1;

// Defines the array used in the normal code prime.c
   for (i=Start; i<=Endy; i++){
    Temp = sieve_eras(i);
     if (Temp==1){ //if we got a prime
      TempCont++;
      }
   }
   //According to MPI now we have to synchronize counters and update the timer
    MPI_Reduce (&TempCont, &Cont, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    Time+= MPI_Wtime();
  //Show results on terminar
    if (Id == 0) {
     printf ("\n");
     printf ("These were the %ld uneven numbers before %d \n ",Cont,N);
     printf ("Total time %f ms\n", Time*1000);
    }
//now you have to close communication
  MPI_Finalize ();
  return 0;
}

//note this method is almost the same es the one implemented in prime.c but it doesnt print just returns 1 or 0 if even or uneven
int sieve_eras(int Var){  //use sieve method to return 1 if uneven or 0 if even
int Flag =1;  //most of this method was taken from OpenMpi example on their opensource code
int i;
int temp = Var%2;  // modulus operation
if(Var != 2 && temp == 0  || Var==1){
  Flag =0;
}
if(Flag != 0)
{
   for (i = 3; i<Var; i=i+2){
     if(Var%i==0){
       Flag = 0;
       break;
     }
     if(i*i > Var){
       break;
     }
   }
}
if(Flag ==1){
  printf("%d,",Var);
  return 1;
}
else{
  return 0;
}
}
