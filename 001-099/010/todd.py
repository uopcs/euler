def primeCheck(num):
    currentNumber = 2
    if num < 0:
        return False
    while currentNumber <= math.sqrt(num):
        if (num % currentNumber) == 0:
            return False
        currentNumber = currentNumber + 1
    return True


def questionTen():
    sumOfPrimes = 17 # 2 + 3 + 5 + 7
    for i in range(11, 2000000, 2):
        if primeCheck(i):
            sumOfPrimes = sumOfPrimes + i
            #print(i)
    print(sumOfPrimes)
