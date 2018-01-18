#ifndef MACHINE_STRUCT_H
#define MACHINE_STRUCT_H

typedef struct machine{
    int rotor_order[3];//(1,2,3)
    int rotor_sett[3];// (03,18,14)
    char plug_board1[10]; //input
    char plug_board2[10]; //scramble
} machine;

#endif
