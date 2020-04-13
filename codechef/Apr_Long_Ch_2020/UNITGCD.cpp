#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 0, u = 0;
    cin >> t;
    while (t--)
    {
        cin >> u;
        if (u <= 3)
        {
            cout << (1) << '\n';
            if (u == 1)
            {
                cout << ("1 1") << '\n';
            }
            else if (u == 2)
            {
                cout << ("2 1 2") << '\n';
            }
            else
            {
                cout << ("3 1 2 3") << '\n';
            }
        }
        else
        {
            cout << (u / 2) << '\n';
            cout << ("3 1 2 3") << '\n';
            for (int i = 4; i <= u; i += 2)
            {
                if (i + 1 <= u)
                {
                    cout << ("2 ") << i << " " << (i + 1) << '\n';
                }
                else
                {
                    cout << ("1 ") << i << '\n';
                }
            }
        }
    }

    return 0;
}