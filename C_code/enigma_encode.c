#include "enigma_encode.h"
#include "machineStruct.h"
#include <stdio.h> //printf, scanf
#include <stdlib.h> //sizeof

static int getPosition(char c);
static int getInvertPos(char c, char rotor[]);


/*void encryptPlugBoard(char *plainC, machine *machine1){
    int i;
    
    for(i = 0; i < sizeof(machine1->plug_board1); i++){ //check if plainC is in plugboard
        if(*plainC == machine1->plug_board1[i]){
            *plainC = machine1->plug_board2[i];
        }
    }
} */

static int getPosition(char c){
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < ALPH; i++){
        if(c == alphabet[i]){
            return i;
        }
    }
    return 0; 
}

static int getInvertPos(char c, char rotor[]){
    for(int i = 0; i < ALPH; i++){
        if(c == rotor[i]){
            return i;
        }
    }
    return 0;
}

char encrypt(char plainC, machine *machine1){
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int position; 
    char c; 

    position = getPosition(plainC); 
    printf("%d\n", position);
    c = machine1->right_rotor[position]; 
    printf("%c\n", c);

    position = getPosition(c);
    printf("%d\n", position);
    c = machine1->mid_rotor[position]; 
    printf("%c\n", c);

    position = getPosition(c);
    c = machine1->left_rotor[position]; 
    printf("%c\n", c);

    position = getPosition(c);
    c = machine1->reflector[position]; 
    printf("%c\n", c);

    printf("Inverting now...\n"); 

    position = getInvertPos(c, machine1->left_rotor); 
    c = alphabet[position];
    printf("%c\n", c); 

    position = getInvertPos(c, machine1->mid_rotor); 
    c = alphabet[position]; 
    printf("%c\n", c);

    position = getInvertPos(c, machine1->right_rotor); 
    c = alphabet[position]; 
    printf("%c\n", c);

    return c; 

}




