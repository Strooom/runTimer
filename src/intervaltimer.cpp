#include <Arduino.h>
#include "runtimer.h"

intervalTimer::intervalTimer(unsigned long interval) : running{true}, timerValue(millis()), timerInterval{interval} {
}

intervalTimer::intervalTimer() : running{false} {
}

void intervalTimer::set(unsigned long interval) {
    timerInterval = interval;
}

bool intervalTimer::expired() {
    if (millis() - timerValue > timerInterval) {        // check if actual time >= previous time + interval
        timerValue += timerInterval;                    // set new compare time
        return true;                                    //
    } else {                                            //
        return false;                                   //
    }
}

void intervalTimer::start() {
    if (timerInterval > 0) {
        timerValue = millis();
        running    = true;
    }
}

void intervalTimer::startOrContinue() {
    if (!running && (timerInterval > 0)) {
        timerValue = millis();
        running    = true;
    }
}

void intervalTimer::start(unsigned long interval) {
    timerInterval = interval;
    timerValue    = millis();
    running       = true;
}

void intervalTimer::stop() {
    running = false;
}

bool intervalTimer::isRunning() {
    return running;
}

unsigned long intervalTimer::value() const {
    return (millis() - timerValue);
}

unsigned long intervalTimer::interval() const {
    return timerInterval;
}
