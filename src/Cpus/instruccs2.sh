#!/bin/bash

#######Cache de 2MB
./cache.o ../../memory-trace-gcc.trace 1 2097152 4
./cache.o ../../memory-trace-gcc.trace 1 2097152 128
./cache.o ../../memory-trace-gcc.trace 1 2097152 2048
./cache.o ../../memory-trace-gcc.trace 1 2097152 16384

./cache.o ../../memory-trace-gcc.trace 2 2097152 4
./cache.o ../../memory-trace-gcc.trace 2 2097152 128
./cache.o ../../memory-trace-gcc.trace 2 2097152 2048
./cache.o ../../memory-trace-gcc.trace 2 2097152 16384

./cache.o ../../memory-trace-gcc.trace 4 2097152 4
./cache.o ../../memory-trace-gcc.trace 4 2097152 128
./cache.o ../../memory-trace-gcc.trace 4 2097152 2048
./cache.o ../../memory-trace-gcc.trace 4 2097152 16384
