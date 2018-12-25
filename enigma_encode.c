#include "enigma_encode.h"
#include "machine_struct.h"
#include <stdio.h> //printf, scanf
#include <stdlib.h> //sizeof

static int getPosition(char c);
static int getInvertPos(char c, char rotor[]);


char getChar(void){
    char c;
    printf("Enter plaintext character:");
    scanf("  %c", &c);
    return c;
}

void encryptPlugBoard(char *plainC, machine *machine1){
    int i;
    
    for(i = 0; i < sizeof(machine1->plug_board1); i++){ //check if plainC is in plugboard
        if(*plainC == machine1->plug_board1[i]){
            *plainC = machine1->plug_board2[i];
        }
    }
}

static int getPosition(char c){
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < sizeof(alphabet); i++){
        if(c == alphabet[i]){
            return i;
        }
    }
    return 0; 
}

static int getInvertPos(char c, char rotor[]){
    for(int i = 0; i < sizeof(rotor); i++){
        if(c == rotor[i]){
            return i;
        }
    }
    return 0;
}

char encryptRotors(char plainC, machine *machine1, char right_rotor[], char mid_rotor[], char left_rotor[], char reflector[]){
    int position;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char c; //character being encrypted 
    
    position = getPosition(plainC);
    
    c = right_rotor[position]; //right rotor substitute
    
    printf("%c\n", c);
    
    position = getPosition(c);
    
    c = mid_rotor[position]; //middle rotor
    printf("%c\n", c);
    
    position = getPosition(c);
    
    c = left_rotor[position]; //left rotor
    printf("%c\n", c);
    
    position = getPosition(c);
    
    c = reflector[position];  //reflector
    printf("%c\n", c);
    
    position = getInvertPos(c, left_rotor); //left rotor inverted
    
    c = alphabet[position];
    printf("%c\n", c);
    
    position = getInvertPos(c, mid_rotor);
    
    c = alphabet[position];
    printf("%c\n", c);
    
    position = getInvertPos(c, right_rotor);
    
    c = alphabet[position];
    
    return c;
}




