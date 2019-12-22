// Question

/*Chef has a sequence A1,A2,…,AN. He needs to find the number of pairs (i,j) (1≤i<j≤N) such that Ai+Aj=Ai⋅Aj. However, he is busy, so he asks for your help.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing one integer ― the desired number of pairs.

Constraints
1≤T≤20
1≤N≤40,000
0≤Ai≤109 for each valid i
Subtasks
Subtask #1 (30 points): 1≤N≤500
Subtask #2 (70 points): original constraints

Example Input
2
3
2 4 2
3
0 2 3
Example Output
1
0
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
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

ll a[MAXn], b[MAXn], c[MAXn], d[MAXn];

ll t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
ll sum = 0, sum1 = 0, mul = 0, subs = 0, res = 0, test = 0, num = 0, num1 = 0;
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
        cin>>u;
        a[0] = a[1] = a[2] = 0;
        while (u--)
        {
            cin>>v;
            if(v == 0)
                a[0]++;
            else if(v == 2)
                a[2]++;
        }
        b1(a[0] * (a[0] - 1) / 2 + a[2] * (a[2] - 1) / 2);
    }

    return 0;
}