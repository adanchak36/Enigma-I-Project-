#include <stdio.h> //printf, scanf
#include "rotor_setup.h"
#include <stdlib.h> //sizeof
//#include "header.h" // use header functions

int main(void){
    machine machine1; //struct create user
    
    getMachineInfo(&machine1);
    
    
    
    
    
    
    
    
    printf("%d %d %d\n", machine1.rotor_order[0], machine1.rotor_order[1], machine1.rotor_order[2]);//DEBUG
    
    printf("/n");
    
    return(0);
    
}//MAIN END

