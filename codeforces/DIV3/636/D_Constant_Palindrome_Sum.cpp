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
#define foe(i, a, b) for (i = a; i <= b; i++)
#define fo(i, a, b) for (i = a; i < b; i++)
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
ll sum1 = 0, mul = 0, subs = 0, test = 0, num = 0, num1 = 0;
//ll aa=0, bb=0, cc=0, dd=0, ee=0;
//ll count=0, ctl=0, ctrl=0, divi=0, flag=0, cal=0, must=0, test=0;
string in;
int testcases()
{
    cin >> test;
    return test;
}

ll cover[400005], diff[400005];
ll sum[400005];
void update(ll l, ll r)
{
    ++diff[l];
    --diff[r + 1];
}

void magic(ll l, ll r)
{
    ll i;
    cover[l] = diff[l];
    foe(i, l + 1, r)
        cover[i] = diff[i] + cover[i - 1];
}

int main()
{
    IOS();
    t = tc();
    //t = 1;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        ll i;
        for(ll i = 0; i < n; i++) cin >> arr[i];
        ll ans = INT_MAX;
        vi sums;
        bool lucky = false;
        fo(i, 0, n / 2)
        {
            ll l, r;
            l = i;
            r = n - 1 - i;
            l = arr[l];
            r = arr[r];
            sum[l + r]++;
            sums.push_back(l + r);
            if (sum[l + r] == n / 2)
            {
                ans = 0;
                lucky = true;
                break;
            }
            update(min(l, r) + 1, max(l, r) + k);
        }
        magic(2, 2 * k);
        if (!lucky)
        {
            foe(i, 2, 2 * k)
            {
                ll temp = 0;
                temp += cover[i];
                temp += 2 * (n / 2 - cover[i]);
                temp -= sum[i];
                ans = min(ans, temp);
            }
        }
        cout << ans << '\n';
        //dont forget to clear values;
        for (auto x : sums)
            sum[x] = 0;
        foe(i, 1, 2 * k + 3) cover[i] = diff[i] = 0;
    }

    return 0;
}