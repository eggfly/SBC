#include "Adafruit_Keypad.h"
#include "app.h"

const byte ROWS = 7; // rows
const byte COLS = 5; // columns
// define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
    {'Q', 'E', 'R', 'U', 'O'},
    {'W', 'S', 'G', 'H', 'L'},
    {'s', 'D', 'T', 'Y', 'I'},
    {'A', 'P', 's', 'n', 'b'},
    {'a', 'X', 'V', 'B', '$'},
    {' ', 'Z', 'C', 'N', 'M'},
    {'m', 's', 'F', 'J', 'K'},
};

byte rowPins[ROWS] = {1, 2, 3, 4, 5, 6, 7}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 11, 12, 13, 14};  // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup_keypad()
{
  customKeypad.begin();
  printf("setup_keypad\n");
}

void loop_keypad()
{
  // put your main code here, to run repeatedly:
  customKeypad.tick();
  while (customKeypad.available())
  {
    keypadEvent e = customKeypad.read();
    Serial.print((char)e.bit.KEY);
    if (e.bit.EVENT == KEY_JUST_PRESSED)
    {
      printf(" pressed");
      uint8_t row = e.bit.ROW;
      uint8_t col = e.bit.COL;
      printf(" row: ");
      Serial.print(row);
      printf(" col: ");
      Serial.print(col);
      printf("\n");
    }
    else if (e.bit.EVENT == KEY_JUST_RELEASED)
    {
      Serial.println(" released");
      // render.printf("%c", e.bit.KEY);
      // lcd_PushColors(0, 0, WIDTH, HEIGHT, (uint16_t *)spr.getPointer());
    }
  }
}