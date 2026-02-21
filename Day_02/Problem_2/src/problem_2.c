#include "problem_2.h"
#include <stdbool.h>

int count_digits(needed_type number){
    int cnt = 0;

    while(number > 0){
        number /= 10;
        cnt++;
    }

    return cnt ? cnt : 1;
}

needed_type ipow10(int number){
    needed_type result = 1;

    for(int i = 0; i < number; ++i)
        result *= 10;

    return result;
}

void number_split_without_middle(needed_type number, needed_type* first_half, needed_type* second_half){
    int n = count_digits(number);
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

bool unity_digits_check(needed_type number, needed_type check){
    needed_type tmp = number < 0 ? -number : number;

    while(tmp > 0){
        if((tmp % 10) != check) return false;
        tmp /= 10;
    }

    return true;
}

bool split_6_for_2_digit_number(needed_type number){
    int division_1 = (int)(pow(10, 4)); 
    int division_2 = (int)(pow(10, 2));
    needed_type first = number / division_1;   
    needed_type second = (number / division_2) % 100;   
    needed_type third = number % 100; 

    return (first == second  && first == third && second == third);
}


bool split_10_for_2_digit_number(needed_type number){
    needed_type parts[5];

    parts[0] = number / ipow10(8);
    parts[1] = (number / ipow10(6)) % 100;
    parts[2] = (number / ipow10(4)) % 100;
    parts[3] = (number / ipow10(2)) % 100;
    parts[4] = number % 100;

    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++)
            if(parts[i] != parts[j]) return false;
    }

    return true;
}


bool split_9_for_3_digit_number(needed_type num){
    int division_1 = (int)(pow(10, 6));
    int division_2 = (int)(pow(10, 3));
    needed_type first = num / division_1;              
    needed_type second = (num / division_2) % 1000;    
    needed_type third = num % 1000;     
    
    return (first == second && first == third && second == third);
}
