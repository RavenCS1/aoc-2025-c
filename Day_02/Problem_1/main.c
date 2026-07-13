#include "problem_1.h"

int main(void){
    const char* filename = "../my_puzzle_input.txt";
    FILE* input = fopen(filename, "r");
    if(!input){
        printf("Unexpected error occured! Cannot open the file.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_BUFFER_SIZE] = {};
    if(!fgets(line, sizeof(line), input)){
        fclose(input);
        return EXIT_FAILURE;
    }
    fclose(input);

    needed_type tab[NUMBER_OF_ALL_STRINGS] = {};

    register int position = 0;
    char* ptr = strtok(line, ",-");
    tab[position++] = atol(ptr);

    while(ptr){
        ptr = strtok(0, ",-");
        if(position != NUMBER_OF_ALL_STRINGS)
            tab[position++] = atol(ptr);
    }

    needed_type start = {};
    needed_type end = {};
    needed_type first_half = {};
    needed_type second_half = {};
    result_type result = {};
    needed_type number_of_digits = {};
  
    for(size_t i = 0; i < NUMBER_OF_ALL_STRINGS; i += 2){
        start = tab[i];
        end = tab[i + 1];

        for(; start <= end; ++start){
            number_of_digits = count_digits(start);

            if(number_of_digits % 2 == 0){
                number_split_without_middle(start, &first_half, &second_half);
                if(first_half == second_half){
                    result += start;
                }
            }
        }
    }

    (void) printf("Result %lld\n", result);
    
    return EXIT_SUCCESS;
}