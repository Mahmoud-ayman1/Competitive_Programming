#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct SegmentTree{
private:
    int sz=1;vector<int>seg;
    int merge(int a,int b)
    {
        return a+b;
    }
    void update(int l,int r,int node,int idx,int val)
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
    int query(int l,int r,int node,int k)
    {
        if(l==r)
        {
            return l;
        }
        int rgt=seg[2*node+2];
        int mid=l+r>>1;
        if(rgt>k)
        {
            return query(mid+1,r,2*node+2,k);
        }
        return query(l,mid,2*node+1,k-rgt);
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
    int query(int k)
    {
        return query(0,sz-1,0,k);
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int s[n+1];
    SegmentTree tree;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        tree.update(i,1);
    }
    int ans[n+1]={};
    for(int i=n;i>=1;i--)
    {
        int x=tree.query(s[i]);
        ans[i]=x;
        tree.update(x,0);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
