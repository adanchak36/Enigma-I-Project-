#include <stdio.h> //sscanf()
#include "machineStruct.h" //constant alphabet size
#include "rotor_setup.h"
#include <string.h> //strcpy

void setMachineOrder(machine *machine1){
    
    char rotor_1[ALPH] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    char rotor_2[ALPH] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    char rotor_3[ALPH] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    char rotor_4[ALPH] = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
    char rotor_5[ALPH] = "VZBRGITYUPSDNHLXAWMJQOFECK";
    //M4 Machine rotors below
    //char rotor_6[ALPH] = "JPGVOUMFYQBENHZRDKASXLICTW";
    //char rotor_7[ALPH] = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
    //char rotor_8[ALPH] = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
    char reflect_B[ALPH] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    
    
    switch(machine1->rotor_order[0]){ //input correct user settings into right_rotor[]
        case 1:
            strncpy(machine1->right_rotor, rotor_1, ALPH);
            break;
        case 2:
            strncpy(machine1->right_rotor, rotor_2, ALPH);
            break;
        case 3:
            strncpy(machine1->right_rotor, rotor_3, ALPH);
            break;
        case 4:
            strncpy(machine1->right_rotor, rotor_4, ALPH);
            break;
        case 5:
            strncpy(machine1->right_rotor, rotor_5, ALPH);
            break;
    }//end of switch for right rotor
    
    switch(machine1->rotor_order[1]){ //input correct user settings into mid_rotor[]
        case 1:
            strncpy(machine1->mid_rotor, rotor_1, ALPH);
            break;
        case 2:
            strncpy(machine1->mid_rotor, rotor_2, ALPH);
            break;
        case 3:
            strncpy(machine1->mid_rotor, rotor_3, ALPH);
            break;
        case 4:
            strncpy(machine1->mid_rotor, rotor_4, ALPH);
            break;
        case 5:
            strncpy(machine1->mid_rotor, rotor_5, ALPH);
            break;
    }//end of switch for mid rotor
    
    switch(machine1->rotor_order[2]){ //input correct user settings into left_rotor[]
        case 1:
            strncpy(machine1->left_rotor, rotor_1, ALPH);
            break;
        case 2:
            strncpy(machine1->left_rotor, rotor_2, ALPH);
            break;
        case 3:
            strncpy(machine1->left_rotor, rotor_3, ALPH);
            break;
        case 4:
            strncpy(machine1->left_rotor, rotor_4, ALPH);
            break;
        case 5:
            strncpy(machine1->left_rotor, rotor_5, ALPH);
            break;
    }//end of switch for right rotor
    
    switch(machine1->reflector_set){
        case 'B':
            strncpy(machine1->reflector, reflect_B, ALPH);
            break;
    }//end of switch for reflector
    
}/*setMachineOrder()*/

void setRingStart(machine *machine1){ //ring settings, so where rotor starts
    //23 02 17
    char temp_rotor[ALPH]; //Shifting array with temporary holder
    int i;
    int z = 0; //counter for temp array
    int start;
    
    /*Shift right rotor*/
    start = (machine1->rotor_sett[0] - 1);
    
    for(i = start; i < ALPH; i++){
        temp_rotor[z] = machine1->right_rotor[i];
        z++; //iterating temp ctr
    }
    
    for(i = 0; i < start; i++){
        temp_rotor[z] = machine1->right_rotor[i];
        z++;
    }
    
    
    for(i = 0; i < ALPH; i++){
        machine1->right_rotor[i] = temp_rotor[i]; //strcpy is not going well
    }
    
    //strncpy(right_rotor, temp_rotor, ALPH); //copy array contents over
    
    /*Shift for mid rotor*/
    start = (machine1->rotor_sett[1] - 1);
    z = 0;
    for(i = start; i < ALPH; i++){
        temp_rotor[z] = machine1->mid_rotor[i];
        z++; //iterating temp ctr
    }
    
    for(i = 0; i < start; i++){
        temp_rotor[z] = machine1->mid_rotor[i];
        z++;
    }
    
    for(i = 0; i < ALPH; i++){
        machine1->mid_rotor[i] = temp_rotor[i]; //strcpy is not going well
    }
    
    /*Shifrt for left rotor*/
    start = (machine1->rotor_sett[2] - 1);
    z = 0;
    for(i = start; i < ALPH; i++){
        temp_rotor[z] = machine1->left_rotor[i];
        z++; //iterating temp ctr
    }
    
    for(i = 0; i < start; i++){
        temp_rotor[z] = machine1->left_rotor[i];
        z++;
    }
    
    for(i = 0; i < ALPH; i++){
        machine1->left_rotor[i] = temp_rotor[i]; //strcpy is not going well
    }
    
}/*setRingStart()*/ 
