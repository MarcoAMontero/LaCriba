/**********************************
Tarea programada 1. Estructuras 2 IE-0
Authors: Francisco Molina C., Marco Montero C.
2 CPUs cache coherency simulator, MESI protocol implemented
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

    //-------------Argument test--------------------
    //cout << "There are " << argc << " arguments:\n";
    // Loop through each argument and print its number and value
    //for (int count=0; count < argc; ++count)
    //    cout << count << " " << argv[count] << '\n';

    //Open the file given in the first argument
    ifstream myfile(argv[1]);   //open to read
    string line,temp;           //string: <hex memory address> <L/S>
    int count=0;
    bool parity=true;
    long hextemp;
    string hexl;
    const int associativity=1;//atoi(argv[2]);
    const int cachesize1=8192;//atoi(argv[3]);
    const int cachesize2=64768;//atoi(argv[4]);
    const int blocksize=16;//atoi(argv[5]);
    const int blockcount1=(cachesize1/blocksize);
    const int blockcount2=(cachesize2/blocksize);
    const int setquant1=blockcount1/associativity;//If associtivity is 1, the cache is directly mapped
    const int setquant2=blockcount2/associativity;//If associtivity is 1, the cache is directly mapped
    const int blocksperset=blockcount1/setquant1;
    cout << "blkcnt1: " << blockcount1 << "."  << endl;
    cout << "sets1: " << setquant1 << "."  << endl;
    cout << "blkcnt2: " << blockcount2 << "."  << endl;

    //cout << "sets: " << setquant << "."  << endl;
    //cout << "blksperset: " << blocksperset << "."  << endl <<endl;


    vector <long> memarray1(setquant1);//saves first position of the block of memory brought
    vector <char> statearray1(setquant1,'I');//saves first position of the block of memory brought
    vector <long> memarray2(setquant2);//saves first position of the block of memory brought
    vector <char> statearray2(setquant2, 'I');//saves first position of the block of memory brought

    int setval1;
    int setval2;
    long tagval1;
    long tagval2;

    while (getline(myfile, line))/* Get a line and save it in a string */
    {
        istringstream iss(line);
        iss >> temp;

        hextemp = stol(temp,0,16);
        hexl = temp;
        //cout << "dir: " << hex << hextemp << "."  << endl;
        iss >> temp;
        cout << "R/W: "<< temp << "."  << endl;
        setval1=hextemp%setquant1;//This is the index in mem hier. To know which set
        setval2=hextemp%setquant2;//This is the index in mem hier. To know which set
        //cout << "index: " << hex << setval << "."  << endl;

        tagval1=hextemp/(blockcount1*associativity);//This is the tag in mem hier.
        tagval2=hextemp/(blockcount2*associativity);//This is the tag in mem hier.

        if(parity){

            //cout << "tag: " << hex << tagval << "."  << endl;
            if (temp=="L"){//Miss, set is not full
            cout << "reading"<< endl;
                if (memarray1[setval1]==0)//Miss, set is not full
                {
                    //cout << "miss"<< endl;

                    memarray1[setval1]=tagval1;
                    //misses++;
                } else
                {
                    if (setval1!=memarray1[setval1])//Hit
                    {
                            memarray1[setval1] = tagval1;
                            //cout << "Full Miss"<< endl;
                    }
                }
                if (memarray2[setval2]==tagval2)// on the other cpu
                {
                    statearray1[setval1]='S';
                    statearray2[setval2]='S';
                }
                else{
                    statearray1[setval1]='E';
                }
                //break;
            }
            else {//Miss, set is not full
            cout << "writing"<< endl;
                if (memarray1[setval1]==0)//Miss, set is not full
                {
                    //cout << "miss"<< endl;

                    memarray1[setval1]=tagval1;
                    //misses++;
                } else
                {
                    if (tagval1!=memarray1[setval1]){//full miss
                            memarray1[setval1] = tagval1;
                            //cout << "Full Miss"<< endl;
                    }//else is a hit
                }
                statearray1[setval1]='M';
                statearray2[setval2]='I';
                //break;
            }
            parity=false;
        } else {

            //cout << "tag: " << hex << tagval << "."  << endl;
            if (temp=="L"){//Miss, set is not full
            cout << "reading"<< endl;
                if (memarray2[setval2]==0)//Miss, set is not full
                {
                    //cout << "miss"<< endl;

                    memarray2[setval2]=tagval2;
                    //misses++;
                } else
                {
                    if (setval2!=memarray2[setval2])//Hit
                    {
                            memarray2[setval2] = tagval2;
                            //cout << "Full Miss"<< endl;
                    }
                }
                if (memarray1[setval1]==tagval1)// on the other cpu
                {
                    statearray1[setval1]='S';
                    statearray2[setval2]='S';
                }
                else{
                    statearray2[setval2]='E';
                }
                //break;
            }
            else {//Miss, set is not full
            cout << "writing"<< endl;
                if (memarray2[setval2]==0)//Miss, set is not full
                {
                    //cout << "miss"<< endl;

                    memarray2[setval2]=tagval1;
                    //misses++;
                } else
                {
                    if (tagval2!=memarray2[setval2]){//full miss
                            memarray2[setval2] = tagval2;
                            //cout << "Full Miss"<< endl;
                    }//else is a hit
                }
                statearray2[setval2]='M';
                statearray1[setval1]='I';
                //break;
            }
            parity=true;
        }

        cout << "Cpu1 State of : " << hexl << " is " << statearray1[setval1] << endl;
        cout << "Cpu2 State of : " << hexl << " is " << statearray2[setval2] << endl;
        cout << endl;
    }

    //std::cout << "Press enter to exit." << std::endl;
	//std::cin.get();

    return 0;
}
