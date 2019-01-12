#include <stdio.h> //sscanf()
#include "machine_struct.h" //constant alphabet size 
#include "rotor_setup.h"
#include <string.h> //strcpy

void getMachineInfo(machine *machine1){
    
    //probably a lot of buffer overflows but I don't care (i think thats user error dogg)
    
    printf("Walzenlage Eingeben:");
    scanf("%d %d %d", &machine1->rotor_order[0], &machine1->rotor_order[1], &machine1->rotor_order[2]); //implement sscanf()
    printf("\n");
    
    printf("Ringstellung Eingeben:");
    scanf("%d %d %d", &machine1->rotor_sett[0], &machine1->rotor_sett[1], &machine1->rotor_sett[2]);
    printf("\n");
    
    printf("Enter reflector: ");
    scanf(" %c", &machine1->reflector);
    printf("\n");
    
    printf("Steckerverindungen Eingeben:");
    scanf("%c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c", &machine1->plug_board1[0], &machine1->plug_board2[0], &machine1->plug_board1[1], &machine1->plug_board2[1], &machine1->plug_board1[2], &machine1->plug_board2[2], &machine1->plug_board1[3], &machine1->plug_board2[3], &machine1->plug_board1[4], &machine1->plug_board2[4],&machine1->plug_board1[5], &machine1->plug_board2[5],&machine1->plug_board1[6], &machine1->plug_board2[6],&machine1->plug_board1[7], &machine1->plug_board2[7],&machine1->plug_board1[8], &machine1->plug_board2[8],&machine1->plug_board1[9], &machine1->plug_board2[9]);
    
    printf("%c\n", machine1->plug_board1[0]); //debuGGG
    
}// end of getMachineInfo

void setup_Machine(char reflector[], char left_rotor[], char mid_rotor[], char right_rotor[], machine *machine1){
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
            strncpy(right_rotor, rotor_1, ALPH);
            break;
        case 2:
            strncpy(right_rotor, rotor_2, ALPH);
            break;
        case 3:
            strncpy(right_rotor, rotor_3, ALPH);
            break;
        case 4:
            strncpy(right_rotor, rotor_4, ALPH);
            break;
        case 5:
            strncpy(right_rotor, rotor_5, ALPH);
            break;
    }
    
    switch(machine1->rotor_order[1]){ //input correct user settings into mid_rotor[]
        case 1:
            strncpy(mid_rotor, rotor_1, ALPH);
            break;
        case 2:
            strncpy(mid_rotor, rotor_2, ALPH);
            break;
        case 3:
            strncpy(mid_rotor, rotor_3, ALPH);
            break;
        case 4:
            strncpy(mid_rotor, rotor_4, ALPH);
            break;
        case 5:
            strncpy(mid_rotor, rotor_5, ALPH);
            break;
    }
    
    switch(machine1->rotor_order[2]){ //input correct user settings into left_rotor[]
        case 1:
            strncpy(left_rotor, rotor_1, ALPH);
            break;
        case 2:
            strncpy(left_rotor, rotor_2, ALPH);
            break;
        case 3:
            strncpy(left_rotor, rotor_3, ALPH);
            break;
        case 4:
            strncpy(left_rotor, rotor_4, ALPH);
            break;
        case 5:
            strncpy(left_rotor, rotor_5, ALPH);
            break;
    }
    
    switch(machine1->reflector){
        case 'B':
            strncpy(reflector, reflect_B, ALPH);
            break; 
    }
    
}


void ringSet(char left_rotor[], char mid_rotor[], char right_rotor[], machine *machine1){ //ring settings, so where the rotor starts
    //23 02 17
    char temp_rotor[ALPH]; //Shifting array with temporary holder
    int i;
    int z = 0; //counter for temp array
    int start;
    
    /*Shift right rotor*/
    start = (machine1->rotor_sett[0] - 1);
    
    for(i = start; i < ALPH; i++){
        temp_rotor[z] = right_rotor[i];
        z++; //iterating temp ctr
    }
    
    for(i = 0; i < start; i++){
        temp_rotor[z] = right_rotor[i];
        z++;
    }
    
    /*Debug*/
    printf("temp array for right: ");
    for(int i = 0; i < ALPH; i++){
        printf("%c", temp_rotor[i]);
    }
    
    for(i = 0; i < ALPH; i++){
        right_rotor[i] = temp_rotor[i]; //strcpy is not going well
    }
    
    //strncpy(right_rotor, temp_rotor, ALPH); //copy array contents over
    
    /*Shift for mid rotor*/
    start = (machine1->rotor_sett[1] - 1);
    z = 0;
    for(i = start; i < ALPH; i++){
        temp_rotor[z] = mid_rotor[i];
        z++; //iterating temp ctr
    }
    
    for(i = 0; i < start; i++){
        temp_rotor[z] = mid_rotor[i];
        z++;
    }
    
    for(i = 0; i < ALPH; i++){
        mid_rotor[i] = temp_rotor[i]; //strcpy is not going well
    }
    
    /*Shifrt for left rotor*/
    start = (machine1->rotor_sett[2] - 1);
    z = 0;
    for(i = start; i < ALPH; i++){
        temp_rotor[z] = left_rotor[i];
        z++; //iterating temp ctr
    }
    
    for(i = 0; i < start; i++){
        temp_rotor[z] = left_rotor[i];
        z++;
    }
    
    for(i = 0; i < ALPH; i++){
        left_rotor[i] = temp_rotor[i]; //strcpy is not going well
    }
    
}








