#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAX = 1e3;

ll add(ll x, ll y)  { return (x%MOD + y%MOD)%MOD; }
ll sub(ll x, ll y)  { return (x%MOD - y%MOD + MOD)%MOD; }
ll mul(ll x, ll y)  { return (x%MOD * y%MOD)%MOD; }

ll edges[MAX][MAX];
int parent[MAX];
bool visited[MAX];

void bfs(int n, int src)
{
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i < n;i++)
            if(edges[u][i] != 0 && visited[i] == false)
            {
                visited[i] = true;
                parent[i] = u;
                q.push(i);
            }
    }
}

ll max_flow(int n, int src, int dest)
{
    ll flow_val = 0;
    while(1)
    {
        for(int i = 0;i < n;i++)
        {
            visited[i] = false;
            parent[i] = -1;
        }
        bfs(n, src);
        if(parent[dest] == -1)
            break;
        ll min_weight = INF;
        int u = dest;
        while(u != src)
        {
            min_weight = min(min_weight, edges[parent[u]][u]);
            u = parent[u];
        }
        u = dest;
        while(u != src)
        {
            edges[parent[u]][u] -= min_weight;
            edges[u][parent[u]] += min_weight;
            u = parent[u];
        }
        flow_val += min_weight;
    }
    return flow_val;
}

void solve()
{
    int n, m;
    cin>>n>>m;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            edges[i][j] = 0;
    int a,b,c;
    for(int i = 0;i < m;i++)
    {
        cin>>a>>b>>c;
        a--, b--;
        edges[a][b] += c;
    }
    if(n == 1)
        cout<<edges[0][0]<<'\n';
    else
        cout<<max_flow(n, 0, n-1)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);
    int i, t;
    // cin>>t;
    t = 1;
    for(i = 0;i < t;++i)
        solve();
}