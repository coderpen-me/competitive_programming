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
ll t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
ll sum = 0, sum1 = 0, mul = 0, subs = 0, test = 0, num = 0, num1 = 0;
string in;
int testcases()
{
    cin >> test;
    return test;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        /*cin >> u;
        cin >> in;
        if(u < 2){
            cout<<in<<"\n";
            continue;
        }
        vector<int> ret;
        int arr[u];
        arr[0] = in[0] - '0';
        ret.push_back(arr[0]);
        for(int i = 1; i < u; i++){
            ret.push_back(in[i] - '0');
            arr[i] = (in[i] - '0') + arr[i-1];
        }
        for(int i = 0; i < u; i++){
            if(in[i] == '0')
                arr[i] = 0;
        }
        ll s = u - 2, e = u - 1, prev = 0;
        while(s >= 0){
            if(s >= e){
                //cout<<"s>e mismatch -- \n";
                s--;
                continue;
            }
            if(ret[s] == -1){
                //cout<<"s mismatch -- \n";
                s--;
                continue;
            }
            if(ret[e] == -1){
                //cout<<"e mismatch -- \n";
                e--;
                continue;
            }
            if(ret[e] == 0 && arr[e] == 0){
                arr[e] = prev-1;
                prev = arr[e];
                //cout<<"Update 0 prev\n";
            }
            if(ret[s] == 1 && ret[e] == 0){
                if(arr[e] < -1){
                    ////cout<<"Moving e --> \n";
                    prev++;
                    ret[e] = -1;
                    e++;
                    while(ret[e] == -1){
                        e++;
                    }
                }
                else if(arr[s] > 1){
                    //cout<<"Moving s <-- \n";
                    ret[s] = -1;
                    s--;
                    while(ret[s] == -1){
                        s--;
                    }
                }
                else{
                    //cout<<"Moving s <-- \n";
                    ret[s] = -1;
                    s--;
                }
            }
            else{
                //cout<<"NO match \n";
                s--;
                e--;
            }
        }
        ///for(auto x : ret){
        //    cout<<x;
        //}
        //nl;
        string res = "";
        for(auto x : ret){
            if(x == -1) continue;
            res += ('0' + x); 
        }
        cout<<res<<"\n";
        //nl;nl;*/

        cin >> u;
        int a[u+1];
        for (int i = 1; i <= u; i++)
        {
            char x;
            cin >> x;
            a[i] = x - '0';
        }
        int l = u, r = 1;
        for (int i = 0; i < u; i++)
        {
            if (a[i+1] == 1)
            {
                l = i;
                break;
            }
        }
        for (int i = u; i >= 1; i--)
        {
            if (a[i] == 0)
            {
                r = i + 1;
                break;
            }
        }
        for (ll i = 1; i <= l; i++) cout << 0;
        if (l + 1 < r) cout << 0;
        for (ll i = r; i <= u; i++) cout << 1;
        nl;
    }
    return 0;
}