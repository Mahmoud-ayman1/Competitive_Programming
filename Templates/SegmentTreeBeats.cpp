#define int long long
struct SegmentTreeBeats{
private:
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
#define inf 1e15+5
    struct Node{
        int sum,mx,secMx,mxCnt,mn,mnCnt,secMn,lazyAdd,lazySet;
        Node(int summ,int mxx,int secMxx,int mxCntt,int mnn,int secMnn,int mnCntt,int add=0,int set=-1)
        :sum(summ),mx(mxx),secMx(secMxx),mxCnt(mxCntt),
        mn(mnn),secMn(secMnn),mnCnt(mnCntt),
        lazyAdd(add),lazySet(set){}
    };
    int sz;vector<Node>seg;
    Node merge(Node&a,Node&b)
    {
        Node ret(0,-inf,-inf,0,inf,inf,0,0,-1);
        ret.sum=a.sum+b.sum;
        ret.mx=max(a.mx,b.mx);// max
        ret.secMx=max(a.secMx,b.secMx);
        if(ret.mx==a.mx) ret.mxCnt+=a.mxCnt;
        else ret.secMx=max(ret.secMx,a.mx);
        if(ret.mx==b.mx) ret.mxCnt+=b.mxCnt;
        else ret.secMx=max(ret.secMx,b.mx);
        ret.mn=min(a.mn,b.mn);// min
        ret.secMn=min(a.secMn,b.secMn);
        if(ret.mn==a.mn) ret.mnCnt+=a.mnCnt;
        else ret.secMn=min(ret.secMn,a.mn);
        if(ret.mn==b.mn) ret.mnCnt+=b.mnCnt;
        else ret.secMn=min(ret.secMn,b.mn);
        return ret;
    }
    void pushSet(int l,int r,int node,int val)
    {
        seg[node]=Node(val*(r-l+1),val,-inf,r-l+1,val,inf,r-l+1,0,val);
    }
    void pushMin(int l,int r,int node,int mn)
    {
        if(seg[node].mn>=mn)
        {
            pushSet(l,r,node,mn);
            return;
        }
        if(seg[node].mx>mn)
        {
            if(seg[node].secMn==seg[node].mx) seg[node].secMn=mn;
            int val=seg[node].mx-mn;
            seg[node].sum-=val*seg[node].mxCnt;
            seg[node].mx=mn;
        }
    }
    void pushMax(int l,int r,int node,int mx)
    {
        if(seg[node].mx<=mx)
        {
            pushSet(l,r,node,mx);
            return;
        }
        if(seg[node].mn<mx)
        {
            if(seg[node].secMx==seg[node].mn) seg[node].secMx=mx;
            int val=mx-seg[node].mn;
            seg[node].sum+=val*seg[node].mnCnt;
            seg[node].mn=mx;
        }
    }
    void pushAdd(int l,int r,int node,int val)
    {
        if(seg[node].mx==seg[node].mn)
        {
            pushSet(l,r,node,seg[node].mn+val);
            return;
        }
        seg[node].mx+=val;
        if(seg[node].secMx!=-inf)  seg[node].secMx+=val;
        seg[node].mn+=val;
        if(seg[node].secMn!=inf)  seg[node].secMn+=val;
        seg[node].sum+=(r-l+1)*val;
        seg[node].lazyAdd+=val;
    }
    void propegate(int l,int r,int node)
    {
        if(l==r) return;
        if(seg[node].lazySet!=-1)
        {
            pushSet(l,mid,L,seg[node].lazySet);
            pushSet(mid+1,r,R,seg[node].lazySet);
            seg[node].lazySet=-1;
        }
        else
        {
            pushAdd(l,mid,L,seg[node].lazyAdd);
            pushAdd(mid+1,r,R,seg[node].lazyAdd);
            seg[node].lazyAdd=0;
            pushMin(l,mid,L,seg[node].mx);
            pushMin(mid+1,r,R,seg[node].mx);
            pushMax(l,mid,L,seg[node].mn);
            pushMax(mid+1,r,R,seg[node].mn);
        }
    }
    void build(int l,int r,int node,vector<int>&v)
    {
        if(l==r)
        {
            if(l<v.size())
            {
                seg[node]=Node(v[l],v[l],-inf,1,v[l],inf,1);
            }
            return;
        }
        build(l,mid,L,v);
        build(mid+1,r,R,v);
        seg[node]= merge(seg[L],seg[R]);
    }
    void updateAdd(int l,int r,int node,int lx,int rx,int val)
    {
        if(l>rx||r<lx)return;
        if(l>=lx&&r<=rx)
        {
            pushAdd(l,r,node,val);
            return;
        }
        propegate(l,r,node);
        updateAdd(l,mid,L,lx,rx,val);
        updateAdd(mid+1,r,R,lx,rx,val);
        seg[node]=merge(seg[L],seg[R]);
    }
    void updateSet(int l,int r,int node,int lx,int rx,int val)
    {
        if(l>rx||r<lx)return;
        if(l>=lx&&r<=rx)
        {
            pushSet(l,r,node,val);
            return;
        }
        propegate(l,r,node);
        updateSet(l,mid,L,lx,rx,val);
        updateSet(mid+1,r,R,lx,rx,val);
        seg[node]=merge(seg[L],seg[R]);
    }
    void updateMin(int l,int r,int node,int lx,int rx,int mn)
    {
        if(r<lx||l>rx||seg[node].mx<=mn) return;
        if(l>=lx&&r<=rx&&mn>seg[node].secMx)
        {
            pushMin(l,r,node,mn);
            return;
        }
        propegate(l,r,node);
        updateMin(l,mid,L,lx,rx,mn);
        updateMin(mid+1,r,R,lx,rx,mn);
        seg[node]=merge(seg[L],seg[R]);
    }
    void updateMax(int l,int r,int node,int lx,int rx,int mx)
    {
        if(l>rx||r<lx||mx<=seg[node].mn) return;
        if(l>=lx&&r<=rx&&mx<seg[node].secMn)
        {
            pushMax(l,r,node,mx);
            return;
        }
        propegate(l,r,node);
        updateMax(l,mid,L,lx,rx,mx);
        updateMax(mid+1,r,R,lx,rx,mx);
        seg[node]=merge(seg[L],seg[R]);
    }
    int querySum(int l,int r,int node,int lx,int rx)
    {
        if(l>rx||r<lx)return 0;
        if(l>=lx&&r<=rx)return seg[node].sum;
        propegate(l,r,node);
        return querySum(l,mid,L,lx,rx)+querySum(mid+1,r,R,lx,rx);
    }
    int queryMin(int l,int r,int node,int lx,int rx)
    {
        if(l>rx||r<lx)return inf;
        if(l>=lx&&r<=rx)return seg[node].mn;
        propegate(l,r,node);
        return min(queryMin(l,mid,L,lx,rx),queryMin(mid+1,r,R,lx,rx));
    }
    int queryMax(int l,int r,int node,int lx,int rx)
    {
        if(l>rx||r<lx)return -inf;
        if(l>=lx&&r<=rx)return seg[node].mx;
        propegate(l,r,node);
        return max(queryMax(l,mid,L,lx,rx),queryMax(mid+1,r,R,lx,rx));
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
        seg=vector<Node>(sz<<1,Node(0,-inf,-inf,0,inf,inf,0,0,-1));
        build(0,sz-1,0,v);
    }
    void updateAdd(int l,int r,int val)
    {
        updateAdd(0,sz-1,0,l,r,val);
    }
    void updateSet(int l,int r,int val)
    {
        updateSet(0,sz-1,0,l,r,val);
    }
    void updateMin(int l,int r,int mn)
    {
        updateMin(0,sz-1,0,l,r,mn);
    }
    void updateMax(int l,int r,int mx)
    {
        updateMax(0,sz-1,0,l,r,mx);
    }
    int queryMax(int l,int r)
    {
        return queryMax(0,sz-1,0,l,r);
    }
    int queryMin(int l,int r)
    {
        return queryMin(0,sz-1,0,l,r);
    }
    int querySum(int l,int r)
    {
        return querySum(0,sz-1,0,l,r);
    }
#undef inf
};
