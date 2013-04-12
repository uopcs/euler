def questionFourteen():
    longest = 0
    winner = 0
    for number in range(600001, 1000000, 2):
        count = 0
        if count == 0:
            x = number
        while number > 1:
            number = int(number)
            #print(number, end=" ")
            if number % 2 == 0:
                number = number / 2
            else:
                number = 3 * number + 1
            count = count + 1
        if count > longest:
            longest = count
            winner = x
        #print("")5
    print(winner, ", ", longest)
