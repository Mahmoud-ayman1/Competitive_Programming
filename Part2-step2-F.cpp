#include<bits/stdc++.h>
using namespace std;
#define int long long
struct SegmentTree{
private:
    int sz=1,skip=0;
    vector<int>seg,lazy;
    void propegate(int l,int r,int node)
    {
        if(lazy[node]==LLONG_MAX)return;
        if(l!=r)
        {
            lazy[2*node+1]=lazy[node];
            lazy[2*node+2]=lazy[node];
        }
        int len=r-l+1;
        seg[node]=len*lazy[node];
        lazy[node]=LLONG_MAX;
    }
    void update(int l,int r,int node,int lx,int rx,int val)
    {
        propegate(l,r,node);
        if(l>rx||r<lx)
        {
            return;
        }
        if(l>=lx&&r<=rx)
        {
            lazy[node]=val;
            propegate(l,r,node);
            return;
        }
        int mid=l+r>>1;
        update(l,mid,2*node+1,lx,rx,val);
        update(mid+1,r,2*node+2,lx,rx,val);
        seg[node]=seg[2*node+1]+seg[2*node+2];
    }
    int query(int l,int r,int node,int lx,int rx)
    {
        propegate(l,r,node);
        if(l>=lx&&r<=rx)
        {
            return seg[node];
        }
        if(l>rx||r<lx)
        {
            return skip;
        }
        int mid=l+r>>1;
        return query(l,mid,2*node+1,lx,rx)+query(mid+1,r,2*node+2,lx,rx);
    }
public:
    void update(int l,int r,int val)
    {
        update(0,sz-1,0,l,r,val);
    }
    int query(int l,int r)
    {
        return query(0,sz-1,0,l,r);
    }
    SegmentTree(int n){
        while(sz<=n)sz*=2;
        seg=vector<int>(sz*2,0);
        lazy=vector<int>(sz*2,LLONG_MAX);
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
            int l,r,val;cin>>l>>r>>val;
            tree.update(l+1,r,val);
        }
        else
        {
            int l,r;cin>>l>>r;
            cout<<tree.query(l+1,r)<<'\n';
        }
    }
    return 0;
}
