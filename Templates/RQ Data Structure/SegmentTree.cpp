struct SegmentTree{
private:
    vector<int>seg;int sz,skip=INT_MAX;
    int merge(int a,int b)
    {
        return min(a,b);
    }
    void update(int l,int r,int node,int idx,int val)
    {
        if(l==r)
        {
            seg[node]=val;
            return;
        }
        int mid=l+r>>1;
        if(mid<idx)
        {
            update(mid+1,r,2*node+2,idx,val);
        }
        else
        {
            update(l,mid,2*node+1,idx,val);
        }
        seg[node]=merge(seg[2*node+1],seg[2*node+2]);
    }
    int query(int l,int r,int node,int lx,int rx)
    {
        if(l>rx||r<lx)return skip;
        if(l>=lx&&r<=rx)return seg[node];
        int mid=l+r>>1;
        int a=query(l,mid,2*node+1,lx,rx);
        int b=query(mid+1,r,2*node+2,lx,rx);
        return merge(a,b);
    }
public:
    SegmentTree(int n)
    {
        sz=1;
        while(sz<=n)sz<<=1;
        seg=vector<int>(sz<<1,skip);
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
