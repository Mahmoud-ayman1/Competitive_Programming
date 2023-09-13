#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
struct SegmentTreeBeats{
private:
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
#define inf 1e18
    struct Node{
        int sum,mx,secMx,mxCnt;
        Node(int summ,int mxx,int secMxx,int mxCntt):sum(summ),mx(mxx),secMx(secMxx),mxCnt(mxCntt){}
    };
    int sz;vector<Node>seg;
    Node merge(Node&a,Node&b)
    {
        Node ret(0,-inf,-inf,0);
        ret.sum=a.sum+b.sum;
        ret.mx=max(a.mx,b.mx);
        ret.secMx=max(a.secMx,b.secMx);
        if(ret.mx==a.mx) ret.mxCnt+=a.mxCnt;
        else ret.secMx=max(ret.secMx,a.mx);
        if(ret.mx==b.mx) ret.mxCnt+=b.mxCnt;
        else ret.secMx=max(ret.secMx,b.mx);
        return ret;
    }
    void pushMin(int node,int mn)
    {
        if(seg[node].mx>mn)
        {
            int val=seg[node].mx-mn;
            seg[node].sum-=val*seg[node].mxCnt;
            seg[node].mx=mn;
        }
    }
    void update(int l,int r,int node,int lx,int rx,int mn)
    {
        if(r<lx||l>rx||seg[node].mx<=mn)return;
        if(l>=lx&&r<=rx&&mn>seg[node].secMx)
        {
            pushMin(node,mn);
            return;
        }
        pushMin(L,seg[node].mx);
        pushMin(R,seg[node].mx);
        update(l,mid,L,lx,rx,mn);
        update(mid+1,r,R,lx,rx,mn);
        seg[node]=merge(seg[L],seg[R]);
    }
    void build(int l,int r,int node,vector<int>&v)
    {
        if(l==r)
        {
            if(l<v.size())
            {
                seg[node]=Node(v[l],v[l],-inf,1);
            }
            return;
        }
        build(l,mid,L,v);
        build(mid+1,r,R,v);
        seg[node]= merge(seg[L],seg[R]);
    }
    int query(int l,int r,int node,int lx,int rx)
    {
        if(l>rx||r<lx)return 0;
        if(l>=lx&&r<=rx)return seg[node].sum;
        pushMin(L,seg[node].mx);
        pushMin(R,seg[node].mx);
        return query(l,mid,L,lx,rx)+query(mid+1,r,R,lx,rx);
    }
#undef L
#undef R
#undef mid
public:
    SegmentTreeBeats(vector<int>&v)
    {
        int n=v.size()+5;
        sz=1;
        while(sz<=n)sz<<=1;
        seg=vector<Node>(sz<<1,Node(0,-inf,-inf,0));
        build(0,sz-1,0,v);
    }
    void update(int l,int r,int mn)
    {
        update(0,sz-1,0,l,r,mn);
    }
    int query(int l,int r)
    {
        return query(0,sz-1,0,l,r);
    }
#undef inf
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int>s(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    SegmentTreeBeats tree(s);
    int q;cin>>q;while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int l,r,mn;cin>>l>>r>>mn;
            tree.update(l,r,mn);
        }
        else
        {
            int l,r;cin>>l>>r;
            cout<<tree.query(l,r)<<'\n';
        }
    }
    return 0;
}
