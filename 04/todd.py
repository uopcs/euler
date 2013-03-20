## OLD CODE

def reverseString(string):
    length = len(string) + 1
    reverse = ""
    for i in range(-1, -length, -1):
        reverse = reverse + string[i]
    return reverse
        


def questionFour():
    currentLargest = 0
    for numberOne in range(100, 999, 1):
        for numberTwo in range(100, 999, 1):
            product = numberOne * numberTwo
            product = str(product)
            reverse = reverseString(product)
            reverse = int(reverse)
            product = int(product)
            if reverse == product:
                if product > currentLargest:
                    currentLargest = product
                    print(product)
