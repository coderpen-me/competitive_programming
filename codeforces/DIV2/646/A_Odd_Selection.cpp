#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define el '\n'
#define IOS()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define b1(a) cout << a << "\n";

int main(){
IOS();
    ll t, u, v, w;
    cin>>t;
    while(t--){
        cin>>u>>v;
        ll sum = 0, sum1 = 0, flag = 0;
        for (ll i = 0; i < u; i++){
            cin>>w;
            if(w&1){
                sum1++;
            }
            else sum++;
        }
        if(sum1 >= 1){
            v--;
            sum1--;
            ll cp_v = v;
            //cout<<(sum1)<<" "<<(sum);
            if(sum >= v){
                flag = 1;
            }
            else{
                v -= sum;
                if(v & 1){
                    //flag = 0;
                }
                else{
                    if(sum1 >= v){
                        flag = 1;
                    }
                    //else flag = 0;
                }
            }
            ll usbl = (sum1 & 1) ? sum1-1 : sum1;
            while(cp_v >=2 && usbl > 0){
                cp_v -= 2;
                usbl -= 2;
            }
            if(sum >= cp_v){
                flag = 1;
            }
        }
        if(flag){
            b1("Yes");
        }
        else{
            b1("No");
        }
    }
    
    return 0;
}