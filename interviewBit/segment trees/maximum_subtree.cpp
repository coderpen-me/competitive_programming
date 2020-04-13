#include <bits/stdc++.h>
using namespace std;

int getRoot(int node, vector<int> &P)
{
    while (P[node] != node)
    {
        node = P[node];
    }
    return node;
}

int find(int n1, int n2, vector<int> &P)
{
    return getRoot(n1, P) == getRoot(n2, P);
}

void unioN(int n1, int n2, vector<int> &P, vector<int> &size, int &maxi)
{
    if (find(n1, n2, P) == 1)
        return;
    int rootN1 = getRoot(n1, P);
    int rootN2 = getRoot(n2, P);
    int sizeN1 = size[rootN1];
    int sizeN2 = size[rootN2];
    if (sizeN1 > sizeN2)
    {
        P[rootN2] = rootN1;
        size[rootN1] += size[rootN2];
        maxi = max(maxi, size[rootN1]);
    }
    else
    {
        P[rootN1] = rootN2;
        size[rootN2] += size[rootN1];
        maxi = max(maxi, size[rootN2]);
    }
    return;
}

vector<int> solve(int A, vector<int> &B, vector<int> &C, vector<int> &D)
{
    map<int, bool> ntMe;
    for (int i = 0; i < D.size(); i++)
    {
        ntMe[D[i] - 1] = true;
    }
    int maxi = 1;
    vector<int> parent(A + 1), size(A + 1);
    for (int i = 0; i <= A; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < B.size(); i++)
    {
        if (!ntMe[i])
        {
            unioN(B[i], C[i], parent, size, maxi);
        }
    }
    vector<int> ans(D.size());
    for (int i = D.size() - 1; i >= 0; i--)
    {
        ans[i] = maxi;
        unioN(B[D[i] - 1], C[D[i] - 1], parent, size, maxi);
    }
    return ans;
}

int main()
{
    int a, q;
    cin >> a >> q;
    vector<int> B(a - 1), C(a - 1), D(q);
    for (int i = 0; i < a - 1; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < a - 1; i++)
    {
        cin >> C[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> D[i];
    }

    vector<int> ans;
    ans = solve(a, B, C, D);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}