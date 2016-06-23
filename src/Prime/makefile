#se definen los objetos , estos son los archivos que necesitan
#para crear el ejecutable .
OBJS = prime.cpp
OBJS2 = prime.c

#Se define el compilador
CC = g++
CC2 = gcc
#Bandera de depuracion
DEBUG = -g

#Banderas de compilacion
CFLAGS = -Wall -c $(DEBUG) -pedantic

#Banderas para el linker
LFLAGS = -Wall $(DEBUG) -pedantic

#Archivo Ejecutable que se va a crear

TARGET = C_PLUS_PRIME
TARGET2 = C_PRIME

#Reglas a ejecutar cuando se ejecute make
all: 
	$(CC) $(OBJS) -o $(TARGET)
	$(CC2) $(OBJS2) -o $(TARGET2)
#Al digitar make clean se borraran todos los archivos compilados,
#note el -f en rm si no sabe para que sirve use el manueal de rm.
clean:
	rm -f *.o $(TARGET) $(TARGET2)

