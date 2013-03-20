## OLD CODE

def intCheck(num):
    isInt = False
    if num - int(num) == 0:
        isInt = True
    return isInt

def questionFive():
    for number in range(2500, 1000000000, 20):
        i = 19
        endLoop = False
        isAnswer = True
        while endLoop == False:
            x = number / i
            if intCheck(x) == False:
                isAnswer = False
                endLoop = True
            elif i == 3:
                endLoop = True
            i = i - 1
        if isAnswer == True:
            print(number)
