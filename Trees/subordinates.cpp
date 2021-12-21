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
vector<bool> visited;
vector<int> no_sub;

void dfs(int src, int n)
{
    visited[src] = true;
    for(int child:edges[src])
    {
        if(visited[child] == false)
        {
            dfs(child, n);
            no_sub[src] += no_sub[child];
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    edges.resize(n, vector<int>());
    int u;
    for(int i = 1;i < n;i++)
    {
        cin>>u;
        u--;
        edges[u].push_back(i);
        edges[i].push_back(u);
    }
    no_sub.resize(n, 1);
    visited.resize(n, false);
    dfs(0, n);
    for(int no:no_sub)
        cout<<no-1<<" ";
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