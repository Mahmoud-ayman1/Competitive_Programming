#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,q,s[N],T[N][22],Log[N];
ll merge(ll a,ll b)
{
    return min(a,b);
}
void build()
{
    for(int i=0;i<n;i++)
    {
        T[i][0]=s[i];
    }
    for(int pw=1;(1<<pw)<=n;pw++) 
    {
        for(int i=0;i+(1<<pw)<=n;i++)
        {
            T[i][pw]=merge(T[i][pw-1],T[i+(1<<(pw-1))][pw-1]);
        }
    }
}
ll query(int l,int r)
{
    if(r<l)
    {
        return LLONG_MAX;
    }
    int sz=r-l+1;
    ll ret=LLONG_MAX;
    for(int i=0;i<22;i++)
    {
        if((sz>>i)&1)
        {
            return merge(query(l+(1<<i),r),T[l][i]);
        }
    }
    return ret;
}
ll query2(int l,int r)
{
    int sz=r-l+1;
    int pw=Log[sz];
    return merge(T[l][pw],T[r-(1<<pw)+1][pw]);
}
void preCount()
{
    Log[1]=0;
    for(int i=2;i<N;i++)
    {
        Log[i]=Log[i>>1]+1;
    }
}
signed main()
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
        cout<<query(--l,--r)<<'\n';
    }
    return 0;
}
