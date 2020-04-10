#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>

#define LP(i, n) for (ll i = 0; i < n; i++)
#define LP1(i, n) for (ll i = 1; i <= n; i++)
#define BLP1(i, n) for (ll i = n; i > 0; i--)
#define BLP(i, n) for (ll i = n; i >= 0; i--)

#define el '\n'
#define IOS()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define b1(a) cout << a << "\n";
ll t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;

int main(){
IOS();
    //t = tc();
    t = 1;
    while(t--){
        cin>>u;
        ll a[100001];
        memset(a, 0, sizeof a);
        ll maxa = 0;
        LP(i, u){
            ll v;
            cin>>v;
            a[v]++;
            if(v > maxa) maxa = v;
        }
        ll dp[maxa+1];
        dp[0] = 0;
        dp[1] = a[1];
        for(ll i = 2; i <= maxa; i++){
            dp[i] = max(dp[i-1], dp[i-2] + a[i] * i);
        }
        b1(dp[maxa]);
    }
    
    return 0;
}