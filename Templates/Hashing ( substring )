#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5,base1=127,base2=131,mod1=1e9+7,mod2=2e9+11;
int n,q,pw1[N],pw2[N];pair<int,int>pre[N],suf[N];
void init()
{
    pw1[0]=pw2[0]=1;
    for(int i=1;i<N;i++)
    {
        pw1[i]=(1LL*pw1[i-1]*base1)%mod1;
        pw2[i]=(1LL*pw2[i-1]*base2)%mod2;
    }
}
void Hash(string&s,pair<int,int>arr[])
{
    int a=0,b=0;
    for(int i=0;i<s.size();i++)
    {
        a=(1LL*a*base1)%mod1;
        b=(1LL*b*base2)%mod2;
        a=(a+s[i])%mod1;
        b=(b+s[i])%mod2;
        arr[i]={a,b};
    }
}
pair<int,int>get(int l,int r,pair<int,int>arr[])
{
    auto ret=arr[r];
    int sz=r-l+1;
    --l;
    if(l>=0)
    {
        ret.first-=(1LL*arr[l].first*pw1[sz])%mod1;
        if(ret.first<0) ret.first+=mod1;
        ret.second-=(1LL*arr[l].second*pw2[sz])%mod2;
        if(ret.second<0) ret.second+=mod2;
    }
    return ret;
}
bool pal(int l,int r)
{
    return get(l,r,pre)==get(n-r-1,n-l-1,suf);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    string s;cin>>s;
    n=s.size();
    Hash(s,pre);
    reverse(s.begin(),s.end());
    Hash(s,suf);
    reverse(s.begin(),s.end());
    if(pal(0,n-1))
    {
        cout<<"YES\n";
    }
    return 0;
}
