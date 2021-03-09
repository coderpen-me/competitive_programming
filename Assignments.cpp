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

ll dp[100100], allmask;

ll assignment(ll mask, vvi arr, int n){
	//Find the number of set bits in the mask and name it as index
	int index = __builtin_popcount(mask);
	//if every student had choosen a subject
	if (index == n && mask == allmask)
		return 1;
	if (dp[mask] != -1)
		return dp[mask];
	ll ways = 0;
	//Assign subject 'j' to each student who had liked the subject and reccur for rest
	for (int j = 0; j < n; j++){
		//if the student number index does not like the subject j then we cannot do the assignment
		if (!arr[index][j])
			continue;
		//if we had already assigned a subject j to a student in this mask then we cannot do the assignment
		if (mask & (1 << j))
			continue;
		//If the subject no. j is not assigned to any student and student number index likes the subject than we assign it to the student
		else
			ways += assignment(mask | (1 << j), arr, n);
	}
	return dp[mask] = ways;
}

int main(){
    IOS();
    t = tc();
    //t = 1;
    while(t--){
        cin>>u;
        memset(dp, -1, sizeof (dp));
        allmask = pow(2, u) - 1;
        vector<vector<int>> pre(u, vector<int>(u, 0));
        for(int i = 0; i < u; i++){
            for(int j = 0; j < u; j++){
                cin>>pre[i][j];
            }
        }
        b1(assignment(0, pre, u));
    }
    
    return 0;
}