#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SegmentTree{
private:
    int sz=1;vector<ll>seg;
    ll merge(ll a,ll b)
    {
        return max(a,b);
    }
    void update(int l,int r,int node,int lx,int rx,ll val)
    {
        if(l>=lx&&r<=rx)
        {
            seg[node]=merge(seg[node],val);
            return;
        }
        if(r<lx||l>rx)
        {
            return;
        }
        int mid=(l+r)/2;
        update(l,mid,2*node+1,lx,rx,val);
        update(mid+1,r,2*node+2,lx,rx,val);
    }
    ll query(int l,int r,int node,int idx)
    {
        if(l==r)
        {
            return seg[node];
        }
        int mid=(l+r)/2;
        if(idx<=mid)
        {
            return merge(query(l,mid,2*node+1,idx),seg[node]);
        }
        return merge(query(mid+1,r,2*node+2,idx),seg[node]);
    }
public:
    SegmentTree(int n)
    {
        while(sz<n)sz*=2;
        seg=vector<ll>(sz*2,0);
    }
    void update(int l,int r,ll val)
    {
        update(0,sz-1,0,l,r,val);
    }
    ll query(int idx)
    {
        return query(0,sz-1,0,idx);
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    SegmentTree tree(n);
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            ll l,r,val;cin>>l>>r>>val;
            tree.update(l,r-1,val);
        }
        else
        {
            int idx;cin>>idx;
            cout<<tree.query(idx)<<'\n';
        }
    }
    return 0;
}
