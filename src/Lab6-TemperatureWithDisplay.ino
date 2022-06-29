#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;
bool unit = false;

void setup() {
    display.setup();
    display.clearDisplay();
    display.display();
    display.setTextSize(5);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    Serial.begin(9600);
  
}

void loop() {
    display.loop();

    uint64_t reading = analogRead(A4);
    double voltage = (reading * 3.3) / 4095.0;
    double temperatureC = (voltage - 0.5) * 100;
    double temperatureF = (1.8 * temperatureC) + 32;

    if (display.pressedB()) {
        unit = !unit;
    }
    
    display.clearDisplay();
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.setCursor(5, 5);
    if (unit) {
        display.println(temperatureF);
    } else {
        display.println(temperatureC);
    }
    display.display();

}
