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
int count(vector<vector<int>> &A, int i, int j, int row, int col, int p, map<pair<int, int>, int> h)
{
    
    if(h[make_pair(i, j)] == 1){
        return INT_MAX;
    }
    else h[make_pair(i, j)] = 1;
    cout<<"Came "<<i<<" "<<j<<" "<<p<<" ";
    cout<<"\n";
    int a = INT_MAX, b = INT_MAX, c = INT_MAX, d = INT_MAX;

    if ((i - 1 >= 0) && (A[i - 1][j] == 1))
    {
        return p + 1;
    }
    if ((i + 1 < row) && (A[i + 1][j] == 1))
    {
        return p + 1;
    }
    if ((j - 1 >= 0) && (A[i][j - 1] == 1))
    {
        return p + 1;
    }
    if ((j + 1 < col) && (A[i][j + 1] == 1))
    {
        return p + 1;
    }

    if ((i - 1 >= 0) && (A[i - 1][j] % 10 == 0))
    {
        cout<<"Going up from "<<i<<" "<<j<<" to "<<i-1<<" "<<j<<"\n";
        a = count(A, i - 1, j, row, col, p + 1, h);
    }
    if ((i + 1 < row) && (A[i + 1][j] % 10 == 0))
    {
        cout<<"Going down from "<<i<<" "<<j<<" to "<<i+1<<" "<<j<<"\n";
        b = count(A, i + 1, j, row, col, p + 1, h);
    }
    if ((j - 1 >= 0) && (A[i][j - 1] % 10 == 0))
    {
        cout<<"Going left from "<<i<<" "<<j<<" to "<<i<<" "<<j-1<<"\n";
        c = count(A, i, j - 1, row, col, p + 1, h);
    }
    if ((j + 1 < col) && (A[i][j + 1] % 10 == 0))
    {
        cout<<"Going right from "<<i<<" "<<j<<" to "<<i<<" "<<j+1<<"\n";
        d = count(A, i, j + 1, row, col, p + 1, h);
    }
    return min(a, min(b, min(c, d)));
}
vector<vector<int> > solve(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    int ctr = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (A[i][j] % 10 == 0)
            {
                map<pair<int, int>, int> h;
                ctr = count(A, i, j, row, col, 0, h);
                A[i][j] = -(ctr*10);
                pvvi(A);
            }
            //cout << A[i][j] << " ";
        }
        //cout << "\n ";
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (A[i][j] < 0)
            {
                A[i][j] = -(A[i][j]/10);
            }
            else if (A[i][j] == 1)
                A[i][j] = 0;
        }
    }
    //pvvi(A);
    return A;
}

int main()
{
    IOS();
    //t = tc();
    t = 1;
    while (t--)
    {
        vvi A = {{0, 1, 1, 1, 0, 0},
                {0, 0, 0, 1, 1, 0},
                {0, 0, 1, 1, 1, 0},
                {0, 0, 0, 1, 0, 1},
                {0, 0, 1, 0, 1, 0}};
        //pvvi(A);
        pvvi(solve(A));
    }

    return 0;
}