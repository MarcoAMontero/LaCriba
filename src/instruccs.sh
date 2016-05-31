#!/bin/bash

g++ cache.cpp -o cache.o -std=c++11 -lboost_iostreams -lboost_system

#######Cache de 1kB
./cache.o ../../memory-trace-gcc.trace 1 1024 2
./cache.o ../../memory-trace-gcc.trace 1 1024 4
./cache.o ../../memory-trace-gcc.trace 1 1024 64
./cache.o ../../memory-trace-gcc.trace 1 1024 128

./cache.o ../../memory-trace-gcc.trace 2 1024 2
./cache.o ../../memory-trace-gcc.trace 2 1024 4
./cache.o ../../memory-trace-gcc.trace 2 1024 64
./cache.o ../../memory-trace-gcc.trace 2 1024 128

./cache.o ../../memory-trace-gcc.trace 4 1024 2
./cache.o ../../memory-trace-gcc.trace 4 1024 4
./cache.o ../../memory-trace-gcc.trace 4 1024 64
./cache.o ../../memory-trace-gcc.trace 4 1024 128

#######Cache de 64kB
#./cache.o ../../memory-trace-gcc.trace 1 65536 4
#./cache.o ../../memory-trace-gcc.trace 1 65536 128
#./cache.o ../../memory-trace-gcc.trace 1 65536 2048
#./cache.o ../../memory-trace-gcc.trace 1 65536 16384

#./cache.o ../../memory-trace-gcc.trace 2 65536 4
#./cache.o ../../memory-trace-gcc.trace 2 65536 128
#./cache.o ../../memory-trace-gcc.trace 2 65536 2048
#./cache.o ../../memory-trace-gcc.trace 2 65536 16384

#./cache.o ../../memory-trace-gcc.trace 4 65536 4
#./cache.o ../../memory-trace-gcc.trace 4 65536 128
#./cache.o ../../memory-trace-gcc.trace 4 65536 2048
#./cache.o ../../memory-trace-gcc.trace 4 65536 16384

#######Cache de 1MB
#./cache.o ../../memory-trace-gcc.trace 1 1048576 4
#./cache.o ../../memory-trace-gcc.trace 1 1048576 128
#./cache.o ../../memory-trace-gcc.trace 1 1048576 2048
#./cache.o ../../memory-trace-gcc.trace 1 1048576 16384
#
#./cache.o ../../memory-trace-gcc.trace 2 1048576 4
#./cache.o ../../memory-trace-gcc.trace 2 1048576 128
#./cache.o ../../memory-trace-gcc.trace 2 1048576 2048
#./cache.o ../../memory-trace-gcc.trace 2 1048576 16384
#
#./cache.o ../../memory-trace-gcc.trace 4 1048576 4
#./cache.o ../../memory-trace-gcc.trace 4 1048576 128
#./cache.o ../../memory-trace-gcc.trace 4 1048576 2048
#./cache.o ../../memory-trace-gcc.trace 4 1048576 16384
#
########Cache de 2MB
#./cache.o ../../memory-trace-gcc.trace 1 2097152 4
#./cache.o ../../memory-trace-gcc.trace 1 2097152 128
#./cache.o ../../memory-trace-gcc.trace 1 2097152 2048
#./cache.o ../../memory-trace-gcc.trace 1 2097152 16384
#
#./cache.o ../../memory-trace-gcc.trace 2 2097152 4
#./cache.o ../../memory-trace-gcc.trace 2 2097152 128
#./cache.o ../../memory-trace-gcc.trace 2 2097152 2048
#./cache.o ../../memory-trace-gcc.trace 2 2097152 16384
#
#./cache.o ../../memory-trace-gcc.trace 4 2097152 4
#./cache.o ../../memory-trace-gcc.trace 4 2097152 128
#./cache.o ../../memory-trace-gcc.trace 4 2097152 2048
#./cache.o ../../memory-trace-gcc.trace 4 2097152 16384
