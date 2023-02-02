#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SegmentTree{
private:
    struct node{
        int val,frq;
        node():val(1e9),frq(0){}
    };
    node ret;
    int sz;vector<node>seg;
    node merge(node a,node b)
    {
        node ret;
        ret.frq=0;
        ret.val=min(a.val,b.val);
        if(ret.val==a.val)ret.frq+=a.frq;
        if(ret.val==b.val)ret.frq+=b.frq;
        return ret;
    }
    void update(int l,int r,int node,int idx,int val)
    {
        if(l==r)
        {
            seg[node].val=val;
            seg[node].frq=1;
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
    node query(int l,int r,int node,int lx,int rx)
    {
        if(r<lx||l>rx)
        {
            return ret;
        }
        if(r<=rx&&l>=lx)
        {
            return seg[node];
        }
        int mid=(l+r)/2;
        return merge(query(l,mid,2*node+1,lx,rx),query(mid+1,r,2*node+2,lx,rx));
    }
public:
    SegmentTree (int n)
    {
        sz=1;
        while(sz<n)sz*=2;
        seg=vector<node>(sz*2);
    }
    void update(int idx,int val)
    {
        update(0,sz-1,0,idx,val);
    }
    pair<int,int>query(int l,int r)
    {
        node ret=query(0,sz-1,0,l,r);
        return {ret.val,ret.frq};
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    SegmentTree tree(n);
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        tree.update(i,x);
    }
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int idx,v;cin>>idx>>v;
            tree.update(idx,v);
        }
        else
        {
            int l,r;cin>>l>>r;
            pair<int,int>ans=tree.query(l,r-1);
            cout<<ans.first<<' '<<ans.second<<'\n';
        }
    }
    return 0;
}
