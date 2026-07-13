#include "problem_02.h"

int counting_lines(FILE filename[restrict const static 1]) {
    register int number_of_lines = {};

    char buffer[MAX_LENGTH_OF_LINE] = {};

    while(fgets(buffer, sizeof(buffer), filename))
        ++number_of_lines;
    
    rewind(filename);

    return number_of_lines;
}

long summing(char str[restrict const static MAX_LENGTH_OF_LINE], bool map[restrict const static MAX_LENGTH_OF_LINE - 2]) {
    register int power = 11;
    register long multiplier = 1;
    register long result = 0;

    for(size_t i = 0; i < power; ++i)
        multiplier *= 10;

    for(size_t i = 0; i < MAX_LENGTH_OF_LINE - 2; ++i)
        if(map[i]){
            result += multiplier * (str[i] - '0');
            multiplier /= 10;
        }

    return result;
}