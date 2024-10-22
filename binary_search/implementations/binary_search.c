#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ARRAY_SIZE = 10;

typedef struct binary_search_data_t {
    int bottom;
    int middle;
    int top;
} binary_search_data_t;

int binary_search(int *ordered_array, int array_size, int scoped_number){
    binary_search_data_t binary_search;

    binary_search.bottom = 0;
    binary_search.top = array_size - 1;

    while(binary_search.bottom <= binary_search.top){
        binary_search.middle = (binary_search.bottom + binary_search.top)/2;

        if(ordered_array[binary_search.middle] == scoped_number){
            return binary_search.middle;
        }
        else if (ordered_array[binary_search.middle] < scoped_number) {
            binary_search.bottom = binary_search.middle;
        }
        else if (ordered_array[binary_search.middle] > scoped_number) {
            binary_search.top = binary_search.middle;
        }
    }

    return -1;
}

int random_bigger_number_generator(int number) {
    int increment = rand() % 100 + 1;
    return number + increment;
}

void populate_array(int* array, int size){
    array[0] = 1;

    for(int i=1; i < size; i++){
        int previous_number = array[i-1];
        array[i] = random_bigger_number_generator(previous_number);
    }
}

void print_array(int *arr, int size){
    printf("\n------- ARRAY START -------");
    for(int i=0; i<size; i++){
        printf("Position: %d", i);
        printf(" | ");
        printf("Value: %d", arr[i]);
        printf("\n");
    }
    printf("------- ARRAY END -------\n");
}

int main(void){
    int *arr;
    int size = ARRAY_SIZE;
    int is_program_running = true;

    arr = malloc(size*sizeof(int));

    populate_array(arr, size);
    
    while (is_program_running){
        print_array(arr, size);

        int selectedNumber;
        printf("Select a number from the array or -1 to stop the program: ");
        scanf("%d", &selectedNumber);
        printf("\n");


        if(selectedNumber == -1) {
            is_program_running = false;
            continue;
        }
        
        int numbersPosition = binary_search(arr, size, selectedNumber);

        printf("\n***** ANSWER *******\n");
        if(numbersPosition == -1) {
            printf("This number does not exist inside the array\n");
            continue;
        }

        // return the position starting to count from number 0
        printf("Numbers position in the array: %d", numbersPosition);
        printf("\n*********************");
    }
    
    printf("See you next time! Hope you enjoyed.");
    printf("\n");
    return 0;
}
