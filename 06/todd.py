## OLD CODE

def questionSix():
        sumOfSquares = 0
        total = 0
        squareOfSum = 0
        for i in range(1, 101, 1):
            square = i * i
            total = total + square
        sumOfSquares = total
        suM = 0
        for i in range(1, 101, 1):
            suM = suM + i
        squareOfSum = suM * suM
        print(squareOfSum)
        if sumOfSquares > squareOfSum:
            difference = sumOfSquares = squareOfSum
        else:
            difference = squareOfSum - sumOfSquares
        print(difference)
