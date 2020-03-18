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

class Graph{
    public:
    int V;
    list<int> *adj;
    Graph(int V){
        this->V = V;
        adj = new list<int>[2*V];
    }
    void addEdge(int u, int v, int w){
        if(w == 2){
            adj[u].push_back(u+V);
            adj[u+V].push_back(v);
            adj[v].push_back(v+V);
            adj[v+V].push_back(u);
        }
        else{
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int findshortdist(int s, int d){
        bool *visited = new bool[2*V];
        int *parent = new int[2*V];
        LP(i, 2*V){
            visited[i] = false;
            parent[i] = -1;
        }
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty()){
            int tmp = q.front();
            //a2("popping", tmp);
            if(tmp == d){
                int ret = 0;
                while(parent[tmp] != -1){
                    tmp = parent[tmp];
                    ret++;
                }
                //a1("GOT YOU");
                return ret;
            }
            q.pop();
            for(auto x : adj[tmp]){
                if(!visited[x]){
                    visited[x] = true;
                    parent[x] = tmp;
                    q.push(x);
                    //a2("pushing", x);
                }
            }
        }
        return -1;
    }
};

int main(){
IOS();
    //t = tc();
    t = 1;
    while(t--){
        Graph g(6); 
        g.addEdge(2, 5, 1); 
        g.addEdge(1, 3, 1); 
        g.addEdge(0, 5, 2); 
        g.addEdge(0, 2, 2); 
        g.addEdge(1, 4, 1); 
        g.addEdge(0, 1, 1);
        b1(g.findshortdist(3, 2));
    }
    
    return 0;
}