#ifndef PROBLEM_2H
#define PROBLEM_2H

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

int count_digits(needed_type number);
needed_type ipow10(int);
void number_split_without_middle(needed_type, needed_type*, needed_type*);
needed_type middle_digit(needed_type);
bool unity_digits_check(needed_type, needed_type);
bool split_6_for_2_digit_number(needed_type);
bool split_10_for_2_digit_number(needed_type);
bool split_9_for_3_digit_number(needed_type);

#endif