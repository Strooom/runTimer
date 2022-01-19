#include <runtimer.h>
singleTimer timer1;        // create a single timer, it does not start yet

void setup() {
    Serial.begin(115200);
    Serial.flush();
    timer1.start(3000);        // start the timer, with a timerout of 3000 ms
}

void loop() {
    if (timer1.expired()) {
        Serial.println("timer 'timer1' expired");
    }
}
