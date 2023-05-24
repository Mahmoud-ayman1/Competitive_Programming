#define int long long
const int N=1e5+5,mod1=1e9+7,mod2=2e9+11;
ll base1=31,base2=37,pw1[N+1],pw2[N+1],inv1[N+1],inv2[N+1];
ll powmod(ll a,ll b,ll m)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return ans;
}
void init()
{
    pw1[0]=pw2[0]=inv1[0]=inv2[0]=1;
    int temp1=powmod(base1,mod1-2,mod1);
    int temp2=powmod(base2,mod2-2,mod2);
    for(int i=1;i<N;i++)
    {
        pw1[i]=(base1*pw1[i-1])%mod1;
        pw2[i]=(base2*pw2[i-1])%mod2;
        inv1[i]=(inv1[i-1]*temp1)%mod1;
        inv2[i]=(inv2[i-1]*temp2)%mod2;
    }
}
struct HashingSegmentTree{
private:
    vector<pair<int,int>>seg;int sz;
    pair<int,int>merge(pair<int,int>l,pair<int,int>r)
    {
        pair<int,int>ret=l;
        ret.first=(ret.first+r.first)%mod1;
        ret.second=(ret.second+r.second)%mod2;
        return ret;
    }
    void update(int l,int r,int node,int idx,int ch)
    {
        if(l==r)
        {
            seg[node]={(ch*pw1[idx])%mod1,(ch*pw2[idx])%mod2};
            return;
        }
        int mid=l+r>>1;
        if(idx<=mid)update(l,mid,2*node+1,idx,ch);
        else update(mid+1,r,2*node+2,idx,ch);
        seg[node]=merge(seg[2*node+1],seg[2*node+2]);
    }
    pair<int,int>query(int l,int r,int node,int lx,int rx)
    {
        if(l>=lx&&r<=rx)
        {
            return seg[node];
        }
        if(l>rx||r<lx)return {0,0};
        int mid=l+r>>1;
        pair<int,int>lft=query(l,mid,2*node+1,lx,rx);
        pair<int,int>rgt=query(mid+1,r,2*node+2,lx,rx);
        return merge(lft,rgt);
    }
public:
    HashingSegmentTree(int n)
    {
        sz=1;
        while(sz<=n)sz*=2;
        seg=vector<pair<int,int>>(sz*2);
    }
    void update(int idx,char ch)
    {
        update(0,sz-1,0,idx,ch-'a'+1);
    }
    pair<int,int>query(int l,int r)
    {
        pair<int,int>ret=query(0,sz-1,0,l,r);
        ret.first=(ret.first*inv1[l-1])%mod1;
        ret.second=(ret.second*inv2[l-1])%mod2;
        return ret;
    }
};
