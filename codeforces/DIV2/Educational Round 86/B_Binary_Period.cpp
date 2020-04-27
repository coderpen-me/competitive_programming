#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define tc() testcases()
ll sum = 0, sum1 = 0;

int main()
{
    IOS();
    ll t;
    cin>>t;
    while (t--)
    {
        string str;
        cin >> str;
        int n = str.length();
        sum = 0, sum1 = 0;
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == '0')
                sum++;
            if (str[i] == '1')
                sum1++;
        }
        string ret = "";
        if (sum == 0 || sum1 == 0)
        {
            if (sum == 0)
            {
                for (ll i = 0; i < (2 * n); i++)
                {
                    ret += '1';
                }
            }
            else
            {
                for (ll i = 0; i < (2 * n); i++)
                {
                    ret += '0';
                }
            }
        }
        else if (str[0] == '0')
        {
            int flag = 0;
            for (ll i = 0; i < (2 * n); i++)
            {
                if (!flag)
                {
                    ret += '0';
                }
                else
                {
                    ret += '1';
                }
                flag = !flag;
            }
        }
        else
        {
            int flag = 1;
            for (ll i = 0; i < (2 * n); i++)
            {
                if (!flag)
                {
                    ret += '0';
                }
                else
                {
                    ret += '1';
                }
                flag = !flag;
            }
        }
        cout<<ret<<"\n";
    }

    return 0;
}