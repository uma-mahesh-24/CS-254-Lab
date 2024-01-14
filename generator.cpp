/*
    Author: pcumamahesh
    From: IIT Indore

    Written on 14-01-2024 at 23:04:36 IST
*/

#include <bits/stdc++.h>
using namespace std;

#define yes() cout<<"YES\n"
#define no() cout<<"NO\n"
#define ne() cout<<"-1\n"

#define pb push_back
#define fr(i, a, b) for(int i = a; i <= b; ++i)
#define rf(i, b, a) for(int i = b; i >= a; --i)
#define all(v) v.begin(), v.end()
#define go(i, a) for(auto& i : a)
#define init(v, val) go(ins, v)  ins = val

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N = 2e5;
const int inf = 2e9;
const ll INF = 5e18;
const ld ep = 1e-9;


void solve()
{
    const int W = 2000, n = W;
    cout<<n<<" "<<W<<"\n";
    fr(i, 1, n)
        cout<<rand() % 71<<" "<<rand() % 113<<"\n";
}


int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        clock_t t0 = clock();
        freopen("input2.txt", "w", stdout);
    #endif

    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }

    return 0;
}