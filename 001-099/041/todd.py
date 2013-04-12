def primeCheck(num):
    currentNumber = 2
    if num < 0:
        return False
    while currentNumber <= math.sqrt(num):
        if (num % currentNumber) == 0:
            return False
        currentNumber = currentNumber + 1
    return True

def questionFortyOne():
    largest = 0
    for num in range(11, 10000000, 2):
        if primeCheck(num): # is it prime?
            string = str(num)
            numList = []
            for i in range(len(string)):
                numList.append(string[i])
            numList = bubbleSort(numList)
            #print(numList)
            pandigitalList = []
            for i in range(len(numList)):
                pandigitalList.append(str(i + 1))
            #print(pandigitalList)
            if pandigitalList == numList:
                isPandigital = True
            else:
                isPandigital = False
            if isPandigital:
                if num > largest:
                    print(num)
                    largest = num
    print(largest)
