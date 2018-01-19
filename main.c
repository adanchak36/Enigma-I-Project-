#include <stdio.h>         // printf, scanf
#include "machine_struct.h"// struct machine1
#include "rotor_setup.h"   // getMachineInfo(), setup_Machine(), setup_rotors()
#include "enigma_encode.h" // input_enigma()
#include <stdlib.h>        // sizeof


int main(void){
    char left_rotor[26], mid_rotor[26], right_rotor[26];
    char plaintext;
    
    machine machine1; //struct create user's machine setup
    
    getMachineInfo(&machine1);
    
    setup_Machine(left_rotor, mid_rotor, right_rotor, &machine1);
    
    print_array(&machine1);
   
    //setup_rotors(left_rotor, mid_rotor, right_rotor, &machine1);
    
    plaintext = input_enigma(&machine1); 
    
    printf("%c", plaintext);
    
    
    
    return(0);
    
}//MAIN END

