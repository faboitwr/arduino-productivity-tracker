// C++ code

// LCD Initialisation
#include <LiquidCrystal.h>
// rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7
LiquidCrystal lcd(0, 1, 2, 7, 6, 5, 4, 3, 8, 9, 10);

// Button Initialisation
const int button1P = 13;
const int button2P = 12;
const int button3P = 11;

int button1S = 0;
int button2S = 0;
int button3S = 0;

// Programme Data Initialisation
int menuS = 0;
String menuI[3] = {"Daily Target", "Daily Total", "+ Hours"};
int dailyTg = 0;
int dailyTt = 0;
int dailyHr = 0;

// Device Start-up 
void setup(){
  // Ensure button state
  int button1S = 0;
  int button2S = 0;
  int button3S = 0;
  
  // LCD Set-up & Start-up Screen
  lcd.begin(16,2);
  lcd.print("Productivity Aid");
  lcd.setCursor(0, 1);
  lcd.print("Vers. 1.0.0");
  delay(1500);
  lcd.clear();
  lcd.print(menuI[menuS]);
  
  // Button Set-up
  pinMode(button1P, INPUT_PULLUP);
  pinMode(button2P, INPUT_PULLUP);
  pinMode(button3P, INPUT_PULLUP);
  
  /*Serial Set-up (For debugging)
  Serial.begin(9600);
  Serial.print("Hello Debug. ");
  Serial.print(menuI[menuS]);
  */
}

// Button Click Detection

// To be rebuilt to have release detection instead
int buttonDet(uint8_t input, int button, int buttonS){
  buttonS = digitalRead(input);
  if (buttonS == LOW)
  {
    return true;
  }
  return false;
}

// Programme Data Manipulator
void menu(int mS){
  String strDTt = "";
  switch (mS){
    case 0: // Adjust daily target
    	
    	break;
    
    case 1: // Check daily "productive hours"
        strDTt = String(dailyTt);
        lcdUpdate(strDTt);
        if (buttonDet(button2P, 2, button2S) == true){
          lcdUpdate(menuI[menuS]);
        }
        break;
    
    case 2: // Add daily "productive hours"
    	
    	break;
  }
}

void lcdUpdate(String output){
  lcd.clear();
  lcd.print(output);
}

// Programme Runner
void loop(){
  // Serial.print(menuS);
  // <- Button
  if (buttonDet(button1P, 1, button1S) == true && menuS > 0){
    Serial.print("Button 1 Pressed; ");
    menuS -= 1;
    lcdUpdate(menuI[menuS]);
  }
  
  // Enter Button
  if (buttonDet(button2P, 2, button2S) == true){
    Serial.print("Button 2 Pressed; ");
    menu(menuS);
  }
  
  // -> Button
  if (buttonDet(button3P, 3, button3S) == true && menuS < 2){
    Serial.print("Button 3 Pressed; ");
    menuS += 1;
    lcdUpdate(menuI[menuS]);
  }
  delay(150);
}