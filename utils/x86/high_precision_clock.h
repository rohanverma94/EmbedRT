//
// Created by rohanverma on 12/1/22.
//

#ifndef EMBEDRT_HIGH_PRECISION_CLOCK_H
#define EMBEDRT_HIGH_PRECISION_CLOCK_H

#include <cstdint>
#include <atomic>
#include <pthread.h>

class high_precision_clock {
    static std::atomic<int64_t> timer_count_micros;
    static constexpr uint64_t kPrecisionMicros = 50;
    static constexpr uint32_t kNumMicrosPerSecond = 100000;

    static void* UpdateTimerCounter(void* arg);
    pthread_t InitCacheClock();
};


#endif //EMBEDRT_HIGH_PRECISION_CLOCK_H
