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
    string str;
    cin>>str;
    int longest_rep = 1;
    int curr_len = 1;
    for(int i = 1;i < str.length();i++)
    {
        while(i < str.length() && str[i] == str[i-1])
        {
            curr_len++;
            i++;
        }
        longest_rep = max(longest_rep, curr_len);
        curr_len = 1;
    }
    cout<<longest_rep<<'\n';
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