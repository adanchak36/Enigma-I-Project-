CC = gcc 

CFLAGS = -g -Wall

default = enigma 

enigma: main.o rotor_setup.o enigma_encode.o
	$(CC) $(CFLAGS) -o enigma main.o rotor_setup.o enigma_encode.o 

main.o: main.c enigma_encode.h rotor_setup.h machineStruct.h
	$(CC) $(CFLAGS) -c main.c 

rotor_setup.o: rotor_setup.c rotor_setup.h machineStruct.h configStruct.h
	$(CC) $(CFLAGS) -c rotor_setup.c 


enigma_encode.o: enigma_encode.c machineStruct.h 
	$(CC) $(CFLAGS) -c enigma_encode.c 