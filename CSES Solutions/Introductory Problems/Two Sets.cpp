#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    ll all=n*(n+1)/2;
    if(all&1)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES\n";
        ll sum=0,c=0;
        bool vis[n+1]={};
        for(int i=n;i>=1;i--)
        {
            if(sum+i<=all/2) sum+=i,vis[i]=1,c++;
        }
        cout<<c<<'\n';
        for(int i=1;i<=n;i++) if(vis[i]) cout<<i<<' ';
        cout<<'\n';
        cout<<n-c<<'\n';
        for(int i=1;i<=n;i++) if(!vis[i]) cout<<i<<' ';
    }
    return 0;
}
