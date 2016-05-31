#Se definen los objetos , estos son los archivos que necesitan
#para crear el ejecutable .
OBJS = cache.cpp


#Se define el compilador
CC = g++

#Bandera de depuracion
DEBUG = -g

#Banderas de compilacion
CFLAGS = -Wall -c $(DEBUG) -pedantic

#Banderas para el linker
LFLAGS = -Wall $(DEBUG) -pedantic

#Archivo Ejecutable que se va a crear

TARGET = cache

#Reglas a ejecutar cuando se ejecute make
all: 
	$(CC) $(OBJS) -o $(TARGET) -std=c++11 -lboost_iostreams -lboost_system 

#Al digitar make clean se borraran todos los archivos compilados,
#note el -f en rm si no sabe para que sirve use el manueal de rm.
clean:
	rm -f *.o $(TARGET)

