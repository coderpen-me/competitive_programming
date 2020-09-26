import math
n, m = [int(x) for x in input().split()]
if m < n :
    tmp = m
    m = n
    n = tmp
i = 0
if (m == n) :
        print(0)
else:
    hash = {}
    count = 1
    hash[m] = 0
    while (m != 1) :
        for i in range(2, int(math.sqrt(m))+2):
            if(m % i == 0):
                break
        #print(i)
        if(i == int(math.sqrt(m))+1):
            hash[1] = count
            break
        else:
            hash[m/i] = count
            count += 1
            m /= i
    count = 0
    while(True) :
        if(n in hash):
            count+=hash[n]
            break
        else :
            for i in range(2, int(math.sqrt(n))+2):
                if(n % i == 0) :
                    break
            #print(i)
            if(i == (int((math.sqrt(n)))) + 1):
                n = 1
                count += 1
            else:
                count += 1
                n = n / i
    print(count)