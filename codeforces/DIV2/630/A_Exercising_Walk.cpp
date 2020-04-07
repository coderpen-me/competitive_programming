#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>
#define pb(a) push_back(a)
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

int main(){
IOS();
    t = tc();
    //t = 1;
    while(t--){
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        ll x, y, x1, y1, x2, y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        ll xa = 0, ya = 0;
        if((a - b) >= 0){
            xa = b - a;
        }
        else xa = (b- a);
        if((c - d) >= 0){
            ya = d - c;
        }
        else ya = d - c;
        ll flag = 0;
        if(xa >= 0){
            if(x2 < (x + 1)){
                flag = 1;
            }
        }
        else{
            if(x1 > (x - 1)){
                flag = 1;
            }
        }
        if(ya >= 0){
            if(y2 < (y + 1)){
                flag = 1;
            }
        }
        else{
            if(y1 > (y - 1)){
                flag = 1;
            }
        }
        if(flag == 1){
            b1("NO");
            continue;
        }
        if((x1 <= (x + xa)) && (x2 >= (x + xa)) && (y1 <= (y + ya)) && (y2 >= (y + ya))){
            b1("YES");
        }
        else b1("NO");
    }
    
    return 0;
}