#include "problem_01.h"

int main(void){
    const char* filename = "../my_puzzle_input.txt";

    FILE* input = fopen(filename, "r");
    if(!input){
        printf("Unexpected error occured! Cannot open the file.\n");
        exit(EXIT_FAILURE);
    }

    register int starting_position = 50;
    register int result = 0;
    register int read_number = 0;

    register bool state = false;
    char buffer[MAX_LENGTH_OF_LINE] = {};

    while(fgets(buffer, sizeof(buffer), input)){
        if(buffer[0] == 'L') state = false;
        else                 state = true;

        switch(strlen(buffer) - 3){
            case 0: read_number = buffer[1] - '0'; break;
            case 1: read_number = (buffer[1] - '0') * 10 + (buffer[2] - '0'); break;
            case 2: read_number = (buffer[1] - '0') * 100 + (buffer[2] - '0') * 10 + (buffer[3] - '0'); break;
        }

        read_number = read_number % 100;

        if(state){
            starting_position += read_number;
            if(starting_position > 99) starting_position = starting_position % 100;
        } else{
            starting_position -= read_number;
            if(starting_position < 0) starting_position += 100;
        }

        if(starting_position == 0) ++result;
    }

    (void) printf("Result: %d\n", result);

    fclose(input);

    return EXIT_SUCCESS;
}