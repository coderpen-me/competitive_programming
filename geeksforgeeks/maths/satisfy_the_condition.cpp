#include <bits/stdc++.h>
using namespace std;

int a, b, x, p;

int expo(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        x = (x * x) % p;
        y /= 2;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> a >> b >> p >> x;
        int ans = 0;
        for (int n2 = 0; n2 < p - 1; n2++)
        {
            int A = expo(a, n2);

            int n1 = (b * expo(A, p - 2)) % p;

            int n = p * (n2 - n1) + n1;

            n = (n + p * (p - 1)) % (p * (p - 1));
            if (n > x)
                continue;
            ans += (x - n) / (p * (p - 1)) + 1;
            if (n == 0)
                ans--;
        }
        cout << ans << endl;
    }
}