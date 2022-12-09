cmake_minimum_required(VERSION 3.17)
project(EmbedRT)

set(CMAKE_CXX_STANDARD 17)

include_directories(utils/x86)

add_executable(EmbedRT
        utils/x86/precision_clock.cpp
        utils/x86/precision_clock.h
        utils/x86/high_precision_clock.cpp
        utils/x86/high_precision_clock.h
        utils/x86/extra_precision_timers.cpp)
