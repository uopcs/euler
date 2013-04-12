def questionTwentyEight():
    n = 1
    edgeSize = 2
    edgeCount = 1
    sumOfNumbers = 1
    while (edgeSize) < 1001:
        n = n + edgeSize
        edgeCount = edgeCount + 1
        if edgeCount == 5:
            edgeCount = 1
            edgeSize = edgeSize + 2
        sumOfNumbers = sumOfNumbers + n
        #print(n)
    print(sumOfNumbers)
