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

int p = 0;
int k = 0;
int direction = 5;
int action = 0;

byte naChar[] = {  B10010,  B11010,  B10110,  B10010,  B00100,  B01010,  B01110,  B01010,};
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

  lcd.createChar(0, naChar);
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

if (ButtonStater1 == HIGH||ButtonStatetriangle == HIGH||ButtonStatesquare == HIGH){
  p = 4;
}
if  (ButtonStater1 == LOW) {
action = 3;
p = 3;
}
if (ButtonStatetriangle == LOW) {
p = 2;
action = 2;
}
if (ButtonStatesquare == LOW) {
p = 1;
action = 1;
}
switch (p){
  case 1:
  lcd.setCursor(0, 0);
  lcd.print("LP");
 break;

 case 2:
 lcd.setCursor(0, 0);
 lcd.print("MP");
 break;

case 3:
lcd.setCursor(0, 0);
  lcd.print("HP");
  break;

 case 4:
lcd.setCursor(0, 0);
lcd.print("  ");
lcd.setCursor(0, 1);
lcd.print("P");
lcd.setCursor(1, 1);
lcd.write(0);  
}
if (p < 4){
  lcd.setCursor(0, 1);
  lcd.print("  ");
}
if (ButtonStatecross == HIGH||ButtonStatecircle == HIGH||ButtonStater2 == HIGH){
k = 4;
}
if  (ButtonStater2 == LOW) {
action = 6;
k = 3;
}
 if (ButtonStatecircle == LOW) {
k = 2;
action = 5;
}
if (ButtonStatecross == LOW) {
k = 1;
action = 4;
}


switch (k){
  case 1:
  lcd.setCursor(2, 0);
  lcd.print("LK");
 break;

 case 2:
 lcd.setCursor(2, 0);
 lcd.print("MK");
 break;

case 3:
lcd.setCursor(2, 0);
  lcd.print("HK");
  break;

 case 4:
lcd.setCursor(2, 0);
lcd.print("  ");
lcd.setCursor(2, 1);
lcd.print("K");
lcd.setCursor(3, 1);
lcd.write(0);  
}

if (k<4){
  lcd.setCursor(2, 1);
  lcd.print("  ");
}
if (ButtonStatel2 == LOW||(ButtonStatetriangle == LOW && ButtonStatecircle == LOW)){
  lcd.setCursor(4, 0);
  lcd.print("dp");
  lcd.setCursor(4, 1);
  lcd.print("  ");
  action = 7;
} else {
   lcd.setCursor(4, 1);
  lcd.print("dp");
  lcd.setCursor(4, 0);
  lcd.print("  ");
} 

if (ButtonStatel1 == LOW||(ButtonStater2 == LOW && ButtonStater1 == LOW)){
  lcd.setCursor(6, 0);
  lcd.print("di");
  lcd.setCursor(6, 1);
  lcd.print("  ");
  action = 8;
} else {
   lcd.setCursor(6, 1);
  lcd.print("di");
  lcd.setCursor(6, 0);
  lcd.print("  ");
}
if (ButtonStatecross == LOW && ButtonStatesquare == LOW){
  lcd.setCursor(8, 0);
  lcd.print("gr");
  lcd.setCursor(8, 1);
  lcd.print("  ");
  action = 9;
} else {
   lcd.setCursor(8, 1);
  lcd.print("gr");
  lcd.setCursor(8, 0);
  lcd.print("  ");
}
if ((ButtonStatesquare == LOW && ButtonStatetriangle == LOW)||(ButtonStatesquare == LOW && ButtonStater1 == LOW)||(ButtonStatetriangle == LOW && ButtonStater1 == LOW)||(ButtonStatecross == LOW && ButtonStatecircle == LOW)||(ButtonStatecross == LOW && ButtonStater2 == LOW)||(ButtonStatecircle == LOW && ButtonStater2 == LOW)){
  lcd.setCursor(10, 0);
  lcd.print("od");
  lcd.setCursor(10, 1);
  lcd.print("  ");

} else {
  lcd.setCursor(10, 1);
  lcd.print("od");
  lcd.setCursor(10, 0);
  lcd.print("  ");
}
if (ButtonStateoptions == LOW){
action = 10;
}
if (ButtonStateshare == LOW){
  action = 11;
}
switch (action){
  case 1:
  lcd.setCursor(13, 0);
  lcd.print("LP");
  break;
  case 2:
  lcd.setCursor(13, 0);
  lcd.print("MP");
  break;
  case 3:
  lcd.setCursor(13, 0);
  lcd.print("HP");
  break;
  case 4:
  lcd.setCursor(13, 0);
  lcd.print("LK");
  break;
  case 5:
  lcd.setCursor(13, 0);
  lcd.print("MK");
  break;
  case 6:
  lcd.setCursor(13, 0);
  lcd.print("HK");
  break;
  case 7:
  lcd.setCursor(13, 0);
  lcd.print("DP");
  break;
  case 8:
  lcd.setCursor(13, 0);
  lcd.print("DI");
  break;
  case 9:
  lcd.setCursor(13, 0);
  lcd.print("Gr");
  break;
  case 10:
  lcd.setCursor(12, 1);
  lcd.print("menu");
  break;
  case 11:
  lcd.setCursor(12, 1);
  lcd.print("shar");
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





