#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); // This line can be ignoured in java
    cin.tie(0);  // This line can be ignoured in java
    int t;
    cin>>t;
    while (t--)
    {
        long long u, v;
        cin >> u >> v;
        long long arr[u];
        for (long long i = 0; i < u; i++){
            cin >> arr[i];
        }
        pair<long long, long long> A[u];
        for (long long i = 0; i < u; i++)
        {
            A[i].first = arr[i], A[i].second = i;
        }
        sort(A, A + u);
        vector<long long> vis(u, 0);
        long long ret = 0;
        for (long long i = 0; i < u; i++)
        {
            if (vis[i] || A[i].second == i)
                continue;
            long long maxa = 0;
            long long j = i;
            while (!vis[j])
            {
                vis[j] = 1;
                j = A[j].second;
                maxa++;
            }
            if (maxa > 0)
            {
                ret += (maxa - 1);
            }
        }
        cout << ret << "\n";
    }

    return 0;
}