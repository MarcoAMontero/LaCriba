/**********************************
Tarea programada 1. Estructuras 2 IE-0
Authors: Francisco Molina C., Marco Montero C.
Cache memory tracer
To compile: g++ cache.cpp -o cache.o -std=c++11 -lboost_iostreams -lboost_system
To run: ./cache.o <memory file> <associativity> <cache size> <block size>
***********************************/


#include <iostream> /* input, output */
#include <sstream>
#include <fstream> /* read file*/
#include <random> /* cpp11 random by hardware */
//#include "gnuplot-iostream/gnuplot-iostream.h" /* GNUplot plotting library */
#include <algorithm> /*array shifting*/
#include <iomanip> /* decimal cout*/




using namespace std;


int main(int argc, char *argv[])
{

    //Argument test
    //cout << "There are " << argc << " arguments:\n";
    // Loop through each argument and print its number and value
    //for (int count=0; count < argc; ++count)
    //    cout << count << " " << argv[count] << '\n';

    //Open the file given in the first argument
    ifstream myfile(argv[1]);   //open to read
    string line,temp;                //string: <hex memory address> <L/S>
    int misses=0,count=0;
    long hextemp;
    const int associativity=atoi(argv[2]);
    const int cachesize=atoi(argv[3]);
    const int blocksize=atoi(argv[4]);
    const int blockcount=(cachesize/blocksize);
    const int setquant=blockcount/associativity;//If associtivity is 1, the cache is directly mapped
    const int blocksperset=blockcount/setquant;
    cout << "blkcnt: " << blockcount << "."  << endl;

    //cout << "sets: " << setquant << "."  << endl;
    //cout << "blksperset: " << blocksperset << "."  << endl <<endl;


    vector <vector <long>> memarray(setquant,vector<long>(blocksperset));//saves first position of the block of memory brought


    while (getline(myfile, line))/* Get a line and save it in a string */
    {
        count++;
        istringstream iss(line);
        iss >> temp;
        hextemp = stol(temp,0,16);

        //cout << "dir: " << hex << hextemp << "."  << endl;
        iss >> temp;

        int setval=hextemp%setquant;//This is the index in mem hier. To know which set
        //cout << "index: " << hex << setval << "."  << endl;

        long tagval=hextemp/(blockcount*associativity);//This is the tag in mem hier.
        //cout << "tag: " << hex << tagval << "."  << endl;

        for (int i = 0; i < blocksize; ++i)
        {
            if (memarray[setval][i]==0)//Miss, set is not full
            {
                memarray[setval][i]=tagval;
                misses++;
                //cout << "Oblig. Miss"<< endl;
                break;
            } else
            {
                if (tagval==memarray[setval][i])//Hit
                {
                    //cout << "Hit"<< endl;
                    break;
                }
                else
                {
                    if (i==blocksize-1)//miss
                    {
                        for (int j = 0; j < blocksperset-2; ++j)//FIFO
                        {
                            memarray[setval][j] = memarray[setval][j+1];

                        }
                        memarray[setval][blocksperset-1] = tagval;
                        //cout << "Full Miss"<< endl;
                        misses++;
                    }
                }
            }
        }
        //cout << "R/W: "<< temp << "."  << endl;
        //cout << endl;
    }

    cout << "Misses: "<< dec << misses << endl;
    cout << "Count: "<< dec << count << endl;
    double mrate = (float)misses/(float)count;
    //cout << setprecision(2) << fixed;
    cout << "Miss Rate: " <<  mrate << endl;

    //std::cout << "Press enter to exit." << std::endl;
	//std::cin.get();

    return 0;
}
