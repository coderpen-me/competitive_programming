#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        int arr[2] = {0, 0};
        for (int i = 0; i <= 9; i++)
        {
            if (i == 3 || i == 0 || i == 6)
            {
                arr[0] = 0;
                arr[1] = 1;
            }
            string in;
            cin >> in;
            ll val = in[i] - '0';
            if (i % 3 == 0)
            {
                if ((val + 1) > 9)
                {
                    in[i] = '1';
                }
                else
                {
                    in[i] = (val + 1) + '0';
                }
                arr[0] = val;
            }
            if (i % 3 == 1)
            {
                if ((val + 1) > 9)
                {
                    if (arr[0] == 1)
                    {
                        in[i] = '2';
                    }
                    else
                    {
                        in[i] = '1';
                    }
                }
                else
                {
                    if (val + 1 == arr[0])
                    {
                        in[i] = (val + 2) + '0';
                    }
                    else
                    {
                        in[i] = (val + 1) + '0';
                    }
                }
                arr[1] = val;
            }
            if (i % 3 == 2)
            {
                if ((val + 1) > 9)
                {
                    if (arr[1] != 1 && arr[0] != 1)
                    {
                        in[i] = '1';
                    }
                    else if (arr[1] != 2 && arr[0] != 2)
                    {
                        in[i] = '2';
                    }
                    else
                        in[i] = '3';
                }
                else
                {
                    if (arr[1] != (val + 1) && arr[0] != (val + 1))
                    {
                        in[i] = (val + 1) + '0';
                    }
                    else if (arr[1] != (val + 2) && arr[0] != (val + 2))
                    {
                        in[i] = (val + 2) + '0';
                    }
                    else
                        in[i] = (val + 3) + '0';
                }
            }
            cout << in << "\n";
        }
    }
    return 0;
}