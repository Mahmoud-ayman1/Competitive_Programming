#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=2e5;
ll s[2*N];
struct segmentTree
{
    int sz;vector<int>seg;int ret=INT_MAX;
    segmentTree(int n)
    {
        sz=1;
        while(sz<n)sz*=2;
        seg.assign(2*sz,0);
    }
    int merge(int a,int b)
    {
        return min(a,b);
    }
    void build(int l,int r,int node)
    {
        if(l==r)
        {
            seg[node]=s[l];
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*node);
        build(mid+1,r,2*node+1);
        seg[node]=merge(seg[2*node],seg[2*node+1]);
    }
    void update(int l,int r,int node,int idx,int val)
    {
        if(l==r)
        {
            seg[node]=val;
            return;
        }
        int mid=(l+r)/2;
        if(mid<idx)
        {
            update(mid+1,r,2*node+1,idx,val);
        }
        else
        {
            update(l,mid,2*node,idx,val);
        }
        seg[node]=merge(seg[2*node],seg[2*node+1]);
    }
    int query(int l,int r,int node,int lx,int rx)
    {
        if(l>rx||r<lx)
        {
            return ret;
        }
        if(l>=lx&&r<=rx)
        {
            return seg[node];
        }
        int mid=(l+r)/2;
        int a=query(l,mid,2*node,lx,rx);
        int b=query(mid+1,r,2*node+1,lx,rx);
        return merge(a,b);
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    segmentTree tree(n);
    tree.build(1,n,1);
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int idx,val;cin>>idx>>val;
            tree.update(1,n,1,idx+1,val);
        }
        else
        {
            int l,r;cin>>l>>r;
            cout<<tree.query(1,n,1,l+1,r)<<'\n';
        }
    }
    return 0;
}
