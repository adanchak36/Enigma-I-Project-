//
//  Machine.cpp
//  C++_Enigma
//
//  Created by Alexander Danchak on 1/15/19.
//  Copyright © 2019 Alexander Danchak. All rights reserved.
//

#include "Machine.hpp"
#include <iostream>
#include <string> 


Machine::Machine(){
    std::cout<<"Machine created"<<std::endl;
    this->setRotorOrder();                      //Sets rotor order
    this->setRingPosition();                    //Set ring position
}

void Machine::setRotorOrder(){
    std::string rotor_1("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
    std::string rotor_2("AJDKSIRUXBLHWTMCQGZNPYFVOE");
    std::string rotor_3("BDFHJLCPRTXVZNYEIWGAKMUSQO");
    std::string rotor_4("ESOVPZJAYQUIRHXLNFTGKDCMWB");
    std::string rotor_5("VZBRGITYUPSDNHLXAWMJQOFECK");
    
    int left, mid, right;
    std::cout<<"Enter Rotor Order: ";
    std::cin>>left;
    std::cin>>mid;
    std::cin>>right;
    std::cout<<"/n";
    
    /*left rotor assignment */
    switch(left){
        case 1:
            this->left_rotor = rotor_1;
            break;
        case 2:
            this->left_rotor = rotor_2;
            break;
        case 3:
            this->left_rotor = rotor_3;
            break;
        case 4:
            this->left_rotor = rotor_4;
            break;
        case 5:
            this->left_rotor = rotor_5;
            break;
    }/*end of left switch*/
    
    /*mid rotor assignment */
    switch(mid){
        case 1:
            this->mid_rotor = rotor_1;
            break;
        case 2:
            this->mid_rotor = rotor_2;
            break;
        case 3:
            this->mid_rotor = rotor_3;
            break;
        case 4:
            this->mid_rotor = rotor_4;
            break;
        case 5:
            this->mid_rotor = rotor_5;
            break;
    }/*end of mid switch*/
    
    /*right rotor assignment */
    switch(left){
        case 1:
            this->right_rotor = rotor_1;
            break;
        case 2:
            this->right_rotor = rotor_2;
            break;
        case 3:
            this->right_rotor = rotor_3;
            break;
        case 4:
            this->right_rotor = rotor_4;
            break;
        case 5:
            this->right_rotor = rotor_5;
            break;
    }/*end of right switch*/
}

void Machine::setRingPosition(){
    int left, mid, right;
    
    std::cout<<"Enter Ring Position ";
    std::cin>>left;
    std::cin>>mid;
    std::cin>>right;
    std::cout<<"/n";
    
    
}
    
    
    

void Machine::selectReflector(){
    std::string reflector_B("YRUHQSLDPXNGOKMIEBFZCWVJAT");
    //add more reflectors
    char reflect;
    
    std::cout<<"Enter reflector: ";
    std::cin>>reflect;
    std::cout<<"/n";
    
    switch(reflect){
        case'B':
            //move B into this->reflector
            break;
    }
    
}/*end selectReflector()*/


    


