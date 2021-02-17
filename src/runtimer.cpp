#include "runtimer.h"

intervalTimer::intervalTimer(unsigned long interval) : timerValue(millis()), timerInterval{interval} {
}

bool intervalTimer::expired() {
    if (millis() - timerValue > timerInterval) {        // check if actual time >= previous time + interval
        timerValue += timerInterval;                    // set new compare time
        return true;
    } else {
        return false;
    }
}

bool singleTimer::expired() {
    if (running) {
        if (millis() - timerStart > timerDuration) {        // check if actual time >= startTime + duration
            running = false;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void singleTimer::start(unsigned long theTimerDuration) {        // re-start a new timeout
    timerStart    = millis();
    timerDuration = theTimerDuration;
    running       = true;
}

void singleTimer::startOrContinue(unsigned long theTimerDuration) {        // start a new timeout or continue if already started
    if (!running) {
        timerStart    = millis();
        timerDuration = theTimerDuration;
        running       = true;
    }
}

void(unsigned long);

void singleTimer::stop() {
    running = false;
}

counter::counter(uint32_t theMaxCount) : maxCount{theMaxCount} {
}
uint32_t counter::value() const {
    return count;
}
bool counter::expired() const {
    return (count >= maxCount);
}
void counter::increment() {
    count++;
}
void counter::reset() {
    count = 0;
}
