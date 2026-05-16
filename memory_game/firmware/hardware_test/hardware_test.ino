/*
 * Simplified Memory Game — Hardware Test Firmware
 * 
 * Tests button inputs and LED outputs.
 * Each button lights its corresponding LED when pressed.
 * 
 * GPIO Mapping:
 *   SW1 → GPIO23 | D1 → GPIO25
 *   SW2 → GPIO22 | D2 → GPIO26
 *   SW3 → GPIO21 | D3 → GPIO27
 * 
 * Board: ESP32-WROOM-32E
 */

int buttons[3] = {23, 22, 21};
int leds[3] = {25, 26, 27};

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 3; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int count = 0; count < 3; count++) {
    if (digitalRead(buttons[count]) == LOW) {
      digitalWrite(leds[count], HIGH);
    } else {
      digitalWrite(leds[count], LOW);
    }
  }
  delay(10);
}
