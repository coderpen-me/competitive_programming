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
ll sum = 0, sum1 = 0, mul = 0, subs = 0, test = 0, num = 0, num1 = 0, n,k;;
string in;
int testcases()
{
    cin >> test;
    return test;
}

long long a[200005], b[200005];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (long long i = 1; i <= n; i++)
            cin >> a[i];
        for (long long i = 1; i <= k; i++)
            cin >> b[i];

        sort(a + 1, a + n + 1);
        sort(b + 1, b + k + 1, cmp);

        long long l = 1, r = n, ans = 0;
        for (long long i = 1; i <= k; i++)
        {
            if (b[i] == 1)
            {
                ans += a[r] * 2;
                r--;
            }
        }
        for (long long i = 1; i <= k; i++)
        {
            if (b[i] == 1)
                break;

            long long minv = 1e9 + 7, maxv = a[r];
            for (long long j = l; j <= l + b[i] - 2; j++)
                minv = min(minv, a[j]);

            ans += minv + maxv;
            l = l + b[i] - 1;
            r--;
        }
        cout << ans << endl;
    }
    return 0;
}