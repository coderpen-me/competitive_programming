//{
#include<bits/stdc++.h>
using namespace std;
 
#define DEBUG

typedef long long int ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define MOD (ll)(1e9 + 7)
#define vi vector<int>
#define vii vector<vector<int> >
#define vl vector<ll>
#define vll vector<vector<ll> >
#define vc(T, nm) vector<T> nm
#define pb push_back
#define popb pop_back
#define si set<int>
#define sl set<ll>
#define F first
#define S second
#define pii pair<int, int>
#define mp make_pair
#define ins insert
#define ers erase
#define endl "\n"
#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD
#define adr(a, b) ((a % MOD) + (b % MOD)) % MOD
#define FORA(x, s, e, inc) for(ll x = s; x != e; x += inc)
#define ROFA(x, s, e, inc) for(ll x = s; x != e; x -= inc)
#define FOR(x, s, e) FORA(x, s, e, 1)
#define ROF(x, s, e) ROFA(x, s, e, 1)
#define loop(x, n) FOR(x, 0, n)
#define rd1(t, a) 					t a; cin >> a;
#define rd2(t, a, b) 				rd1(t, a); rd1(t, b); 
#define rd3(t, a, b, c) 			rd2(t, a, b); rd1(t, c);
#define rd4(t, a, b, c, d) 			rd3(t, a, b, c); rd1(t, d);
#define rd5(t, a, b, c, d, e) 		rd4(t, a, b, c, d); rd1(t, e);
#define rd6(t, a, b, c, d, e, f) 	rd5(t, a, b, c, d, e); rd1(t, f);
#define rdA(t, nm, len)				t nm[len]; loop(i, len) {cin >> nm[i];}
#ifdef DEBUG
	#define deb(v) cout << endl << #v << ": " << v << endl
	#define db1(v) cout << endl << #v << ": " << "[ "; for(auto x: v) {cout << x << " ";}; cout << "]" << endl;
	#define db2(v) cout << endl << #v << ": " << endl; for(auto r: v) {cout << "[ "; for(auto x: r) {cout << x << " ";}; cout << "]" << endl;};
	#define dbl cout << "-------------------------------" << endl
#else
	#define deb(v)
	#define db1(v)
	#define db2(v)
	#define dbl
#endif
//}

vector<int> solve(string s, vl &A, vl &B) {
    vector<int> ret;
    long long ln = s.size();
    long long qs = A.size();
    long long pre[ln][26];
    memset(pre, 0, sizeof pre);
    for(long long i = 0; i != ln; i++){
        pre[i][s[i] - 'a']++;
        
        if(i != 0) {
            for(long long j = 0; j != 26; j++){
                pre[i][j] += pre[i - 1][j];
        }
    }
    for(long long i = 0; i != qs; i++){
        long long l = A[i] - 1;
        long long r = B[i] - 1;
        int maxi = 0; 
        char c = 'a'; 
        for(long long j = 0; j != 26; j++){
            int times = pre[r][j]; 
  
            if (l != 0) 
                times -= pre[l - 1][j]; 
  
            if (times > maxi) { 
                maxi = times; 
                c = char('a' + j); 
            } 
        }
        ret.push_back(maxi);
    }
    return ret;
}

void Input() {
    rd1(string, s);
    
    rd1(ll, a);
    vl A(a);
    FOR(i, 0, a)
        cin >> A[i];
    
    rd1(ll, b);
    vl B(b);
    FOR(i, 0, b)
        cin >> B[i];
        
    solve(s, A, B);
}

int main() {
	
	fastio;

    // rd1(ll, t);
	ll t = 1;

    while(t--) {
        Input();
    }
    
	return 0;
}