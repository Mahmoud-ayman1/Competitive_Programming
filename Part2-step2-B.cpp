#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int mul(int a,int b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
int add(int a,int b)
{
    a%=mod;
    b%=mod;
    return (a+b)%mod;
}
struct SegmentTree{
private:
    int sz=1,skip=0;
    vector<int>seg,lazy;
    void propegate(int l,int r,int node)
    {
        if(lazy[node]==1)return;
        if(l!=r)
        {
            lazy[2*node+1]=mul(lazy[2*node+1],lazy[node]);
            lazy[2*node+2]=mul(lazy[2*node+2],lazy[node]);
        }
        seg[node]=mul(seg[node],lazy[node]);
        lazy[node]=1;
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
            lazy[node]=mul(lazy[node],val);
            propegate(l,r,node);
            return;
        }
        int mid=l+r>>1;
        update(l,mid,2*node+1,lx,rx,val);
        update(mid+1,r,2*node+2,lx,rx,val);
        seg[node]=add(seg[2*node+1],seg[2*node+2]);
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
        return add(query(l,mid,2*node+1,lx,rx),query(mid+1,r,2*node+2,lx,rx));
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
        seg=vector<int>(sz*2,1);
        lazy=vector<int>(sz*2,1LL);
        for(int i=1;i<sz;i++)
        {
            update(i,i,1);
        }
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
