#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const ll INF = 1e9;
const ll MOD = 1e9 + 7;

ll add(ll x, ll y)  { return (x%MOD + y%MOD)%MOD; }
ll sub(ll x, ll y)  { return (x%MOD - y%MOD + MOD)%MOD; }
ll mul(ll x, ll y)  { return (x%MOD * y%MOD)%MOD; }


void solve()
{
    ll n;
    cin>>n;
    ll ans = 0;
    for(ll five_pow = 5;five_pow <= n;five_pow *= 5)
    {
        ans += n/five_pow;
    }
    cout<<ans<<'\n';
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