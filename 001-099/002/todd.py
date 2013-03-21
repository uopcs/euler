def questionTwo():
    total = 2
    currentValue = 2
    nMinusOne = 1
    nMinusTwo = 1
    while currentValue < 4000000:
        nMinusTwo = nMinusOne
        nMinusOne = currentValue
        currentValue = nMinusOne + nMinusTwo
        if (currentValue % 2) == 0:
            total = total + currentValue
    print(total)
