#include <stdio.h>
#include "rotor_setup.h"
#include "machine_struct.h"

char getChar(void);

void encryptPlugBoard(char *plainC, struct machine *machine1);

char encryptRotors(char plainC, struct machine *machine1, char right_rotor[], char mid_rotor[], char left_rotor[], char reflector[]);



