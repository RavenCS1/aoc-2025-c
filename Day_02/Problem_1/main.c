#include "problem_1.h"

int main(void){
    const char* filename = "../my_puzzle_input.txt";
    FILE* input = fopen(filename, "r");
    if(!input){
        printf("Unexpected error occured! Cannot open the file.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_BUFFER_SIZE] = {0};
    if(!fgets(line, sizeof(line), input)){
        fclose(input);
        return EXIT_FAILURE;
    }
    fclose(input);

    needed_type tab[NUMBER_OF_ALL_STRINGS] = {0};

    int position = 0;
    char *ptr = strtok(line, ",-");
    tab[position++] = atol(ptr);

    while(ptr){
        ptr = strtok(0, ",-");
        if(position != NUMBER_OF_ALL_STRINGS)
            tab[position++] = atol(ptr);
    }

    needed_type start = 0;
    needed_type end = 0;
    needed_type first_half = 0;
    needed_type second_half = 0;
    result_type result = 0;
    needed_type number_of_digits = 0;
  
    for(size_t i = 0; i < NUMBER_OF_ALL_STRINGS; i += 2){
        start = tab[i]; end = tab[i + 1];
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

    printf("Result %lld\n", result);
    
    return EXIT_SUCCESS;
}