// #############################################################################
// ###                                                                       ###
// ### General Purpose Timer and Counters for Arduino Framework              ###
// ### https://github.com/Strooom/runtimer                                   ###
// ### Author(s) : Pascal Roobrouck - @strooom                               ###
// ### License : https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode ###
// ###                                                                       ###
// #############################################################################

// In the Arduino framework there is typically a loop() function which is called forever, but
// without a predictable timing. On the other hand there is a function miilis() which gives milliseconds since boot time
// With this library you can easily create timers (one shot as well as interval) that run in the loop() function
// and base their timing on the millis() function.
//
// V 1.0.0 07-02-2021 First release

#pragma once
#include "Arduino.h"

class intervalTimer {
  public:
    explicit intervalTimer(unsigned long);        // constructor
    bool expired();                               // check if intervalTimer has expired

  private:
    unsigned long timerValue{0};
    unsigned long timerInterval;
};

class singleTimer {
  public:
    bool expired();                             // check if timer has expired, if so stops it
    bool expiredAndContinue();                  // check if timer has expired but does not stop it..
    void start(unsigned long);                  // re-start a new timeout
    void startOrContinue(unsigned long);        // start a new timeout or continue if already started
    void stop();                                // disable before expiring

  private:
    bool running{false};
    unsigned long timerStart;
    unsigned long timerDuration;
};

class counter {
  public:
    explicit counter(uint32_t maxCount);
    uint32_t value() const;
    bool expired() const;        // check if counter has expired
    void increment();
    void reset();

  private:
    uint32_t count;
    uint32_t maxCount;
};
