#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int solve(int n)
{
    int high = 0;
    for (int i = 0; i < n; i++)
        high = max(high, i);

    int count[high + 1] = {0};
    for (int i = 0; i < n; i++)
        count[i]++;
    int counter = 0;
    for (int i = high; i >= 1; i--)
    {
        int j = i;
        counter = 0;
        while (j <= high)
        {

            if (count[j] >= 2)
                return j;

            else if (count[j] == 1)
                counter++;
            j += i;
            if (counter == 2)
                return i;
        }
    }
    return 1;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {

        ll u;
        cin >> u;
        ll ret = solve(u+1);
        cout<<ret<<"\n";
    }
    return 0;
}