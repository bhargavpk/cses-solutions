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
vector<int> depth;

void dfs(int src, int parent = -1)
{

    // Populate ancestors
    if(parent != -1)
    {
        depth[src] = depth[parent]+1;
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
}

int kth_ancestor(int u, int k)
{
    if(k > depth[u])
        return -1;
    for(int i = ancestors[0].size()-1;i >= 0;i--)
    {
        int two_pow = (1<<i);
        if(two_pow > k)
            continue;
        if(two_pow == k)
            return ancestors[u][i];
        k -= two_pow;
        u = ancestors[u][i];
    }
    // Never reached hopefully
    return -1;
}

void solve()
{
    int n, q;
    cin>>n>>q;
    edges.resize(n, vector<int>());
    int u;
    for(int i = 1;i < n;i++)
    {
        cin>>u;
        u--;
        edges[u].push_back(i);
        edges[i].push_back(u);
    }
    int hgt = ceil(log2(n));
    ancestors.resize(n, vector<int>(hgt, 0));
    
    depth.resize(n, 0);
    // Run dfs for ancestral findings
    dfs(0);
    int k;
    for(int i = 0;i < q;i++)
    {
        cin>>u>>k;
        u--;
        int ans = kth_ancestor(u, k);
        if(ans != -1)
            ans++;
        cout<<ans<<'\n';
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