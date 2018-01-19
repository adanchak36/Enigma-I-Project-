#include <stdio.h>
#include "machine_struct.h"
#include "rotor_setup.h"
#include <string.h> //strcpy

void getMachineInfo(machine *machine1){
    //let's do some bounds checking for user input (DANGEROUS RIGHT NOW!!!!!!!!!!!!)
        // extra functions including do while checks 
    
    printf("Walzenlage Eingeben:");
    scanf("%d %d %d", &machine1->rotor_order[0], &machine1->rotor_order[1], &machine1->rotor_order[2]);
    printf("\n");
    
    printf("Ringstellung Eingeben:");
    scanf("%d %d %d", &machine1->rotor_sett[0], &machine1->rotor_sett[1], &machine1->rotor_sett[2]);
    printf("\n");
    
    printf("Steckerverindungen Eingeben:");
    scanf("%c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c", &machine1->plug_board1[0], &machine1->plug_board2[0], &machine1->plug_board1[1], &machine1->plug_board2[1], &machine1->plug_board1[2], &machine1->plug_board2[2], &machine1->plug_board1[3], &machine1->plug_board2[3], &machine1->plug_board1[4], &machine1->plug_board2[4],&machine1->plug_board1[5], &machine1->plug_board2[5],&machine1->plug_board1[6], &machine1->plug_board2[6],&machine1->plug_board1[7], &machine1->plug_board2[7],&machine1->plug_board1[8], &machine1->plug_board2[8],&machine1->plug_board1[9], &machine1->plug_board2[9]);
    
    printf("%c", machine1->plug_board1[0]);
    
    printf("\n");
    
}//getMachineInfo

void setup_Machine(char left_rotor[], char mid_rotor[], char right_rotor[], machine *machine1){
    int i;
    char rotor_1[26] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    char rotor_2[26] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    char rotor_3[26] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    char rotor_4[26] = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
    char rotor_5[26] = "VZBRGITYUPSDNHLXAWMJQOFECK";
    //M4 Machine rotors below 
    //char rotor_6[26] = "JPGVOUMFYQBENHZRDKASXLICTW";
    //char rotor_7[26] = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
    //char rotor_8[26] = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
    
    //probably should be pointers
    for(i = 0; i < 3; i++){
        if (machine1->rotor_order[i] == 1){
            if (i == 0){
                strcpy(left_rotor, rotor_1);
            }else if (i == 1){
                strcpy(mid_rotor, rotor_1);
            }else{
                strcpy(right_rotor, rotor_1);
            }
            //i = 0 left
            //i = 1 mid
            //i = 2 right
        }else if (machine1->rotor_order[i] == 2){
            if(i == 0){
                strcpy(left_rotor, rotor_2);
            }else if (i == 1){
                strcpy(mid_rotor, rotor_2);
            }else{
                strcpy(right_rotor, rotor_2);
            }
        }else if (machine1->rotor_order[i] == 3){
            if (i == 0){
                strcpy(left_rotor, rotor_3);
            }else if (i == 1){
                strcpy(mid_rotor, rotor_3);
            }else{
                strcpy(right_rotor, rotor_3);
            }
        }else if (machine1->rotor_order[i] == 4){
            if (i == 0){
                strcpy(left_rotor, rotor_4);
            }else if (i == 1){
                strcpy(mid_rotor, rotor_4);
            }else{
                strcpy(right_rotor, rotor_4);
            }
            
        }else{//5
            if (i == 0){
                strcpy(left_rotor, rotor_5);
            }else if (i == 1){
                strcpy(mid_rotor, rotor_5);
            }else{
                strcpy(right_rotor, rotor_5);
            }
            
        }
    }//end of for loop
}





