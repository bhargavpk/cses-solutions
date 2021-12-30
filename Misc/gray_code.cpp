#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

ll add(ll x, ll y)  { return (x%MOD + y%MOD)%MOD; }
ll sub(ll x, ll y)  { return (x%MOD - y%MOD + MOD)%MOD; }
ll mul(ll x, ll y)  { return (x%MOD * y%MOD)%MOD; }


string get_bin(int n, int len)
{
    string res = "";
    for(int i = 0;i < len;i++)
    {
        int bit_val = (n>>i)&1;
        char ch = '0' + bit_val;
        res = ch + res;
    }
    return res;
}

void solve()
{
    // Constructing a graph and BFSing it
    int n;
    cin>>n;
    vector<int> tour = {0, 1};
    for(int i = 2;i <= n;i++)
    {
        int xor_val = (1<<(i-1)) + tour.back();
        for(int j = 1;j <= 1<<(i-1);j++)
        {
            tour.push_back(tour[j-1]^xor_val);
        }
    }
    for(int val:tour)
        cout<<get_bin(val, n)<<'\n';
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