def intCheck(num):
    isInt = False
    if num - int(num) == 0:
        isInt = True
    return isInt

def bubbleSort(list2):
    #swap_test = False
    for i in range(0, len(list2) - 1):
        # as suggested by kubrick, makes sense
        swap_test = False
        for j in range(0, len(list2) - i - 1):
            if list2[j] > list2[j + 1]:
                list2[j], list2[j + 1] = list2[j + 1], list2[j]  # swap
            swap_test = True
        if swap_test == False:
            break
    return list2

def questionThirtyTwo():
    terms = []
    for num in range(1000, 98765, 1):
        for i in range(1, int(math.sqrt(num)) + 1, 1):
            if intCheck(num / i):
                
                multiplicant = str(int(num / i))
                multiplyer = str(i)
                product = str(num)
                string = str(multiplicant + multiplyer + product)
                if len(string) == 9:
                    digits = []
                    for digit in string:
                       digits.append(digit) # create list of digits
                    digits = bubbleSort(digits) # sort list
                    #print(digits)
                    k = 1
                    index = 0
                    endLoop = False
                    isPandigital = True
                    while endLoop == False: # check if list is pandigital
                        
                       # print(k, " ",digits[index])
                        if k != int(digits[index]):
                            endLoop = True
                            isPandigital = False
                        if k == 9:
                            endLoop = True
                        k = k + 1
                        index = index + 1
                    if isPandigital:  
                        print(digits)
                       # digits.append(num)
                        canAdd = True
                        for term in range(len(terms)): # checks if the product already exists
                            if num == terms[term]:
                                canAdd = False
                        if canAdd == True:
                            terms.append(num)
                            print(num)
    print(terms)
    total = 0
    for term in terms:
        total = total + term
    print(total)
