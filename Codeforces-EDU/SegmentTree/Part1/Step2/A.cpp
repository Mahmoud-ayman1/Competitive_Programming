#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
struct SegmentTree{
private:
    struct node{
        int pre,suf,mx,sum;
        node():pre(0),suf(0),mx(0),sum(0){}
        node(int v):sum(v),mx(max(v, 0LL)),suf(max(v, 0LL)),pre(max(v, 0LL)){}
    };
    int sz;vector<node>seg;
    node merge(node a,node b)
    {
        node ret;
        ret.sum=a.sum+b.sum;
        ret.pre=max(a.pre,a.sum+b.pre);
        ret.suf=max(b.suf,b.sum+a.suf);
        ret.mx=max({a.mx,b.mx,a.suf+b.pre});
        return ret;
    }
    void update(int l,int r,int node,int idx,int val)
    {
        if(l==r)
        {
            seg[node]={val};
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

public:
    SegmentTree(int n){
        sz=1;
        while(sz<n)sz*=2;
        seg=vector<node>(sz*2);
    }
    void update(int idx,int val)
    {
        update(0,sz-1,0,idx,val);
    }
    int query()
    {
        return seg[0].mx;
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
    cout<<tree.query()<<'\n';
    while(q--)
    {
        int idx,val;cin>>idx>>val;
        tree.update(idx,val);
        cout<<tree.query()<<'\n';
    }
    return 0;
}
