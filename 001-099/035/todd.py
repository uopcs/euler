def primeCheck(num):
    currentNumber = 2
    if num < 0:
        return False
    while currentNumber <= math.sqrt(num):
        if (num % currentNumber) == 0:
            return False
        currentNumber = currentNumber + 1
    return True

def shiftString(string):
    listStr = []
    for i in range(len(string)): # convert string to list
        listStr.append(string[i])
    temp = string[0]
    for i in range(len(string)): # shift contents
        if (i + 1) > (len(string) - 1):
            listStr[i] = temp
        else:
            listStr[i] = listStr[i + 1]
    string = ""
    for i in range(len(listStr)): # return to string
        string  = string + listStr[i]
    return string
    

def questionThirtyFive():
    counter = 1
    for i in range(3, 1000000, 2):
        if primeCheck(i):
            string = str(i)
            j = 0
            endLoop = False
            isCircularPrime = True
            while j < len(string) and endLoop == False:
                string = shiftString(string)
                if not primeCheck(int(string)):
                    isCircularPrime = False
                    endLoop = True
                j = j + 1
            if isCircularPrime:
                counter = counter + 1
    print(counter)
