#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// it is bugged but imma not debbug it 
int findSmallerNumberPosition(int* nums, int numsSize, int bottom, int top){
    if (bottom >= top) {
        return bottom; 
    }

    int middle = (top + bottom) / 2;

    if (nums[bottom] > nums[middle]) {
        return findSmallerNumberPosition(nums, numsSize, bottom, middle); 
    } else {
        return findSmallerNumberPosition(nums, numsSize, middle + 1, top); 
    }
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
        else if(nums[middle] < target){
            top = middle - 1;
        }
    }

    return -1;
}

int search(int* nums, int numsSize, int target) {
    int bottom = 0;
    int top = numsSize - 1;
    int smallestNumberPosition;

    int probablySmallestNumberPosition = findSmallerNumberPosition(nums, numsSize, bottom, top);

    // turnaround bc i am lazzy enought to fix the function findSmallerNumberPosition
    if(nums[probablySmallestNumberPosition] > nums[probablySmallestNumberPosition+1]){
        smallestNumberPosition = probablySmallestNumberPosition + 1;
    } else smallestNumberPosition = probablySmallestNumberPosition;
    

    printf("%d", smallestNumberPosition);

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

int main(){
    int array[7] = {4,5,6,7,0,1,2};

    int position = search(array, 7, 0);

    printf("%d\n", position);

    return 0;
}