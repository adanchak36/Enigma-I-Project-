#ifndef MACHINESTRUCT_H
#define MACHINESTRUCT_H

struct Plug{
    char plainT;
    char cipherT;
};

typedef struct machine{
    char right_rotor[27];
    char mid_rotor[27];
    char left_rotor[27];
    char reflector[27];
    struct Plug pBoard[10];

} machine;

#endif

#define ALPH 27 
