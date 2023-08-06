#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll s[N],dp[N][22];int n,q,LOG[N];
ll merge(ll a,ll b)
{
    return max(a,b);
}
void build()
{
    for(int i=0;i<n;i++)
    {
        dp[i][0]=s[i];
    }
    for(int mask=1;(1<<mask)<=n;mask++)
    {
        for(int i=0;i+(1<<mask)<=n;i++)
        {
            dp[i][mask]=merge(dp[i][mask-1],dp[i+(1<<(mask-1))][mask-1]);
        }
    }
}
ll query(int l,int r)
{
    int mask=LOG[r-l+1];
    return merge(dp[l][mask],dp[r-(1<<mask)+1][mask]);
}
void preCount()
{
    LOG[1]=0;
    for(int i=2;i<N;i++)
    {
        LOG[i]=LOG[i>>1]+1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    preCount();
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    build();
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<query2(--l,--r)<<'\n';
    }
    return 0;
}
