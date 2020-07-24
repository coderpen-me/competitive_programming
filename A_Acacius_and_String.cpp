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
int testcases()
{
    cin >> test;
    return test;
}

int comp(string in, ll st, string mat)
{
    //cout<<in<<"\n";
    ll fg = 0;
    ll i;
    for (i = 0; i < 7; i++)
    {
        if(in[i] == '?') fg = 1;
        if (in[i] == '?' || in[i] == mat[i])
        {
        }
        else
        {
            break;
        }
    }
    if (i == 7){
        if(fg == 0){
            return 1;
        }
        else return -1;
    }
    else
        return 0;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string in;
        cin >> u;
        cin >> in;
        string mat = "abacaba";
        ll st = 0, sd = 0, flag = 0, ctr = 0, cbr = 0;
        for (ll i = 0; i < u - 6; i++)
        {
            int ret = comp(in.substr(i), i, mat);
            if (ret == 1)
            {
                ctr++;
                if (ctr == 1)
                {
                    st = i;
                }
            }
            if (ret == -1)
            {
                cbr++;
                if (cbr == 1)
                {
                    sd = i;
                }
                if(cbr == 2 && i <= sd + 7 ){
                    ll fl = 0;
                    for(ll k = i; k < st + 7; k++){
                        if(in[k] == '?')
                            fl = 1;
                    }
                    for(ll k = st + 7; k <= i + 7; k++){
                        if(in[k] == '?')
                            fl = 0;
                    }
                    if(fl == 1)
                        cbr = 0;
                }
            }
            //cout << ctr << " " << cbr << " \n";
        }
        //cout << ctr << " " << cbr << "\n";
        if (ctr > 1)
        {
            b1("No");
            continue;
        }
        else if (ctr == 1)
        {
            b1("Yes");
            for (ll j = 0; j < in.size(); j++)
            {
                //cout << j << " ";
                if (j == st)
                {
                    cout << "abacaba";
                    j += 6;
                    continue;
                }
                if (in[j] == '?')
                {
                    cout << "d";
                    continue;
                }
                cout << in[j];
            }
            nl;
        }
        else if (ctr == 0 && cbr > 0)
        {
            b1("Yes");
            for (ll j = 0; j < in.size(); j++)
            {
                if (j == sd)
                {
                    cout << "abacaba";
                    j += 6;
                    continue;
                }
                if (in[j] == '?')
                {
                    cout << "d";
                    continue;
                }
                cout << in[j];
            }
            nl;
        }
        else{
            b1("No");
        }
    }
    return 0;
}