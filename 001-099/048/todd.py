def questionFortyEight():
    string = ""
    newString = ""
    series = 0
    for n in range(1, 1001, 1):
        series = series + (n ** n)
    string = str(series)
    for i in range(-10, 0, 1):
        newString = newString + string[i]
    print(newString)
