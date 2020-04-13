#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LP(i, n) for (ll i = 0; i < n; i++)

int main()
{
    ll t, n, a, b;
    cin >> t;
    while (t--){
        vector<char> ret = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        cin >> n >> a >> b;
        LP(i, n)
        {
            cout<<(ret[i%b]);
        }
        cout<<'\n';
    }
    return 0;
}