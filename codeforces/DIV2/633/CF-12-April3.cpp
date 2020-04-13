#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t, u;
    cin>>t;
    while(t--){
        cin >> u;
        long long arr[u];
        for (long long i = 0; i < u; i++)
        {
            cin >> arr[i];
        }
        if(u == 0){
            cout<<0<<"\n";
            continue;
        }
        ll maxa = 0;
        ll prev = 0;
        for(ll i = 1; i < u; i++){
            if(arr[i] >= arr[i-1]){
                prev = i;
                continue;
            }
            ll loc;
            if(prev = i - 1) loc = 1; 
            else loc = maxa + 1;
            while(arr[i] < arr[i-1]){
                arr[i] += (pow(2, loc - 1));
                loc++;
            }
            maxa = max(maxa, loc - 1);
        }
        cout<<maxa<<"\n";
    }
    return 0;
}