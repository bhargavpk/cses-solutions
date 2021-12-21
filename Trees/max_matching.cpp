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
vector<pair<int, int>> match_count;

void dfs(int src, int parent = -1)
{
    int sum_max_matches = 0;
    for(int child:edges[src])
    {
        if(child != parent)
        {
            dfs(child, src);
            sum_max_matches += max(match_count[child].first, match_count[child].second);
        }
    }
    match_count[src].first = sum_max_matches;
    for(int child:edges[src])
    {
        if(child != parent)
            match_count[src].second = max(match_count[src].second, sum_max_matches-max(match_count[child].first, match_count[child].second) + match_count[child].first + 1);
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
    match_count.resize(n, {0, 0});
    dfs(0);
    cout<<max(match_count[0].first, match_count[0].second)<<'\n';
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