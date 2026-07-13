# cmake -B build
# cmake --build build

cmake_minimum_required(VERSION 3.10)
project(AdventOfCode2025 C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_01 "-O1 -Wall")
set(CMAKE_C_FLAGS_02 "-O2 -Wall")
set(CMAKE_C_FLAGS_03 "-O3 -Wall")
set(CMAKE_C_FLAGS_0FAST "-Ofast -Wall")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

if(CMAKE_BUILD_TYPE STREQUAL "01")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_01}")
elseif(CMAKE_BUILD_TYPE STREQUAL "02")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_02}")
elseif(CMAKE_BUILD_TYPE STREQUAL "03")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_03}")
elseif(CMAKE_BUILD_TYPE STREQUAL "0fast")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_0FAST}")
endif()

# Every day_NN/problem_NN directory containing a main.c becomes its own
# executable target, named <day>_<problem> (e.g. day_01_problem_01),
# with its binary written back into that same directory so relative
# paths to puzzle input files keep working. Directories that don't match
# the day_NN/problem_NN convention (e.g. one-off scratch dirs) are skipped.
file(GLOB DAY_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/day_*")

foreach(DAY_DIR ${DAY_DIRS})
    if(NOT IS_DIRECTORY ${DAY_DIR})
        continue()
    endif()
    get_filename_component(DAY_NAME ${DAY_DIR} NAME)
    if(NOT DAY_NAME MATCHES "^day_[0-9]+$")
        continue()
    endif()

    file(GLOB PROBLEM_DIRS LIST_DIRECTORIES true "${DAY_DIR}/*")
    foreach(PROBLEM_DIR ${PROBLEM_DIRS})
        if(NOT IS_DIRECTORY ${PROBLEM_DIR} OR NOT EXISTS "${PROBLEM_DIR}/main.c")
            continue()
        endif()
        get_filename_component(PROBLEM_NAME ${PROBLEM_DIR} NAME)
        if(NOT PROBLEM_NAME MATCHES "^problem_[0-9]+$")
            continue()
        endif()
        set(TARGET_NAME "${DAY_NAME}_${PROBLEM_NAME}")

        file(GLOB PROBLEM_SOURCES "${PROBLEM_DIR}/src/*.c")

        add_executable(${TARGET_NAME} "${PROBLEM_DIR}/main.c" ${PROBLEM_SOURCES})
        target_include_directories(${TARGET_NAME} PRIVATE "${PROBLEM_DIR}/include")
        target_link_libraries(${TARGET_NAME} m)
        set_target_properties(${TARGET_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${PROBLEM_DIR}"
        )
    endforeach()
endforeach()
