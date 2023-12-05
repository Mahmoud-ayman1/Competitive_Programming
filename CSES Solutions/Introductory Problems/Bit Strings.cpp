#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll powmod(ll a,ll b,ll m)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1) ans=(ans*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    cout<<powmod(2,n,1e9+7);
    return 0;
}
