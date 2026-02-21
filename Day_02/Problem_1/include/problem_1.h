#ifndef PROBLEM_1H
#define PROBLEM_1H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_LEN ((int) 10)
#define NUMBER_OF_ALL_STRINGS ((int) 66)
#define NUMBER_OF_ALL_RANGES ((int) NUMBER_OF_ALL_STRINGS / 2)
#define MAX_BUFFER_SIZE ((int) 477) // 476 + 1

typedef long needed_type;
typedef long long result_type;

needed_type count_digits(needed_type);
needed_type ipow10(int);
void number_split_without_middle(needed_type, needed_type*, needed_type*);
needed_type middle_digit(needed_type);
needed_type unity_figure(needed_type);

#endif