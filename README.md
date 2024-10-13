Code that allows for you to connect an I2C LCD to a fight stick/DIY controller, so that the inputs will be displayed on the I2C LCD. The inputs are for guilty gear strive, street fighter 6 (classic controls) and playstation... but could be for anything with a bit of code tinkering. This was originally made with the Arduino uno in mind, but it has also been tested and works with an esp32 too, with slight simple tweaks to the code, and I am very sure that due to its simplicity it would work on all Arduino boards that have 17 pins or more. The basic result that this code should create is that notation for the button is on the bottom, but when the button is pushed, it moves up to the top row of the I2C LCD. I know that this is kinda odd, but this could be changed to anything, for example, if you wanted to make it so that when a button is pushed, the corresponding button on the I2C LCD starts flashing, or goes a solid colour or something of the like. While this code is not short, it can be changed a lot to service many different projects. It would make my day if there is someone out there who sees my code so they can copy parts and Frankenstein a project together, or if I can help out someone else in the FGC who is also weirdly too much into DIY fight sticks.

I have included all 3 modes separately in case anyone exclusively uses either playstation, guilty gear or street fighter but me personally I use all 3 so that is why the main one contains all 3.

The LiquidCrystal_I2C.h library is used in this project. To install just open Arduino IDE, go to the left and click on boards manager, then search up "liquidcrystal I2C", and download the one by Frank. Manual installation of the library can be done by going to this GitHub page: https://github.com/johnrickman/LiquidCrystal_I2C. on this page, click code in the top left, and click download ZIP, then once it has downloaded, unzip it, and then put it in your library folder (most likely found in user/documents/Arduino/libraries, and then just chuck it in there.

If you have any more suggestions for other outputs that I could do just email me stirlingcuming@gmail.com and I could make it for you for free because I just love making stuff like this... I have a few ideas for what I could make such as modern controls for street fighter 6, for tekken, for smash bros, (insert any fighting game here), ect.

wiring summary:

I2C LCD:

VCC: connect to 5v
GND: connect to the ground
SDA: connect to A4 pin
SCL: connect to A5 pin

(this following section is for playstation inputs)
pins for wired up buttons
these can be changed to be whatever you want

square = 0
X = 1
triangle = 2
0 = 3;
l1 = 4
l2 = 5
l3 = 6
r1 = 7
r2 = 8
r3 = 9
left = 10
right = 11
down = 12
up = A0
options = A1
share = A2
button the change the mode = A3 

Another thing to note that the arrows that represent the 8 directions from the d pad can also be changed to anything else using this website: https://arduinointro.com/lcdcustomcharacter/

If there are issues that are happening with the code, there is also a debug code that uses the serial monitor on Arduino IDE to determine exactly what buttons are being hit at what time, which may be useful.

credits: thanks to this website which helped me learn the basics of using buttons and code: https://docs.arduino.cc/built-in-examples/digital/Button/
