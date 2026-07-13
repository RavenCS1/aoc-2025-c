#include "problem_01.h"

int counting_lines(FILE filename[restrict const static 1]) {
    register int number_of_lines = {};

    char buffer[MAX_LENGTH_OF_LINE] = {};

    while(fgets(buffer, sizeof(buffer), filename))
        ++number_of_lines;

    rewind(filename);
    
    return number_of_lines;
}