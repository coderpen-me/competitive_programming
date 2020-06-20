x = [14, 27, 1, 4, 2, 50, 3, 1]
y = [2, 4, -4, 3, 1, 1, 14, 27, 50]

n = len(x)
m = len(y)

d = {}
if n > m :
    for i in range(0, m):
        if y[i] in d.keys():
            d[y[i]] = d[y[i]]+1
        else:
            d[y[i]] = 1
    for i in range(0, n):
        if x[i] not in d.keys():
            print(x[i])
else :
    for i in range(0, n):
        if x[i] in d.keys():
            d[x[i]] = d[x[i]]+1
        else:
            d[x[i]] = 1
    for i in range(0, m):
        if y[i] not in d.keys():
            print(y[i])