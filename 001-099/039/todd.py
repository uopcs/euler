def questionThirtyNine():
    current = [0, 0] # p, noOfCombos
    for p in range(720, 1000, 120):
        noOfCombos = 0
        for a in range(int(p / 2)):
            for b in range(int(p / 2)):
                for c in range(int(p / 2)):
                    if (( a ** 2) + (b ** 2)) == (c ** 2):
                        if a + b + c == p:
                            print(a, b, c)
                            noOfCombos = noOfCombos + 1
        if noOfCombos > current[1]:
            current[0] = p
            current[1] = noOfCombos
            print(p)
    print(current)
