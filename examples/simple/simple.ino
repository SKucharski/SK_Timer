#include <SK_Timer.h>

const unsigned char LED_PIN = 13;
const unsigned int TOGGLE_TIME = 200; // ms

SK_Timer timer;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    timer.start(TOGGLE_TIME);
}

void loop() {
    if(timer.timeout())
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}
