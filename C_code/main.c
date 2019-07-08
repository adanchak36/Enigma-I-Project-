#include <stdio.h>         // printf, scanf
#include "configStruct.h"  //configuration struct (holding user input to use for setup)
#include "machineStruct.h" //machine struct
#include "rotor_setup.h"   // getMachineInfo(), setup_Machine(), ringSet()
#include "enigma_encode.h" //getChar(),encryptPlugBoard(),encryptRotors()
#include <stdlib.h>        // sizeof

int main(void){
    char reflector[ALPH], left_rotor[ALPH], mid_rotor[ALPH], right_rotor[ALPH]; //declare the 3 rotors as local variables in main
    configMachine userConfig; 
    machine machine1; //struct create user's machine setup
    char plainC;      //character that is going to be encrypted
    char cipherC;     //encrypted character

    /* End of machine configuration input */
    
    setMachineOrder(&machine1); //implements rotor order
    setRingStart(&machine1);    //implements ring settings
    
    
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
    
    /*
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

