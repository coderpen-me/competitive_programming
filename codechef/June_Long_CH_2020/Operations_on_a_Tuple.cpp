#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;

void solve(ll test_case)
{
    // Initial triplet
    ll p, q, r;
    // Target triplet
    ll a, b, c;

    cin >> p >> q >> r;
    cin >> a >> b >> c;

    ll initial[3] = {p, q, r};
    ll target[3] = {a, b, c};

    // No moves required - No problem here
    if (p == a && q == b && r == c)
    {
        cout << "0\n";
        return;
    }
    // 1 move required - (+)
    ll diff[3] = {a - p, b - q, c - r};
    ll temp = diff[0];
    bool isOne = true;
    for (int i = 1; i < 3; i++)
    {
        if (temp == 0 && diff[i] != 0)
        {
            temp = diff[i];
        }
        else if (diff[i] != 0 && diff[i] != temp)
        {
            isOne = false;
            break;
        }
    }
    if (isOne)
    {
        cout << "1\n";
        return;
    }

    // 1 move required - (*) - No problem here
    isOne = true;
    ll factor = LLONG_MAX;
    for (int i = 0; i < 3; i++)
    {
        if ((initial[i] == 0 && target[i] != 0))
        {
            isOne = false;
            break;
        }
        if (initial[i] != 0)
        {
            if (target[i] % initial[i] != 0)
            {
                isOne = false;
                break;
            }
            else
            {
                ll curr_fact = (ll)target[i] / initial[i];
                if (factor == LLONG_MAX || factor == 1)
                {
                    factor = curr_fact;
                }
                else if (curr_fact != 1 && curr_fact != factor)
                {
                    isOne = false;
                    break;
                }
            }
        }
    }
    if (isOne)
    {
        cout << "1\n";
        return;
    }

    /**
     * Error is here somewhere
     * 2 moves required
     * */

    /**
     * Case 1, 2, 3, 4 - No problem here 
     * Choose {1, 1} (+, +) (+, *) (*, +) (*,*)
     * */
    if (diff[0] == 0 || diff[1] == 0 || diff[2] == 0)
    {
        cout << "2\n";
        return;
    }

    /**
     * Case 5 - No problem here
     * Choose {1, 2} (+, +)
     * */
    if ((diff[0] == diff[1] && diff[0] != diff[2]) ||
        (diff[0] == diff[2] && diff[0] != diff[1]) ||
        (diff[1] == diff[2] && diff[1] != diff[0]))
    {
        cout << "2\n";
        return;
    }

    /**
     * Case 6 - No problem here
     * Choose {1, 2} (+, *)
     * a. 1 zero in initial array
     * b. No zeros in initial array
     * */
    // 1 zero in initial array - No problem here
    if (initial[0] == 0 && initial[1] != 0 && initial[2] != 0)
    {
        if (target[1] % initial[1] == 0 && target[2] % initial[2] == 0)
        {
            ll div_1 = target[1] / initial[1];
            ll div_2 = target[2] / initial[2];
            if (div_1 == div_2)
            {
                cout << "2\n";
                return;
            }
        }
    }
    if (initial[1] == 0 && initial[0] != 0 && initial[2] != 0)
    {
        if (target[0] % initial[0] == 0 && target[2] % initial[2] == 0)
        {
            ll div_1 = target[0] / initial[0];
            ll div_2 = target[2] / initial[2];
            if (div_1 == div_2)
            {
                cout << "2\n";
                return;
            }
        }
    }
    if (initial[2] == 0 && initial[1] != 0 && initial[0] != 0)
    {
        if (target[1] % initial[1] == 0 && target[0] % initial[0] == 0)
        {
            ll div_1 = target[1] / initial[1];
            ll div_2 = target[0] / initial[0];
            if (div_1 == div_2)
            {
                cout << "2\n";
                return;
            }
        }
    }
    // No zeros in initial array - No problem here
    if (initial[0] != 0 && initial[1] != 0 && initial[2] != 0)
    {
        if ((target[0] % initial[0] == 0 && target[1] % initial[1] == 0))
        {
            if ((target[0] / initial[0]) == (target[1] / initial[1]))
            {
                cout << "2\n";
                return;
            }
        }
        if ((target[2] % initial[2] == 0 && target[1] % initial[1] == 0))
        {
            if ((target[2] / initial[2]) == (target[1] / initial[1]))
            {
                cout << "2\n";
                return;
            }
        }
        if ((target[0] % initial[0] == 0 && target[2] % initial[2] == 0))
        {
            if ((target[0] / initial[0]) == (target[2] / initial[2]))
            {
                cout << "2\n";
                return;
            }
        }
    }

    /**
     * Case 7 - No problem here
     * Choose {1, 2} (*, +)
     * */
    if (diff[0] == diff[1] && initial[2] != 0)
    {
        if (target[2] % initial[2] == 0)
        {
            cout << "2\n";
            return;
        }
    }
    if (diff[2] == diff[1] && initial[0] != 0)
    {
        if (target[0] % initial[0] == 0)
        {
            cout << "2\n";
            return;
        }
    }
    if (diff[0] == diff[2] && initial[1] != 0)
    {
        if (target[1] % initial[1] == 0)
        {
            cout << "2\n";
            return;
        }
    }

    /**
     * Case 8 - No problem here. Case already handled by Case 6
     * Choose {1, 2} (*, *)
     * 
     * if (initial[0] != 0 && initial[1] != 0 && initial[2] != 0)
    {
        if (target[0] % initial[0] == 0 && target[1] % initial[1] == 0 && target[2] % initial[2] == 0)
        {
            ll div_0 = target[0] / initial[0];
            ll div_1 = target[1] / initial[1];
            ll div_2 = target[2] / initial[2];
            if (div_0 == div_1 || div_1 == div_2 || div_2 == div_0)
            {
                cout << "2\n";
                return;
            }
        }
    }
     * */

    /**
     * Case 9, 10, 11, 12 - No problem here. Case already handled
     * Choose {1, 3} (+, +) (+, *) (*, +) (*, *)
    */

    /**
     * Case 13, 14, 15, 16 - No problem here. Case already handled by Cases 5, 6, 7, 8
     * Choose {2, 1} (+, +) (+, *) (*, +) (*, *)
    */

    /**
     * Case 17 - No problem here
     * Choose {2, 2} (+, +)
    */
    if ((diff[0] + diff[1] == diff[2]) || (diff[1] + diff[2] == diff[0]) || diff[2] + diff[0] == diff[1])
    {
        cout << "2\n";
        return;
    }

    /**
     * Case 18 - No problem here
     * Choose {2, 2} (+, *)
     * a. If 2 elements in target array are 0
     * b. 1 element in initial array is 0
     * c. 2 elements in initial array are 0
     * d. No element in initial array is 0
    */
    // If 2 elements in target array are 0 - No problem here
    if ((target[0] == 0 && target[1] == 0 && target[2] != 0) || (target[0] == 0 && target[2] == 0 && target[1] != 0) || (target[2] == 0 && target[1] == 0 && target[0] != 0))
    {
        cout << "2\n";
    }

    // One element is 0 in initial array - No problem here
    if (initial[0] == 0 && initial[1] != 0 && initial[2] != 0)
    {
        if (target[1] != 0 && target[1] % initial[1] == 0)
        {
            ll d2 = target[1] / initial[1];
            if (target[0] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2]};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[2] % d2 == 0)
            {
                ll temp_div[3] = {target[0], target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
        if (target[2] != 0 && target[2] % initial[2] == 0)
        {
            ll d2 = target[2] / initial[2];

            if (target[0] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1], target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[1] % d2 == 0)
            {
                ll temp_div[3] = {target[0], target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
    }

    if (initial[2] == 0 && initial[1] != 0 && initial[0] != 0)
    {
        if (target[1] != 0 && target[1] % initial[1] == 0)
        {
            ll d2 = target[1] / initial[1];
            if (target[0] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2]};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[2] % d2 == 0)
            {
                ll temp_div[3] = {target[0], target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
        if (target[0] != 0 && target[0] % initial[0] == 0)
        {
            ll d2 = target[0] / initial[0];
            if (target[1] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2]};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[2] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1], target[2]};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
    }

    if (initial[1] == 0 && initial[0] != 0 && initial[2] != 0)
    {
        if (target[0] != 0 && target[0] % initial[0] == 0)
        {
            ll d2 = target[0] / initial[0];
            if (target[1] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2]};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[2] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1], target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
        if (target[2] != 0 && target[2] % initial[2] == 0)
        {
            ll d2 = target[2] / initial[2];
            if (target[0] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1], target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[1] % d2 == 0)
            {
                ll temp_div[3] = {target[0], target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
    }

    // Two elements are 0 in initial array - No problem here
    if (initial[0] == 0 && initial[1] == 0 && initial[2] != 0)
    {
        if (target[2] != 0 && target[2] % initial[2] == 0)
        {
            ll d2 = target[2] / initial[2];
            if (target[0] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1], target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[1] % d2 == 0)
            {
                ll temp_div[3] = {target[0], target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
    }

    if (initial[2] == 0 && initial[1] == 0 && initial[0] != 0)
    {
        if (target[0] != 0 && target[0] % initial[0] == 0)
        {
            ll d2 = target[0] / initial[0];
            if (target[1] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2]};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[2] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1], target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
    }

    if (initial[0] == 0 && initial[2] == 0 && initial[1] != 0)
    {
        if (target[1] != 0 && target[1] % initial[1] == 0)
        {
            ll d2 = target[1] / initial[1];
            if (target[0] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2]};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[2] % d2 == 0)
            {
                ll temp_div[3] = {target[0], target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
    }

    // No zero in initial array - No problem here
    if (initial[0] != 0 && initial[1] != 0 && initial[2] != 0)
    {
        if (target[0] != 0 && target[0] % initial[0] == 0)
        {
            ll d2 = target[0] / initial[0];
            if (target[1] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2]};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[2] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1], target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
        if (target[1] != 0 && target[1] % initial[1] == 0)
        {
            ll d2 = target[1] / initial[1];
            if (target[0] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2]};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[2] % d2 == 0)
            {
                ll temp_div[3] = {target[0], target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
        if (target[2] != 0 && target[2] % initial[2] == 0)
        {
            ll d2 = target[2] / initial[2];
            if (target[1] % d2 == 0)
            {
                ll temp_div[3] = {target[0], target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
            if (target[0] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1], target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
    }

    /**
     * Case 19 - No problem here
     * Choose {2, 2} (*, +)
     * a. 1 zero in initial array
     * b. No zero in initial array
    */
    // 1 zero in initial array - No problem here
    if (initial[0] == 0 && initial[1] != 0 && initial[2] != 0)
    {
        // d1 = 0
        if ((target[0] == 0 && target[1] != 0 && target[2] != 0 && target[1] == target[2]) ||
            (target[1] == 0 && target[0] != 0 && target[2] != 0 && target[0] == target[2]) ||
            (target[2] == 0 && target[1] != 0 && target[0] != 0 && target[1] == target[0]))
        {
            cout << "2\n";
            return;
        }
    }
    if (initial[1] == 0 && initial[0] != 0 && initial[2] != 0)
    {
        // d1 = 0
        if ((target[0] == 0 && target[1] != 0 && target[2] != 0 && target[1] == target[2]) ||
            (target[1] == 0 && target[0] != 0 && target[2] != 0 && target[0] == target[2]) ||
            (target[2] == 0 && target[1] != 0 && target[0] != 0 && target[1] == target[0]))
        {
            cout << "2\n";
            return;
        }
    }
    if (initial[2] == 0 && initial[1] != 0 && initial[0] != 0)
    {
        // d1 = 0
        if ((target[0] == 0 && target[1] != 0 && target[2] != 0 && target[1] == target[2]) ||
            (target[1] == 0 && target[0] != 0 && target[2] != 0 && target[0] == target[2]) ||
            (target[2] == 0 && target[1] != 0 && target[0] != 0 && target[1] == target[0]))
        {
            cout << "2\n";
            return;
        }
    }

    // No zeros in initial array - No problem here
    if (initial[0] != 0 && initial[1] != 0 && initial[2] != 0)
    {
        // if d1 = 0
        if (target[0] == 0 && target[1] != 0 && target[2] != 0)
        {
            // Either target[1] or target[2] is d2
            if (target[1] - target[2] == initial[1] ||
                target[2] - target[1] == initial[2])
            {
                cout << "2\n";
                return;
            }
        }
        if (target[1] == 0 && target[0] != 0 && target[2] != 0)
        {
            // Either target[1] or target[2] is d2
            if (target[0] - target[2] == initial[0] ||
                target[2] - target[0] == initial[2])
            {
                cout << "2\n";
                return;
            }
        }
        if (target[2] == 0 && target[1] != 0 && target[0] != 0)
        {
            // Either target[1] or target[2] is d2
            if (target[1] - target[0] == initial[1] ||
                target[2] - target[1] == initial[0])
            {
                cout << "2\n";
                return;
            }
        }

        // id d1 != 0
        if (target[0] != 0 && target[0] % initial[0] == 0)
        {
            ll d1 = target[0] / initial[0];
            if ((initial[1] * d1 - target[1]) == (initial[2] - target[2]) ||
                (initial[2] * d1 - target[2]) == (initial[1] - target[1]))
            {
                cout << "2\n";
                return;
            }
        }
        if (target[1] != 0 && target[1] % initial[1] == 0)
        {
            ll d1 = target[1] / initial[1];
            if ((initial[0] * d1 - target[0]) == (initial[2] - target[2]) ||
                (initial[2] * d1 - target[2]) == (initial[0] - target[0]))
            {
                cout << "2\n";
                return;
            }
        }
        if (target[2] != 0 && target[2] % initial[2] == 0)
        {
            ll d1 = target[2] / initial[2];
            if ((initial[1] * d1 - target[1]) == (initial[0] - target[0]) ||
                (initial[0] * d1 - target[0]) == (initial[1] - target[1]))
            {
                cout << "2\n";
                return;
            }
        }
    }

    // Choose 2 in 1st turn and 2 in 2nd (*, *) - No proble here
    if (initial[0] != 0 && initial[1] != 0 && initial[2] != 0)
    {
        if (target[0] % initial[0] == 0 && target[1] % initial[1] == 0 && target[2] % initial[2] == 0)
        {
            ll d2_0 = target[0] / initial[0];
            ll d2_1 = target[1] / initial[1];
            ll d2_2 = target[2] / initial[2];
            if (d2_0 * d2_1 == d2_2 || d2_1 * d2_2 == d2_0 || d2_2 * d2_0 == d2_1)
            {
                cout << "2\n";
                return;
            }
        }
    }

    // Choose {2,3} (+, *)
    // No zero in initial and target array
    if ((initial[0] != 0 && initial[1] != 0 && initial[2] != 0) &&
        (target[0] != 0 && target[1] != 0 && target[2] != 0))
    {
        if (target[0] % initial[0] == 0)
        {
            ll d2 = target[0] / initial[0];
            if (target[1] % d2 == 0 && target[2] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
        if (target[1] % initial[1] == 0)
        {
            ll d2 = target[1] / initial[1];
            if (target[0] % d2 == 0 && target[2] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
        if (target[2] % initial[2] == 0)
        {
            ll d2 = target[2] / initial[2];
            if (target[0] % d2 == 0 && target[1] % d2 == 0)
            {
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};
                if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                    (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                    (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
                {
                    cout << "2\n";
                    return;
                }
            }
        }
    }

    // Choose {2, 3} (*, +) There was a fault here
    // 1 zero in initial array
    if (initial[0] == 0 && initial[1] != 0 && initial[2] != 0)
    {
        ll d2 = target[0] - initial[0];
        ll temp_div[3] = {target[0] - d2, target[1] - d2, target[2] - d2};
        ll temp_diff[3] = {temp_div[0], temp_div[1] / initial[1], temp_div[2] / initial[2]};

        if (temp_diff[1] % initial[1] == 0 && temp_diff[2] % initial[2] == 0 &&
            (temp_diff[1] / initial[1]) == (temp_diff[2] / initial[2]))
        {
            cout << "2\n";
            return;
        }
    }
    if (initial[1] == 0 && initial[1] != 0 && initial[2] != 0)
    {
        ll d2 = target[1] - initial[1];
        ll temp_div[3] = {target[0] - d2, target[1] - d2, target[2] - d2};
        ll temp_diff[3] = {temp_div[0] / initial[0], temp_div[1], temp_div[2] / initial[2]};

        if (temp_diff[0] % initial[0] == 0 && temp_diff[2] % initial[2] == 0 &&
            (temp_diff[0] / initial[0]) == (temp_diff[2] / initial[2]))
        {
            cout << "2\n";
            return;
        }
    }
    if (initial[2] == 0 && initial[1] != 0 && initial[0] != 0)
    {
        ll d2 = target[2] - initial[2];
        ll temp_div[3] = {target[0] - d2, target[1] - d2, target[2] - d2};
        ll temp_diff[3] = {temp_div[0] / initial[0], temp_div[1] / initial[1], temp_div[2]};

        if (temp_diff[1] % initial[1] == 0 && temp_diff[0] % initial[0] == 0 &&
            (temp_diff[1] / initial[1]) == (temp_diff[0] / initial[0]))
        {
            cout << "2\n";
            return;
        }
    }

    // No zeros in initial array
    if (initial[0] != 0 && initial[1] != 0 && initial[2] != 0)
    {
        ll d2 = target[0] - initial[0];
        ll temp_div[3] = {target[0] - d2, target[1] - d2, target[2] - d2};

        if (temp_div[0] % initial[0] == 0 &&
            temp_div[1] % initial[1] == 0 &&
            temp_div[2] % initial[2] == 0)
        {
            ll t1 = temp_div[0] / initial[0];
            ll t2 = temp_div[1] / initial[1];
            ll t3 = temp_div[2] / initial[2];

            if ((t1 == 1 && t2 == t3) ||
                (t2 == 1 && t1 == t3) ||
                (t3 == 1 && t2 == t1))
            {
                cout << "2\n";
                return;
            }
        }

        d2 = target[1] - initial[1];
        ll temp_div_1[3] = {target[0] - d2, target[1] - d2, target[2] - d2};

        if (temp_div_1[0] % initial[0] == 0 &&
            temp_div_1[1] % initial[1] == 0 &&
            temp_div_1[2] % initial[2] == 0)
        {
            ll t1 = temp_div_1[0] / initial[0];
            ll t2 = temp_div_1[1] / initial[1];
            ll t3 = temp_div_1[2] / initial[2];

            if ((t1 == 1 && t2 == t3) ||
                (t2 == 1 && t1 == t3) ||
                (t3 == 1 && t2 == t1))
            {
                cout << "2\n";
                return;
            }
        }

        d2 = target[2] - initial[2];
        ll temp_div_2[3] = {target[0] - d2, target[1] - d2, target[2] - d2};

        if (temp_div_2[0] % initial[0] == 0 &&
            temp_div_2[1] % initial[1] == 0 &&
            temp_div_2[2] % initial[2] == 0)
        {
            ll t1 = temp_div_2[0] / initial[0];
            ll t2 = temp_div_2[1] / initial[1];
            ll t3 = temp_div_2[2] / initial[2];

            if ((t1 == 1 && t2 == t3) ||
                (t2 == 1 && t1 == t3) ||
                (t3 == 1 && t2 == t1))
            {
                cout << "2\n";
                return;
            }
        }
    }

    // Choose {3, 2} (+, *)
    // d1 = diff[0]
    {
        ll d1 = diff[0];
        if ((initial[1] + d1) != 0 && target[1] % (initial[1] + d1) == 0 &&
            (initial[2] + d1) != 0 && target[2] % (initial[2] + d1) == 0)
        {
            if ((target[1] / (initial[1] + d1) == (target[2] / (initial[2] + d1))))
            {
                cout << "2\n";
                return;
            }
        }
    }
    {
        ll d1 = diff[1];
        if ((initial[2] + d1) != 0 && target[2] % (initial[2] + d1) == 0 &&
            (initial[0] + d1) != 0 && target[0] % (initial[0] + d1) == 0)
        {
            if ((target[2] / (initial[2] + d1) == (target[0] / (initial[0] + d1))))
            {
                cout << "2\n";
                return;
            }
        }
    }
    {
        ll d1 = diff[2];
        if ((initial[1] + d1) != 0 && target[1] % (initial[1] + d1) == 0 &&
            (initial[0] + d1) != 0 && target[0] % (initial[0] + d1) == 0)
        {
            if ((target[1] / (initial[1] + d1) == (target[0] / (initial[0] + d1))))
            {
                cout << "2\n";
                return;
            }
        }
    }

    // Choose 3 in the 1st turn and 2 in 2nd (*, +)
    // 1 zero in initial array
    if (initial[0] == 0 && initial[1] != 0 && initial[2] != 0)
    {
        ll d2 = target[0] - initial[0];
        if ((target[1] - d2) % initial[1] == 0 && (target[2] % initial[2] == 0))
        {
            ll d11 = (target[1] - d2) / initial[1];
            ll d21 = target[2] / initial[2];
            if (d11 == d21)
            {
                cout << "2\n";
                return;
            }
        }
        if ((target[2] - d2) % initial[2] == 0 && (target[1] % initial[1] == 0))
        {
            ll d11 = (target[2] - d2) / initial[2];
            ll d21 = target[1] / initial[1];
            if (d11 == d21)
            {
                cout << "2\n";
                return;
            }
        }
    }
    if (initial[1] == 0 && initial[0] != 0 && initial[2] != 0)
    {
        ll d2 = target[1] - initial[1];
        if ((target[0] - d2) % initial[0] == 0 && (target[2] % initial[2] == 0))
        {
            ll d11 = (target[0] - d2) / initial[0];
            ll d21 = target[2] / initial[2];
            if (d11 == d21)
            {
                cout << "2\n";
                return;
            }
        }
        if ((target[2] - d2) % initial[2] == 0 && (target[0] % initial[0] == 0))
        {
            ll d11 = (target[2] - d2) / initial[2];
            ll d21 = target[0] / initial[0];
            if (d11 == d21)
            {
                cout << "2\n";
                return;
            }
        }
    }
    if (initial[2] == 0 && initial[0] != 0 && initial[1] != 0)
    {
        ll d2 = target[2] - initial[2];
        if ((target[1] - d2) % initial[1] == 0 && (target[0] % initial[0] == 0))
        {
            ll d11 = (target[1] - d2) / initial[1];
            ll d21 = target[0] / initial[0];
            if (d11 == d21)
            {
                cout << "2\n";
                return;
            }
        }
        if ((target[0] - d2) % initial[0] == 0 && (target[1] % initial[1] == 0))
        {
            ll d11 = (target[0] - d2) / initial[0];
            ll d21 = target[1] / initial[1];
            if (d11 == d21)
            {
                cout << "2\n";
                return;
            }
        }
    }

    // No zeros in initial array
    if (initial[0] != 0 && initial[1] != 0 && initial[2] != 0)
    {
        if (target[0] % initial[0] == 0)
        {
            ll d1 = target[0] / initial[0];
            ll temp_div[3] = {initial[0] * d1, initial[1] * d1, initial[2] * d1};
            ll temp_diff[3] = {temp_div[0] - target[0], temp_div[1] - target[1], temp_div[2] - target[2]};

            if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
            {
                cout << "2\n";
                return;
            }
        }
        if (target[1] % initial[1] == 0)
        {
            ll d1 = target[1] / initial[1];
            ll temp_div[3] = {initial[0] * d1, initial[1] * d1, initial[2] * d1};
            ll temp_diff[3] = {temp_div[0] - target[0], temp_div[1] - target[1], temp_div[2] - target[2]};

            if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
            {
                cout << "2\n";
                return;
            }
        }
        if (target[2] % initial[2] == 0)
        {
            ll d1 = target[2] / initial[2];
            ll temp_div[3] = {initial[0] * d1, initial[1] * d1, initial[2] * d1};
            ll temp_diff[3] = {temp_div[0] - target[0], temp_div[1] - target[1], temp_div[2] - target[2]};

            if ((temp_diff[0] == 0 && temp_diff[1] == temp_diff[2]) ||
                (temp_diff[1] == 0 && temp_diff[0] == temp_diff[2]) ||
                (temp_diff[2] == 0 && temp_diff[1] == temp_diff[0]))
            {
                cout << "2\n";
                return;
            }
        }
    }

    // Choose 3 in 1st turn and 3 in 2nd turn (+, *)
    // Initial array pairwise distinct
    if (initial[0] != initial[1] && initial[0] != initial[2] && initial[1] != initial[2] &&
        target[0] != target[1] && target[1] != target[2] && target[0] != target[2])
    {
        if ((target[0] - target[1]) % (initial[0] - initial[1]) == 0 &&
            ((target[0] - target[2]) % (initial[0] - initial[2]) == 0) &&
            ((target[2] - target[1]) % (initial[2] - initial[1]) == 0))
        {
            ll d01_2 = (target[0] - target[1]) / (initial[0] - initial[1]);
            ll d02_2 = (target[0] - target[2]) / (initial[0] - initial[2]);
            ll d21_2 = (target[2] - target[1]) / (initial[2] - initial[1]);
            if (d01_2 == d02_2 && d02_2 == d21_2)
            {
                ll d2 = d01_2;
                ll temp_div[3] = {target[0] / d2, target[1] / d2, target[2] / d2};
                ll temp_diff[3] = {temp_div[0] - initial[0], temp_div[1] - initial[1], temp_div[2] - initial[2]};

                if (temp_diff[0] == temp_diff[1] && temp_diff[1] == temp_diff[2])
                {
                    cout << "2\n";
                    return;
                }
            }
        }
    }

    // Choose {3, 3} (*, +)
    // Initial array pairwise distinct
    if (initial[0] != initial[1] && initial[0] != initial[2] && initial[1] != initial[2])
    {
        if (target[0] != target[1] && target[0] != target[2] && target[2] != target[1])
        {
            if ((target[0] - target[1]) % (initial[0] - initial[1]) == 0 &&
                ((target[0] - target[2]) % (initial[0] - initial[2]) == 0) &&
                ((target[2] - target[1]) % (initial[2] - initial[1]) == 0))
            {
                ll d01_1 = (target[0] - target[1]) / (initial[0] - initial[1]);
                ll d02_1 = (target[0] - target[2]) / (initial[0] - initial[2]);
                ll d21_1 = (target[2] - target[1]) / (initial[2] - initial[1]);
                if (d01_1 == d02_1 && d02_1 == d21_1)
                {
                    ll d1 = d01_1;
                    ll temp_div[3] = {initial[0] * d1, initial[1] * d1, initial[2] * d1};
                    ll temp_diff[3] = {temp_div[0] - target[0], temp_div[1] - target[1], temp_div[2] - target[2]};

                    if (temp_diff[0] == temp_diff[1] && temp_diff[1] == temp_diff[2])
                    {
                        cout << "2\n";
                        return;
                    }
                }
            }
        }

        if (target[0] == target[1] && target[1] == target[2])
        {
            cout << "2\n";
            return;
        }
    }

    // 3 moves required
    cout << "3\n";
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t, t1 = 0;
    cin >> t;
    while (t1 < t)
    {
        solve(t1 + 1);
        t1++;
    }
}