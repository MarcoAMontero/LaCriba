#se definen los objetos , estos son los archivos que necesitan
#para crear el ejecutable .
OBJS = prime.cpp
OBJS2 = prime.c
OBJS3 = prime_mpi.c

#Se define el compilador
CC = g++
CC2 = gcc
CC3 = mpicc
#Bandera de depuracion
DEBUG = -g

#Banderas de compilacion
CFLAGS = -Wall -c $(DEBUG) -pedantic

#Banderas para el linker
LFLAGS = -Wall $(DEBUG) -pedantic

#Archivo Ejecutable que se va a crear

TARGET = C_PLUS_PRIME
TARGET2 = C_PRIME
TARGET3 = C_PRIME_MPI

#Reglas a ejecutar cuando se ejecute make
all: 
	$(CC) $(OBJS) -o $(TARGET)
	$(CC2) $(OBJS2) -o $(TARGET2)
	$(CC3) $(OBJS3) -o $(TARGET3)
#Al digitar make clean se borraran todos los archivos compilados,
#note el -f en rm si no sabe para que sirve use el manueal de rm.
clean:
	rm -f *.o $(TARGET) $(TARGET2)

