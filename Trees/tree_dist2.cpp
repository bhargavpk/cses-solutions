#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

ll add(ll x, ll y)  { return (x%MOD + y%MOD)%MOD; }
ll sub(ll x, ll y)  { return (x%MOD - y%MOD + MOD)%MOD; }
ll mul(ll x, ll y)  { return (x%MOD * y%MOD)%MOD; }

vector<vector<int>> edges;
vector<ll> burden, sum_dist, subtree_count;

void dfsRootSum(int src, int parent = -1)
{
    for(int child:edges[src])
    {
        if(child != parent)
        {
            dfsRootSum(child, src);
            subtree_count[src] += subtree_count[child];
            sum_dist[src] += (sum_dist[child] + subtree_count[child]);
        }
    }
}

void dfsDistSum(int src, ll burden, int parent = -1)
{
    if(parent != -1)
        sum_dist[src] = sum_dist[parent] + burden - (subtree_count[src]-1);
    for(int child:edges[src])
    {
        if(child != parent)
        {
            dfsDistSum(child, burden + subtree_count[src] - 1 - subtree_count[child] + (parent==-1?0:1), src);
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    edges.resize(n, vector<int>());
    int u, v;
    for(int i = 0;i < n-1;i++)
    {
        cin>>u>>v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    sum_dist.resize(n, 0);
    subtree_count.resize(n, 1);
    dfsRootSum(0);
    dfsDistSum(0, 0);
    for(ll val:sum_dist)
        cout<<val<<" ";
    cout<<'\n';
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