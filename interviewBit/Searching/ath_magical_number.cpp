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
 
ll a[MAXn], b[MAXn], c[MAXn], d[MAXn];
 
ll t=0, u=0, v=0, w=0, x=0, y=0, z=0;
ll sum=0, sum1=0, mul=0, subs=0, res=0, test=0, num=0, num1=0;
//ll aa=0, bb=0, cc=0, dd=0, ee=0;
//ll count=0, ctl=0, ctrl=0, divi=0, flag=0, cal=0, must=0, test=0;
string in;
int testcases(){ cin>>test; return test; }

int solve(int A, int B, int C){
    long long multi=(B*C)/__gcd(B,C);
    long long l=0,r=1000000000000000000, mid, res, temp;
    while(l <= r){
        nl;
        mid=(l + r) >> 1;
        temp = (mid/B) + (mid/C) - (mid/multi);
        //b5(l, r, mid, temp, multi);
        if(temp >= A){
            res = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return (int)(res%MOD);
}

int main(){
IOS();
    //t = tc();
    t = 1;
    while(t--){
        cout<<solve(4, 2, 3);
    }
    
    return 0;
}