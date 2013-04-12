def primeCheck(num):
    currentNumber = 2
    if num < 0:
        return False
    while currentNumber <= math.sqrt(num):
        if (num % currentNumber) == 0:
            return False
        currentNumber = currentNumber + 1
    return True

def reduceStringLeft(string):
    newStr = ""
    for i in range(1, len(string), 1):
        newStr = newStr + string[i]
    return newStr

def reduceStringRight(string):
    newStr = ""
    for i in range(len(string) - 1):
        newStr = newStr + string[i]
    return newStr

def questionThirtySeven():
    total = 0
    for num in range(10, 1000000, 1):
        if primeCheck(num):
            string = str(num)
            checks = 1
            endLoop = False
            truncatable = True
            while endLoop == False:
                string = reduceStringLeft(string)
                if not primeCheck(int(string)):
                    truncatable = False
                    endLoop = True
                checks = checks + 1
                if checks == len(str(num)):
                    endLoop = True
            if truncatable:
                string = str(num)
                checks = 1
                endLoop = False
                while endLoop == False:
                    string = reduceStringRight(string)
                    if not primeCheck(int(string)):
                        truncatable = False
                        endLoop = True
                    checks = checks + 1
                    if checks == len(str(num)):
                        endLoop = True
            string = str(num)
            
            if int(string[0]) == 1:
                truncatable = False
            elif int(string[-1]) == 1:
                truncatable = False
                
            if truncatable:
                total = total + num
                print(num)
    print(total)
