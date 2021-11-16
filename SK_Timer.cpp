#include "SK_Timer.h"

SK_Timer::SK_Timer()
{
    state = State::Disabled;
    singleShot = false;
    interval_time = 0;
    start_time = 0;
    rest = 0;
}

SK_Timer::~SK_Timer() {}

void SK_Timer::stop()
{
    state = State::Disabled;
}

void SK_Timer::start()
{
    if(interval_time) {
        state = State::Enabled;
        start_time = millis();
        rest = 0;
    }
}

void SK_Timer::start(unsigned long interval_ms)
{
    setInterval(interval_ms);
    start();
}

void SK_Timer::setInterval(unsigned long interval_ms)
{
    interval_time = interval_ms;
}

void SK_Timer::setSingleShot(bool enable)
{
    singleShot = enable;
}

bool SK_Timer::timeout()
{
    if(state == State::Disabled)
        return false;

    unsigned long actual_time = millis();

    if(start_time > actual_time) {
        rest = MAX_MILLIS - start_time;
        start_time = 0;
    }

    if((actual_time - start_time) + rest >= interval_time) {
        if(singleShot) state = State::Disabled;
        else {
            start_time = actual_time;
            rest = 0;
        }
        return true;
    }
    return false;
}

bool SK_Timer::isActive() const
{
    return state == State::Enabled;
}

bool SK_Timer::isSingleShot() const
{
    return singleShot;
}

unsigned long SK_Timer::interval() const
{
    return interval_time;
}
