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


// Including this single file will include all three timer/counter classes

#pragma once
#include "singletimer.h"
#include "intervaltimer.h"
#include "counter.h"
