def questionThirtyFour():
    total = 0
    for num in range(10, 100000, 1):
        digits = []
        string = str(num)
        for digit in range(len(string)):
            digits.append(string[digit])
        factorialSum = 0
        for i in range(len(digits)):
            factorialSum = factorialSum + math.factorial(int(digits[i]))
        if factorialSum == num:
            print(num)
            total = total + num
    print(total)
