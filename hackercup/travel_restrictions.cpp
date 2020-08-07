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

void recurr(ll i, vector<vi> &mag, ll I[], ll O[]){
    mag[i][i] = 1;
    if(O[i] == 1){
        ll j = i;
        while((j+1 < u) && (I[j+1] == 1)){
            mag[i][j+1] = 1;
            if(O[j+1] == 0) break;
            j++;
        }

        j = i;
        while((j-1 >= 0) && (I[j-1] == 1)){
            mag[i][j-1] = 1;
            if(O[j-1] == 0) break;
            j--;
        }
    }
}

int main()
{
    ll t, nn;
    cin >> t;
    nn = t;
    while (t--)
    {
        cin >> u;
        ll I[u], O[u];
        LP(i, u)
        {
            char c;
            cin >> c;
            if (c == 'Y')
                I[i] = 1;
            else
                I[i] = 0;
        }
        LP(i, u)
        {
            char c;
            cin >> c;
            if (c == 'Y')
                O[i] = 1;
            else
                O[i] = 0;
        }
        vector<vi> mag(u, vector<int>(u, 0));
        for(int i = 0; i < u; i++){
            recurr(i, mag, I, O);
        }
        cout<<"Case #"<<(nn-t)<<":\n";
        for(auto x : mag){
            for(auto y : x){
                if(y == 1)
                    cout<<'Y';
                else cout<<'N';
            }
            nl;
        }
    }
    return 0;
}