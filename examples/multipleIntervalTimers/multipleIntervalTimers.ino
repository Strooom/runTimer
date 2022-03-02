#include <runtimer.h>

intervalTimer timer1(1000);        // create an intervalTimer with 1000 ms interval
intervalTimer timer2(2000);        // create an intervalTimer with 2000 ms interval
intervalTimer timer3(3000);        // create an intervalTimer with 3000 ms interval
// You can have as much timers as you want

void setup() {
    Serial.begin(115200);
    Serial.flush();
}

void loop() {
    if (timer1.expired()) {
        Serial.println("interval timer 'timer1' expired");
    }
    if (timer2.expired()) {
        Serial.println("interval timer 'timer2' expired");
    }
    if (timer3.expired()) {
        Serial.println("interval timer 'timer3' expired");
    }
}
