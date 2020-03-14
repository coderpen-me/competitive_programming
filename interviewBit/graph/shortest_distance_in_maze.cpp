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

vector<vector<int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
void dfs(vector<vector<int>>& A, vector<int> start, vector<vector<int>>& dist){
    int row = A.size(), col = A[0].size();
    for(auto dir: dirs){
        int x = start[0] + dir[0],
            y = start[1] + dir[1];
        int count = 0;
        while(x >= 0 && y >= 0 && x < row && y < col && A[x][y]==0){
            x += dir[0];
            y += dir[1];
            count++;
        }
        if(dist[start[0]][start[1]] + count < dist[x-dir[0]][y-dir[1]]){
            dist[x-dir[0]][y-dir[1]] = dist[start[0]][start[1]] + count;
            dfs(A, {x-dir[0], y-dir[1]}, dist);
        }
    }
}

int solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {
    int row = A.size(), col = A[0].size();
    vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
    dist[B[0]][B[1]] = 0;
    dfs(A, B, dist);
    //pvvi(dist);
    return (dist[C[0]][C[1]] == INT_MAX) ? -1 : dist[C[0]][C[1]];
}

int main(){
IOS();
    //t = tc();
    t = 1;
    while(t--){
        vvi A = {{0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 1, 0},
                 {1, 1, 0, 1, 1},
                 {0, 0, 0, 0, 0}};
        vi B = {0, 4};
        vi C = {4, 4};
        a1(solve(A, B, C));
    }
    
    return 0;
}