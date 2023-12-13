#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    ll s[n],sum=0;
    for(auto&it:s) cin>>it,sum+=it;
    ll ans=LLONG_MAX;
    for(int mask=1;mask<(1<<n);mask++)
    {
        ll sum2=0;
        for(int i=0;i<n;i++) if((mask>>i)&1) sum2+=s[i];
        ans=min(ans,abs(sum2-sum+sum2));
    }
    cout<<ans;
    return 0;
}
