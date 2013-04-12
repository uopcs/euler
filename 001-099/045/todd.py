def triangle(n):
    tN = ((n ** 2) + n) / 2
    return int(tN)

def pentagon(n):
    pN = n *((3 * n) - 1) / 2
    return int(pN)

def hexagon(n):
    hN = n * ((2 * n) - 1)
    return int(hN)



def questionFortyFive():
    triangle = 1
    add = 2
    endLoop = False
    while not endLoop:
        triangle = triangle + add
        add = add + 1
        if pentagonalCheck(triangle) and hexagonalCheck(triangle):
            print(triangle)
            if triangle > 50000:
                endLoop = True
    return triangle
