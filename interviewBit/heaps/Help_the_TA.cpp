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
        //1 1 1 1 1 1 2 1 2 1 2 0 1 2 0 1 2 3 4 
        vi A = {2, 10, 5, 1, 1};
        int B = 15;
        priority_queue<pair<int, int>> q;
        vector<int> ret;
        for (int i = 0; i < A.size(); i++)
        {
            q.push({A[i], i});
        }
        while (B--)
        {
            cout<<" q size is "<<q.size()<<" ";
            if (q.empty())
                break;
            pair<int, int> p = q.top();
            q.pop();
            vector<pair<int, int>> md;
            md.push_back(p);
            int mini = p.second;
            while (!q.empty() && q.top().first == p.first)
            {
                md.push_back(q.top());
                if (q.top().second < mini)
                    mini = q.top().second;
                q.pop();
            }
            ret.push_back(mini);
            for (auto x : md)
            {
                if (x.second == mini)
                {
                    if (x.first > 1)
                    {
                        q.emplace(make_pair(x.first - 1, x.second));
                    }
                }
                else
                {
                    q.emplace(make_pair(x.first, x.second));
                }
            }
        }
        pvi(ret);
    }

    return 0;
}