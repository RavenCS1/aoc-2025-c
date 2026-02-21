#include "problem_1.h"

int main(void){
    const char* filename = "../my_puzzle_input.txt";
    FILE* input = fopen(filename, "r");
    if(!input){
        printf("Unexpected error occured! Cannot open the file.\n");
        exit(EXIT_FAILURE);
    }

    int result = 0;
    int first = 0;
    int second = 0;
    int read = 0;

    size_t len = 0;
    char buffer[MAX_LENGTH_OF_LINE];

    while(fgets(buffer, sizeof(buffer), input)){
        len = strlen(buffer);
        first = buffer[0] - '0';
        second = buffer[1] - '0';
        for(size_t i = 1; i < len - 1; ++i){
            if(first < (buffer[i] - '0') && (i + 2 != len)){
                first = buffer[i] - '0';
                second = buffer[i + 1] - '0';
            }
            else if(first < (buffer[i] - '0') && (i + 2 == len))
                second = buffer[i] - '0';
            else if(second < (buffer[i] - '0'))
                second = buffer[i] - '0';
        }
        read = first * 10 + second * 1;
        result += read;
    }

    printf("Result: %d\n", result);
    fclose(input);
    
    return EXIT_SUCCESS;
}