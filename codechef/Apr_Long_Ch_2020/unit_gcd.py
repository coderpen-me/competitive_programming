for i in range(int(input())): #unitgcd
    n=int(input())
    if n<=4:
        print(1)
        print(n,end=" ")
        for i in range(n):
            print(i+1,end=" ")
    else:
        k=4
        print(n//2)
        print(3,1,2,3)
        while k<n:
            if n-k>=1:
                print(2,k,k+1)
                k+=2
        if n%2==0:
            print(1,n)