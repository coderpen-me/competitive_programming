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

vector<vector<int>> arr, bit;
int n, m;

int lowbit(int x)
{
    return x & (-x);
}

int prefixSum(int row, int col)
{
    int sum = 0;
    for (int i = row + 1; i > 0; i -= lowbit(i))
    {
        for (int j = col + 1; j > 0; j -= lowbit(j))
        {
            sum += bit[i][j];
        }
    }
    return sum;
}

void update(int row, int col, int val)
{
    int delta = val - arr[row][col];
    arr[row][col] = val;
    b5("Changing value at ", row, col, val, delta);
    for (int i = row + 1; i <= n; i += lowbit(i))
    {
        for (int j = col + 1; j <= m; j += lowbit(j))
        {
            a3(" updating value in bit at ", i, j);
            nl;
            bit[i][j] += delta;
        }
    }
}

int sumRegion(int row1, int col1, int row2, int col2)
{
    return (
        prefixSum(row2, col2) -
        prefixSum(row2, col1 - 1) -
        prefixSum(row1 - 1, col2) +
        prefixSum(row1 - 1, col1 - 1));
}

int main()
{
    vector<vector<int>> matrix = {{4, 7, 8, 12}, {12, 3, 4, 5}, {5, 7, 6, 3}};
    n = matrix.size();
    m = matrix[0].size();

    arr = vector<vector<int>>(n, vector<int>(m, 0));
    bit = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            update(i, j, matrix[i][j]);
        }
    }

    pvvi(arr);
    pvvi(bit);

    cout << sumRegion(0, 0, 1, 1);

    return 0;
}