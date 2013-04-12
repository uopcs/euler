def getDOfN(n):
    d = 0
    for i in range(1, int(math.sqrt(n)) + 1, 1):
        if intCheck(n / i):
            d = d + (n  / i)
            d = d + i
    d = d - n
    return d



def questionTwentyOne():
    total = 0
    for n in range(1, 10001, 1):
        dOfN = getDOfN(n)
        if getDOfN(dOfN) == n and int(dOfN) != n:
            #print(dOfN, ", ", n)
            
            total = total + (n)
    print(total)
