#include <runtimer.h>

counter counter1(16);              // create a counter to count events, with a count threshold of 16
intervalTimer timer1(1000);        // also creating an intervalTimer, so we create expire events which we can count
singleTimer timer2;                // also creating a singleshot timer, this oneshot event will reset the counter...

void setup() {
    Serial.begin(115200);
    Serial.flush();
    timer2.start(8000);        // start the timer, with a timerout of 8000 ms
}

void loop() {
    if (timer1.expired()) {
        counter1.increment();
        Serial.print("'timer1' expired, 'counter1 incremented to ");
        Serial.println(counter1.value());
    }
    if (timer2.expired()) {
        counter1.reset();
        Serial.print("'timer2' expired, 'counter1 reset to ");
        Serial.println(counter1.value());
        }
    if (counter1.expired()) {
            Serial.println("'counter1' expired");
        counter1.reset();
        }
}
