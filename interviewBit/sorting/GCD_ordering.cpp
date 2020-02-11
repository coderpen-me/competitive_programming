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
/*
int gcd(int a, int b)
{
    if (a > b)
        return gcd(b, a);
    else if (a == 0 && a == b)
        return 0;
    else if (a == 0)
        return b;
    else
        return __gcd(a, b);
}

vector<int> solvee(vector<int> &A)
{
    int n = A.size();
    vector<int> ret;
    int i, flag, ps;
    sort(A.begin(), A.end());
    if (n < 3)
    {
        for (i = n - 1; i >= 0; i--)
            ret.push_back(A[i]);
        return ret;
    }
    else
    {
        flag = 0;
        for (i = 2; i < n; i++)
        {
            if (A[i] != A[i - 1] + gcd(A[i - 1], A[i - 2]))
            {
                flag = 1;
                ps = i;
                break;
            }
        }
        if (flag == 0)
        {
            if (A[1] == A[0] + gcd(A[0], A[n - 1]))
            {
                ret.push_back(A[n - 1]);
                for (i = 0; i < n - 1; i++)
                    ret.push_back(A[i]);
                return ret;
            }
            else
            {
                for (i = 0; i < n; i++)
                    ret.push_back(A[i]);
                return ret;
            }
        }
        else
        {
            if (A[1] == A[0] + gcd(A[ps], A[0]))
            {
                flag = 0;
                for (i = n - 1; i > ps + 2; i--)
                {
                    if (A[i] != A[i - 1] + gcd(A[i - 1], A[i - 2]))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0 and ps < n - 1)
                {
                    if (A[ps + 1] != A[ps - 1] + gcd(A[ps - 1], A[ps - 2]))
                        flag = 1;
                }
                if (flag == 0 and ps < n - 2)
                {
                    if (A[ps + 2] != A[ps + 1] + gcd(A[ps - 1], A[ps + 1]))
                        flag = 1;
                }
                if (flag == 0)
                {
                    ret.push_back(A[ps]);
                    for (i = 0; i < n; i++)
                        if (i != ps)
                            ret.push_back(A[i]);
                    return ret;
                }
            }
        }
    }
    ret.push_back(-1);
    return ret;
}*/

int main()
{
    IOS();
    //t = tc();
    t = 1;
    while (t--)
    {
        vi A = {4, 6, 2, 5, 3};
        sort(A.begin(), A.end());
        if (A.size() > 2){
            for (int i = 2; i < A.size(); i++){
                if (A[i] != A[i - 1] + __gcd(A[i - 1], A[i - 2])){
                    vector<int> ans;
                    ans.push_back(-1);
                    pvi(A);
                }
            }
            pvi(A);
        }
        else{
            
            if (A.size() == 2){
                if (A[0] > A[1]) pvi(A);
                else{
                    swap(A[0], A[1]);
                    pvi(A);
                }
            }
            else pvi(A);
        }
    }

    return 0;
}