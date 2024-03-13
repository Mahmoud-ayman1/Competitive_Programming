const int N=1e6+5,base1=127,base2=131,mod1=1e9+7,mod2=2e9+11;
int pw1[N],pw2[N];pair<int,int>pre[N];
void init()
{
    pw1[0]=pw2[0]=1;
    for(int i=1;i<N;i++)
    {
        pw1[i]=(1LL*pw1[i-1]*base1)%mod1;
        pw2[i]=(1LL*pw2[i-1]*base2)%mod2;
    }
}
void Hash(string&s)
{
    int a=0,b=0;
    for(int i=0;i<s.size();i++)
    {
        a=(1LL*a*base1)%mod1;
        b=(1LL*b*base2)%mod2;
        a=(a+s[i])%mod1;
        b=(b+s[i])%mod2;
        pre[i]={a,b};
    }
}
pair<int,int>get(int l,int r)
{
    auto ret=pre[r];
    int sz=r-l+1;
    --l;
    if(l>=0)
    {
        ret.first-=(1LL*pre[l].first*pw1[sz])%mod1;
        if(ret.first<0) ret.first+=mod1;
        ret.second-=(1LL*pre[l].second*pw2[sz])%mod2;
        if(ret.second<0) ret.second+=mod2;
    }
    return ret;
}
