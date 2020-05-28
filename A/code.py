res = 0
c = 0
with open('input-201.txt', 'r') as file:
    for x in file.readlines():
        x = int(x.strip())
        if c == 0:
            res = x
            c += 1
        else:
            res ^= x
with open('input-201.a.txt', 'w') as file:
    file.write(str(res))