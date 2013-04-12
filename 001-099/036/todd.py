def denToBin(num):
    binStr = ""
    endLoop = False
    while not endLoop:
        if num == 0:
            endLoop = True
        if num % 2 == 1:
            binStr = binStr + "1"
        else:
            binStr = binStr + "0"
        num = num / 2
        num = int(num)
    binStr = reverseString(binStr)
    binStr = int(binStr)
    return binStr

def questionThirtySix():
    total = 0
    for num in range(1, 1000000, 1):
        num = str(num)
        if num == reverseString(num):
            binStr = denToBin(int(num))
            binStr = str(binStr)
            #print(num, binStr)
            if binStr == reverseString(binStr):
                total = total + int(num)
    print(total)
