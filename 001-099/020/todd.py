def questionTwenty():
    string = str(math.factorial(100))
    total = 0
    for i in range(len(string)):
        total = total + int(string[i])
    print(total)
