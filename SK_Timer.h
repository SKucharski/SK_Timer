/*
 * SK_Timer.h
 *
 * Arduino library
 *
 * This code is released into the public domain
 *
 */

#ifndef SK_TIMER_H
#define SK_TIMER_H

#include <Arduino.h>

class SK_Timer
{
public:
    SK_Timer();
    ~SK_Timer();

    void stop();
    void start();
    void start(unsigned long interval_ms);
    void setInterval(unsigned long interval_ms);
    void setSingleShot(bool enable);

    bool timeout();
    bool isActive() const;
    bool isSingleShot() const;

    unsigned long interval() const;

private:
    static const unsigned long MAX_MILLIS = 4294967295;
    enum class State : char {
            Disabled,
            Enabled
    } state;

    bool singleShot;

    unsigned long interval_time;
    unsigned long start_time;
    unsigned long rest;
};

#endif // SK_TIMER_H
