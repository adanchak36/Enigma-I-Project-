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

#define ALPH 27     //constant alphabet size  (check size issues with arrays + 1)

class Machine{
private:
    int rotor_Order[3]; //(3,2,1)
    int rotor_Start[3]; //(03,18,14)
    char reflector[ALPH]; //reflector won't change
    //char plainInput; //plaintext input
    //char cipherC; //ciphertext output
    
public:
    char left_rotor[ALPH], mid_rotor[ALPH], right_rotor[ALPH]; //rotors can be accessed from anywhere
    Machine(); //constructor
    void setOrder(int n1, int n2, int n3);
    void setStartPosition(int n1, int n2, int n3);
    void selectReflector(char input);

    
};
#endif /* Machine_hpp */

