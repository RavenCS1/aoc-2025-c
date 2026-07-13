#ifndef PROBLEM_1H
#define PROBLEM_1H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

constexpr int MAX_LEN = 10;
constexpr int NUMBER_OF_ALL_STRINGS = 66;
constexpr int NUMBER_OF_ALL_RANGES = NUMBER_OF_ALL_STRINGS / 2;
constexpr int MAX_BUFFER_SIZE = 477; // 476 + 1

typedef long needed_type;
typedef long long result_type;

needed_type count_digits(needed_type);
needed_type ipow10(int);
void number_split_without_middle(needed_type, needed_type [const static 1], needed_type [const static 1]);
needed_type middle_digit(needed_type);
needed_type unity_figure(needed_type);

#endif