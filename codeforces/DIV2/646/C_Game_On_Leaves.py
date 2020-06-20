import sys
input = sys.stdin.readline
T = int(input())

def rem(cnt):
    global ans
    if tree[x].count(1) == 1:
        if cnt % 2 == 1:
            ans = 'Ashish'
            return
    elif ans == 'Ashish':
        return
    else:
        for i in range(n+1):
            if tree[i].count(1) == 1:
                idx = tree[i].index(1)
                tree[i][idx] = 0
                tree[idx][i] = 0
                rem(cnt+1)
                tree[i][idx] = 1
                tree[idx][i] = 1
for _ in range(T):
    n, x = map(int, input().split())
    node = []

    tree = [[0] * (n+1) for _ in range(n+1)]
    for i in range(n-1):
        u, v = map(int, input().split())
        tree[u][v] = 1
        tree[v][u] = 1

    ans = 'Ayush'
    cnt = 0
    rem(cnt)
    print(ans)