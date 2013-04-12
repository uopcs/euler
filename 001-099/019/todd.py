def questionNineteen():
    month = 1
    dayOfMonth = 1
    day = 1
    count = 0
    year = 1901
    while year < 2001:
        if day == 6 and dayOfMonth == 1: # add to count
            count = count + 1
           # print(day, dayOfMonth)
        dayOfMonth = dayOfMonth + 1
        day = day + 1
        if day == 7: # update day of week
            day = 0
        if month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12:
            if dayOfMonth == 32: # update month
                dayOfMonth = 1
                month = month + 1
        elif month == 4 or month == 6 or month == 9 or month == 11:
            if dayOfMonth == 31:
                dayOfMonth = 1
                month = month + 1
        elif month == 2:
            if year % 4 == 0 and year % 400 != 0: # leap year
                if dayOfMonth == 30:
                    #print(dayOfMonth - 1, "   ", year)
                    dayOfMonth = 1
                    month = month + 1
            else:
                if dayOfMonth == 29:
                    dayOfMonth = 1
                    month = month + 1
        if month == 13:
            month = 1
            year = year + 1
            #print(year)
    print(count)
