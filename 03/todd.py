## OLD CODE


def primeCheck(num):
    currentNumber = 2
    if num < 0:
        return False
    while currentNumber <= math.sqrt(num):
        if (num % currentNumber) == 0:
            return False
        currentNumber = currentNumber + 1
    return True

def intCheck(num):
    isInt = False
    if num - int(num) == 0:
        isInt = True
    return isInt
    

def questionThree():
    for i in range(1, 100000000, 1):
        current = 600851475143 / i
        isInt = intCheck(current)
        if isInt == True:
            current = int(current)
            #print(current, i)
            isPrime = primeCheck(current)
            if isPrime == True:
                print("PRIME ", current)
            isPrime = primeCheck(i)
            if isPrime == True:
                print("PRIME ", i)
