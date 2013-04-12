def pentagonalCheck(pN):
    n = (math.sqrt((24 * pN) + 1) + 1) / 6
    if n == int(n):
        return True
    return False

def hexagonalCheck(hN):
    n = (math.sqrt((8 * hN) + 1) + 1) / 4
    if n == int(n):
        return True
    return False

def questionFortyFour():
    lowestD = 99999
    for j in range(1, 50000, 1):
        pJ = pentagon(j)
        for k in range(1, j, 1):
            pK = pentagon(k)
            if pentagonalCheck(pJ + pK):
                if pentagonalCheck(pJ - pK):
                    d = abs(pK - pJ)
                    print(d)
                    if d < lowestD:
                        lowestD = d
    print(lowestD)
