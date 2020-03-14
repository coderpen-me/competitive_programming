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
ll a[MAXn], b[MAXn], c[MAXn], d[MAXn];
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

int findx(int n){
    return int(ceil(n/6));
}
int findy(int n, int p){
    if( p == 0 ){
        if(n % p == 0){
            return 6;
        }
        return (n % p);
    }
    else{
        int j = n % p;
        if(j == 0) return 1;
        return (7-j);
    }
}

int main(){
IOS();
    t = tc();
    //t = 1;
    while(t--){
        cin>>u;
        int arr[6][7];
        for(int i = 1; i <= 5; i++){
            if(i & 1){
                for(int j = 1; j <= 6; j++){
                    int val = (6*(i-1)) + j;
                    arr[i][j] = val;
                }
            }
            else{
                for(int j = 1; j <= 6; j++){
                    int val = (6*(i-1)) + (6-j+1);
                    arr[i][j] = val;
                }
            }
            
        }
        
        while(u--){
            cin>>v>>w;
            cout<<v<<" "<<w<<"    ";
            int i1, j1, i2, j2;
            int dir;
            if((v >= 7 && v <= 12) || (v >= 19 && v <= 24)){
                dir = 1;
            }
            else dir = 0;
            i1 = findx(v);
            j1 = findy(v, dir);

            if((w >= 7 && w <= 12) || (w >= 19 && w <= 24)){
                dir = 1;
            }
            else dir = 0;
            i2 = findx(w);
            j2 = findy(w, dir);

            arr[i1][j1] = w;
        }
        for(int i = 5; i > 0; i--){
            LP1(j, 6){
                cout<<arr[i][j]<<" ";
            }
            nl;
        }
    }
    
    return 0;
}