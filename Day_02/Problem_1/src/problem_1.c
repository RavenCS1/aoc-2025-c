#include "problem_1.h"

needed_type count_digits(needed_type number){
    if(number == 0) return ((needed_type) 1); // number cannot be 0 here
    if(number < 0) number = -number;          // number cnanot be negative here

    return (needed_type)(log10(number)) + 1;
}

needed_type ipow10(int number){
    needed_type result = 1;

    for(int i = 0; i < number; ++i)
        result *= 10;

    return result;
}

void number_split_without_middle(needed_type number, needed_type* first_half, needed_type* second_half){
    int n = 0;
    needed_type tmp = number;

    while(tmp > 0){
        tmp /= 10;
        n++;
    }

    int half_len = n / 2;
    needed_type division = ipow10(n - half_len);
    needed_type modulo = ipow10(half_len);

    *first_half = number / division;
    *second_half = number % modulo;

    return;
}

needed_type middle_digit(needed_type number){
    needed_type n = count_digits(number);
    needed_type mid = n / 2;
    needed_type division = ipow10(mid);

    number /= division;
    
    return number % 10;
}

needed_type unity_figure(needed_type number){
    return number % 10;
}