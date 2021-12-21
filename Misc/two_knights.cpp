#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

ll add(ll x, ll y)  { return (x%MOD + y%MOD)%MOD; }
ll sub(ll x, ll y)  { return (x%MOD - y%MOD + MOD)%MOD; }
ll mul(ll x, ll y)  { return (x%MOD * y%MOD)%MOD; }


void solve()
{
    int n;
    cin>>n;
    ll num_cap = 0;
    ll total_pos;
    if(n >= 1)
        cout<<0<<'\n';
    if(n >= 2)
        cout<<6<<'\n';
    if(n >= 3)
        cout<<28<<'\n';
    if(n >= 4)
        cout<<96<<'\n';
    if(n == 3)
        num_cap = 8;
    if(n >= 4)
        num_cap = 24;
    for(ll i = 5;i <= n;i++)
    {
        total_pos = (i*i*(i*i-1))/2;
        num_cap += (8*i-16);
        cout<<total_pos-num_cap<<'\n';
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