#include <stdio.h>         // printf, scanf
#include "configStruct.h"  //configuration struct (holding user input to use for setup)
#include "machineStruct.h" //machine struct
#include "rotor_setup.h"   // getMachineInfo(), setup_Machine(), ringSet()
#include "enigma_encode.h" //getChar(),encryptPlugBoard(),encryptRotors()
#include <stdlib.h>        // sizeof

int main(void){
    char reflector[ALPH], left_rotor[ALPH], mid_rotor[ALPH], right_rotor[ALPH]; //declare the 3 rotors as local variables in main
    configMachine userConfig; //configuration settings for user input
    machine machine1; //struct create user's machine setup
    char plainC;      //character that is going to be encrypted
    char cipherC;     //encrypted character

    /* Arduino inputs the configuration settings -> userConfig */
    userConfig.rotor_order[0] = 3; 
    userConfig.rotor_order[1] = 2; 
    userConfig.rotor_order[2] = 1; 
    userConfig.reflector = 'B'; 

    setMachineOrder(&userConfig, &machine1); //implements rotor order
    //setRingStart(&machine1);    //implements ring settings

    printf("\nRight rotor: ");
    for(int i = 0; i < ALPH; i++){
        printf("%c", machine1.right_rotor[i]);
    }
    
    printf("\nMiddle rotor: ");
    for(int i = 0; i < ALPH; i++){
        printf("%c", machine1.mid_rotor[i]);
    }

    printf("\nLeft rotor: ");
    for(int i = 0; i < ALPH; i++){
        printf("%c", machine1.left_rotor[i]);
    }
    
    printf("\nReflector: ");
    for(int i = 0; i < ALPH; i++){
        printf("%c", machine1.reflector[i]);
    }
    printf("\n"); 

    plainC = 'G'; 
    encrypt(plainC, &machine1); 
    

    
    return(0);
    
}//MAIN END

