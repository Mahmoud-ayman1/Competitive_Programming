#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll n,k;ld s[10005];
bool can(ld mid)
{
    ll ret=0;
    for(int i=0;i<n;i++)
    {
        ret+=floor(s[i]/mid);
    }
    return ret>=k;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>s[i];
    int iterations=300;ld l=0,r=1e7,ans=0;
    while(iterations--&&l<=r)
    {
        ld mid=(l+r)/2;
        if(can(mid))
        {
            ans=mid;
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<fixed<<setprecision(6)<<ans;
    return 0;
}
