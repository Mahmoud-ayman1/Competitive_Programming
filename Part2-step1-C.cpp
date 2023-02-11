#include<bits/stdc++.h>
using namespace std;
#define int long long
struct SegmentTree{
private:
    int sz=1,skip;
    vector<int>seg,lazy;
    void propegate(int l,int r,int node)
    {
        if(lazy[node]==LLONG_MAX)return;
        if(l!=r)
        {
            lazy[2*node+1]=lazy[2*node+2]=lazy[node];
        }
        seg[node]=lazy[node];
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
    }
    int query(int l,int r,int node,int idx)
    {
        propegate(l,r,node);
        if(l==r)
        {
            return seg[node];
        }
        int mid=l+r>>1;
        if(idx<=mid)
        {
            return query(l,mid,2*node+1,idx);
        }
        else
        {
            return query(mid+1,r,2*node+2,idx);
        }
    }
public:
    SegmentTree(int n){
        while(sz<=n)sz*=2;
        seg=vector<int>(sz*2,0);
        lazy=vector<int>(sz*2,LLONG_MAX);
    }
    void update(int l,int r,int val)
    {
        update(0,sz-1,0,l,r,val);
    }
    int query(int idx)
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
            int l,r,val;cin>>l>>r>>val;
            tree.update(l+1,r,val);
        }
        else
        {
            int idx;cin>>idx;
            cout<<tree.query(idx+1)<<'\n';
        }
    }
    return 0;
}
