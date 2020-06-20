#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        string in;
        cin>>in;
        ll i = 0, j = in.length()-1;
        cout<<i<<" "<<j<<"\n";
        int mid = j / 2;
        ll ctr = 0, sum = 0, sum1 = 0, left1 = 0, left0 = 0, right1 = 0, right0 = 0;
        for(i = 0; i <= j; i++){
            if(j & 1){
                if(i < mid){
                    if(in[i] == '0'){
                        left0++;
                    }
                    else{
                        left1++;
                    }
                }
                else if(i == mid){

                }
                else if(i > mid + 1){
                    if(in[i] == '0'){
                        right0++;
                    }
                    else{
                        right1++;
                    }
                }
            }
            else{
                if(i < mid){

                }
                else if( i > mid){

                }
            }
            if(in[i] == '0'){
                sum++;
            }
            else{
                sum1++;
            }
        }
        if(min(sum, sum1) < ctr){
            cout<<"HERE";
            cout<<min(sum, sum1);
        }
        else cout<<ctr<<"\n";
    }
    
    return 0;
}