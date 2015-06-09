# pandigital finder


def getCombinations(st):
    if (len(st) == 1):
        return [st]
    toRet = []
    for i in range(len(st)):
        ch = st[i]
        chs = st[0:i]+st[(i+1):len(st)]
        toRet += [ch + x for x in getCombinations(chs)]
    return toRet

def getPandigital(n):
    st = ("").join([str(x) for x in range(n)])
    return getCombinations(st)

def test(n):
    d234 = int(n[1:4])
    d345 = int(n[2:5])
    d456 = int(n[3:6])
    d567 = int(n[4:7])
    d678 = int(n[5:8])
    d789 = int(n[6:9])
    d890 =int(n[7:10])
    
    if d234 % 2 != 0:
        return False
    if d345 % 3 != 0:
        return False
    if d456 % 5 != 0:
        return False
    if d567 % 7 != 0:
        return False
    if d678 % 11 != 0:
        return False
    if d789 % 13 != 0:
        return False
    if d890 % 17 != 0:
        return False
    return True

s=0
pandigitals = getPandigital(10)
for pan in pandigitals:
    if test(pan):
        s += int(pan)

print s
