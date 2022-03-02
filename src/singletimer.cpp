#include <Arduino.h>
#include "runtimer.h"


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

bool singleTimer::expiredAndContinue() const {
    if (running) {
        if (millis() - timerStart > timerDuration) {        // check if actual time >= startTime + duration
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

void singleTimer::stop() {
    running = false;
}

bool singleTimer::isRunning() {
    return running;
}

unsigned long singleTimer::value() const {
    return (millis() - timerStart);
}

unsigned long singleTimer::duration() const {
    return timerDuration;
}

