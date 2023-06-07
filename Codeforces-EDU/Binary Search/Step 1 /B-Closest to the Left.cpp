#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    int s[n+1];
    for(int i=1;i<=n;i++)cin>>s[i];
    while(k--)
    {
        int x;cin>>x;
        int l=1,r=n,ans=0;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(s[mid]>x)r=mid-1;
            else ans=mid,l=mid+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
