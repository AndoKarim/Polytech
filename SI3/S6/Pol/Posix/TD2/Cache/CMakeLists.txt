cmake_minimum_required(VERSION 3.3)
project(Cache)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES
    cache.c
    cache.h
    cache.o
    cache_list.h
    cache_list.o
    FIFO_default.out
    FIFO_strategy.c
    foo
    low_cache.h
    low_cache.o
    LRU_default.out
    main_Cache.c
    main_Cache.o
    Makefile
    NUR_default.out
    plot.sh
    RAND_default.out
    RAND_strategy.c
    RAND_strategy.o
    random.h
    strategy.h)

add_executable(Cache ${SOURCE_FILES})