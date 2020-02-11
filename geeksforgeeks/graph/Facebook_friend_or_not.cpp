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

int main(){
IOS();
    t = tc();
    //t = 1;
    while(t--){
        cin>>u>>v;
        //a2(u, v);
        map<char, set<char>> m;
        LP(i, u){
            char c;
            cin>>c;
            //a1(c);
        }
        LP(j, v){
            char c1, c2;
            cin>>in>>c1>>c2;
            //b3(in, c1, c2);
            if(in[1] == 'd'){
                m[c1].insert(c2);
                m[c2].insert(c1);
            }
            else{
                int flag = 0;

                stack<char> s;
                map<char, int> mm;

                for(auto x : m[c1]){
                    s.push(x);
                }

                while(!s.empty()){
                    char temp = s.top();
                    s.pop();
                    if(mm[temp] == 2){
                        //a1("get");
                        continue;
                    }
                    if(temp == c2){
                        b1(1);
                        flag = 1;
                        break;
                    }
                    for(auto x : m[temp]){
                        //a2("pushing", x);
                        s.push(x);
                    }
                    mm[temp] = 2;
                }

                /*for(auto x : m[c1]){
                    if(x == c2){
                        b1(1);
                        flag = 1;
                        continue;
                    }
                    else if(m[x].find(c2) != m[x].end()){
                        b1(1);
                        flag = 1;
                        continue;
                    }
                }*/
                if(flag == 0){
                    b1(0);
                }
            }
        }
        /*for(auto x : m['p']){
            a1(x);
        }*/
    }
    
    return 0;
}