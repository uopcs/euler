def primeCheck(num):
    currentNumber = 2
    if num < 0:
        return False
    while currentNumber <= math.sqrt(num):
        if (num % currentNumber) == 0:
            return False
        currentNumber = currentNumber + 1
    return True

def getCycle(dec):
    dec = str(dec)
    haveCycle = False
    cycleSize = 1
    while haveCycle == False:
        if dec[2:2 + cycleSize] == dec[(cycleSize)+ 2:(2 * cycleSize) + 2] == dec[(2 * cycleSize)+ 2:(3 * cycleSize) + 2]:
            haveCycle = True
            return cycleSize
        elif (len(dec) - 3) < cycleSize:
            return cycleSize
        else:
            cycleSize = cycleSize + 1

            
def questionTwentySix():
    total = 0
    current = 1
    for d in range(1, 1000, 1):
        if primeCheck(d):
            cycle = getCycle(1 / d)
            print(cycle, " ", d)
            if cycle > total:
                total = cycle
                print(d)
