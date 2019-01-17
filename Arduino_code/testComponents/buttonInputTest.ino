[200~const short int ledPin_1 = 13; 
const short int ledPin_2 = 12; 
const short int ledPin_3 = 11; 

const short int buttonPin_1 = 5; 
const short int buttonPin_2 = 4;
const short int buttonPin_3 = 3; 

const short int buttonENTER = 2;

short int pushState_1;
short int pushState_2; 
short int pushState_3; 

short int pushState_ENTER; 

short int rotorOrder[3]; 

void setup() {
  Serial.begin(9600); //Set up serial connection 
  // put your setup code here, to run once:

  /*setup output LED pins*/ 
  pinMode(ledPin_1, OUTPUT); 
  pinMode(ledPin_2, OUTPUT); 
  
  /*setup input LED pins*/
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
  pinMode(buttonPin_3, INPUT);
  pinMode(buttonENTER, INPUT);

  /*Grab Rotor Order*/
  Serial.println("Enter the following rotors for "); 
  rotorInput(buttonPin_1, buttonPin_2, buttonPin_3); 

  Serial.print("Left Rotor = "); 
  Serial.println(rotorOrder[0], DEC);

  Serial.print("Mid Rotor = "); 
  Serial.println(rotorOrder[1], DEC);

  Serial.print("Right Rotor = "); 
  Serial.println(rotorOrder[2], DEC);
  
}

void loop() {
  Serial.print("Lolz");
  delay(60000); 

  // put your main code here, to run repeatedly:
    /* Mostly just character input */

}

/*
 * Used for 3 user inputs for rotor order and rotor ring settings
 * 
 * @param int buttonPin_1 used for 
 * @param int buttonPin_2 
 * @param int buttonPin_3
 * 
 */
void rotorInput(int leftbutton, int midbutton, int rightbutton){ //add functionality so it can be used for both 
 
  short int ctr1 = 0;
  short int ctr2 = 0; 
  short int ctr3 = 0;
  
  pushState_ENTER = LOW; //reset enter pin to low 

  do{
    /*reading in button values*/ 
    pushState_1 = digitalRead(leftbutton);
    pushState_2 = digitalRead(midbutton); 
    pushState_3 = digitalRead(rightbutton); 
    pushState_ENTER = digitalRead(buttonENTER);
    
    if(pushState_1 == HIGH){ //left
      ctr1 += 1; 
    };    
    if(pushState_2 == HIGH){  //mid
      ctr2 += 1; 
    };    
    if(pushState_3 == HIGH){ //right
      ctr3 += 1; 
    };   

    if(pushState_ENTER == HIGH){ Serial.println("Enter pushed");}
    
  }while(pushState_ENTER == LOW); 

  Serial.print("Left = "); 
  Serial.println(ctr1, DEC);

  Serial.print("Mid Rotor = "); 
  Serial.println(ctr2, DEC);

  Serial.print("Right Rotor = "); 
  Serial.println(ctr3, DEC);
  

  ctr1 = convertCtr(ctr1); 
  ctr2 = convertCtr(ctr2); 
  ctr3 = convertCtr(ctr3); 

  rotorOrder[0] = ctr1; 
  rotorOrder[1] = ctr2; 
  rotorOrder[2] = ctr3; 
  
  return; 
}/* rotorInput()*/ 


short int convertCtr(int ctr){
  ctr = ctr % 3; 
  if(ctr == 0){ ctr = 3; };
  return ctr;  
}
  
