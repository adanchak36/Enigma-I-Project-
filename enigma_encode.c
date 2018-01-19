#include "enigma_encode.h"
#include "machine_struct.h"
#include <stdio.h> //printf, scanf
#include <stdlib.h> //sizeof

static char input_plaintext(void); //takes plaintext character input from input_enigma (only used in this)

char input_enigma(machine *machine1){
    char plaintext;
    int i;
    
    plaintext = input_plaintext();
    
    for (i = 0; i < sizeof(machine1->plug_board1); i++){
        if (plaintext == machine1->plug_board1[i]){
            plaintext = machine1->plug_board2[i];
            return plaintext;
        }
        
    }//end of for loop
    return plaintext;
}//end of input_enigma


static char input_plaintext(void){
    char c;
    printf("Enter Plaintext Character:");
    scanf("%s", &c);
    return c; 
}




