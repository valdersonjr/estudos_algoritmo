def binary_search(nums, numsSize, target):
    bottom = 0
    top = len(nums) - 1

    while bottom <= top:
        middle = (top + bottom) // 2

        if nums[middle] == target:
            return middle
        elif nums[middle] < target:
            bottom = middle + 1
        else:
            top = middle - 1

    return -1

def search_in_range(nums, numsSize, target):
    randomTargetPosition = binary_search(nums, numsSize, target)

    increased_position = randomTargetPosition
    decreased_position = randomTargetPosition
    run_loop1 = True
    run_loop2 = True

    while run_loop1 or run_loop2:
        if increased_position < numsSize - 1 and nums[increased_position + 1] == target:
            increased_position+=1
        else:
            run_loop1 = False
        
        if decreased_position > 0 and nums[decreased_position - 1] == target:
            decreased_position-=1
        else:
            run_loop2 = False
        
    positions = [0, 0]
    positions[0] = decreased_position
    positions[1] = increased_position
    return positions


def main():
    nums = list(map(int, input("Enter sorted numbers separated by space: ").split()))
    target = int(input("Enter target number: "))
    
    positions = search_in_range(nums, len(nums), target)
    
    if positions[0] == positions[1]:
        print(f"Target {target} found at index: {positions[0]}")
    else:
        print(f"Target {target} found from index {positions[0]} to {positions[1]}")

if __name__ == "__main__":
    main()