def questionTwentyFive():
    term = 3
    n = 2
    n1 = 1
    n2 = 1
    while True:
        n2 = n1
        n1 = n
        n = n1 + n2
        term = term + 1
        if len(str(n)) > 999:
            return term
