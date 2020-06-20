#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k, in) for (int i = j; i < k; i += in)

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(ll test_case)
{
    int n, p;
    cin >> n >> p;
    vvi op, sum;
    FOR(i, 0, n, 1)
    {
        vi row(n);
        op.push_back(row);
        sum.push_back(row);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "1 1 1 " << (i + 1) << " " << (j + 1) << "\n";
            int x;
            cin >> x;
            sum[i][j] = x;
            if (i == 0 && j == 0)
                op[i][j] = x;
        }
    }

    // Sum array
    /*cout << "Sum Array\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }*/

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j > 0)
            {
                op[i][j] = sum[i][j] - sum[i][j - 1];
            }
            else if (j == 0 && i > 0)
            {
                op[i][j] = sum[i][j] - sum[i - 1][j];
            }
            else if (i > 0 && j > 0)
            {
                op[i][j] = sum[i][j] - sum[i - 1][j] - sum[i][j - 1] + sum[i - 1][j - 1];
            }
        }
    }

    // Solution Found
    cout << "2\n";
    for (int i = 0; i < n; i++)
    {
        vi row = op[i];
        for (int j = 0; j < n; j++)
        {
            cout << op[i][j] << " ";
        }
        cout << "\n";
    }
    int x;
    cin >> x;
    if (x == -1)
        return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t, t1 = 0;
    cin >> t;
    while (t1 < t)
    {
        solve(t1 + 1);
        t1++;
    }
}