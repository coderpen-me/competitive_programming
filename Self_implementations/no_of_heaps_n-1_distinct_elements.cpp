#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> ncr(long long int n)
{
    vector<vector<long long int>> nr(n + 1, vector<long long int>(n + 1, (long long int)0));
    nr[0][0] = (long long int)1;
    for (int x = 1; x <= n; x++)
    {
        long long int mod = 1000000007;
        nr[x][0] = (long long int)1;
        for (long long int i = 1; i <= x; i++)
        {
            nr[x][i] = (nr[x - 1][i - 1] + nr[x - 1][i]) % mod;
        }
    }
    return nr;
}
long long int ncrr(long long int n, long long int r, vector<vector<long long int>> &nr)
{
    if (r > n)
        return 0;
    if (r == 0)
        return 1;
    if (n < 0 || r < 0)
        return 0;

    return nr[n][r];
}
vector<long long int> lr(long long int n)
{
    long long int h = (int)((double)log(n + 1) / (double)log(2));
    //cout << h <<" ";
    long long int l = pow(2, h - 1) - 1;
    long long int r = l;
    long long int rem = n - 1 - l - r;
    if (rem <= pow(2, h - 1))
    {
        l += rem;
    }
    else
    {
        l += pow(2, h - 1);
        r += rem - pow(2, h - 1);
    }
    vector<long long int> x(2);
    x[0] = l;
    x[1] = r;
    return x;
}
int helper(vector<long long int> &ans, int i, vector<vector<long long int>> &nr)
{
    if (ans[i] != -1)
    {
        return ans[i];
    }
    long long int n = i;
    vector<long long int> s = lr(n);
    long long int l = s[0];
    long long int r = s[1];
    //cout << l << " " <<  r << endl;
    ans[i] = (((ncrr(n - 1, l, nr) % 1000000007) * helper(ans, l, nr) % 1000000007) * helper(ans, r, nr)) % 1000000007;
    return ans[i];
}

int helper1(vector<long long int> &ans, vector<long long int> &ans1, long long int i, vector<vector<long long int>> &nr)
{
    if (ans[i] != -1)
    {
        return ans[i];
    }
    //cout << i << " ";
    long long int n = i;
    vector<long long int> s = lr(n);
    long long int l = s[0];
    long long int r = s[1];
    //cout << l << " " <<  r << endl;
    ans[i] = ((((ncrr(n - 3, l - 1, nr) % 1000000007) * helper(ans1, l, nr) % 1000000007) * helper(ans1, r, nr)) % 1000000007) + (((ncrr(n - 3, l - 2, nr) * helper1(ans, ans1, l, nr) % 1000000007) * helper(ans1, r, nr)) % 1000000007) + (((nr[n - 3][l] * helper(ans1, l, nr) % 1000000007) * helper1(ans, ans1, r, nr)) % 1000000007);
    ans[i] %= 1000000007;
    return ans[i];
}

int main()
{
    int tests;
    cin >> tests;
    vector<long long int> res(1000 + 1, -1);
    vector<long long int> res1(1000 + 1, -1);
    res1[0] = (long long int)1;
    res1[1] = (long long int)1;
    res[0] = (long long int)1;
    res1[2] = (long long int)1;
    res[2] = (long long int)1;
    vector<vector<long long int>> nr = ncr(1000);
    while (tests--)
    {
        long long int n;
        cin >> n;
        vector<int> v(n);
        for (int p = 0; p < n; p++)
        {
            cin >> v[p];
        }
        sort(v.begin(), v.end());
        if (v[n - 1] == v[n - 2])
        {
            if (helper(res, n, nr) < 0)
            {
                cout << n << " a" << endl;
            }
            cout << helper(res, n, nr) << endl;
        }
        else
        {
            if (helper1(res1, res, n, nr) < 0)
            {
                cout << n << " b" << endl;
            }
            cout << helper1(res1, res, n, nr) << endl;
        }
    }
}