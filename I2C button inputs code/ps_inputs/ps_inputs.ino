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
int l = 0;
int r = 0;
int shape = 0;

byte upChar[] = {  B00000,  B00100,  B01110,  B11111,  B00100,  B00100,  B00100,  B00000,};        //creates up arrow
byte downChar[] = {  B00000,  B00100,  B00100,  B00100,  B11111,  B01110,  B00100,  B00000,};      //creates down arrow
byte rightChar[] = {  B00000,  B00100,  B00110,  B11111,  B00110,  B00100,  B00000,  B00000,};     //creates right arrow
byte leftChar[] = {  B00000,  B00100,  B01100,  B11111,  B01100,  B00100,  B00000,  B00000,};      //creates left arrow
byte uprightChar[] = {  B00000,  B01111,  B00111,  B01111,  B11101,  B11000,  B10000,  B00000,};   //creates up-right arrow
byte upleftChar[] = {  B00000,  B11110,  B11100,  B11110,  B10111,  B00011,  B00001,  B00000,};    //creates up-left arrow
byte downleftChar[] = {  B00000,  B00001,  B00011,  B10111,  B11110,  B11100,  B11110,  B00000,};  //creates down-left arrow
byte downrightChar[] = {  B00000,  B10000,  B11000,  B11101,  B01111,  B00111,  B01111,  B00000,}; //creates down-right arrow
byte neutralChar[] = {  B00000,  B00100,  B01110,  B11111,  B01110,  B00100,  B00000,  B00000,};  
byte triangleChar[] = {  B00000,  B00100,  B00100,  B01110,  B01110,  B11111,  B11111,  B00000,};
byte squareChar[] = {  B00000,  B00000,  B01110,  B01110,  B01110,  B00000,  B00000,  B00000,};
byte naChar[] = {  B10010,  B11010,  B10110,  B10010,  B00100,  B01010,  B01110,  B01010,};

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
  lcd.createChar(1, triangleChar);
  lcd.createChar(2, squareChar);
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
if (ButtonStatecross == LOW) {
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 0);
  lcd.print("X");
  action = 1;
  shape = 1;
} else {
  lcd.setCursor(0, 0);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print("X");
}

// Circle button logic
if (ButtonStatecircle == LOW) {
  lcd.setCursor(1, 0);
  lcd.print("O");
  lcd.setCursor(1, 1);
  lcd.print(" ");
  action = 2;
  shape = 2;
} else {
  lcd.setCursor(1, 1);
  lcd.print("O");
  lcd.setCursor(1, 0);
  lcd.print(" ");
}

// Triangle button logic
if (ButtonStatetriangle == LOW) {
  lcd.setCursor(2, 0);
  lcd.write(1);
  lcd.setCursor(2, 1);
  lcd.print(" ");
  action = 3;
  shape = 3;
} else {
  lcd.setCursor(2, 1);
  lcd.write(1);
  lcd.setCursor(2, 0);
  lcd.print(" ");
}

// Square button logic
if (ButtonStatesquare == LOW) {
  lcd.setCursor(3, 0);
  lcd.write(2);
  lcd.setCursor(3, 1);
  lcd.print(" ");
  action = 4;
  shape = 4;
} else {
  lcd.setCursor(3, 1);
  lcd.write(2);
  lcd.setCursor(3, 0);
  lcd.print(" ");
}

// Handle L buttons logic
if (ButtonStatel1 == LOW) {
  action = 5;
  l = 1;
  shape = 5;
} else if (ButtonStatel2 == LOW) {
  action = 6;
  l = 2;
  shape = 6;
} else if (ButtonStatel3 == LOW) {
  action = 7;
  l = 3;
  shape = 7;
} else {
  l = 4; // Default case when no button is pressed
}

// Handle R buttons logic
if (ButtonStater1 == LOW) {
  action = 8;
  r = 1;
  shape = 8;
} else if (ButtonStater2 == LOW) {
  action = 9;
  r = 2;
  shape = 9;
} else if (ButtonStater3 == LOW) {
  action = 10;
  r = 3;
  shape = 10;
} else {
  r = 4; // Default case when no button is pressed
}

// Display L button status
switch (l) {
  case 1:
    lcd.setCursor(4, 0);
    lcd.print("L1");
    break;
  case 2:
    lcd.setCursor(4, 0);
    lcd.print("L2");
    break;
  case 3:
    lcd.setCursor(4, 0);
    lcd.print("L3");
    break;
  case 4:
    lcd.setCursor(4, 0);
    lcd.print("  ");
    lcd.setCursor(4, 1);
    lcd.print("L");
    lcd.setCursor(5, 1);
    lcd.write(0);
    break;
}

// Clear lower row if l < 4
if (l < 4) {
  lcd.setCursor(4, 1);
  lcd.print("  ");
}

// Display R button status
switch (r) {
  case 1:
    lcd.setCursor(6, 0);
    lcd.print("R1");
    break;
  case 2:
    lcd.setCursor(6, 0);
    lcd.print("R2");
    break;
  case 3:
    lcd.setCursor(6, 0);
    lcd.print("R3");
    break;
  case 4:
    lcd.setCursor(6, 0);
    lcd.print("  ");
    lcd.setCursor(6, 1);
    lcd.print("R");
    lcd.setCursor(7, 1);
    lcd.write(0);
    break;
}

// Clear lower row if r < 4
if (r < 4) {
  lcd.setCursor(6, 1);
  lcd.print("  ");
}

// Handle Options button
if (ButtonStateoptions == LOW) {
  lcd.setCursor(8, 0);
  lcd.print("op");
  lcd.setCursor(8, 1);
  lcd.print("  ");
  action = 11;
} else {
  lcd.setCursor(8, 1);
  lcd.print("op");
  lcd.setCursor(8, 0);
  lcd.print("  ");
}

// Handle Share button
if (ButtonStateshare == LOW) {
  lcd.setCursor(10, 0);
  lcd.print("sh");
  lcd.setCursor(10, 1);
  lcd.print("  ");
  action = 12;
} else {
  lcd.setCursor(10, 1);
  lcd.print("sh");
  lcd.setCursor(10, 0);
  lcd.print("  ");
}

// Action display based on button press
switch (action) {
  case 1:
    Serial.println("Action: X");
    lcd.setCursor(12, 1);
    lcd.print("X");
    lcd.setCursor(13, 0);
    lcd.print("cros");
    break;
  case 2:
    Serial.println("Action: circle");
    lcd.setCursor(12, 1);
    lcd.print("O");
    lcd.setCursor(13, 0);
    lcd.print("circ");
    break;
  case 3:
    Serial.println("Action: triangle");
    lcd.setCursor(12, 1);
    lcd.print("tria");
    break;
  case 4:
    Serial.println("Action: square");
    lcd.setCursor(12, 1);
    lcd.print("squa");
    break;
  case 5:
    Serial.println("Action: Dash");
    lcd.setCursor(12, 1);
    lcd.print("r1  ");
    break;
  case 6:
    Serial.println("Action: Roman Cancel");
    lcd.setCursor(12, 1);
    lcd.print("r2  ");
    break;
  case 7:
    Serial.println("Action: Dust");
    lcd.setCursor(12, 1);
    lcd.print("Dust");
    lcd.setCursor(13, 0);
    lcd.print("r3  ");
    break;
  case 8:
    Serial.println("Action: Pause");
    lcd.setCursor(12, 1);
    lcd.print("l1  ");
    break;
  case 9:
    Serial.println("Action: Taunt");
    lcd.setCursor(12, 1);
    lcd.print("l2  ");
    break;
  case 10:
    lcd.setCursor(12, 1);
    lcd.print("l3  ");
    break;
  case 11:
    lcd.setCursor(12, 1);
    lcd.print("menu");
    break;
  case 12:
    lcd.setCursor(12, 1);
    lcd.print("shar");
    break;
}

// Shape display based on button press
switch (shape) {
  case 1:
    lcd.setCursor(13, 0);
    lcd.print("X ");
    break;
  case 2:
    lcd.setCursor(13, 0);
    lcd.print("O ");
    break;
  case 3:
    lcd.setCursor(13, 0);
    lcd.write(1);
    lcd.setCursor(14, 0);
    lcd.print(" ");
    break;
  case 4:
    lcd.setCursor(13, 0);
    lcd.write(2);
    lcd.setCursor(14, 0);
    lcd.print(" ");
    break;
  case 5:
    lcd.setCursor(13, 0);
    lcd.print("r1");
    break;
  case 6:
    lcd.setCursor(13, 0);
    lcd.print("r2");
    break;
  case 7:
    lcd.setCursor(13, 0);
    lcd.print("r3");
    break;
  case 8:
    lcd.setCursor(13, 0);
    lcd.print("l1");
    break;
  case 9:
    lcd.setCursor(13, 0);
    lcd.print("l2");
    break;
  case 10:
    lcd.setCursor(13, 0);
    lcd.print("l3");
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
