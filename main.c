#include <stdio.h>         // printf, scanf
#include "machine_struct.h"// struct machine1, constant alphabet size
#include "rotor_setup.h"   // getMachineInfo(), setup_Machine(), ringSet()
#include "enigma_encode.h" //getChar(),encryptPlugBoard(),encryptRotors()
#include <stdlib.h>        // sizeof


#define ALPH_LENGTH 27     //constant alphabet size  (check size issues with arrays + 1)



int main(void){
    char reflector[ALPH], left_rotor[ALPH], mid_rotor[ALPH], right_rotor[ALPH]; //declare the 3 rotors as local variables in main
    machine machine1; //struct create user's machine setup
    char plainC; //character that is going to be encrypted
    char cipherC; //encrypted character

    getMachineInfo(&machine1);//Get user input for machine settings
    
    setup_Machine(reflector, left_rotor, mid_rotor, right_rotor, &machine1); //setup rotor order... ex:3 2 1
    
    ringSet(left_rotor, mid_rotor, right_rotor, &machine1);
    
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
    
    printf("\nReflector: ");
    for(int i = 0; i < ALPH; i++){
        printf("%c", reflector[i]);
    }
    printf("\n"); 
    
    plainC = getChar(); //input plaintext character
    
    encryptPlugBoard(&plainC, &machine1); //plugboard scramble
    cipherC = encryptRotors(plainC, &machine1, right_rotor, mid_rotor, left_rotor, reflector);//plaintext goes through rotors
    
    printf("Encrypted character: %c", cipherC);
    
    /*
    plaintext = input_enigma(&machine1); 
    
    printf("%c", plaintext);
    */
    
    
    return(0);
    
}//MAIN END

