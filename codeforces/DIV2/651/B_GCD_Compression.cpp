#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll u;
        cin>>u;
        map<int, pair<int, int>> odd_ele, even_ele;
        ll id_o = 0, id_e = 0;
        for(int i = 0; i < (u * 2); i++){
            ll v;
            cin>>v;
            if(v & 1){
                odd_ele[id_o++] = {v, i};
            }
            else{
                even_ele[id_e++] = {v, i};
            }
        }
        ll lene = id_e, leno = id_o;
        if(leno & 1) leno--;
        id_e = 0, id_o = 0;
        ll ctr = 0;
        for(int i = 0; i < leno; i+=2){
            if(ctr == u-1) break;
            cout<<odd_ele[i].second+1<<" "<<odd_ele[i+1].second+1<<"\n";
            ctr++;
        }
        for(int i = 0; i < lene; i+=2){
            if(ctr == u-1) break;
            cout<<even_ele[i].second+1<<" "<<even_ele[i+1].second+1<<"\n";
            ctr++;
        }
    }
    return 0;
}