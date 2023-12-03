#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    ll s[n];
    for(auto&it:s) cin>>it;
    ll ans=0;
    for(int i=1;i<n;i++) if(s[i]<s[i-1]) ans+=s[i-1]-s[i],s[i]=s[i-1];
    cout<<ans;
    return 0;
}
