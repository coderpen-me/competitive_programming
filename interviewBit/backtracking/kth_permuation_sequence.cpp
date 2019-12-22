#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define LP(i,n) for(ll i=0;i<n;i++)
#define LP1(i,n) for(ll i=1;i<=n;i++)
#define BLP1(i, n) for(ll i=n;i>0;i--)
#define BLP(i, n) for(ll i=n;i>=0;i--)
 
#define el '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define tc() testcases()
 
#define a1(a) cout<<a<<" ";
#define a2(a, b) cout<<a<<" "<<b<<" ";
#define a3(a, b, c) cout<<a<<" "<<b<<" "<<c<<" ";
#define a4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" ";
#define a5(a, b, c, d, e) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" ";
 
#define b1(a) cout<<a<<"\n";
#define b2(a, b) cout<<a<<" "<<b<<"\n";
#define b3(a, b, c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define b4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define b5(a, b, c, d, e) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
 
#define nl cout<<"\n"
 
const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);
 
ll t=0, u=0, v=0, w=0, x=0, y=0, z=0, test=0;
//ll aa=0, bb=0, cc=0, dd=0, ee=0;
//ll count=0, ctl=0, ctrl=0, divi=0, flag=0, cal=0, must=0, test=0;
string in;
int testcases(){ cin>>test; return test; }

void recurr(string &res, vector<int> &coll, ll l, ll seq, ll A, vector<int> &Ar, ll B){
    if(l == A && seq == B){
        res = "";
        for(int i = 0; i < coll.size(); i++){
            res += to_string(coll[i]);
        }
        return;
    }
    for(ll j = l; j < Ar.size(); j++){
        coll.push_back(Ar[j]);
        swap(Ar[l], Ar[j]);
        recurr(res, coll, l+1, seq+1, A, Ar, B);
        swap(Ar[l], Ar[j]);
        coll.pop_back();
    }
}

int main(){
IOS();
    //t = tc();
    t = 1;
    while(t--){
        int A = 3, B = 4;
        vector<int> Ar;
        for(ll i = 0; i < A; i++){
            Ar.push_back(i);
        }
        string res;
        vector<int> coll;
        recurr(res, coll, 0, 0, A, Ar, B);
        a1(res);
    }
    
    return 0;
}