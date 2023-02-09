#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int n,q;
struct SegmentTree{
private:
    int sz=1,skip=0;vector<int>seg;
    int merge(int a,int b)
    {
        return a+b;
    }
    void update(int l,int r,int node,int idx,int val)
    {
        if(l==r)
        {
            seg[node]+=val;
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
    int query(int l,int r,int node,int lx,int rx)
    {
        if(l>rx||r<lx)
        {
            return skip;
        }
        if(l>=lx&&r<=rx)
        {
            return seg[node];
        }
        int mid=l+r>>1;
        int lft=query(l,mid,2*node+1,lx,rx);
        int rgt=query(mid+1,r,2*node+2,lx,rx);
        return merge(lft,rgt);
    }
public:
    SegmentTree(){
        while(sz<n+5)sz*=2;
        seg=vector<int>(sz*2,0);
    }
    void update(int idx,int val)
    {
        update(0,sz-1,0,idx,val);
    }
    int query(int l,int r)
    {
        return query(0,sz-1,0,l,r);
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    SegmentTree tree;
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int l,r,val;cin>>l>>r>>val;
            tree.update(l+1,val);
            tree.update(r+1,-val);
        }
        else
        {
            int idx;cin>>idx;
            cout<<tree.query(1,idx+1)<<'\n';
        }
    }
    return 0;
}
