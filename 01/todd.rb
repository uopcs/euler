# ruby solution
# problem 1

total = 0
for i in 1 .. 999
    if (i % 3 == 0) | (i % 5 == 0)
        total = total + i
    end
end
puts("#{total}")
