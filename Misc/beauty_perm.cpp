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
    if(n == 1)
    {
        cout<<1<<'\n';
        return;
    }
    if(n <= 3)
    {
        cout<<"NO SOLUTION\n";
        return;
    }
    for(int i = 2;i <= n;i+=2)
        cout<<i<<" ";
    for(int i = 1;i <= n;i+=2)
        cout<<i<<" ";
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