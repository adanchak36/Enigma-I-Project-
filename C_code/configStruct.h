#ifndef CONFIG_STRUCT_H
#define CONFIG_STRUCT_H

typedef struct configMachine{
    int rotor_order[3];//(1,2,3)
    int rotor_sett[3];// (03,18,14)
    char reflector; //(B) 
    char plug_board1[10]; //input
    char plug_board2[10]; //scramble
} configMachine;

#endif

#define ALPH 27 //constant alphabet size 
