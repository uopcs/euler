def primeCheck(num):
    currentNumber = 2
    if num < 0:
        return False
    while currentNumber <= math.sqrt(num):
        if (num % currentNumber) == 0:
            return False
        currentNumber = currentNumber + 1
    return True

def questionTwentySeven():
    current = [0, 0, 0] # [a, b, streak]
    for a in range(-999, 1000, 1):
        for b in range(-999, 1000, 1):
            endLoop = False
            n = 0
            streak = 0
            while endLoop == False:
                p = (n * n) + (a * n) + b
                if not primeCheck(p):
                    endLoop = True
                else:
                    streak = streak + 1
                if streak > current[2]: # update largest
                    #print(streak)
                    current[0] = a
                    current[1] = b
                    current[2] = streak
                n = n + 1
    product = current[0] * current[1]
    return product, current
