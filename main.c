#include <stdio.h>         // printf, scanf
#include "machine_struct.h"// struct machine1, constant alphabet size
#include "rotor_setup.h"   // getMachineInfo(), setup_Machine(), ringSet()
#include "enigma_encode.h" // input_enigma()
#include <stdlib.h>        // sizeof


#define ALPH_LENGTH 27     //constant alphabet size  (check size issues with arrays + 1)



int main(void){
    char left_rotor[ALPH], mid_rotor[ALPH], right_rotor[ALPH]; //declare the 3 rotors as local variables in main
    //char plaintext; //declare the plaintext character being put into the machine
    machine machine1; //struct create user's machine setup

    getMachineInfo(&machine1);//Get user input for machine settings
    
    setup_Machine(left_rotor, mid_rotor, right_rotor, &machine1); //setup rotor order... ex:3 2 1
    
    //ringSet(left_rotor, mid_rotor, right_rotor, &machine1);
    
    printf("\nRight rotor: ");
    for(int i = 0; i < ALPH; i++){
        printf("%c", right_rotor[i]);
    }
    
    printf("\nMiddle rotor: ");
    for(int i = 0; i < ALPH; i++){
        printf("%c", mid_rotor[i]);
    }

    printf("\nLeft rotor: ");
    for(int i = 0; i < ALPH; i++){
        printf("%c", left_rotor[i]);
    }
    
    //print_array(&machine1);
   
    setup_rotors(left_rotor, mid_rotor, right_rotor, &machine1);
    /*
    plaintext = input_enigma(&machine1); 
    
    printf("%c", plaintext);
    */
    
    
    return(0);
    
}//MAIN END



