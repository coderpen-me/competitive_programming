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

ll a[MAXn], b[MAXn], c[MAXn], d[MAXn];

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

vector<int> seg[400005];
int n, ip[100005];
void build(int x = 0, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        seg[x] = vector<int>(1, ip[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * x + 1, l, m);
    build(2 * x + 2, m + 1, r);
    seg[x] = vector<int>();
    int i = 0, j = 0;
    while (i < seg[2 * x + 1].size() && j < seg[2 * x + 2].size())
    {
        if (seg[2 * x + 1][i] <= seg[2 * x + 2][j])
        {
            seg[x].push_back(seg[2 * x + 1][i++]);
        }
        else
        {
            seg[x].push_back(seg[2 * x + 2][j++]);
        }
    }
    while (i < seg[2 * x + 1].size())
    {
        seg[x].push_back(seg[2 * x + 1][i++]);
    }
    while (j < seg[2 * x + 2].size())
    {
        seg[x].push_back(seg[2 * x + 2][j++]);
    }
    return;
}

int query(int a, int b, int y, int x = 0, int l = 0, int r = n - 1)
{
    if (l > r || r < a || b < l)
    {
        return 0;
    }
    if (a <= l && r <= b)
    {
        return lower_bound(seg[x].begin(), seg[x].end(), y) - seg[x].begin();
    }
    int m = (l + r) / 2;
    return query(a, b, y, 2 * x + 1, l, m) + query(a, b, y, 2 * x + 2, m + 1, r);
}

int main()
{
    IOS();
    //t = tc();
    t = 1;
    while (t--)
    {
        vi A = {1, 5, 4, 2, 1};
        n = A.size();
        copy(A.begin(), A.end(), ip);
        build();
        vector<int> ans(n);
        for (int i = 0; i < A.size(); i++)
        {
            ans[i] = query(i + 1, n - 1, A[i]);
        }
        pvi(ans);
    }

    return 0;
}