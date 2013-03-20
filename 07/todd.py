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

def questionSeven():
    number = 5
    count = 2
    while count < 10001:
        isPrime = primeCheck(number)
        if isPrime:
            count = count + 1
            print("PRIME ", count, ": ", number)
        number = number + 2
