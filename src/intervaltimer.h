#pragma once

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
    unsigned long value() const;                  // time passed in current interval, in milliseconds
    unsigned long interval() const;               // current interval, in milliseconds

  private:
    bool running{false};                // is the timer running{true}  or stopped{false}
    unsigned long timerValue{0};        // time in milliseconds of previous tick
    unsigned long timerInterval;        // length of the interval in milliseconds
};
