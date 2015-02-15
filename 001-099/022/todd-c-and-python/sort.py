open("names_s.txt", "w+").write(",".join(sorted(open("names.txt").read().split(","))))

# sorts names in names.txt
