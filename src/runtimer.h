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
// V 1.1.0 21-04-2021 Extended intervalTimer with more public methods
// V 1.2.0 05-05-2021 Extended with value() method, returning elapsed time

#pragma once
#include "Arduino.h"

// ========================================================
// ====    intervalTimer                               ====
// ========================================================

class intervalTimer {
  public:
    explicit intervalTimer(unsigned long);        // constructor 1 starts the intervalTimer
    explicit intervalTimer();                     // constructor 2, does NOT start the intervalTimer
    void set(unsigned long);                      // set a new interval time
    bool expired();                               // check if intervalTimer has expired
    void start();                                 // start the intervaltimer
    void startOrContinue();                       // start the intervalTimer if not yet running, do nothing if it already runs
    void start(unsigned long);                    // set a new interval time and start the intervaltimer
    void stop();                                  // disable before expiring
    bool isRunning();                             // is the timer running or stopped
    unsigned long value();                        // time passed in current interval, in milliseconds

  private:
    bool running{false};                // is the timer running{true}  or stopped{false}
    unsigned long timerValue{0};        // time in milliseconds of previous tick
    unsigned long timerInterval;        // length of the interval in milliseconds
};

// ========================================================
// ====    singleTimer                                 ====
// ========================================================

class singleTimer {
  public:
    bool expired();                             // check if timer has expired, if so stops it
    bool expiredAndContinue() const;            // check if timer has expired but does not stop it..
    void start(unsigned long);                  // re-start a new timeout
    void startOrContinue(unsigned long);        // start a new timeout or continue if already started
    void stop();                                // disable before expiring
    bool isRunning();                           // is the timer running or stopped
    unsigned long value();                      // time from start to now, in milliseconds

  private:
    bool running{false};                // is the timer running{true}  or stopped{false}
    unsigned long timerStart;           // time in milliseconds when timer was started
    unsigned long timerDuration;        // time from start to expire, in milliseconds
};

// ========================================================
// ====    counter                                     ====
// ========================================================

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
