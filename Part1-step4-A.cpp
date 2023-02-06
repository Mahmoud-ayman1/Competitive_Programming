#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SegmentTree{
private:
    int sz=1,skip=0;vector<ll>seg;
    ll merge(ll a,ll b)
    {
        return a+b;
    }
    void update(int l,int r,int node,int idx,ll val)
    {
        if(l==r)
        {
            seg[node]=val;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid)
        {
            update(l,mid,2*node+1,idx,val);
        }
        else
        {
            update(mid+1,r,2*node+2,idx,val);
        }
        seg[node]=merge(seg[2*node+1],seg[2*node+2]);
    }
    ll query(int l,int r,int node,int lx,int rx)
    {
        if(r<lx||l>rx)
        {
            return skip;
        }
        if(l>=lx&&r<=rx)
        {
            return seg[node];
        }
        int mid=(l+r)/2;
        return merge(query(l,mid,2*node+1,lx,rx),query(mid+1,r,2*node+2,lx,rx));
    }
public:
    SegmentTree(int n)
    {
        while(sz<n)sz*=2;
        seg=vector<ll>(sz*2,0);
    }
    void update(int idx,ll val)
    {
        update(0,sz-1,0,idx,val);
    }
    ll query(int l,int r)
    {
        return query(0,sz-1,0,l,r);
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n;
    SegmentTree tree(n);
    for(int i=0;i<n;i++)
    {
        ll x;cin>>x;
        if(i&1)x=-x;
        tree.update(i,x);
    }
    cin>>q;
    while(q--)
    {
        int op;cin>>op;
        if(!op)
        {
            ll idx,val;cin>>idx>>val;
            if(idx%2==0)val*=-1;
            tree.update(idx-1,val);
        }
        else
        {
            int l,r;cin>>l>>r;
            ll ans=tree.query(l-1,r-1);
            if(l%2==0)ans*=-1;
            cout<<ans<<'\n';
        }
    }
    return 0;
}
