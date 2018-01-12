#include <stdio.h> //printf, scanf
#include "rotor_setup.h"
#include <stdlib.h> //sizeof
//#include "header.h" // use header functions

int main(void){
    char left_rotor[26], mid_rotor[26], right_rotor[26];
    int i; //DEBUG
    
    machine machine1; //struct create user's machine setup
    
    getMachineInfo(&machine1);
    
    setup_Machine(left_rotor, mid_rotor, right_rotor, &machine1);
    
    
    printf("%d %d %d\n", machine1.rotor_order[0], machine1.rotor_order[1], machine1.rotor_order[2]);//DEBUG
    
    for(i = 0; i < sizeof(left_rotor); i++){
        printf("%c", left_rotor[i]);
    }
    
    printf("\n");

    for(i = 0; i < sizeof(mid_rotor); i++){
        printf("%c", mid_rotor[i]);
    }
    
    printf("\n");
    
    for(i = 0; i < sizeof(right_rotor); i++){
        printf("%c", right_rotor[i]);
    }
    
    printf("\n");
    
    
    setup_rotors(left_rotor, mid_rotor, right_rotor, &machine1);
    
    return(0);
    
}//MAIN END

