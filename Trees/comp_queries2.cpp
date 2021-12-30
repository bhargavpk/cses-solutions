#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

ll add(ll x, ll y)  { return (x%MOD + y%MOD)%MOD; }
ll sub(ll x, ll y)  { return (x%MOD - y%MOD + MOD)%MOD; }
ll mul(ll x, ll y)  { return (x%MOD * y%MOD)%MOD; }

vector<vector<int> > edges;
vector<vector<int> > ancestors;
vector<int> start_time, end_time;
int timer = 0;

void dfs(int src, int parent = -1)
{
    start_time[src] = timer++;

    // Populate ancestors
    if(parent != -1)
    {
        ancestors[src][0] = parent;
        int anc = parent;
        for(int i = 1;i < ancestors[src].size();i++)
        {
            ancestors[src][i] = ancestors[anc][i-1];
            anc = ancestors[src][i];
        }
    }
    

    for(int child:edges[src])
    {
        if(child != parent)
            dfs(child, src);
    }
    end_time[src] = timer++;
}

bool isAncestor(int u, int anc)
{
    return start_time[u] >= start_time[anc] && end_time[u] <= end_time[anc];
}

int lca(int u, int v)
{
    if(isAncestor(u, v))
        return v;
    if(isAncestor(v, u))
        return u;
    int hgt = ancestors[0].size();
    for(int i = hgt-1;i >= 0;i--)
    {
        if(!isAncestor(v, ancestors[u][i]))
            u = ancestors[u][i];
    }
    return ancestors[u][0];
}

void solve()
{
    int n;
    cin>>n;
    int num_queries;
    cin>>num_queries;
    edges.resize(n, vector<int>());
    int u, v;
    for(int i = 1;i < n;i++)
    {
        cin>>u;
        u--;
        edges[u].push_back(i);
        edges[i].push_back(u);
    }
    int hgt = ceil(log2(n));
    ancestors.resize(n, vector<int>(hgt, 0));
    start_time.resize(n);
    end_time.resize(n);
    
    // Run dfs for ancestral findings
    dfs(0);
    for(int i = 0;i < num_queries;i++)
    {
        cin>>u>>v;
        u--, v--;
        cout<<lca(u, v)+1<<'\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);
    int i, t;
    t = 1;
    for(i = 0;i < t;++i)
        solve();
}