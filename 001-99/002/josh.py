def fibionacciNumbers():
    total = 0
    previousNumber = 0
    currentNumber = 1
    totalNumber = 0
    while previousNumber <= 4000000:
        totalNumber = previousNumber + currentNumber
        previousNumber = currentNumber
        currentNumber = totalNumber
        if currentNumber % 2 == 0:
            total = total + currentNumber
    print(total)
