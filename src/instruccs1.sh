#!/bin/bash

#######Cache de 64kB
./cache.o ../../memory-trace-gcc.trace 1 65536 4
./cache.o ../../memory-trace-gcc.trace 1 65536 128
./cache.o ../../memory-trace-gcc.trace 1 65536 2048
./cache.o ../../memory-trace-gcc.trace 1 65536 16384

./cache.o ../../memory-trace-gcc.trace 2 65536 4
./cache.o ../../memory-trace-gcc.trace 2 65536 128
./cache.o ../../memory-trace-gcc.trace 2 65536 2048
./cache.o ../../memory-trace-gcc.trace 2 65536 16384

./cache.o ../../memory-trace-gcc.trace 4 65536 4
./cache.o ../../memory-trace-gcc.trace 4 65536 128
./cache.o ../../memory-trace-gcc.trace 4 65536 2048
./cache.o ../../memory-trace-gcc.trace 4 65536 16384
