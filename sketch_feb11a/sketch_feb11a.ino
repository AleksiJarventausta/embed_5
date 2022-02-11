#include <LiquidCrystal.h>
enum states {
  start,
  waiting,
  measuring,
  cheater
};
states state = start;
const int button_pin = 2, led_pin = 7,button_debounce = 300;
unsigned long measurement_start, result;
volatile unsigned long button_press_time;
volatile boolean button_pressed = false;
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(
    digitalPinToInterrupt(button_pin),
    button_interrupt,
    FALLING
  );
   lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  delay(1000);
}
void button_interrupt() {
  button_press_time = millis();
  Serial.println("painettu");
  button_pressed = true;
}
void loop() {
  switch (state) {
    case start:
      Serial.println("Press button to start the game!");
      while (!button_pressed) {}
      digitalWrite(led_pin, HIGH);
      lcd.clear();
      lcd.print("painettu");
      delay(button_debounce);
      state = waiting;
      break;
    case waiting:
      
      break;
    case measuring:
      break;
    case cheater:
      break;
    default:
    // We shouldn’t reach this, if every state is defined
      Serial.println("Default state reached :SSS");
      break;
  }
  button_pressed = false;
}
