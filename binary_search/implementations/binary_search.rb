NOT_FOUNT_WITHIN_ARRAY = - 1
STOP_APPLICATION = -1

def binary_search(ordered_array, scoped_number)
    ordered_array_size = ordered_array.size

    bottom = 0
    top = ordered_array_size - 1

    while(bottom <= top)
        middle = (top + bottom)/2

        if ordered_array[middle] == scoped_number
            return middle;
        elsif ordered_array[middle] < scoped_number 
            bottom = middle + 1
        elsif ordered_array[middle] > scoped_number
            top = middle - 1
        end
    end

    return NOT_FOUNT_WITHIN_ARRAY
end


def run_program
    scoped_number = 35;
    array = [1, 2, 3, 4, 5, 6, 7, 8, 10, 11]
    is_program_running = true
    loopTracker = 1

    while is_program_running
        print "-" * 15
        print loopTracker
        puts "-" * 15

        print "Type the number you wanna find in the array: "
        input = gets.chomp.to_i

        if input == STOP_APPLICATION
            break
        end

        numberPosition = binary_search(array, input)

        if numberPosition == NOT_FOUNT_WITHIN_ARRAY
            puts "Your number is not within the array";
        elsif
            print "Your number is in the position: "
            puts numberPosition
        end
        puts "-" * 31

        loopTracker = loopTracker + 1
    end

    puts "Hope you enjoyed"
end


run_program