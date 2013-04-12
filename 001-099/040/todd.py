def questionForty():
    d = ""
    for i in range(1, 1000000, 1):
        d = d + str(i)
    print(int(d[0]) * int(d[9]) * int(d[99]) * int(d[999]) * int(d[9999]) * int(d[99999]) * int(d[999999]))
