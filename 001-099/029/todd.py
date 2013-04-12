def questionTwentyNine():
    combinations = []
    for a in range(2, 101, 1):
        for b in range(2, 101, 1):
            term = a ** b
            #print(term)
            double = False
            for current in combinations:
                if term == current:
                    double = True
            if double == False:
                combinations.append(term)
    print(len(combinations))
