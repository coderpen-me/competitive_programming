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

int main()
{
    IOS();
    //t = tc();
    t = 1;
    while (t--)
    {
        int A = 10;
        vvi B = {{3, 5}, {3, 3}, {5, 6}, {1, 3}, {5, 8}, {3, 8}};
        vvi C = {{3, 7}, {8, 8}, {9, 2}, {7, 0}, {9, 7}, {1, 9}, {4, 3}, {9, 8}};
        unordered_set<long> s;
        unordered_map<int, int> xcheck, ycheck, d1check, d2check;
        for (auto p : B)
        {
            int x = p[0];
            int y = p[1];
            s.insert(static_cast<long>(x) << 32 | y);
            xcheck[x]++;
            ycheck[y]++;
            d1check[x + y]++;
            d2check[x - y]++;
        }
        vector<int> ans;
        for (auto p : C)
        {
            int x = p[0];
            int y = p[1];
            if (xcheck.count(x) || ycheck.count(y) || d1check.count(x + y) || d2check.count(x - y))
            {
                ans.push_back(1);
                for (int i = x - 1; i <= x + 1; i++)
                {
                    for (int j = y - 1; j <= y + 1; j++)
                    {
                        if (i < 0 || i >= A || j < 0 || j >= A)
                            continue;
                        const long key = static_cast<long>(i) << 32 | j;
                        if (!s.count(key))
                            continue;
                        s.erase(key);
                        if (xcheck[i] == 0)
                        {
                            xcheck[i]--;
                            xcheck.erase(i);
                        }
                        if (ycheck[j] == 0)
                        {
                            ycheck[j]--;
                            ycheck.erase(j);
                        }
                        if (d1check[i + j] == 0)
                        {
                            d1check[i + j]--;
                            d1check.erase(i + j);
                        }
                        if (d2check[i - j] == 0)
                        {
                            d2check[i - j]--;
                            d2check.erase(i - j);
                        }
                    }
                }
            }
            else
                ans.push_back(0);
        }
        pvi(ans);
    }

    return 0;
}