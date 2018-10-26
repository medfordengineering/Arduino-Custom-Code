// Demo the quad alphanumeric display LED backpack kit
// scrolls through every character, then scrolls Serial
// input onto the display

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
const char test[22] = "BUS 134 IN 5 MIN.";

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

char displaybuffer[4] = {' ', ' ', ' ', ' '};

void scroll_display(char c[])
{
  int i = 0;
  while (c[i]) {
    // scroll down display
    displaybuffer[0] = displaybuffer[1];
    displaybuffer[1] = displaybuffer[2];
    displaybuffer[2] = displaybuffer[3];
    displaybuffer[3] = c[i++];

    // set every digit to the buffer
    alpha4.writeDigitAscii(0, displaybuffer[0]);
    alpha4.writeDigitAscii(1, displaybuffer[1]);
    alpha4.writeDigitAscii(2, displaybuffer[2]);
    alpha4.writeDigitAscii(3, displaybuffer[3]);

    // write it out!
    alpha4.writeDisplay();
    delay(200);

  }
}

void setup() {
  Serial.begin(9600);
  alpha4.begin(0x70);  // pass in the address
  alpha4.clear();

  scroll_display(test);

}




void loop() {

  scroll_display(test);

}
