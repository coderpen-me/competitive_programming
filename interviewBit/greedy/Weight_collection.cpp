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

int n, k;

vector<pair<int, ll>> tree[500001];

int vis[500001];

ll ans;

void solve(int x, ll sum, ll chance)
{
    vis[x] = 1;

    if (chance <= 0)
    {
        return;
    }

    for (int i = 0; i < tree[x].size(); i++)
    {
        pair<int, ll> p;

        p = tree[x][i];

        if (vis[p.first] == 0)
        {
            ll temp = sum + (p.second * chance);

            if (temp > ans)
                ans = temp;

            sum = sum + p.second;

            solve(p.first, sum, chance - 1);

            sum = sum - p.second;
        }
    }
}

int main()
{
    IOS();
    //t = tc();
    t = 1;
    while (t--)
    {
        int A = 3;
        vi B = {0, 1, 1, 2, 2, 3};
        vi C = {1, 6, 7, 21, 5, 18};
        int s = B.size();
        for (int i = 1; i < s; i++){
            ll a, b, c;
            b = i+1;
            a = B[i];
            c = abs(C[i]-C[a-1]);
            tree[b].push_back(make_pair(a, c));
            tree[a].push_back(make_pair(b, c));
            /*a3(a, b, c);
            nl;*/
        }
        ans = 0;
        memset(vis, 0, sizeof(vis));
        solve(1, 0, A);
        cout << ans;
    }

    return 0;
}