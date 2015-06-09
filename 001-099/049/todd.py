#prime permutations

import math

def isPrime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if (n % i == 0):
            return False
    return True

def test(n):
    n1 = n+3330
    n2 = n+6660
    if sorted(str(n)) == sorted(str(n1)) and sorted(str(n1)) == sorted(str(n2)):
        if isPrime(n) and isPrime(n1) and isPrime(n2):
            return True
    return False
    

for i in range(1000, 9999-6660):
    if i == 1487:
        continue
    if test(i):
        print str(i) + str(i+3330) + str(i+6660)
