#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int buttonPinsquare = 0;
const int buttonPincross = 1;
const int buttonPintriangle = 2;
const int buttonPincircle = 3;
const int buttonPinl1 = 4;
const int buttonPinl2 = 5;
const int buttonPinl3 = 6;
const int buttonPinr1 = 7;
const int buttonPinr2 = 8;
const int buttonPinr3 = 9;
const int buttonleft = 10;
const int buttonright = 11;
const int buttondown = 12;
const int buttonup = A0;
const int buttonPinoptions = A1;
const int buttonPinshare = A2;

int ButtonStatecross = 0;
int ButtonStatesquare = 0;
int ButtonStatetriangle = 0;
int ButtonStatecircle = 0;
int ButtonStatel1 = 0;
int ButtonStatel2= 0;
int ButtonStatel3 = 0;
int ButtonStater1 = 0;
int ButtonStater2 = 0;
int ButtonStater3 = 0;
int ButtonStateup = 0;
int ButtonStateoptions = 0;
int ButtonStateshare = 0;
int ButtonStatedown = 0;
int ButtonStateleft = 0;
int ButtonStateright = 0;

int direction = 5;
int action = 0;

byte upChar[] = {  B00000,  B00100,  B01110,  B11111,  B00100,  B00100,  B00100,  B00000,};        //creates up arrow
byte downChar[] = {  B00000,  B00100,  B00100,  B00100,  B11111,  B01110,  B00100,  B00000,};      //creates down arrow
byte rightChar[] = {  B00000,  B00100,  B00110,  B11111,  B00110,  B00100,  B00000,  B00000,};     //creates right arrow
byte leftChar[] = {  B00000,  B00100,  B01100,  B11111,  B01100,  B00100,  B00000,  B00000,};      //creates left arrow
byte uprightChar[] = {  B00000,  B01111,  B00111,  B01111,  B11101,  B11000,  B10000,  B00000,};   //creates up-right arrow
byte upleftChar[] = {  B00000,  B11110,  B11100,  B11110,  B10111,  B00011,  B00001,  B00000,};    //creates up-left arrow
byte downleftChar[] = {  B00000,  B00001,  B00011,  B10111,  B11110,  B11100,  B11110,  B00000,};  //creates down-left arrow
byte downrightChar[] = {  B00000,  B10000,  B11000,  B11101,  B01111,  B00111,  B01111,  B00000,}; //creates down-right arrow
byte neutralChar[] = {  B00000,  B00100,  B01110,  B11111,  B01110,  B00100,  B00000,  B00000,};  

void setup() {
  // put your setup code here, to run once:
 lcd.init();       // turn on the I2C LCD                  
  lcd.backlight();  // turn on the LCD light               
  lcd.clear(); 
  pinMode(buttonPincross, INPUT_PULLUP);
  pinMode(buttonPincircle, INPUT_PULLUP);
  pinMode(buttonPintriangle, INPUT_PULLUP);
  pinMode(buttonPinsquare, INPUT_PULLUP);
  pinMode(buttonPinl1, INPUT_PULLUP);
  pinMode(buttonPinl2, INPUT_PULLUP);
  pinMode(buttonPinl3, INPUT_PULLUP);
  pinMode(buttonPinr1, INPUT_PULLUP);
  pinMode(buttonPinr2, INPUT_PULLUP);
  pinMode(buttonPinr3, INPUT_PULLUP);
  pinMode(buttonup, INPUT_PULLUP);
  pinMode(buttondown, INPUT_PULLUP);
  pinMode(buttonleft, INPUT_PULLUP);
  pinMode(buttonPinoptions, INPUT_PULLUP);
  pinMode(buttonPinshare, INPUT_PULLUP);
  pinMode(buttonright, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
ButtonStateup = digitalRead(buttonup);
ButtonStatedown = digitalRead(buttondown);
ButtonStateleft = digitalRead(buttonleft);
ButtonStateright = digitalRead(buttonright);
ButtonStatecross = digitalRead(buttonPincross);
ButtonStatesquare = digitalRead(buttonPinsquare);
ButtonStatecircle = digitalRead(buttonPincircle);
ButtonStatetriangle = digitalRead(buttonPintriangle);
ButtonStatel1 = digitalRead(buttonPinl1);
ButtonStatel2 = digitalRead(buttonPinl2);
ButtonStatel3 = digitalRead(buttonPinl3);
ButtonStater1 = digitalRead(buttonPinr1);
ButtonStater2 = digitalRead(buttonPinr2);
ButtonStater3 = digitalRead(buttonPinr3);
ButtonStateoptions = digitalRead(buttonPinoptions);
ButtonStateshare = digitalRead(buttonPinshare);

if (ButtonStateup == LOW && ButtonStatedown == LOW && ButtonStateleft == LOW && ButtonStateright == LOW){      // all directions pressed
  direction = (5);
}
else if (ButtonStateup == LOW && ButtonStateleft == LOW && ButtonStateright == LOW && ButtonStatedown == HIGH){ // up, left and right directions pressed
  direction = (8);
}
else if (ButtonStatedown == LOW && ButtonStateleft == LOW && ButtonStateright == LOW && ButtonStateup == HIGH){ // down left and right directions pressed
  direction = (2);
}
else if (ButtonStateup == LOW && ButtonStatedown == LOW && ButtonStateright == LOW && ButtonStateleft == HIGH){   // up down and right directions pressed 
  direction = (6);
}
else if (ButtonStateup == LOW && ButtonStatedown == LOW && ButtonStateleft == LOW && ButtonStateright == HIGH){   // up down and left directions pressed
  direction = (4);
}
else if (ButtonStateup == LOW && ButtonStatedown == LOW && ButtonStateleft == HIGH && ButtonStateright == HIGH){     // up and down directions pressed
  direction = (5);
}
else if (ButtonStateup == LOW && ButtonStateleft == LOW && ButtonStatedown == HIGH && ButtonStateright == HIGH){     // up and left directions pressed
  direction = (7);
}
else if (ButtonStateup == LOW && ButtonStateright == LOW && ButtonStatedown == HIGH && ButtonStateleft == HIGH){    // up and right directions pressed
  direction = (9);
}
else if (ButtonStatedown == LOW && ButtonStateup == LOW && ButtonStateleft == HIGH && ButtonStateright == HIGH){    // down and up directions pressed
  direction = (5);
}
else if (ButtonStatedown == LOW && ButtonStateleft == LOW && ButtonStateup == HIGH && ButtonStateright == HIGH){    // down and left directions pressed
  direction = (1);
}
else if (ButtonStatedown == LOW && ButtonStateright == LOW && ButtonStateup == HIGH && ButtonStateleft == HIGH){    //down and right directions pressed
  direction = (3);
}
else if (ButtonStateleft == LOW && ButtonStateup == LOW && ButtonStatedown == HIGH && ButtonStateright == HIGH){    //left and up directions pressed
  direction = (7);
}
else if (ButtonStateleft == LOW && ButtonStatedown == LOW && ButtonStateup == HIGH && ButtonStateright == HIGH){    // left and down directions pressed
  direction = (1);
}
else if (ButtonStateleft == LOW && ButtonStateright == LOW && ButtonStateup == HIGH && ButtonStatedown == HIGH){    // left and right directions pressed
  direction = (5);
}
else if (ButtonStateright == LOW && ButtonStateup == LOW && ButtonStatedown == HIGH && ButtonStateleft == HIGH){    // right and up directions pressed
  direction = (9);
}
else if (ButtonStateright == LOW && ButtonStatedown == LOW && ButtonStateup == HIGH && ButtonStateleft == HIGH){    // right and down directions pressed
  direction = (3);
}
else if (ButtonStateright == LOW && ButtonStateleft == LOW && ButtonStateup == HIGH && ButtonStatedown == HIGH){    // right and left directions pressed
  direction = (5);
}
else if (ButtonStateup == LOW && ButtonStatedown == HIGH && ButtonStateleft == HIGH && ButtonStateright == HIGH){     // up direction pressed
  direction = (8);
}
else if (ButtonStatedown == LOW && ButtonStateup == HIGH && ButtonStateleft == HIGH && ButtonStateright == HIGH){     // down direction pressed
  direction = (2);
}
else if (ButtonStateleft == LOW && ButtonStateup == HIGH && ButtonStatedown == HIGH && ButtonStateright == HIGH){     // left direction pressed
  direction = (4);
}
else if (ButtonStateright == LOW && ButtonStateup == HIGH && ButtonStatedown == HIGH && ButtonStateleft == HIGH){     // right direction pressed
  direction = (6);
}
if (ButtonStatesquare == LOW) {
    // turn LED on:
  lcd.setCursor(0, 0);
  lcd.print("P");
  lcd.setCursor(0, 1);
  lcd.print(" ");
  action = 1;
  } else {
  lcd.setCursor(0, 1);
  lcd.print("P");  
  lcd.setCursor(0, 0);
  lcd.print(" ");
  }
  if (ButtonStatecross == LOW) {
    // turn LED on:
  lcd.setCursor(1, 0);
  lcd.print("K");
  lcd.setCursor(1, 1);
  lcd.print(" ");
  action = 2;
  } else {
  lcd.setCursor(1, 1);
  lcd.print("K"); 
  lcd.setCursor(1, 0);
  lcd.print(" "); 
}
if (ButtonStatetriangle == LOW) {
    // turn LED on:
  lcd.setCursor(2, 0);
  lcd.print("S");
  lcd.setCursor(2, 1);
  lcd.print(" ");
  action = 3;
  } else {
  lcd.setCursor(2, 1);
  lcd.print("S");
  lcd.setCursor(2, 0);
  lcd.print(" ");
  
}
if (ButtonStatecircle == LOW) {
    // turn LED on:
  lcd.setCursor(3, 0);
  lcd.print("HS");
  lcd.setCursor(3, 1);
  lcd.print("  ");
  action = 4;
  } else {
  lcd.setCursor(3, 1);
  lcd.print("HS");
  lcd.setCursor(3, 0);
  lcd.print("  ");
  }
  if (ButtonStater1 == LOW) {
    // turn LED on:
  lcd.setCursor(5, 0);
  lcd.print("D");
  lcd.setCursor(5, 1);
  lcd.print(" ");
  action = 5;
  } else {
  lcd.setCursor(5, 1);
  lcd.print("D");
  lcd.setCursor(5, 0);
  lcd.print(" ");

}
if (ButtonStatel1 == LOW) {
    // turn LED on:
  lcd.setCursor(6, 0);
  lcd.print("RC");
  lcd.setCursor(6, 1);
  lcd.print("  ");
  action = 6;
  } else {
  lcd.setCursor(6, 1);
  lcd.print("RC");
  lcd.setCursor(6, 0);
  lcd.print("  ");
}
if (ButtonStatel3 == LOW) {
    // turn LED on:
  lcd.setCursor(8, 0);
  lcd.print("Da");
  lcd.setCursor(8, 1);
  lcd.print("  ");
  action = 7;
  } else {
  lcd.setCursor(8, 1);
  lcd.print("Da");
  lcd.setCursor(8, 0);
  lcd.print("  ");
}
if (ButtonStatel2 == LOW) {
    // turn LED on:
  lcd.setCursor(11, 0);
  lcd.print("T");
  lcd.setCursor(11, 1);
  lcd.print(" ");
  action = 10;
  } else {
  lcd.setCursor(11, 1);
  lcd.print("T");
  lcd.setCursor(11, 0);
  lcd.print(" ");
    
}
if (ButtonStateoptions == LOW) {
    // turn LED on:
  lcd.setCursor(10, 0);
  lcd.print("M");
  lcd.setCursor(10, 1);
  lcd.print(" ");
  action = 11;
  } else {
  lcd.setCursor(10, 1);
  lcd.print("M");
  lcd.setCursor(10, 0);
  lcd.print(" ");
}
switch (action) {
    case 1: 
       Serial.println("Action: Punch");
       lcd.setCursor(12, 1);
       lcd.print("Punc");
       lcd.setCursor(13, 0);
       lcd.print("P ");
     break;
   case 2: 
        Serial.println("Action: Kick");
        lcd.setCursor(12, 1);
        lcd.print("Kick");
        lcd.setCursor(13, 0);
        lcd.print("K ");
      break;
case 3: 
  Serial.println("Action: Slash");
       lcd.setCursor(12, 1);
       lcd.print("Slas");
       lcd.setCursor(13, 0);
       lcd.print("S ");
break;
    case 4: 
        Serial.println("Action: Heavy Slash");
        lcd.setCursor(12, 1);
       lcd.print("HEAV");
       lcd.setCursor(13, 0);
       lcd.print("HS");
       break;
    case 5: 
       Serial.println("Action: Dash");
       lcd.setCursor(12, 1);
       lcd.print("Dust");
       
        break;
   case 6: 
        Serial.println("Action: Roman Cancel");
        lcd.setCursor(12, 1);
        lcd.print("RoCa");
        break;
   case 7: 
        Serial.println("Action: Dust");
       lcd.setCursor(13, 0);
       lcd.print("D ");
        break;
    case 8: 
       Serial.println("Action: Pause");
       lcd.setCursor(12, 1);
       lcd.print("Menu");
        break;
    case 9: 
        Serial.println("Action: Taunt");
        lcd.setCursor(12, 1);
       lcd.print("Taun");
        break;
}
switch(direction){
  case 1:
  lcd.createChar(4, downleftChar);
  lcd.setCursor(15, 0);
  lcd.write(4);
  break;
  case 2:
  lcd.createChar(4, downChar);
  lcd.setCursor(15, 0);
  lcd.write(4);
  break;
  case 3:
  lcd.createChar(4, downrightChar);
  lcd.setCursor(15, 0);
  lcd.write(4);
  break;
  case 4:
  lcd.createChar(4, leftChar);
  lcd.setCursor(15, 0);
  lcd.write(4);
  break;
  case 5:
  lcd.createChar(4, neutralChar);
  lcd.setCursor(15, 0);
  lcd.write(4);
  break;
  case 6:
  lcd.createChar(4, rightChar);
  lcd.setCursor(15, 0);
  lcd.write(4);
  break;
  case 7:
  lcd.createChar(4, upleftChar);
  lcd.setCursor(15, 0);
  lcd.write(4);
  break;
  case 8:
  lcd.createChar(4, upChar);
  lcd.setCursor(15, 0);
  lcd.write(4);
  break;
  case 9:
  lcd.createChar(4, uprightChar);
  lcd.setCursor(15, 0);
  lcd.write(4);
  break;

}
lcd.setCursor(12, 0);
lcd.print(direction);






}
