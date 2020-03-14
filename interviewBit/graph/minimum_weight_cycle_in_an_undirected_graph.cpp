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
ll a[MAXn], b[MAXn], c[MAXn], d[MAXn];
ll t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
ll sum = 0, sum1 = 0, mul = 0, subs = 0, test = 0, num = 0, num1 = 0;
//ll aa=0, bb=0, cc=0, dd=0, ee=0;
//ll count=0, ctl=0, ctrl=0, divi=0, flag=0, cal=0, must=0, test=0;
string in;
int testcases()
{
    cin >> test;
    return test;
}

struct Edge
{
    int v;
    int u;
    int w;
};

class graph
{
    int V;
    list<pair<int, int>> *adj;
    vector<Edge> edge;

public:
    graph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
        Edge e{u, v, w};
        edge.push_back(e);
    }

    void removeEdge(int u, int v, int w)
    {
        adj[u].remove(make_pair(v, w));
        adj[v].remove(make_pair(u, w));
    }
    int shortestPath(int u, int v)
    {
        set<pair<int, int>> s;
        vector<int> dist(V, INT_MAX);
        s.insert(make_pair(0, u));
        dist[u] = 0;
        while(!s.empty()){
            pair<int, int> temp = *s.begin();
            s.erase(s.begin());
            int u = temp.second;
            list<pair<int, int>> :: iterator i;
            for(i = adj[u].begin(); i != adj[u].end(); i++){
                int v = (*i).first;
                int w = (*i).second;
                if(dist[v] > dist[u] + w){
                    if(dist[v] != INT_MAX){
                        s.erase(s.find(make_pair(dist[v], v)));
                    }
                    dist[v] = dist[u]+w;
                    s.insert(make_pair(dist[v], v));
                }
            }
        }
        return dist[v];
    }
    int findMinCycle()
    {
        int min_cycle = INT_MAX;
        int E = edge.size();
        for(int i = 0; i < E; i++){
            Edge e = edge[i];
            removeEdge(e.u, e.v, e.w);
            int path = shortestPath(e.u, e.v);
            min_cycle = max(min_cycle, path + e.w);
            addEdge(e.u, e.v, e.w);
        }
        return min_cycle;
    }
};

int main()
{
    IOS();
    //t = tc();
    t = 1;
    while (t--)
    {
        int A = 4;
        vvi B = {{1, 2, 2},
                 {2, 3, 3},
                 {3, 4, 1},
                 {4, 1, 4},
                 {1, 3, 15}};
        graph g(A);
        int E = B.size();
        for(int i = 0; i < E; i++){
            B[i][0]--;B[i][1]--;
            g.addEdge(B[i][0], B[i][1], B[i][2]);
        }
        b1(g.findMinCycle());
    }

    return 0;
}