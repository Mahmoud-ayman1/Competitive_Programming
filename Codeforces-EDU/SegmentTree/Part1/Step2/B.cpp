#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SegmentTree{
private:
    int sz;vector<int>seg;
    int merge(int a,int b)
    {
        return a+b;
    }
    void update(int l,int r,int node,int idx)
    {
        if(l==r)
        {
            seg[node]^=1;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid)
        {
            update(l,mid,2*node+1,idx);
        }
        else
        {
            update(mid+1,r,2*node+2,idx);
        }
        seg[node]=merge(seg[2*node+1],seg[2*node+2]);
    }
    int query(int l,int r,int node,int k)
    {
        if(l==r)
        {
            return l;
        }
        int lft=seg[2*node+1];
        int mid=(l+r)/2;
        if(k<=lft)
        {
            return query(l,mid,2*node+1,k);
        }
        return query(mid+1,r,2*node+2,k-lft);
    }
public:
    SegmentTree(int n)
    {
        sz=1;
        while(sz<n)sz*=2;
        seg=vector<int>(sz*2);
    }
    void update(int idx)
    {
        update(0,sz-1,0,idx);
    }
    int query(int k)
    {
        return query(0,sz-1,0,k);
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
        if(x)tree.update(i);
    }
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int idx;cin>>idx;
            tree.update(idx);
        }
        else
        {
            int k;cin>>k;
            cout<<tree.query(k+1)<<'\n';
        }
    }
    return 0;
}
