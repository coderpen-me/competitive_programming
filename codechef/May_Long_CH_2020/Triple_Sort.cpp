#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<ll>
#define vs vector<string>
#define vvi vector<vector<ll>>

#define LP(i, n) for (ll i = 0; i < n; i++)
#define LP1(i, n) for (ll i = 1; i <= n; i++)
#define BLP1(i, n) for (ll i = n; i > 0; i--)
#define BLP(i, n) for (ll i = n; i >= 0; i--)

#define el '\n'
#define IOS()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define tc() testcases()
#define pvi(A) prllvectorll(A)
#define pvs(A) prllvectorstring(A)
#define pvvi(A) prllvectorvectorll(A)

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

void prllvectorll(vector<ll> A)
{
    nl;
    for (auto x : A)
    {
        a1(x);
    }
    nl;
}

void prllvectorstring(vector<string> A)
{
    nl;
    for (auto x : A)
    {
        cout << (x);
    }
    nl;
}

void prllvectorvectorll(vector<vector<ll>> A)
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
ll testcases()
{
    cin >> test;
    return test;
}

vi Depth_First(ll src, ll a[], bool mark[]) {
    vi tmp;
    ll copy_src = src;
    while (a[copy_src] != src) {
        mark[copy_src] = true;
        tmp.push_back(copy_src);
        copy_src = a[copy_src];
    }
    mark[copy_src] = true;
    tmp.push_back(copy_src);
    return tmp;
}

int main()
{
    IOS();
    t = tc();
    //t = 1;
    while (t--)
    {
        ll a[200001];
        bool mark[200001];
        ll n, k;
        cin >> n >> k;
        
        ll cnt = 0, odd_ops = 0, even_ops = 0;
        memset(mark, 0, sizeof(mark));
        vvi odd, even;

        LP1(i, n){
            cin>>a[i];
        }
        
        LP1(j, n){
            if (!mark[j]){
                vi au = Depth_First(j, a, mark);
                if (au.size() % 2 == 1){
                    odd_ops += au.size() / 2;
                    odd.push_back(au);
                }
                else{
                    even_ops += (au.size() - 1) / 2;
                    even.push_back(au);
                    cnt++;
                }
            }
        }
        int total = odd_ops + even_ops + (cnt);

        if (cnt % 2 == 1 || total > k){
            b1(-1);
        }

        else{
            int p, s;
            b1(total);
            
            for (auto l : odd){
                s = l.size();
                for (p = 1; p < s - 1; p += 2){
                    b3(l[0],l[p],l[p + 1]);
                }
            }
            
            for (auto l : even){
                s = l.size();
                for (p = 1; p < s - 1; p += 2){
                    b3(l[0],l[p],l[p + 1]);
                }
            }
            
            for (p = 0; p < cnt - 1; p += 2){
                vi l1 = even[p];
                vi l2 = even[p+1];
                ll x1 = l1[0], y1 = l1[l1.size() - 1];
                ll x2 = l2[0], y2 = l2[l2.size() - 1];
                b3(x1,y1,x2);
                b3(y2,x2,x1);
            }
        }
    }

    return 0;
}