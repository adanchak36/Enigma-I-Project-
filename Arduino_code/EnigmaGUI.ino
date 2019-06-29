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

void getRingSettings(){
  int start_x = 25; 
  int start_y = 100; 
  int sqLength = 70; 
  int sqWidth = 70; 

  writeText(50, 30, ILI9341_BLUE, 2, "Enter Ring Settings"); 

  tft.drawRect(start_x + 70, start_y - 40, sqLength, sqWidth - 20, ILI9341_BLUE);

  
  tft.drawRect(start_x, start_y, sqLength,sqWidth, ILI9341_RED); //ROTOR I button 
  tft.fillRect(start_x, start_y, sqLength,sqWidth, ILI9341_RED); 
  writeText(start_x, start_y, ILI9341_BLACK, 6, "1"); 

  tft.drawRect(start_x + 100, start_y, sqLength,sqWidth, ILI9341_RED); //ROTOR II button 
  tft.fillRect(start_x + 100, start_y, sqLength,sqWidth, ILI9341_RED); 
   
  
  tft.drawRect(start_x + 200, start_y, sqLength,sqWidth, ILI9341_RED); //ROTOR III button 
  tft.fillRect(start_x + 200, start_y, sqLength,sqWidth, ILI9341_RED);

  tft.drawRect(start_x + 70, start_y + 90, 125 ,sqWidth - 30, ILI9341_GREEN); //Enter button for ring settings (1,2,3)
  tft.fillRect(start_x + 70, start_y + 90, 125 ,sqWidth - 30, ILI9341_GREEN); 

}

/* Issue with overwriting characters*/ 
void writeText(int x, int y, int color, int textSize, String text){
  tft.setCursor(x, y); 
  tft.setTextColor(color); 
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
  //enterRingSetText();
  getRingSettings(); 
  

  /* Get User Input for all 3 rotors */ 
  Serial.println("Enter Text"); 
  char text = Serial.read(); 
  //writeText(text); 
  delay(5000); //5 second delay  
 
}
