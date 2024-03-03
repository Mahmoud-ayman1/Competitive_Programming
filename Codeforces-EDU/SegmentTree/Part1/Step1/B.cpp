#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SegmentTree{
private:
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
    int sz;vector<ll>seg;ll skip=LLONG_MAX;
    ll merge(ll x,ll y)
    {
        return min(x,y);
    }
    void build(int l,int r,int node,vector<ll>&arr)
    {
        if(l==r)
        {
            if(l<arr.size())
            {
                seg[node]=arr[l];
            }
            return;
        }
        build(l,mid,L,arr);
        build(mid+1,r,R,arr);
        seg[node]=merge(seg[L],seg[R]);
    }
    void update(int l,int r,int node,int idx,ll val)
    {
        if(l==r)
        {
            seg[node]=val;
            return;
        }
        if(idx<=mid)
        {
            update(l,mid,L,idx,val);
        }
        else
        {
            update(mid+1,r,R,idx,val);
        }
        seg[node]=merge(seg[L],seg[R]);
    }
    ll query(int l,int r,int node,int lq,int rq)
    {
        if(r<lq||l>rq)
        {
            return skip;
        }
        if(l>=lq&&r<=rq)
        {
            return seg[node];
        }
        ll lft=query(l,mid,L,lq,rq);
        ll rgt=query(mid+1,r,R,lq,rq);
        return merge(lft,rgt);
    }
public:
    SegmentTree(vector<ll>&arr)
    {
        sz=1;int n=arr.size();
        while(sz<n) sz*=2;
        seg=vector<ll>(sz*2,skip);
        build(0,sz-1,0,arr);
    }
    void update(int idx,ll val)
    {
        update(0,sz-1,0,idx,val);
    }
    ll query(int l,int r)
    {
        return query(0,sz-1,0,l,r);
    }
#undef L
#undef R
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    SegmentTree tree(v);
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            ll idx,val;cin>>idx>>val;
            tree.update(idx,val);
        }
        else
        {
            int l,r;cin>>l>>r;
            cout<<tree.query(l,r-1)<<'\n';
        }
    }
    return 0;
}
