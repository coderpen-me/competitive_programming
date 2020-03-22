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

class Graph { 
    // No. of vertices 
    int V; 
  
    // Pointer to an array containing adjacency lists 
    list<int>* adj; 
  
    // A function used by DFS 
    void DFSUtil(int v, bool visited[]); 
  
public: 
    // Constructor 
    Graph(int V); 
  
    void addEdge(int v, int w); 
    int NumberOfconnectedComponents(); 
}; 
  
// Function to return the number of 
// connected components in an undirected graph 
int Graph::NumberOfconnectedComponents() 
{ 
  
    // Mark all the vertices as not visited 
    bool* visited = new bool[V]; 
  
    // To store the number of connected components 
    int count = 0; 
    for (int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v = 0; v < V; v++) { 
        if (visited[v] == false) { 
            DFSUtil(v, visited); 
            count += 1; 
        } 
    } 
  
    return count; 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
  
    // Mark the current node as visited 
    visited[v] = true; 
  
    // Recur for all the vertices 
    // adjacent to this vertex 
    list<int>::iterator i; 
  
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
// Add an undirected edge 
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);
} 

int fun(int arr[],int k,int ar[])
{
if(arr[k]==-1 || arr[k]==-2) return -2;

if(ar[k]>0) return -1;
ar[k]+=1;

arr[k]=fun(arr,arr[k],ar);

return arr[k];
}

int main(){
IOS();
    //t = tc();
    t = 1;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1]={0},ar[n+1]={0};
        for(int i=1;i<=n;i++)
        cin>>arr[i];
        arr[1]=-1;

        int sum=0;
        for(int i=2;i<=n;i++)
        if(fun(arr,i,ar)==-1)
        sum+=1;
        cout<<sum;
    }
    
    return 0;
}