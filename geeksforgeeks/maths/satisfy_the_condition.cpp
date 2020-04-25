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
            cout<<" For n2 = "<<n2<<endl<<endl;
            int A = expo(a, n2);
            cout<<" A = "<<A<<endl;
            int n1 = (b * expo(A, p - 2)) % p;
            cout<<" For n1 = "<<n1<<endl;
            int n = p * (n2 - n1) + n1;
            cout<<" For n = "<<n<<endl;
            n = (n + p * (p - 1)) % (p * (p - 1));
            cout<<" For n = "<<n<<endl;
            if (n > x)
                continue;
            ans += (x - n) / (p * (p - 1)) + 1;
            cout<<" For ans = "<<ans<<endl<<endl;
            if (n == 0)
                ans--;
        }
        cout << ans << endl;
    }
}