#include <Arduino.h>
#include <runtimer.h>
singleTimer timer1;        // create a single timer, it does not start yet

void setup() {
    Serial.begin(115200);          // initialize and cleanup Serial
    Serial.flush();                //
    Serial.println("\n\n");        //

    timer1.start(3000);        // start the timer, with a timeout of x ms
    Serial.println("timer 'timer1' started");
}

void loop() {
    if (timer1.expired()) {
        Serial.println("timer 'timer1' expired");
    }
}
