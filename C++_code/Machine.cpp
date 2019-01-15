//
//  Machine.cpp
//  C++_Enigma
//
//  Created by Alexander Danchak on 1/15/19.
//  Copyright © 2019 Alexander Danchak. All rights reserved.
//

#include "Machine.hpp"
#include <iostream>


Machine::Machine(){
    std::cout<<"Machine created"<<std::endl;
}

void Machine::setOrder(int n1, int n2, int n3){
    this->rotor_Order[0] = n1;
    this->rotor_Order[1] = n2;
    this->rotor_Order[2] = n2; 
}

void Machine::setStartPosition(int n1, int n2, int n3){
    this->rotor_Start[0] = n1;
    this->rotor_Start[1] = n2;
    this->rotor_Start[2] = n3;
}

void Machine::selectReflector(char relector){
    char reflector_B[ALPH] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    //add more reflectors
    
    switch(relector){
        case'B':
            //move B into this->reflector
            break;
    }
    
}/*end selectReflector()*/
    


