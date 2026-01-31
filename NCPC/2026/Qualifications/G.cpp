#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll mul(ll a,ll b)
{
    return ((a%mod)*(b%mod))%mod;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        ll s[n];
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        ll f[n];
        for(int i=0;i<n;i++)
        {
            cin>>f[i];
        }
        sort(s,s+n,greater<ll>());
        sort(f,f+n);
        ll ans=1;
        for(int i=0;i<n;i++)
        {
            ll ch=n-(upper_bound(f,f+n,s[i])-f);
            if(ch-i<=0)
            {
                cout<<0<<'\n';
                goto done;
            }
            ans=mul(ans,ch-i);
        }
        cout<<ans<<'\n';
        done:{}
    }
    return 0;
}
