#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isPowerOfTwo(ll n)
{
    if (n <= 0)
        return false;
    return !(n & (n - 1));
}
ll grundy(ll x) {
    if (__builtin_popcountll(x) == 1)return x / 2;
    if(isPowerOfTwo(x+1)) return 0;
    ll w = (1LL << (63 - __builtin_clzll(x))) / 2, cur = w * 2;
    while (cur + w - 1 < x) {
        cur += w;
        w /= 2;
    }
    return w + (x - cur);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        ll ans=0;
        while(n--)
        {
            ll x;cin>>x;
            ans^=grundy(x);
        }
        if(ans)
        {
            cout<<"First\n";
        }
        else
        {
            cout<<"Second\n";
        }
    }
    return 0;
}
