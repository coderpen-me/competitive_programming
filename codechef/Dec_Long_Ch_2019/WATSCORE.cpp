// Question

/*You are participating in a contest which has 11 problems (numbered 1 through 11). The first eight problems (i.e. problems 1,2,…,8) are scorable, while the last three problems (9, 10 and 11) are non-scorable ― this means that any submissions you make on any of these problems do not affect your total score.

Your total score is the sum of your best scores for all scorable problems. That is, for each scorable problem, you look at the scores of all submissions you made on that problem and take the maximum of these scores (or 0 if you didn't make any submissions on that problem); the total score is the sum of the maximum scores you took.

You know the results of all submissions you made. Calculate your total score.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of submissions you made.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains two space-separated integers pi and si, denoting that your i-th submission was on problem pi and it received a score si.
Output
For each test case, print a single line containing one integer ― your total score.

Constraints
1≤T≤10
1≤N≤1,000
1≤pi≤11 for each valid i
0≤si≤100 for each valid i
Subtasks
Subtask #1 (15 points): all submissions are on the same problem, i.e. p1=p2=…=pN
Subtask #2 (15 points): there is at most one submission made on each problem, i.e. pi≠pj for each valid i,j (i≠j)

Subtask #3 (70 points): original constraints

Example Input
2
5
2 45
9 100
8 0
2 15
8 90
1
11 1
Example Output
135
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
        cin >> u;
        LP(i, 12)   a[i] = 0;
        sum = 0;
        LP(i, u)
        {
            cin >> v >> w;
            if (v < 9)
            {
                a[v] = max(a[v], w);
            }
        }
        LP(i, 12)   sum += a[i];
        b1(sum);
    }

    return 0;
}