NOT_FOUND_WITHIN_ARRAY = -1
STOP_APPLICATION = -1

def binary_search(ordered_array, scoped_number):
    ordered_array_size = len(ordered_array)

    bottom = 0
    top = ordered_array_size - 1

    while bottom <= top:
        middle = (top + bottom) // 2

        if ordered_array[middle] == scoped_number:
            return middle
        elif ordered_array[middle] < scoped_number:
            bottom = middle + 1
        else:
            top = middle - 1

    return NOT_FOUND_WITHIN_ARRAY


def run_program():
    array = [1, 2, 3, 4, 5, 6, 7, 8, 10, 11]
    is_program_running = True
    loop_tracker = 1

    while is_program_running:
        print("-" * 15)
        print(loop_tracker)
        print("-" * 15)

        input_number = int(input("Type the number you wanna find in the array: "))

        if input_number == STOP_APPLICATION:
            break

        number_position = binary_search(array, input_number)

        if number_position == NOT_FOUND_WITHIN_ARRAY:
            print("Your number is not within the array")
        else:
            print(f"Your number is in the position: {number_position}")

        print("-" * 31)
        loop_tracker += 1

    print("Hope you enjoyed")


run_program()