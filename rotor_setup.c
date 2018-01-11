#include <stdio.h>
#include "rotor_setup.h"

void getMachineInfo(machine *machine1){
    int i; //counter
    
    printf("Walzenlage Eingeben:");
    scanf("%d %d %d", &machine1->rotor_order[0], &machine1->rotor_order[1], &machine1->rotor_order[2]);
    printf("\n");
    
    printf("Ringstellung Eingeben:");
    scanf("%d %d %d", &machine1->rotor_sett[0], &machine1->rotor_sett[1], &machine1->rotor_sett[2]);
    printf("\n");
    
    printf("Steckerverindungen Eingeben:");
    scanf("%c%c %c%c %c%c %c%c %c%c", &machine1->plug_board[0], &machine1->plug_board[1], &machine1->plug_board[2], &machine1->plug_board[3], &machine1->plug_board[4], &machine1->plug_board[5], &machine1->plug_board[6], &machine1->plug_board[7], &machine1->plug_board[8], &machine1->plug_board[9]); 
    printf("\n");
    
}//getMachineInfo




