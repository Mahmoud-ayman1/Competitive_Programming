#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
const int Q=100005;
const int SQ=317;
struct query{
    int l,r,q_idx,block_idx;
    query(){}
    query(int _l,int _r,int _q_idx)
    {
        l=_l-1,r=_r-1,q_idx=_q_idx,block_idx=_l/SQ;
    }
    bool operator<(const query&y)const{
        if(block_idx!=y.block_idx)
        {
            return block_idx<y.block_idx;
        }
        return r<y.r;
    }
};
int n,q,s[N],res=0,q_ans[Q],f[N],ff[N];int mx=0;
query queries[Q];
void add(int idx)
{
    // what you need to add
}
void remove(int idx)
{
    // what you need to remove
}
void MO_process()
{
    sort(queries,queries+q);
    int l=1,r=0;
    for(int i=0;i<q;i++)
    {
        while(r<queries[i].r)add(++r);
        while(r>queries[i].r)remove(r--);
        while(l<queries[i].l)remove(l++);
        while(l>queries[i].l)add(--l);
        q_ans[queries[i].q_idx]=res;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<q;i++)
    {
        int l,r;cin>>l>>r;
        queries[i]=query(++l,++r,i);
    }
    MO_process();
    for(int i=0;i<q;i++)
    {
        cout<<q_ans[i]<<'\n';
    }
    return 0;
}
