cmake_minimum_required(VERSION 3.10)
project(MyCProject C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include_directories(include)
file(GLOB SOURCES "src/*.c")

add_executable(solution_1 main.c ${SOURCES})

target_link_libraries(solution_1 m)

set(CMAKE_C_FLAGS_DEBUG "-std=c2x -g -O0")
set(CMAKE_C_FLAGS_01 "-std=c2x -O1 -Wall")
set(CMAKE_C_FLAGS_02 "-std=c2x -O2 -Wall")
set(CMAKE_C_FLAGS_03 "-std=c2x -O3 -Wall")
set(CMAKE_C_FLAGS_0FAST "-std=c2x -Ofast -Wall")

set(CMAKE_C_FLAGS_RELEASE "-std=c2x -O3 -DNDEBUG")

if(CMAKE_BUILD_TYPE STREQUAL "01")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_01}")
elseif(CMAKE_BUILD_TYPE STREQUAL "02")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_02}")
elseif(CMAKE_BUILD_TYPE STREQUAL "03")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_03}")
elseif(CMAKE_BUILD_TYPE STREQUAL "0fast")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_0FAST}")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_DEBUG}")
endif()
