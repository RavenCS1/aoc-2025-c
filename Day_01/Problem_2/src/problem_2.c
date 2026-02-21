#include "problem_2.h"

int counting_lines(FILE* filename){
    int number_of_lines = 0;
    char buffer[MAX_LENGTH_OF_LINE];

    while (fgets(buffer, sizeof(buffer), filename))
        number_of_lines++;

    rewind(filename);
    
    return number_of_lines;
}
