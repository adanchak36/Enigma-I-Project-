typedef struct machine{
    int rotor_order[3];//(1,2,3)
    int rotor_sett[3];// (03,18,14)
    char plug_board[10]; //(AB, CD, EF..)
} machine;

void getMachineInfo(struct machine *machine1);



//struct create 
