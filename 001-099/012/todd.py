def questionTwelve():
    first = 1 # the number to be added on each time
    triangle = 0 # the last triangle number to be used
    for i in range(1, 50000, 1):
        triangle = triangle + first
        first = first + 1
        if (triangle % 2) == 0:  
            count = 0
            for k in range(1, int(math.sqrt(triangle)) + 1 , 1): # no factor and it's pair can exist above sqrt(number)
                if triangle % k == 0:
                    count = count + 2 # factors come in pairs
            if count >= 500:
                print(triangle, "!!!!!", count, "!!!!!!", i)
                return triangle
