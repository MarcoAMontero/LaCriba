#!/bin/bash

#######Cache de 1MB
./cache.o ../../memory-trace-gcc.trace 1 1048576 4
./cache.o ../../memory-trace-gcc.trace 1 1048576 128
./cache.o ../../memory-trace-gcc.trace 1 1048576 2048
./cache.o ../../memory-trace-gcc.trace 1 1048576 16384

./cache.o ../../memory-trace-gcc.trace 2 1048576 4
./cache.o ../../memory-trace-gcc.trace 2 1048576 128
./cache.o ../../memory-trace-gcc.trace 2 1048576 2048
./cache.o ../../memory-trace-gcc.trace 2 1048576 16384

./cache.o ../../memory-trace-gcc.trace 4 1048576 4
./cache.o ../../memory-trace-gcc.trace 4 1048576 128
./cache.o ../../memory-trace-gcc.trace 4 1048576 2048
./cache.o ../../memory-trace-gcc.trace 4 1048576 16384
