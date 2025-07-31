#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
struct SegmentTree{
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
private:
    vector<ll>seg;ll sz,skip=LLONG_MAX;
    ll merge(ll a,ll b)
    {
        return min(a,b);
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
    ll query(int l,int r,int node,int lx,int rx)
    {
        if(r<lx||l>rx) return skip;
        if(l>=lx&&r<=rx) return seg[node];
        ll left=query(l,mid,L,lx,rx);
        ll right=query(mid+1,r,R,lx,rx);
        return merge(left,right);
    }
public:
    SegmentTree(vector<ll>&arr)
    {
        int n=arr.size();
        sz=1;
        while(sz<n)
        {
            sz<<=1;
        }
        seg=vector<ll>(sz<<1,skip);
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
#undef mid
};
struct SegmentTree2{
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
private:
    ll sz;vector<ll>seg,lazy;
    void propegate(int l,int r,int node)
    {
        if(l>r) return;
        if(lazy[node]==0) return;
        if(l!=r)
        {
            lazy[L]+=lazy[node];
            lazy[R]+=lazy[node];
        }
        seg[node]+=lazy[node];
        lazy[node]=0;
    }
    void update(int l,int r,int node,int lx,int rx,ll val)
    {
        propegate(l,r,node);
        if(l>rx||r<lx) return;
        if(l>=lx&&r<=rx)
        {
            lazy[node]+=val;
            propegate(l,r,node);
            return;
        }
        update(l,mid,L,lx,rx,val);
        update(mid+1,r,R,lx,rx,val);
        seg[node]=min(seg[L],seg[R]);
    }
    int get(int l,int r,int node)
    {
        propegate(l,r,node);
        if(l==r) return l;
        propegate(l,mid,L);
        if(seg[L]<0) return get(l,mid,L);
        propegate(mid+1,r,R);
        if(seg[R]<0) return get(mid+1,r,R);
        seg[node]=min(seg[L],seg[R]);
        return -1;
    }
    ll query(int l,int r,int node,int lx,int rx)
    {
        propegate(l,r,node);
        if(l>rx||r<lx) return LLONG_MAX;
        if(l>=lx&&r<=rx) return seg[node];
        return min(query(l,mid,L,lx,rx),query(mid+1,r,R,lx,rx));
    }
    void set(int l,int r,int node,int idx,ll val)
    {
        propegate(l,r,node);
        if(l==r)
        {
            seg[node]=val;
            return;
        }
        propegate(l,mid,L);
        propegate(mid+1,r,R);
        if(idx<=mid)
        {
            set(l,mid,L,idx,val);
        }
        else
        {
            set(mid+1,r,R,idx,val);
        }
        seg[node]=min(seg[L],seg[R]);
    }
public:
    SegmentTree2(int n)
    {
        sz=1;
        while(sz<n) sz<<=1;
        seg=vector<ll>(sz<<1);
        lazy=vector<ll>(sz<<1);
    }
    void update(int l,int r,ll val)
    {
        update(0,sz-1,0,l,r,val);
    }
    ll query(int l,int r)
    {
        return query(0,sz-1,0,l,r);
    }
    int get()
    {
        return get(0,sz-1,0);
    }
    void set(int idx,ll val)
    {
        set(0,sz-1,0,idx,val);
    }
#undef L
#undef R
#undef mid
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    vector<ll>s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    SegmentTree tree(s);SegmentTree2 tr(n+5),tr2(n+5);
    for(int i=0;i<n;i++)
    {
        tr.set(i,s[i]);
        tr2.set(i,1e15);
    }
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            ll l,r,x;cin>>l>>r>>x;
            --l,--r;
            tr.update(l,r,-x);
            tr2.update(l,r,x);
            while(1)
            {
                int idx=tr.get();
                if(idx==-1) break;
                tree.update(idx,LLONG_MAX);
                tr2.set(idx,-tr.query(idx,idx)+s[idx]);
                tr.set(idx,LLONG_MAX);
            }
        }
        else if(op==2)
        {
            int l,r;cin>>l>>r;
            --l,--r;
            cout<<min(tree.query(l,r),tr2.query(l,r))<<'\n';
        }
    }
    return 0;
}
