#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t, u, v;
    cin >> t;
    while (t--)
    {
        cin >> u;
        map<int, int> mp;
        for(ll i = 0; i < (2*u); i++){
            cin>>v;
            if(mp[v] != 0){
                continue;
            }
            else{
                mp[v] = 1;
                cout<<v<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}