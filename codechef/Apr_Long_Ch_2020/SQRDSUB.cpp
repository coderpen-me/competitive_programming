#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>

#define LP(i, n) for (ll i = 0; i < n; i++)
#define LP1(i, n) for (ll i = 1; i <= n; i++)
#define BLP1(i, n) for (ll i = n; i > 0; i--)
#define BLP(i, n) for (ll i = n; i >= 0; i--)

#define el '\n'
#define IOS()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define tc() testcases()
#define pvi(A) printvectorint(A)
#define pvs(A) printvectorstring(A)
#define pvvi(A) printvectorvectorint(A)

#define a1(a) cout << a << " ";
#define a2(a, b) cout << a << " " << b << " ";
#define a3(a, b, c) cout << a << " " << b << " " << c << " ";
#define a4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << " ";
#define a5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e << " ";

#define b1(a) cout << a << "\n";
#define b2(a, b) cout << a << " " << b << "\n";
#define b3(a, b, c) cout << a << " " << b << " " << c << "\n";
#define b4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << "\n";
#define b5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e << "\n";

#define nl cout << "\n"

const ll MAXn = 1e5 + 5, MAXlg = __lg(MAXn) + 2;
const ll MOD = 1000000007;
const ll INF = ll(1e15);

void printvectorint(vector<int> A)
{
    nl;
    for (auto x : A)
    {
        a1(x);
    }
    nl;
}

void printvectorstring(vector<string> A)
{
    nl;
    for (auto x : A)
    {
        cout << (x);
    }
    nl;
}

void printvectorvectorint(vector<vector<int>> A)
{
    nl;
    for (auto x : A)
    {
        for (auto y : x)
        {
            a1(y);
        }
        nl;
    }
    nl;
}
ll t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
ll sum = 0, sum1 = 0, mul = 0, subs = 0, test = 0, num = 0, num1 = 0;
//ll aa=0, bb=0, cc=0, dd=0, ee=0;
//ll count=0, ctl=0, ctrl=0, divi=0, flag=0, cal=0, must=0, test=0;
string in;
int testcases()
{
    cin >> test;
    return test;
}

int facts(int x)
{
    int ctr = 0;
    while (x % 2 == 0 && x > 0)
    {
        ctr++;
        x /= 2;
        if (ctr >= 2)
            break;
    }
    return ctr;
}

void modd(int a[], int n)
{
    LP(i, n)
    {
        if (a[i] % 2 == 1)
            a[i] = 0;
        else
        {
            a[i] = facts(a[i]);
        }
    }
}

int main()
{
    IOS();
    t = tc();
    while (t--)
    {
        cin>>u;
        int a[u];
        LP(i, u)
        {
            cin >> v;
            a[i] = abs(v);
        }
        sum = 0;
        modd(a, u);

        int b[u];
        LP(i, u)
        {
            b[i] = 0;
        }
        LP(i, u)
        {
            if (a[i] > 1)
            {
                int l = (u - i);
                b[i] = l;
                sum += l;
            }
        }
        LP(i, u)
        {
            if (a[i] == 1)
            {
                for (int j = i + 1; j < u; j++)
                {
                    if (a[j] > 0)
                    {
                        int l = (u - j);
                        sum += l;
                        b[i] = l;
                        i = j - 1;
                        break;
                    }
                }
            }
        }
        w = 0;
        for (int i = 0; i < u; i++)
        {
            if (a[i] == 0) w++;
            else
            {
                ll s = w * (w + 1) / 2;
                sum += s + w * b[i];
                w = 0;
            }
        }

        if (w > 0)
        {
            ll s = w * (w + 1) / 2;
            sum += s;
        }

        b1(sum);
    }
    return 0;
}