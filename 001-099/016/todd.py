def questionSixteen():
    string = 2 ** 1000
    string = str(string)
    total = 0
    for i in range(len(string)):
        total = total + int(string[i])
    print(total)
