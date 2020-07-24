#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        cin>>u>>v>>w;
        if(u != v && v != w && u != w){
            cout<<"NO\n";
            continue;
        }
        if(u == v && u >= w){
            cout<<"YES\n";
            cout<<u<<" "<<w<<" "<<w<<"\n";
            continue;
        }
        if(u == w && u >= v){
            cout<<"YES\n";
            cout<<u<<" "<<v<<" "<<v<<"\n";
            continue;
        }
        if(w == v && w >= u){
            cout<<"YES\n";
            cout<<w<<" "<<u<<" "<<u<<"\n";
            continue;
        }
        if(w == v && v == u){
            cout<<"YES\n";
            cout<<u<<" "<<u<<" "<<u<<"\n";
            continue;
        }
        cout<<"NO\n";
    }
    return 0;
}