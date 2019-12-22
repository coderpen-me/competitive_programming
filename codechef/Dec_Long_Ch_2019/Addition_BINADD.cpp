//codechef DEC long challeneg 2019
// Problem Code - BINADD
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
 
ll t=0, u=0, v=0, w=0, x=0, y=0, z=0, te1, te2;
ll sum=0, sum1=0, mul=0, subs=0, res=0, test=0, num=0, num1=0;
//ll aa=0, bb=0, cc=0, dd=0, ee=0;
//ll count=0, ctl=0, ctrl=0, divi=0, flag=0, cal=0, must=0, test=0;
string in1, in2;
int testcases(){ cin>>test; return test; }

ll cntloop(const string& a, const string& b)
{
    ll cnt(0);
    if (a.size() >= b.size())
    {
        for (ll i = 0; i < b.size(); ++i)
            if (a[a.size() - 1 - i] == '1' && b[b.size() - 1 - i] == '1')
            {
                ll j = i + 1;
                for (; j < a.size(); ++j)
                {
                    const char u = j < a.size() ? a[a.size() - 1 - j] : '0';
                    const char v = j < b.size() ? b[b.size() - 1 - j] : '0';
                    if (!(u == '0' && v == '1') && !(u == '1' && v == '0'))
                        break;
                }
                cnt = max(cnt, j - i + 1);
            }
            else if (a[a.size() - 1 - i] == '0' && b[b.size() - 1 - i] == '1')
                cnt = max(cnt, 1LL);
    }
    else
    {
        for (ll i = 0; i < a.size(); ++i)
            if (a[a.size() - 1 - i] == '1' && b[b.size() - 1 - i] == '1')
            {
                ll j = i + 1;
                for (; j < b.size(); ++j)
                {
                    const char u = j < a.size() ? a[a.size() - 1 - j] : '0';
                    const char v = j < b.size() ? b[b.size() - 1 - j] : '0';
                    if (!(u == '0' && v == '1') && !(u == '1' && v == '0'))
                        break;
                }
                cnt = max(cnt, j - i + 1);
            }
            else if (a[a.size() - 1 - i] == '0' && b[b.size() - 1 - i] == '1')
                cnt = max(cnt, 1LL);

        for (ll i = a.size(); i < b.size(); ++i)
            if (b[b.size() - 1 - i] == '1')
                cnt = max(cnt, 1LL);
    }

    return cnt;
}

int main(){
IOS();
    t = tc();
    //t = 1;
    while(t--){
        cin>>in1>>in2;
        u = in1.length();
        v = in2.length();
        
        //////////////////////////////////////
        /*               1                  */
        //-----20 points solution ----------//
        /*te1 = 0, te2 = 0, res = 0;
        num = 0, num1 = 0, w = 0;
        BLP1(z, u){
            if(in1[z-1] == '1'){
                num += pow(2, w);
            }
            w++;
        }
        w = 0;
        BLP1(z, v){
            if(in2[z-1] == '1'){
                num1 += pow(2, w);
            }
            w++;
        }
        while(num1 != 0){
            te1 = num ^ num1;
            te2 = num & num1;
            num = te1;
            num1 = te2 * 2;
            res++;
        }
        b1(res);*/
        

       ////////////////////////////////////
       //          Solution - 2
       ////////////////////////////////////
       
       b1(cntloop(in1, in2));
    }
    
    return 0;
}