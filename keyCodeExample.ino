#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();
uint8_t y;

void setup() {
  pinMode(10, INPUT_PULLUP);
  matrix.begin(0x70);
  matrix.print(0, DEC);
  matrix.writeDisplay();
}
void loop()
{
 for (int y = 0; y < 500; y++){
    matrix.print(y, DEC);
    matrix.writeDisplay();
    delay(50);
  }
}

