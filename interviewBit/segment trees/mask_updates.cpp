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

int testcases()
{
    cin >> test;
    return test;
}

void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss > se || ss > ue || se < us)
        return;
    if (ss >= us && se <= ue)
    {
        tree[si] += (se - ss + 1) * diff;
        if (ss != se)
        {
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }
        return;
    }
    int mid = (ss + se) / 2;
    updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
    updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void updateRange(int n, int us, int ue, int diff)
{
    updateRangeUtil(0, 0, n - 1, us, ue, diff);
}

int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss > se || ss > qe || se < qs)
        return 0;
    if (ss >= qs && se <= qe)
        return tree[si];
    int mid = (ss + se) / 2;
    return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
           getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}

int getSum(int n, int qs, int qe)
{
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil(0, n - 1, qs, qe, 0);
}

void constructSTUtil(int arr[], int ss, int se, int si)
{
    if (ss > se)
        return;
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    constructSTUtil(arr, ss, mid, si * 2 + 1);
    constructSTUtil(arr, mid + 1, se, si * 2 + 2);

    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void constructST(int arr[], int n)
{
    constructSTUtil(arr, 0, n - 1, 0);
}

void upDate(vector<long long> &A, long long a, long long op, long long val)
{
    op += a;
    A[op] = val;
    for (op /= 2; op >= 1; op /= 2)
    {
        A[op] = A[2 * op] + A[2 * op + 1];
    }
}

long long search(vector<long long> &A, long long i, long long j, long long a)
{
    i += a, j += a;
    long long s = 0;
    while (i <= j)
    {
        if (i % 2 == 1)
        {
            s += A[i++];
        }
        if (j % 2 == 0)
        {
            s += A[j--];
        }
        i /= 2;
        j /= 2;
    }
    return s;
}

int main()
{
    IOS();
    //t = tc();
    t = 1;
    while (t--)
    {
        int a = 5;
        vector<vector<int>> B = {{0, 1, 3}, {1, 1, 2}, {0, 0, 4}, {1, 3, 4}};
        vector<long long> A((2 * a), 0);

        long long ret = 0;
        for (auto x : B)
        {
            if (x[0] == 0)
            {
                for (int k = x[1] + 1; k <= x[2] + 1; k++)
                {
                    if (A[a + k] == 1)
                    {
                        upDate(A, a, k, 0);
                    }
                    else
                    {
                        upDate(A, a, k, 1);
                    }
                }
            }
            if (x[0] == 1)
            {
                ret += (search(A, x[1] + 1, x[2] + 1, a) % MOD);
            }
        }
        return ret % MOD;
    }
    return 0;
}