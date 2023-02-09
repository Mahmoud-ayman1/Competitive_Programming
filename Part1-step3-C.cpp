#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
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
    cin>>n;n*=2;
    int s[n+1];
    int vis[200005]={};
    SegmentTree tree;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(!vis[s[i]])
        {
            tree.update(i,1);
        }
        else
        {
            tree.update(i,-1);
        }
        vis[s[i]]=i;
    }
    int ans[n];
    for(int i=1;i<=n;i++)
    {
        if(vis[s[i]]==0)continue;
        int q=tree.query(i,vis[s[i]]);
        int num=vis[s[i]]-i-1;
        ans[s[i]]=(num-q)/2;
        tree.update(vis[s[i]],1);
        vis[s[i]]=0;
    }
    for(int i=1;i<=n/2;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
