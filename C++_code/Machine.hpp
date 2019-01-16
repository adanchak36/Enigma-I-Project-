//
//  Machine.hpp
//  C++_Enigma
//
//  Created by Alexander Danchak on 1/15/19.
//  Copyright © 2019 Alexander Danchak. All rights reserved.
//

#ifndef Machine_hpp
#define Machine_hpp

#include <stdio.h>
#include <string> 

#define ALPH 27     //constant alphabet size  (check size issues with arrays + 1)

class Machine{
private:
    std::string left_rotor, mid_rotor, right_rotor; //rotors can be accessed from anywhere
    int rotor_Start[3]; //(03,18,14)
    char reflector[ALPH]; //reflector won't change
    //char plainInput; //plaintext input
    //char cipherC; //ciphertext output
    
public:
    Machine(); //constructor
    std::string setLeftRotor(int left), setMidRotor(int mid), setRightRotor(int right);
    void setRotorOrder();
    void setRingPosition(); 
    void selectReflector(); 

};
#endif /* Machine_hpp */

