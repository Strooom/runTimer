#include <runtimer.h>

intervalTimer timer1(2000);	// create an intervalTimer with 2000 ms interval

void setup() {
	Serial.begin(115200);
    Serial.flush();
}

void loop() {
    if (timer1.expired()) {
        Serial.println("interval timer 'timer1' expired");
    }
}
