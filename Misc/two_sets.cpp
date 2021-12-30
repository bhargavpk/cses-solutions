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
    if(n%4 == 1 || n%4 == 2)
    {
        cout<<"NO\n";
        return;
    }
    vector<int> set1, set2;
    if(n%4 == 0)
    {
        for(int i = 1;i < n+1-i;i += 2)
        {
            set1.push_back(i); set1.push_back(n+1-i);
            set2.push_back(i+1); set2.push_back(n+1-i-1);
        }
    }
    else
    {
        set2.push_back(n);
        for(int i = 1;i < n-i;i += 2)
        {
            set1.push_back(i); set1.push_back(n-i);
            if(i+1 < n-(i+1))
            {
                set2.push_back(i+1); set2.push_back(n-(i+1));
            }
        }
    }
    cout<<"YES\n";
    cout<<set1.size()<<"\n";
    for(int v:set1)
        cout<<v<<" ";
    cout<<'\n';
    cout<<set2.size()<<'\n';
    for(int v:set2)
        cout<<v<<" ";
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