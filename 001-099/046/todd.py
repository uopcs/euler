def questionFortySix():
    endLoop = False
    num = 10
    while not endLoop:
        if (num % 2) == 1:
            if not primeCheck(num):
                root = 1
                endLoop2 = False
                doesWork = False
                while not endLoop2:
                    if (2 * (root ** 2)) >= num:
                        endLoop2 = True
                    difference = num - 2 * (root ** 2)
                    if primeCheck(difference):
                        doesWork = True
                        endLoop2 = True
                    root = root + 1
                if not doesWork:
                    print(num)
                    endLoop = True
        num = num + 1
