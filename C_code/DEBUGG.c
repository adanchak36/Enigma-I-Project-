#include "machine_struct.h"
#include <stdio.h>

#include <stdio.h>
void print_array(struct machine *machine1);

void print_array(struct machine *machine1){
    int i;
    for (i = 0; i < 10; i++){
        printf("%c", machine1->plug_board1[i]);
        if (i == 9){
            printf("\n");
        }
    }//for end (DEBUG)

}

