#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findSmallerNumberPosition(int* nums, int numsSize) {
    int bottom = 0;
    int top = numsSize - 1;
    
    if (nums[bottom] < nums[top] || numsSize == 1) {
        return bottom;
    }

    while (bottom <= top) {
        int mid = (bottom + top) / 2;

        if (mid > 0 && nums[mid] < nums[mid - 1]) {
            return mid;
        }

        if (nums[mid] > nums[top]) {
            bottom = mid + 1;
        } else {
            top = mid - 1;
        }
    }

    return -1;
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
        else if(nums[middle] > target){
            top = middle - 1;
        }
    }

    return -1;
}

int search(int* nums, int numsSize, int target) {
    int bottom = 0;
    int top = numsSize - 1;

    int smallestNumberPosition = findSmallerNumberPosition(nums, numsSize);
    
    int sizeArr1 = numsSize - smallestNumberPosition;
    int sizeArr2 = numsSize - sizeArr1;

    int *arr1 = malloc(sizeArr1*sizeof(int));
    int *arr2 = malloc(sizeArr2*sizeof(int));

    memcpy(arr1, &nums[smallestNumberPosition], sizeArr1 * sizeof(int));
    memcpy(arr2, &nums[bottom], sizeArr2 * sizeof(int));

    int resultArr1 = binary_search(arr1, sizeArr1, target);

    if(resultArr1 != -1){
        return resultArr1 + sizeArr2;
    } else {
        int resultArr2 = binary_search(arr2, sizeArr2, target);

        if (resultArr2 != -1){
            return resultArr2;
        }
        else {
            return -1;
        }
    }

    free(arr1);
    free(arr2);
}

// created to run locally
int main(){
    int array[7] = {4,5,6,7,0,1,2};
    int position = search(array, 7, 0);
    printf("%d\n", position);
    return 0;
}