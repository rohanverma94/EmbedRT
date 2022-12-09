//
// Created by rohanverma on 12/1/22.
//

#include <cerrno>
#include <ctime>

#include "precision_clock.h"


 void precision_clock::SleepMicros(uint32_t micros) {
    timespec sleep_time{};
    sleep_time.tv_sec = micros / numMicrosPerSecond;
    sleep_time.tv_nsec = (micros % numMicrosPerSecond) * 1000;

    while(nanosleep(&sleep_time,&sleep_time) != 0 && errno == EINTR);
}

 void *precision_clock::UpdateTimerCounter(void *arg) {
    timespec ts{};

    auto sleep_micros = reinterpret_cast<int64_t>(arg);
    while(isEnabled()){
        clock_gettime(CLOCK_REALTIME, &ts);
        timer_count_micros.store(ts.tv_sec * numMicrosPerSecond + ts.tv_nsec / 1000);

        SleepMicros(sleep_micros);
    }
    return nullptr;
}

 pthread_t precision_clock::InitClock(uint32_t precision_micros) {
    pthread_t result;

    timespec ts{};
    clock_gettime(CLOCK_REALTIME, &ts);
    timer_count_micros.store(ts.tv_nsec * numMicrosPerSecond + ts.tv_nsec / 1000);

    pthread_create(&result, nullptr, UpdateTimerCounter,
                   reinterpret_cast<void*>(precision_micros/2));

    return result;
}

 bool precision_clock::isEnabled() {
    if(enabledClock) return true;
    return false;
}
