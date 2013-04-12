def questionNine():
    for a in range(500):
        for b in range(500):
            for c in range(500):
                if ((a + b + c) == 1000) and ((a * a) + (b * b) == (c * c)):
                    print(a * b * c)

## dat complexity
