void setup() {
  Serial.begin(9600);

  /*create struct data type...maybe array? Linked List?*/ 
  /*struct alphPINS{
    char alph; 
    int pin; 
  };*/


  int i; 
  
  /*Setting each button pin as input */
  for(i = 2; i < 6; i++){
    pinMode(i, INPUT);
  }

  for(i = 8; i < 12; i++){
    pinMode(i, OUTPUT);
  }
  
}

void loop() {
  

  /* Optimize through loop*/
 if(digitalRead(2) == HIGH){
    Serial.print("a"); 
    digitalWrite(8, HIGH);
    //send through encryption 
  }else if(digitalRead(3) == HIGH){
    digitalWrite(9, HIGH);
    Serial.print("b"); 
  }else if(digitalRead(4) == HIGH){
    digitalWrite(10, HIGH);
    Serial.print("c");
  }else if(digitalRead(5) == HIGH){
    digitalWrite(11, HIGH);
    Serial.print("d");
  }

  delay(250);

  for(int i = 8; i< 12; i++){
    digitalWrite(i, LOW);
  }

  







  
  //if digitalread(pin#) == 1 { send character through encryption } 

  
  

}
