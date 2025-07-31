#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SegmentTree{
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
private:
    vector<ll>seg;ll sz,skip=0;
    ll merge(ll a,ll b)
    {
        return max(a,b);
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
    SegmentTree(int n)
    {
        sz=1;
        while(sz<n)
        {
            sz<<=1;
        }
        seg=vector<ll>(sz<<1,skip);
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
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        int s[n];SegmentTree tr(n+5);
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            tr.update(i,s[i]);
        }
        int Q;cin>>Q;
        vector<pair<int,int>>q[n];
        for(int i=0;i<Q;i++)
        {
            int a,b;cin>>a>>b;
            --a,--b;
            q[a].push_back({b,i});
        }
        map<int,int>lst;SegmentTree tree(n+5);int ans[Q]={};
        for(int i=n-1;i>=0;i--)
        {
            if(lst.count(s[i]))
            {
                int mx=tr.query(i,lst[s[i]]);
                if(mx>s[i])
                {
                    tree.update(lst[s[i]],mx);
                }
            }
            lst[s[i]]=i;
            for(auto[a,b]:q[i])
            {
                ans[b]=tree.query(i,a);
            }
        }
        for(int i=0;i<Q;i++)
        {
            cout<<ans[i]<<'\n';
        }
    }
    return 0;
}
