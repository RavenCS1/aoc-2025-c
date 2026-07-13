#include "problem_02.h"

int main(void){
    const char* filename = "../my_puzzle_input.txt";
    FILE* input = fopen(filename, "r");
    if(!input){
        printf("Unexpected error occured! Cannot open the file.\n");
        exit(EXIT_FAILURE);
    }

    register long result = {};
    register long read = {};

    register int first = {};
    register int second = {};
    register int first_index = {};
    register int second_index = {};

    register int max_found_index = {};
    register int end_found_index = {};
    register int second_found_index = {};

    register int count = {};

    register size_t len = {};

    char buffer[MAX_LENGTH_OF_LINE] = {};

    register bool check = false;

    while(fgets(buffer, sizeof(buffer), input)){
        len = strlen(buffer);

        bool map[MAX_LENGTH_OF_LINE - 2] = {};

        max_found_index = 0;
        count = 0;

        for(size_t j = 0; j < NUMBER_OF_PAIRS; ++j){
            first = second = 0;
            first_index = 0;
            second_index = 1;

            for(size_t i = max_found_index + 1; i < len - 1; ++i){
                if(first < (buffer[i] - '0') && (len - 1 - i >= NUMBER_OF_PAIRS * 2 - count) && !(map[i])){
                    register size_t k = {};

                    for(k = i + 1; k < len - 1; ++k){
                        if(!(map[k])){
                            check = true;
                            break;
                        }
                    }

                    if(check){
                        first = buffer[i] - '0';
                        map[first_index] = false;

                        first_index = i;

                        map[first_index] = true;
                        second = buffer[k] - '0';
                        map[second_index] = false;

                        second_index = k;

                        map[second_index] = true;
                    }
                }
                /*else if(first < (buffer[i] - '0') && (len - 1 - i >= NUMBER_OF_PAIRS * 2 - count) && second_index == i){
                    size_t k;
                    for(k = i + 1; k < len - 1; ++k){
                        if(!(map[k])){
                            check = true;
                            break;
                        }
                    }
                    if(check){
                        first = buffer[i] - '0';
                        map[first_index] = false;
                        first_index = i;
                        map[first_index] = true;
                        second = buffer[k] - '0';
                        map[second_index] = false;
                        second_index = k;
                        map[second_index] = true;
                    }
                }*/
                else if(second < (buffer[i] - '0') && !(map[i])){
                    second = buffer[i] - '0';
                    map[second_index] = false;
                    second_index = i;
                    map[second_index] = true;
                }

                check = false;
            }

            count += 2;
            second_found_index = second_index;

            if(second_found_index > end_found_index)                        end_found_index = second_found_index;
            if(len - 1 - second_index >= (NUMBER_OF_PAIRS - (j + 1)) * 2)   max_found_index = second_index;
            else                                                            max_found_index = first_index;
            
            /*else{
                for(size_t w = first_index + 1; w < len - 1; ++w){
                    map[w] = true;
                }
                goto end;
            }*/
        }
        //end:
        result = summing(buffer, map);
        result += read;
    }

    (void) printf("Result: %ld\n", result);

    fclose(input);
    
    return EXIT_SUCCESS;
}

