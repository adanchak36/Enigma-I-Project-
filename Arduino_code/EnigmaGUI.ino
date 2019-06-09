#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>

Adafruit_FT6206 ts = Adafruit_FT6206(); //I2C communication setup (drawing object) 

/* Define the pins */ 
#define TFT_CS 10
#define TFT_DC 9
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void drawButton(){
  tft.fillRect(20, 100, 100, 50, ILI9341_GREEN); 
  tft.drawRect(20, 100, 100, 50, ILI9341_RED);
}

void enterRingSetText(){
  tft.setCursor(50, 50); 
  tft.setTextColor(ILI9341_BLUE); 
  tft.setTextSize(2); 
  tft.println("Enter Ring Settings: "); 
}

/* Issue with overwriting characters*/ 
void writeText(char text){
  tft.setCursor(50, 60); 
  tft.setTextColor(ILI9341_RED); 
  tft.setTextSize(2); 
  tft.println(text); 
  
}

void setup() {
  Serial.begin(9600); 
  tft.begin(); 
  tft.fillScreen(ILI9341_BLACK);
  tft.setRotation(1);  
}

void loop() {
  /* Show ring setting input text */ 
  enterRingSetText();

  /* Get User Input for all 3 rotors */ 
  Serial.println("Enter Text"); 
  char text = Serial.read(); 
  writeText(text); 
  delay(5000); //5 second delay  
 
}
