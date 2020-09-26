n, m = [int(x) for x in input().split()]
arr_size = int(input())
l = list(map(float, input().split()))

if m < n :
    tmp = m
    m = n
    n = tmp

st1 = m - n
st2 = 0

ed1 = m-1
ed2 = m-1

moving_avg_n = 0.0
moving_avg_m = 0.0

i = 0
while (i < n) :
        moving_avg_n += l[m - i - 1]
        i+=1
i = 0
while (i < m) :
        moving_avg_m += l[i]
        i+=1

#print(moving_avg_n/n, moving_avg_m/m)

ctr = 0

prev_n = moving_avg_n
prev_m = moving_avg_m

for i in range(m, arr_size):
    if( ((moving_avg_n/n) - (moving_avg_m/m)) != 0):
        prev_n = moving_avg_n
        prev_m = moving_avg_m

    moving_avg_n -= l[st1]
    st1 += 1
    ed1 += 1
    moving_avg_n += l[ed1]

    moving_avg_m -= l[st2]
    st2 += 1
    ed2 += 1
    moving_avg_m += l[ed2]

    if(((prev_n/n) - (prev_m/m) < 0) and ((moving_avg_n/n) - (moving_avg_m/m) > 0)):
        ctr += 1
    if(((prev_n/n) - (prev_m/m) > 0) and ((moving_avg_n/n) - (moving_avg_m/m) < 0)):
        ctr += 1
    #print(moving_avg_n/n, moving_avg_m/m)
print(ctr)