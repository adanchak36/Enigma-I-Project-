const int ledPin_1 = 13; 
const int ledPin_2 = 12; 

const int buttonPin_1 = 4; 
const int buttonPin_2 = 3;

const int buttonENTER = 2;

int pushState_1; 
int pushState_ENTER; 

int ctrButton_1; 
int ctrButton_Enter; 

void setup() {
  Serial.begin(9600); //Set up serial connection 
  // put your setup code here, to run once:

  /*setup output LED pins*/ 
  pinMode(ledPin_1, OUTPUT); 
  pinMode(ledPin_2, OUTPUT); 
  
  /*setup input LED pins*/
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
  pinMode(buttonENTER, INPUT);

}

void loop() {
  /*check button states */ 
  ctrButton_1 = 0; 
  pushState_1 = digitalRead(buttonPin_1); 
  Serial.print("Enter Rotor Order: "); 
  do{
    pushState_1 = digitalRead(buttonPin_1); 
    pushState_ENTER = digitalRead(buttonENTER);

    if(pushState_1 == HIGH){
      ctrButton_1 += 1; 
      Serial.println("Count");
    }
    if(pushState_ENTER ==HIGH){
      Serial.println("I'm outty");
    }
  }while(pushState_ENTER == LOW); 

  Serial.print("First button pushed: "); 
  Serial.println((ctrButton_1 % 3), DEC); 


  // put your main code here, to run repeatedly:

}

