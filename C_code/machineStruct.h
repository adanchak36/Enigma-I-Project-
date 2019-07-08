#ifndef MACHINE_STRUCT_H
#define MACHINE_STRUCT_H

struct Plug{
    char plainT;
    char cipherT;
};

typedef struct machine{
    char rightRotor[27];
    char midRotor[27];
    char leftRotor[27];
    char reflector[27];
    struct Plug pBoard[10];

} machine;

#endif

#define ALPH 27 
