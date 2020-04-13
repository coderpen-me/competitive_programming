#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, u;
    cin >> t;
    while (t--)
    {
        cin >> u;
        long long arr[u];
        for (long long i = 0; i < u; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + u);
        if (!(u & 1))
        {
            long long m2 = u / 2;
            long long m1 = m2 - 1;
            cout << arr[m1] << " " << arr[m2] << " ";
            long long st = m1 - 1, ed = m2 + 1;
            while (st > -1 && ed < u)
            {
                cout << arr[st] << " " << arr[ed] << " ";
                st--, ed++;
            }
        }
        else
        {
            long long m = u / 2;
            cout << arr[m] << " ";
            long long st = m - 1, ed = m + 1;
            while (st > -1 && ed < u)
            {
                cout << arr[st] << " " << arr[ed] << " ";
                st--, ed++;
            }
        }
        cout << '\n';
    }
    return 0;
}