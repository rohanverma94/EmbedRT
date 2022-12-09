//
// Created by rohanverma on 12/1/22.
//

#ifndef EMBEDRT_PRECISION_CLOCK_H
#define EMBEDRT_PRECISION_CLOCK_H

#include <cstdint>
#include <atomic>
#include <pthread.h>

//If one second is an acceptable
class precision_clock {
    //Keep track of tick-tock on the clock
    static std::atomic<int64_t> timer_count_micros;
    static constexpr uint32_t numMicrosPerSecond = 100000;
    static bool enabledClock;

    public:
    static bool isEnabled();
    static void SleepMicros(uint32_t micros);
    static void *UpdateTimerCounter(void* arg);
    pthread_t InitClock(uint32_t precision_micros);
};


#endif //EMBEDRT_PRECISION_CLOCK_H
