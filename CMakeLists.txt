cmake_minimum_required(VERSION 3.10)
project(MemoryPooltest2)

set(CMAKE_CXX_STANDARD 11)

set(CXX_FLAGS
        -Wall
        -std=c++11
        -lpthread
        -Wno-unused-parameter
        -O3
        )
link_libraries(pthread)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O3")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(SOURCE_FILES
        src/HttpData.cpp
        main.cpp
        src/MemoryPool.cpp
        src/MemoryBlock.cpp
        include/HttpData.h
        include/MemoryBlock.h
        include/MemoryPool.h
        include/MutexLock.h
        include/noncopyable.h)

add_executable(memorypool ${SOURCE_FILES})


