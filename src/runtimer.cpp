#include "runtimer.h"

// ========================================================
// ====    intervalTimer                               ====
// ========================================================

intervalTimer::intervalTimer(unsigned long interval) : running{true} , timerValue(millis()), timerInterval{interval} {
}

intervalTimer::intervalTimer() : running{false} {
}

void intervalTimer::set(unsigned long interval) {
    timerInterval = interval;
}

bool intervalTimer::expired() {
    if (millis() - timerValue > timerInterval) {        // check if actual time >= previous time + interval
        timerValue += timerInterval;                    // set new compare time
        return true;
    } else {
        return false;
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

unsigned long intervalTimer::value() {
    return (millis() - timerValue);
}

unsigned long intervalTimer::interval() {
    return timerInterval;
}



// ========================================================
// ====    singleTimer                                 ====
// ========================================================

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

unsigned long singleTimer::value() {
    return (millis() - timerStart);
}

unsigned long singleTimer::duration() {
    return timerDuration;
}

// ========================================================
// ====    counter                                     ====
// ========================================================

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
