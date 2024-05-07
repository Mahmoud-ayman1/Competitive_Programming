#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int l=0,r=0;ll ans=0;
    for(int i=0;i<n;i++)
    {
        while(r<m&&b[r]<=a[i]) r++;
        while(l<m&&b[l]<a[i]) l++;
        ans+=r-l;
    }
    cout<<ans;
    return 0;
}
