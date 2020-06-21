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
string in;
int testcases()
{
    cin >> test;
    return test;
}

set<int, greater <int>> printDivisors(int n) 
{
    vector<int> v;
    set<int, greater <int>> s; 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i==0) 
        { 
            if (n/i == i){
                if(i & 1 && i != 1) s.insert(i);
                //printf("%d ", i);
            }
            else
            {
                if(i & 1 && i != 1) s.insert(i);
                //printf("%d ", i);
                v.push_back(n/i); 
            } 
        } 
    }
    for (int i=v.size()-1; i>=0; i--)
        if(v[i] & 1 && i != 1) s.insert(v[i]);
    return s;
}

int main()
{
    
    ll t;
    cin >> t;
    while (t--)
    {
        ll win = 0;
        cin >> u;
        while(u > 1){
            set<int, greater <int>> odd = printDivisors(u);
            if(odd.size() == 0){
                u--;
                win = !win;
            }
            else{
                for(auto x : odd){
                    int res = u / x;
                    if(res == 1){
                        win = !win;
                        u = 1;
                        break;
                    }
                    if(res & 1){
                        continue;
                    }
                    else{
                        u = res;
                        win = !win;
                        break;
                    }
                }
            }
        }
        (win == 0) ? cout<<"FastestFinger" : cout<<"Ashishgup";
        nl;
    }
    return 0;
}