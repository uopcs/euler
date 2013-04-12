def questionThirty():
    values = []
    for i in range(2, 1000000, 1):
        string = str(i)
        total = 0
        for j in range(len(string)):
            total = total + int(string[j]) ** 5
        if total == i:
            values.append(i)
    sumOfValues = 0
    for i in values:
        sumOfValues = sumOfValues + i
    return values, sumOfValues
