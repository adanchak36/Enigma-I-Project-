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

/* Issue with overwriting characters*/ 
void writeText(int x, int y, int color, int textSize, String text){
  tft.setCursor(x, y); 
  tft.setTextColor(color); 
  tft.setTextSize(textSize); 
  tft.println(text); 
} 

void getRotorOrder(){
  int start_x = 25; 
  int start_y = 100; 
  int sqLength = 70; 
  int sqWidth = 70;
  boolean endRingSet = false; 

  writeText(50, 20, ILI9341_WHITE, 2, "Enter Rotor Order"); 

  tft.drawRect(start_x + 60, start_y - 45, sqLength + 50, sqWidth - 40, ILI9341_WHITE);
  tft.fillRect(start_x + 60, start_y - 45, sqLength + 50, sqWidth - 40, ILI9341_WHITE);

  //tft.drawRect(start_x + 70, start_y - 40, sqLength, sqWidth - 10, ILI9341_BLUE);

  tft.drawRect(start_x, start_y, sqLength,sqWidth, ILI9341_ORANGE); //ROTOR I button 
  tft.fillRect(start_x, start_y, sqLength,sqWidth, ILI9341_ORANGE); 
  writeText(start_x + 15, start_y + 10, ILI9341_BLACK, 6, "1"); 
  
  tft.drawRect(start_x + 100, start_y, sqLength,sqWidth, ILI9341_ORANGE); //ROTOR II button 
  tft.fillRect(start_x + 100, start_y, sqLength,sqWidth, ILI9341_ORANGE); 
  writeText(start_x + 115, start_y + 10, ILI9341_BLACK, 6, "2"); 
   
  tft.drawRect(start_x + 200, start_y, sqLength,sqWidth, ILI9341_ORANGE); //ROTOR III button 
  tft.fillRect(start_x + 200, start_y, sqLength,sqWidth, ILI9341_ORANGE);
  writeText(start_x + 215, start_y + 10, ILI9341_BLACK, 6, "3"); 

  tft.drawRect(start_x, start_y + 90, 100, sqWidth - 30, ILI9341_RED); 
  tft.fillRect(start_x, start_y + 90, 100, sqWidth - 30, ILI9341_RED); 
  writeText(start_x + 5, start_y + 100, ILI9341_BLACK, 2, "Delete"); 

  tft.drawRect(start_x + 175, start_y + 90, 100, sqWidth - 30, ILI9341_GREEN); 
  tft.fillRect(start_x + 175, start_y + 90, 100, sqWidth - 30, ILI9341_GREEN); 
  writeText(start_x + 180, start_y + 100, ILI9341_BLACK, 2, "Enter"); 

  /* Conditional, if you press enter then lets get out of the funciton */ 
}

void setup() {
  Serial.begin(9600); 
  tft.begin(); 
  tft.fillScreen(ILI9341_BLACK);
  tft.setRotation(1);  
}

void loop() {
  getRotorOrder(); //return a pointer of integer array here 

  //touch data for input/delete/enter here 

  /* Get User Input for all 3 rotors */ 
  Serial.println("Enter Text"); 
  char text = Serial.read(); 
  //writeText(text); 
  delay(5000); //5 second delay  
 
}
