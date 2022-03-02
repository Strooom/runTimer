#pragma once

class singleTimer {
  public:
    bool expired();                             // check if timer has expired, if so stops it
    bool expiredAndContinue() const;            // check if timer has expired but does not stop it..
    void start(unsigned long);                  // re-start a new timeout
    void startOrContinue(unsigned long);        // start a new timeout or continue if already started
    void stop();                                // disable before expiring
    bool isRunning();                           // is the timer running or stopped
    unsigned long value() const;                // time from start to now, in milliseconds
    unsigned long duration() const;             // get timer duration, in milliseconds

  private:
    bool running{false};                // is the timer running{true}  or stopped{false}
    unsigned long timerStart;           // time in milliseconds when timer was started
    unsigned long timerDuration;        // time from start to expire, in milliseconds
};

