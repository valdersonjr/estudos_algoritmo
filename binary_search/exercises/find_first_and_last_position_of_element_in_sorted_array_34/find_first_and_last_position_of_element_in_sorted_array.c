#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void print_array(int *arr, int size){
    printf("\n------- ARRAY START -------\n");
    for(int i = 0; i < size; i++){
        printf("Position: %d", i);
        printf(" | ");
        printf("Value: %d", arr[i]);
        printf("\n");
    }
    printf("------- ARRAY END -------\n");
}

int binary_search(int* nums, int numsSize, int target){
    int bottom = 0;
    int top = numsSize - 1;

    while(bottom <= top){
        int middle = (top + bottom) / 2;

        if(nums[middle] == target){
            return middle;
        }
        else if(nums[middle] < target){
            bottom = middle + 1;
        }
        else {
            top = middle - 1;
        }
    }

    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* positions = malloc(2 * sizeof(int));
 
    int randomTargetPosition = binary_search(nums, numsSize, target);

    int increased_position = randomTargetPosition;
    int decreased_position = randomTargetPosition;
    bool run_loop1 = true, run_loop2 = true;

    while(run_loop1 || run_loop2) {
        if (increased_position < numsSize - 1 && nums[increased_position + 1] == target) {
            increased_position++;
        } else {
            run_loop1 = false;
        }

        if (decreased_position > 0 && nums[decreased_position - 1] == target) {
            decreased_position--;
        } else {
            run_loop2 = false;
        }
    }

    positions[0] = decreased_position;
    positions[1] = increased_position;
    *returnSize = 2;
    return positions;
}


int main(){
    int arr[6] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int returnSize;
    
    int* positions = searchRange(arr, 6, target, &returnSize);

    printf("First and last positions of %d are: [%d, %d]\n", target, positions[0], positions[1]);

    free(positions);
    return 0;
}