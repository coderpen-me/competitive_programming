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
#define tc() testcases()
#define pvi(A) printvectorint(A)
#define pvs(A) printvectorstring(A)
#define pvvi(A) printvectorvectorint(A)

#define a1(a) cout << a << " ";
#define a2(a, b) cout << a << " " << b << " ";
#define a3(a, b, c) cout << a << " " << b << " " << c << " ";
#define a4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << " ";
#define a5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e << " ";

#define b1(a) cout << a << "\n";
#define b2(a, b) cout << a << " " << b << "\n";
#define b3(a, b, c) cout << a << " " << b << " " << c << "\n";
#define b4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << "\n";
#define b5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e << "\n";

#define nl cout << "\n"

const ll MAXn = 1e5 + 5, MAXlg = __lg(MAXn) + 2;
const ll MOD = 1000000007;
const ll INF = ll(1e15);

void printvectorint(vector<int> A)
{
    nl;
    for (auto x : A)
    {
        a1(x);
    }
    nl;
}

void printvectorstring(vector<string> A)
{
    nl;
    for (auto x : A)
    {
        cout << (x);
    }
    nl;
}

void printvectorvectorint(vector<vector<int>> A)
{
    nl;
    for (auto x : A)
    {
        for (auto y : x)
        {
            a1(y);
        }
        nl;
    }
    nl;
}
//ll a[MAXn], b[MAXn], c[MAXn], d[MAXn];
ll t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
ll sum = 0, sum1 = 0, mul = 0, subs = 0, test = 0, num = 0, num1 = 0;
//ll aa=0, bb=0, cc=0, dd=0, ee=0;
//ll count=0, ctl=0, ctrl=0, divi=0, flag=0, cal=0, must=0, test=0;
string in;
int testcases()
{
    cin >> test;
    return test;
}

int main()
{
    IOS();
    t = tc();
    //t = 1;
    while (t--)
    {
        cin >> u >> v >> w >> x;
        if(u == 0 || v == 0){
            b1(0);
            continue;
        }
        ll per = (ll)log2(x);
        ll digi = (ll)log2(max(u, v))+1;
        //b2(per+1, digi);
        per++;
        if(per > digi){
            per = digi;
        }
        //b1(digi);
        ll ret = 0;
        map<ll, ll> Map;
        map<ll, pair<ll, ll>> Rec;
        priority_queue<ll, vector<ll>, greater<ll>> vis;
        ll per_ctr = 0;
        ll get_it = -1;
        for(ll i = 0; i < digi; i++){
            if(per_ctr >= per){
                continue;
            }
            ll l, m;
            if(u & 1){
                l = 1;
            }
            else{
                l = 0;
            }
            if(v & 1){
                m = 1;
            }
            else{
                m = 0;
            }
            if(m == 1 || l == 1){
                Map[i] = 1;
                ret += pow(2, i);
            }
            else {
                Map[i] = 0;
            }
            //b2(l, m);
            if(get_it == -1){
                if(l == 1 && m == 1){
                    get_it = i;
                }
            }
            Rec[i] = {l, m};
            u >>= 1;
            v >>= 1;
            per_ctr++;
            //a3(i, l, m);
            //nl;
        }
        //a2(get_it, x);
        if(get_it == -1){
            b1(0);
            continue;
        }
        if((ll)pow(2, get_it) > x){
            b1(0);
            continue;
        }
        /*nl;
        for(auto a = Map.rbegin(); a != Map.rend(); a++){
            cout<<(a->second);
        }
        nl;*/
        //b1(ret);
        ll rem = ret - x;
        //a1(rem);
        //nl;
        while(rem > 0){
            //a2(" rem is ",rem);
            //nl;
            ll p = (ll)log2(rem);

            //a2("GOT P as", p);
            if(rem == (ll)pow(2, p)){
                //b3("ending at ", p, rem);
                Map[p] = 0;
                break;
            }
            while(!Map[p]/* || (Rec[p+1]*)*/){
                if(p >= digi) break;
                p++;
            }
            //a4("normal ",p, (ll)pow(2, p), rem);
            //nl;
            Map[p] = 0;
            if(!vis.empty()){
                if(vis.top() < p){
                    rem += (ll)pow(2, vis.top());
                    Map[vis.top()] = 1;
                    vis.pop();
                }
            }
            vis.push(p);
            p = (ll)pow(2, p);
            //a1(p);
            //nl;
            rem -= p;
        }
        /*nl;
        for(auto a = Map.rbegin(); a != Map.rend(); a++){
            cout<<(a->second);
        }
        nl;*/
        ll po = 0;
        ret = 0;
        ll i = 0;
        for(auto x : Map){
            if(x.second){
                ret += pow(2, po);
            }
            i++;
            po++;
        }
        //nl;nl;
        b1(ret);
    }

    return 0;
}
//                                  
//    1101100100000100110111000011100000
//    0001000010010100000101111100100001

//    1101100110010100110111111111100001