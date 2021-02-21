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

int main(){
IOS();
    t = tc();
    //t = 1;
    while(t--){
        cin>>u;
        ll zero = 0, one = 0, two = 0;
        LP(i, u){
            cin>>v;
            if(v % 3 == 1){
                one++;
            }
            if(v % 3 == 2){
                two++;
            }
            if(v % 3 == 0){
                zero++;
            }
        }
        ll total = zero + one + two;
        ll per = total / 3;
        ll ret = 0;
        zero -= per;
        one -= per;
        two -= per;
        ll A[3] = {zero, one, two};
        while(A[0] != 0 || A[1] != 0 || A[2] != 0){
            ll i = 0;
            while(A[i] <= 0 && i < 3){
                i++;
            }
            if(i == 3) {
                break;
            }
            ll prev = A[i];
            A[i] = 0;
            ret += prev;
            i++;
            if(i == 3) i = 0;
            A[i] += prev;
            prev = A[i];
            if(A[i] <= 0) continue;
            A[i] = 0;
            ret += prev;
            i++;
            if(i == 3) i = 0;
            A[i] += prev;
            prev = A[i];
            if(A[i] <= 0) continue;
            A[i] = 0;
            ret += prev;
            i++;
            if(i == 3) i = 0;
        }
        b1(ret);
    }
    
    return 0;
}