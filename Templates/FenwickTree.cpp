const int N=1e5+5;
struct FenwickTree{
    int bit[N]={};
    void update(int idx,int val)
    {
        while(idx<N)
        {
            bit[idx]+=val;
            idx+=idx&-idx;
        }
    }
    int query(int idx)
    {
        int ret=0;
        while(idx>0)
        {
            ret+=bit[idx];
            idx-=idx&-idx;
        }
        return ret;
    }
    ll prefix(int l,int r)
    {
        return query(r)-query(l-1);
    }
};
