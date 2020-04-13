#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<int, int> mm;
        ll same = 0;
        ll id = -1;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            mm[a]++;
            if (mm[a] > same)
            {
                same = mm[a];
                id = a;
            }
        }
        if (n == 1 || n == 2)
        {
            cout << n - 1 << '\n';
            continue;
        }
        if (mm[id] == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        ll sum = 0;
        for (auto x : mm)
        {
            if (x.first != id)
            {
                sum++;
            }
        }
        if (mm[id] <= sum)
        {
            cout << mm[id];
        }
        else
        {
            if (sum < mm[id] - 1)
            {
                cout << sum + 1;
            }
            else
                cout << sum;
        }
        cout << '\n';
    }
    return 0;
}