#include <stdio.h> //printf, scanf
#include "machine_struct.h"
#include <stdlib.h> //sizeof


int main(void){
    char left_rotor[26], mid_rotor[26], right_rotor[26];
    //int i; //DEBUG
    char plaintext;
    int a, b; 
    
    machine machine1; //struct create user's machine setup
    
    getMachineInfo(&machine1);
    
    setup_Machine(left_rotor, mid_rotor, right_rotor, &machine1);
    
    for (a = 0; a < 10; a++){
        printf("%c", machine1.plug_board1[a]);
        if (a == 9){
            printf("\n");
        }
    }//for end (DEBUG)
    
    for (b = 0; b < 10; b++){
        printf("%c", machine1.plug_board1[a]);
        if (b == 9){
            printf("\n");
        }
    }//for end (DEBUG)
    
    //setup_rotors(left_rotor, mid_rotor, right_rotor, &machine1);
    
    plaintext = input_enigma(&machine1); 
    
    printf("%c", plaintext);
    
    
    
    return(0);
    
}//MAIN END

