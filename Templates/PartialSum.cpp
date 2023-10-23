#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    ll s[n]={};
    for(int i=0;i<n;i++) cin>>s[i];
    ll par[n+1]={};
    while(q--)
    {
        ll l,r,val;cin>>l>>r>>val;
        --l,--r;
        par[l]+=val;
        par[r+1]-=val;
    }
    for(int i=1;i<n;i++) par[i]+=par[i-1];
    for(int i=0;i<n;i++) cout<<s[i]+par[i]<<' ';
    return 0;
}
