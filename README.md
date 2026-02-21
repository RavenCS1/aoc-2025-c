# AoC 2025 in C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

Advent of Code 2025 solutions in clean C.

## Status
**Completed:** Day 01, Day 02, Day 03 - Problem 1  
**Under construction** - more solutions coming (time constraints)

## Build & Run

**Each problem folder:**
```bash
cd Day_01/Problem_1
mkdir build && cd build
cmake ..
make
./solution_1
```

## Input Files
IMPORTANT:

Constants in .h files (NUMBER_OF_ALL_STRINGS, etc.) are optimized for MY input data (AoC rules prohibit sharing puzzle inputs).

Users MUST:

Download YOUR my_puzzle_input.txt from adventofcode.com

Place in same folder as main.c

Adjust constants in problem_X.h for your input size

Rebuild

Problem_1/
- main.c
- my_puzzle_input.txt     ← YOUR private input
- include/problem_1.h     ← Adjust NUMBER_OF_ALL_STRINGS
- src/problem_1.c
